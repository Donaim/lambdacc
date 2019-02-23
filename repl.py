#! /usr/bin/env python3

from multiprocessing import Pool
import subprocess

CC = 'tcc'
PROJ = 'repl'
SRC = PROJ + '/repl.ini'
DEST = 'repl.c'

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)

	parser.add_argument('-r', dest='refresh', action='store_true', help='Refresh contents of script file')
	parser.add_argument('-k', dest='refresh', action='store_false', help='Keep contents of script file')
	parser.set_defaults(refresh=False)

	return parser.parse_args()

TFLAGS = [
	'--source', '{SRC}'.format(SRC=SRC),
	'--dest', '{DEST}'.format(DEST=DEST),
	'--no-make-inline',
	'--do-caching',
	'--no-print-intermediate',
	'--count-total-exec',
	'--no-show-debug',
	'--use-typeid',
	'--echo-expr',
	'--flagsfile', '{PROJ}/flags.h',
	'--headerfile', '{PROJ}/header.h',
	'--declare-file', '{PROJ}/declare.h',
	'--define-file', '{PROJ}/define.c',
	'--footerfile', '{PROJ}/footer.c',
]
TFLAGS = [s.format(PROJ=PROJ) for s in TFLAGS]

def kcompile():
	subprocess.check_call(['./lambda-cpp.py'] + TFLAGS)
	subprocess.check_call([CC, '-o', 'repl.exe', '-O0', DEST, PROJ + '/header.c'])
	subprocess.check_call(['./repl.exe'])

def loop(file):
	while True:
		inp = input('> ')
		inp = (inp.replace('\n', ' ')).strip()
		if inp == 'exit':
			break

		file.write(inp + '\n\n')
		file.flush()
		kcompile()

def setup(args, callback):
	mode = 'w' if args.refresh else 'a'
	file = open(SRC, mode)

	callback(file)

def main():
	args = get_arguments()
	setup(args, loop)

if __name__ == '__main__':
	main()

