#!/usr/bin/env python3

import parser
from parser import *

class ClassifiedLine:
	def __init__(self, good: str, all: str):
		self.good = good
		self.all = all

class SplittedLine:
	def __init__(self, pre: str, post: str, all: str):
		self.pre = pre
		self.post = post
		self.all = all
	def get_name_and_token(self) -> (str, Branch):
		branch = parse_tokens(self.post) if self.post else None
		return TokenizedLine (bind_name=self.pre, branch=branch, all=self.all)

class TokenizedLine:
	def __init__(self, bind_name: str, branch: Branch, all: str):
		self.bind_name = bind_name
		self.branch = branch
		self.all = all

def split_binding_and_def(cline: ClassifiedLine) -> SplittedLine:
	line = cline.good
	if not line:
		return SplittedLine (pre=None, post=None, all=cline.all)
	else:
		print ("Good: {}".format(line))

	(pre, _, p) = line.partition(' ')
	(p2, mid, post) = p.strip().partition('=')

	post = post.strip()
	if len(p2) <= 0:
		if not post:
			raise SyntaxError('Binding at line "{}" cannot have empty definition'.format(line))

		pre = pre.strip()
		if not pre:
			raise SyntaxError('Binding at line "{}" cannot have empty name'.format(line))
		if parser.LAMBDA_SYMBOL in pre or '\\' in pre:
			raise SyntaxError('Binding "{}" has invalid symbols in its name'.format(pre))
	else:
		post = line.strip()
		pre = None
	return SplittedLine (pre=pre, post=post, all=cline.all)
	
def join_lines(lines: iter) -> iter:
	prev = ''
	for o in lines:
		if  o.startswith('\t') or o.startswith('    '):
			prev += ' ' + o.strip()
			yield ''
		else:
			prev = prev.strip()
			if prev: yield prev
			prev = o
	prev = prev.strip()
	if prev: yield prev

def filter_lines(lines: iter) -> iter:
	for o in lines:
		if len(o) < 1 or o.isspace() or o[0] == ';':
			yield ClassifiedLine (None, o)
		elif '#' in o:
			(pre, _, _) = o.partition('#')
			pre = pre.strip()
			if len(pre) < 1:
				yield ClassifiedLine (None, o)
			else:
				yield ClassifiedLine (pre, o)
		else:
			yield ClassifiedLine (o, o)

def parse_text(text: str) -> list:
	linesR = text.split('\n')
	linesR = list(join_lines(linesR))
	lines = list(filter_lines(linesR))
	tuples = map(split_binding_and_def, lines)
	toks = map(SplittedLine.get_name_and_token, tuples)

	binds = []
	for t in toks:
		if not t.branch:
			continue
		br = t.branch

		b = Bind ( name=t.bind_name, target=None )
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
	group.add_argument('--no-show-debug', dest='show_debug', action='store_false', help=None)
	group.set_defaults(show_debug=False)

	group = parser.add_mutually_exclusive_group()
	group.add_argument('--use-typeid', dest='use_typeid', action='store_true', help='Use unique_id to determine lambda type')
	group.add_argument('--no-use-typeid', dest='use_typeid', action='store_false', help=None)
	group.set_defaults(use_typeid=True)

	group = parser.add_mutually_exclusive_group()
	group.add_argument('--make-inline', dest='make_inline', action='store_true', help='Inline all bindings except for recursive ones')
	group.add_argument('--no-make-inline', dest='make_inline', action='store_false', help=None)
	group.set_defaults(show_debug=False)

	def includehelp(name): return 'File to be included after generated file "{}" section'.format(name)
	parser.add_argument('--headerfile', help=includehelp('header'))
	parser.add_argument('--declare-file', help=includehelp('declare'))
	parser.add_argument('--define-file', help=includehelp('define'))
	parser.add_argument('--footerfile', help=includehelp('footer'))

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
	config = writer.OutConfig(
		filename=args.dest,
		show_debug=args.show_debug,
		use_typeid=args.use_typeid,
		headerfile=args.headerfile,
		declare_file=args.declare_file,
		define_file=args.define_file,
		footerfile=args.footerfile)
	writer.write_some(config=config, binds=binds)

def main():
	print('macro parser loaded :)')

	args = get_arguments()
	processone(args)
	
if __name__ == '__main__':
	main()


