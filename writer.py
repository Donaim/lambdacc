
import parser
from parser import *

show_debug = True

class SplittedOut:
	def __init__(self, filename: str):
		self.filename = filename

		self.template = ''
		self.struct_declarations = ''
		self.init_declarations = ''
		self.exec_declarations = ''
		self.struct_definitions = ''
		self.init_definitions = ''
		self.exec_definitions = ''
		self.footer = ''

	def dump(self):
		with open(self.filename, 'w+') as w:
			for t in [
					self.template,
					self.struct_declarations,
					self.init_declarations,
					self.exec_declarations,
					self.struct_definitions,
					self.init_definitions,
					self.exec_definitions,
					self.footer,
					]:
				w.write(t)
				w.write('\n\n')

class CFunction:
	def __init__(self, leaf_name: str, t: str):
		self.name = leaf_name
		self.t = t

def get_leaf_name(le) -> str:
	if type(le) is Leaf:
		return 'Leaf_' + str(le.unique_id)
	if type(le) is Argument:
		return 'Argument_' + str(le.unique_id)
	if type(le) is Lambda:
		return 'Lambda_' + str(le.unique_id)
	if type(le) is Bind:
		return 'Bind_' + str(le.name)
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
def get_ovv_member_name(mem: Leaf):
	name = get_leaf_name(mem)
	name = get_member_name(name)
	t = type(mem)
	if t is Bind or t is Lambda or t is Leaf:
		return '(me->{})'.format(name)
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
	for l in le.leafs:
		t = type(l)
		if t is Bind or t is Lambda:
			name = get_ovv_member_name(l)
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
			name = get_ovv_member_name(l)
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
	members = get_unique_lambda_members(le=le)
	st_members = ''
	ret = '	if (me->x == NULL) {\n'
	for l in members:
		mem = ''
		if type(l) is Lambda or type(l) is Bind or type(l) is Leaf:
			name = get_leaf_name(l)
			name_m = get_member_name(name)

			mem += '		me->{} = new {};\n'.format(name_m, name)
			mem += '		me->{}->parent = me;\n'.format(name_m)

			init_name = get_leaf_name(CFunction(name, 'init'))
			mem += '		{}(me->{});\n'.format(init_name, name_m)
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
	if show_debug:
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
def get_unique_lambda_members(le: Lambda) -> list:
	re = []
	for m in get_lambda_members(le=le):
		if not m in re:
			re.append(m)
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

	members = get_unique_lambda_members(le=le)
	st_members = ''
	for l in members:
		if type(l) is Lambda:
			name = get_leaf_name(l)
			name_m = get_member_name(name)
			
			st_members += get_structure_member(name, name_m)
		elif type(l) is Bind:
			name = get_leaf_name(l)
			name_m = get_member_name(name)

			st_members += get_structure_member(name, name_m)
		elif type(l) is Leaf:
			name = get_leaf_name(l)
			name_m = get_member_name(name)

			st_members += get_structure_member(name, name_m)
		else:
			raise Exception('Unexpected member type {}'.format(type(l)))

	out.struct_definitions += stname
	out.struct_definitions += st_members
	if show_debug:
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
def write_some(filepath: str, binds: list):
	out = SplittedOut(filepath)
	with open('template.cc') as tempr:
		out.template = tempr.read()
		if show_debug:
			out.template = '#define SHOW_DEBUG\n' + out.template

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
