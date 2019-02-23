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
	'--no-count-total-exec',
	'--no-show-debug',
	'--use-typeid',
	'--no-echo-expr',
	'--flagsfile', '{PROJ}/flags.h',
	'--headerfile', '{PROJ}/header.h',
	'--declare-file', '{PROJ}/declare.h',
	'--define-file', '{PROJ}/define.c',
	'--footerfile', '{PROJ}/footer.c',
]
TFLAGS = [s.format(PROJ=PROJ) for s in TFLAGS]

def is_binding(line: str) -> bool:
	(pre, _, p) = line.partition(' ')
	(p2, mid, post) = p.strip().partition('=')
	return post

def kcompile():
	subprocess.check_call(['./lambda-cpp.py'] + TFLAGS)
	subprocess.check_call([CC, '-o', 'repl.exe', '-O0', DEST, PROJ + '/header.c'])
	subprocess.check_call(['./repl.exe'])

def loop(file):
	buffor = []
	while True:
		inp = input('> ')
		inp = (inp.replace('\n', ' ')).strip()
		if inp == '#exit':
			break

		buffor.append(inp + '\n')

		file.seek(0, 0)
		file.truncate(0)
		file.writelines(buffor)
		file.flush()

		if not is_binding(inp):
			try:
				kcompile()
			except:
				print('Repl sees error')

			buffor.pop()

def setup(args, callback):
	mode = 'w' if args.refresh else 'a'
	file = open(SRC, mode)

	callback(file)

def main():
	args = get_arguments()
	setup(args, loop)

if __name__ == '__main__':
	main()

