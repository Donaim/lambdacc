import string

import parser
from parser import *

class OutConfig:
	def __init__(self,
			filename: str,
			show_debug: bool,
			use_typeid: bool,
			headerfile: str,
			declare_file: str,
			define_file: str,
			footerfile: str):
		self.filename = filename
		self.show_debug = show_debug
		self.use_typeid = use_typeid
		self.headerfile = headerfile
		self.declare_file = declare_file
		self.define_file = define_file
		self.footerfile = footerfile

class SplittedOut:
	def __init__(self, config: OutConfig):
		self.config = config

		self.header = ''
		self.struct_declarations = ''
		self.init_declarations = ''
		self.exec_declarations = ''
		self.struct_definitions = ''
		self.init_definitions = ''
		self.exec_definitions = ''
		self.footer = ''

	def dump(self):
		w = open(self.config.filename, 'w+')

		def include(filename: str) -> None:
			if not filename is None:
				w.write('\n#include "{}"\n\n'.format(filename))
		def writeone(one: str) -> None:
			w.write(one)
			w.write('\n\n')
		def writearr(arr: list) -> None:
			for t in arr:
				writeone(t)
		
		writeone(self.header)
		include(self.config.headerfile)
		writearr([self.struct_declarations, self.init_declarations, self.exec_declarations])
		include(self.config.declare_file)
		writearr([self.struct_definitions, self.init_definitions, self.exec_definitions])
		include(self.config.define_file)
		writeone(self.footer)
		include(self.config.footerfile)

		w.close()

class CFunction:
	def __init__(self, leaf_name: str, t: str):
		self.name = leaf_name
		self.t = t

class StructField:
	def __init__(self, leaf, name):
		self.leaf = leaf
		self.name = name
		self.t = type(leaf)

allowed_chars = string.ascii_letters + string.digits + '_'
def bind_is_valid_char(c):
	return c in allowed_chars
def bind_fix_name(bind: Bind):
	ret = 'BindInval_' + str(bind.unique_id) + '_'
	for c in bind.name:
		if bind_is_valid_char(c):
			ret += c.lower()
		else:
			ret += 'X'
	return ret

def bind_get_valid_name(bind: Bind):
	if all( map (bind_is_valid_char, bind.name) ):
		return 'Bind_' + bind.name
	else:
		return bind_fix_name(bind)

def get_leaf_name(le) -> str:
	if type(le) is Leaf:
		return 'Leaf_' + str(le.unique_id)
	if type(le) is Argument:
		return 'Argument_' + str(le.unique_id)
	if type(le) is Lambda:
		return 'Lambda_' + str(le.unique_id)
	if type(le) is Bind:
		valid = bind_get_valid_name(le)
		return valid
	if type(le) is CFunction:
		if le.t == 'exec':
			return "Exec_" + str(le.name)
		elif le.t == 'init':
			return "Init_" + str(le.name)
		else:
			raise Exception("Unknown CFuntion type: {}".format(le.t))
	raise Exception('Unknown type {}'.format(type(le)))
def get_member_name(leaf_name: str) -> str:
	return 'm_' + leaf_name
def get_ovv_member_name(field: StructField):
	t = field.t
	if t is Bind or t is Lambda or t is Leaf:
		return '(me->{})'.format(field.name)
	elif t is Argument:
		return '(me->x)'
	else:
		raise Exception('expected types {} and {} '.format(Bind, Argument, Lambda))

def get_argument_by_parents(me: Lambda, arg: Argument):
	re = 'me->'
	p = me
	while type(p) is Leaf or p.arg != arg:
		if p is None: raise Exception('Argument not found (None parent)')
		p = p.parent
		re += 'parent->'
		while not type(p) is Lambda:
			if p is None: raise Exception('Argument not found (None parent)')
			p = p.parent
			re += 'parent->'
	return re + 'x'

def get_return_part(out: SplittedOut, le: Leaf, base_lambda: Lambda) -> str:
	exec_line = ''
	for field in get_fields(le=le):
		l = field.leaf
		t = field.t
		name = get_ovv_member_name(field=field)
		if t is Bind or t is Lambda:
			if exec_line:
				exec_line += '->eval({})'.format(name)
			else:
				exec_line += name
		elif t is Argument:
			name = get_argument_by_parents(base_lambda, l)
			if exec_line:
				exec_line += '->eval({})'.format(name)
			else:
				exec_line += name
		elif t is Leaf:
			write_lambda(out=out, le=l)
			if exec_line:
				exec_line += '->eval({})'.format(name)
			else:
				exec_line += name
		else:
			raise Exception('unexpected type {}'.format(t))
	return '(' + exec_line + ')'
def get_ovv(out: SplittedOut, le: Leaf) -> str:
	exec_line = get_return_part(out=out, le=le, base_lambda=le)

	lt = type(le)
	if lt is Lambda:
		return 'return ' + exec_line + ';'
	elif lt is Leaf or lt is Argument or lt is Bind:
		return 'return ' + exec_line + '->eval(x)' + ';'
	else:
		raise Exception('get_ovv expects {} or {} but got {}'.format(Bind, Lambda, lt))
def init_children(le: Leaf, parent_lambda_name: str) -> str:
	members = get_fields(le=le)
	st_members = ''
	ret = '	if (me->x == NULL) {\n'
	for field in members:
		name_m = field.name
		l = field.leaf
		mem = ''
		t = field.t
		if t is Lambda or t is Bind or t is Leaf:
			name = get_leaf_name(l)

			mem += '		me->{} = new {};\n'.format(name_m, name)
			mem += '		me->{}->parent = me;\n'.format(name_m)

			init_name = get_leaf_name(CFunction(name, 'init'))
			mem += '		{}(me->{});\n'.format(init_name, name_m)
		elif t is Argument:
			continue
		else:
			raise Exception('Unexpected member type {}'.format(type(l)))
		ret += mem
	ret += '	}\n'
	return ret
def get_exec_func(out: SplittedOut, le: Leaf, lambda_name: str) -> None:
	exec_name = get_leaf_name(CFunction(lambda_name, 'exec'))
	decl = 'ff {:<30} (ff me_abs, ff x)'.format(exec_name)
	out.exec_declarations += decl + ';\n'
	
	defi  = decl + ' {\n'
	defi += '	struct {} * me = (struct {} *)me_abs;\n'.format(lambda_name, lambda_name)
	if out.config.show_debug:
		defi += '	printf ("Lam [%s] got [%s]\\n", me->tostr(), x->tostr());\n'
	defi += init_children(le=le, parent_lambda_name=lambda_name)
	defi += '	me->x = x;\n'
	defi += '	' + get_ovv(out=out, le=le)                                                # RETURN STATEMENT
	defi += '\n}\n\n'
	out.exec_definitions += defi
def get_init_func(out: SplittedOut, le: Leaf, lambda_name: str) -> None:
	init_name = get_leaf_name(CFunction(lambda_name, 'init'))
	exec_name = get_leaf_name(CFunction(lambda_name, 'exec'))
	decl = 'int {:<30} (struct {} *me)'.format(init_name, lambda_name)
	out.init_declarations += decl + ';\n'
	body  = '	if (me->eval_now == NULL) {\n'
	body += '		me->eval_now = {};\n'.format(exec_name)
	body += '	}\n'
	ret   = 'return 0;'
	out.init_definitions += '{} {{\n{}\n\t{}\n}}\n\n'.format(decl, body, ret)

def get_lambda_members(le: Lambda) -> iter:
	for l in le.leafs:
		t = type(l)
		if t is Lambda:
			yield l
		if t is Bind:
			yield l
		if t is Leaf:
			yield l

def get_fields(le: Lambda) -> list:
	re = []
	for (i, leaf) in enumerate(le.leafs):
		t = type(leaf)
		name = leaf.name if t is Argument else 'm_' + str(i)
		re.append(StructField(leaf=leaf, name=name))
	return re

def get_structure_member(name, name_m):
	return '\t{:<30} * {};\n'.format(name, name_m)
def write_named_lambda(out: SplittedOut, le: Lambda, lambda_name: str):
	for l in le.leafs:
		if type(l) is Lambda:
			write_lambda(out=out, le=l)

	out.struct_declarations += 'struct {};\n'.format(lambda_name)

	stname = 'der({}) {{\n'.format(lambda_name)

	is_bind = type(le.parent) is Bind

	members = get_fields(le=le)
	st_members = ''
	for field in members:
		leaf = field.leaf
		name_m = field.name
		if field.t is Lambda or field.t is Bind or field.t is Leaf:
			name = get_leaf_name(leaf)
			st_members += get_structure_member(name, name_m)
		elif field.t is Argument:
			continue
		else:
			raise Exception('Unexpected member type {}'.format(type(leaf)))

	out.struct_definitions += stname
	out.struct_definitions += st_members
	if out.config.show_debug:
		out.struct_definitions += '\n	const char * tostr() override {{ return "{}"; }}\n'.format(lambda_name)
	out.struct_definitions += ('};\n\n')

	get_init_func(out, le, lambda_name)
	get_exec_func(out, le, lambda_name)

def write_lambda(out: SplittedOut, le: Leaf):
	name = get_leaf_name(le)
	return write_named_lambda(out=out, le=le, lambda_name=name)

def write(out: SplittedOut, le: Leaf):
	if type(le) is Lambda:
		return write_lambda(out=out, le=le)
	elif type(le) is Bind:
		name = get_leaf_name(le)
		return write_named_lambda(out=out, le=le.target, lambda_name=name)
	else:
		raise Exception('Dont know how to start writing from {} type'.format(type(le)))
def write_some(config: OutConfig, binds: list):
	out = SplittedOut(config)

	proper_binds = []
	exec_expr = []
	expr_count = 0
	for b in binds:
		if b.name is None:
			b.name = 'EXPR_' + str(expr_count)
			expr_count += 1
			exec_expr.append(b)
		else:
			proper_binds.append(b)
			
	for b in proper_binds:
		write(out=out, le=b)
	for e in exec_expr:
		write_named_lambda(out=out, le=e.target, lambda_name=e.name)

	footer = ''
	footer += ('int main() {\n')
	footer += ('\tputs("start");\n')
	for e in exec_expr:
		init_name = get_leaf_name(CFunction(e.name, 'init'))
		varname = e.name + '_var';
		footer += '	struct {} * {} = new {};\n'.format(e.name, varname, e.name)
		footer += '	{}({});\n'.format(init_name, varname);
		footer += '	{}->eval(bind_err);\n\n'.format(varname);
	footer += ('\tputs("end");\n')
	footer += ('\treturn 0; \n}')
	out.footer += footer

	out.dump()
	print('write some ended')

def main():
	# expr = r'\b -> b x y'
	# expr = r'\a b -> x a'
	expr = r'\a b c -> x (a b) c'
	# expr = r'\a b -> b'

	p = parse_tokens(expr)
	p = parse_structure(p, [], [Bind('x', Leaf([], None))], None)
	# t = p.print(0)
	# print(t)

	out = SplittedOut('test.cc')
	write(out, p)
	print('end writing')

if __name__ == '__main__':
	main()
