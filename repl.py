#! /usr/bin/env python3

from multiprocessing import Pool
import subprocess
from collections import OrderedDict

from lambdacc import get_splitted_lines

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
	'--no-track-allocs',
	'--no-track-pool-allocs',
	'--flagsfile', '{PROJ}/flags.h',
	'--headerfile', '{PROJ}/header.h',
	'--declare-file', '{PROJ}/declare.h',
	'--define-file', '{PROJ}/define.c',
	'--footerfile', '{PROJ}/footer.c',
]
TFLAGS = [s.format(PROJ=PROJ) for s in TFLAGS]

def get_binding_name(line: str) -> str:
	(pre, _, p) = line.partition(' ')
	(p2, mid, post) = p.strip().partition('=')
	if p2:
		return None
	if post:
		return pre
	else:
		return None

def lines_splited(text: str) -> list:
	''' Fold lines that start with tab '''

	sp = get_splitted_lines(text)
	return OrderedDict([ (line.pre, line.all + '\n') for line in sp ])

def kcompile():
	subprocess.check_call(['./lambdacc.py'] + TFLAGS)
	subprocess.check_call([CC, '-o', 'repl.exe', '-O0', DEST, PROJ + '/header.c'])
	subprocess.check_call(['./repl.exe'])

def dump_buffor(file, buffor):
	file.seek(0, 0)
	file.truncate(0)
	for line in buffor.values():
		file.write(line)
	file.flush()

def loop(file, buffor):
	while True:
		inp = input('> ')
		inp = (inp.replace('\n', ' ')).strip()
		if inp == '#exit':
			dump_buffor(file, buffor)
			break
		if inp == '#env':
			print('\t' + '\n\t'.join(filter(lambda k: k, buffor.keys())))
			continue

		name = get_binding_name(inp)

		buffor[name] = '\n' + inp + '\n'
		dump_buffor(file, buffor)

		if not name:
			try:
				kcompile()
			except:
				pass

			buffor.pop(name)

def setup(args, callback):
	buffor = OrderedDict()
	if not args.refresh:
		r = None
		try:
			with open(SRC, 'r') as r:
				text = r.read()
				buffor = lines_splited(text)
		except:
			with open(SRC, 'w+'):
				pass

	file = open(SRC, 'w')

	subprocess.check_call(['make', 'PROJ={PROJ}'.format(PROJ=PROJ), '{PROJ}/define.c'.format(PROJ=PROJ)])

	callback(file, buffor=buffor)

def main():
	args = get_arguments()
	setup(args, loop)

if __name__ == '__main__':
	try:
		main()
	except EOFError:
		pass

