#! /usr/bin/env python3

from multiprocessing import Pool
import subprocess

CC = 'tcc'
PROJ = 'repl'
SRC = PROJ + '/repl.ini'
DEST = PROJ + '/repl.c'

TFLAGS = [
	'--source "" --dest "{dest}"',
	'--no-make-inline',
	'--do-caching',
	'--no-print-intermediate',
	'--count-total-exec',
	'--no-show-debug',
	'--use-typeid',
	'--echo-expr',
	'--flagsfile $(PROJ)/flags.h',
	'--headerfile $(PROJ)/header.h',
	'--declare-file $(PROJ)/declare.h',
	'--define-file $(PROJ)/define.c',
	'--footerfile $(PROJ)/footer.c',
]

def kcompile():
	subprocess.check_call(['lambda-cpp.py', '--no-make-inline'])
	subprocess.check_call([CC, '-O0', ])

with open(SRC, 'w') as file:
	while True:
		inp = input('> ')
		inp = (inp.replace('\n', ' ')).strip()
		if inp == 'exit':
			break

		file.flush()
		kcompile()




