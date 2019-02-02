#!/usr/bin/env python3

import parser
from parser import *

def split_binding_and_def(line: str) -> (str, str):
	(pre, mid, post) = line.partition('=')

	post = post.strip()
	if mid:
		if not post:
			raise SyntaxError('Binding at line "{}" cannot have empty definition'.format(line))
		
		pre = pre.strip()
		if not pre:
			raise SyntaxError('Binding at line "{}" cannot have empty name'.format(line))
		if any(map(lambda c: c.isspace(), pre)) or parser.LAMBDA_SYMBOL in pre or '\\' in pre:
			raise SyntaxError('Binding "{}" has invalid symbols in its name'.format(pre))
	else:
		post = line.strip()
		pre = None
	return (pre, post)
	
def join_lines(lines: iter) -> iter:
	prev = ''
	for o in lines:
		if  o.startswith('\t') or o.startswith('    '):
			prev += o
		else:
			prev = prev.strip()
			if prev: yield prev
			prev = o
	prev = prev.strip()
	if prev: yield prev

def filter_lines(lines: iter) -> iter:
	for o in lines:
		if len(o) < 1 or o.isspace():
			continue
		if '#' in o:
			(pre, _, post) = o.partition('#')
			if len(post) < 1:
				yield o
			else:
				yield pre
		else:
			yield o

def parse_text(text: str) -> list:
	lines = text.split('\n')
	lines = list(filter_lines(lines))
	lines = list(join_lines(lines))
	tuples = map(lambda o: split_binding_and_def(o), lines)
	toks = map(lambda p: (p[0], parse_tokens(p[1])), tuples)

	binds = []
	for (name, br) in toks:
		b = Bind ( name=name, target=None )
		binds.append( b )
		s = parse_structure( b=br, scope=[], binds=binds, parent=b )
		b.target = s

	return binds

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)

	parser.add_argument('--source', required=True, help='Path to the source file of lambda script')
	parser.add_argument('--dest', required=True, help='Path to the output file')

	group = parser.add_mutually_exclusive_group()
	group.add_argument('--show-debug', dest='show_debug', action='store_true', help='Include debug information')
	group.add_argument('--no-show-debug', dest='show_debug', action='store_false', help='Do not include debug information')
	group.set_defaults(show_debug=False)

	return parser.parse_args()

def processone(args):
	text = ''
	source = args.source

	with open(source, 'r') as r:
		text = r.read()

	binds = parse_text(text)
	for o in binds:
		print('{}=\n{}\n\n'.format(o.name, o.target.print(0)))

	import writer
	writer.show_debug = args.show_debug
	dest = args.dest
	writer.write_some(dest, binds)

def main():
	print('macro parser loaded :)')

	args = get_arguments()
	processone(args)
	
if __name__ == '__main__':
	main()

