import string

import parser
from parser import *

MAPKEY_T = 'mapkey_t'
CACHING_MAP_NAME = 'g_caching_map'
TYPEID_TYPE = 'int'
COUNT_TOTAL_EXEC_NAME = 'total_eval_count'
COUNT_CACHE_NAME      = 'g_cache_hits_count'

def line(code: str, indent: int = 1) -> str:
	return ('\t' * indent) + code
def lfold(lines: list) -> str:
	return '\n'.join(lines) + '\n'
def tufold(tuples: list) -> str:
	return lfold(map( lambda p: line(code=p[1], indent=p[0]), tuples))
def block_norm(block: str, indent: int = 1) -> list:
	lines = block.split('\n')
	lines = list(filter(lambda line: not (len(line) > 0 and str.isspace(line)), lines))

	def get_indent(line: str) -> int:
		if len(line) == 0 or line.isspace():
			return 999
		count = 0
		for c in line:
			if c == '\t': count += 1
			else: break
		return count

	ignore = min( map(get_indent, lines) )

	lines = [line[ignore:] for line in lines]
	lines = [(indent, line) for line in lines]

	return lines

class OutConfig:
	def __init__(self,
			filename: str,
			show_debug: bool,
			use_typeid: bool,
			headerfile: str,
			declare_file: str,
			define_file: str,
			footerfile: str,
			do_caching: bool,
			count_total_exec: bool,
			echo_expr: bool):
		self.filename = filename
		self.show_debug = show_debug
		self.use_typeid = use_typeid
		self.headerfile = headerfile
		self.declare_file = declare_file
		self.define_file = define_file
		self.footerfile = footerfile
		self.do_caching = do_caching
		self.count_total_exec = count_total_exec
		self.echo_expr = echo_expr

class SplittedOut:
	def __init__(self, config: OutConfig):
		self.config = config

		self.header = ''
		self.typeuuids = ''
		self.struct_declarations = ''
		self.caching_declarations = ''
		self.init_declarations = ''
		self.exec_declarations = ''
		self.struct_definitions = ''
		self.caching_definitions = ''
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
		include(self.config.declare_file)
		writearr([self.typeuuids, self.struct_declarations, self.caching_declarations, self.init_declarations, self.exec_declarations])
		include(self.config.define_file)
		writearr([self.struct_definitions, self.caching_definitions, self.init_definitions, self.exec_definitions])
		include(self.config.footerfile)
		writeone(self.footer)

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
	if bind.name is None:
		return 'Expr_' + str(bind.unique_id)
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
		elif le.t == 'cache':
			return 'Cache_' + str(le.name)
		elif le.t == 'typeid':
			return 'Typeid_' + str(le.name)
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
		return exec_line + ';'
	elif lt is Leaf or lt is Argument or lt is Bind:
		return exec_line + '->eval(x)' + ';'
	else:
		raise Exception('get_ovv expects {} or {} but got {}'.format(Bind, Lambda, lt))
def init_children(le: Leaf, parent_lambda_name: str) -> str:
	members = get_fields(le=le)
	st_members = ''
	ret = '\n'
	for field in members:
		name_m = field.name
		l = field.leaf
		mem = ''
		t = field.t
		if t is Lambda or t is Bind or t is Leaf:
			name = get_leaf_name(l)

			mem += '	me->{} = ALLOC({});\n'.format(name_m, name)
			mem += '	me->{}->parent = me;\n'.format(name_m)
			mem += '	me->{}->x = nullptr;\n'.format(name_m)

			init_name = get_leaf_name(CFunction(name, 'init'))
			mem += '	{}(me->{});\n'.format(init_name, name_m)
		elif t is Argument:
			continue
		else:
			raise Exception('Unexpected member type {}'.format(type(l)))
		ret += mem
	ret += '\n'
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

	# Return statement (depends on caching)
	return_statement = get_ovv(out=out, le=le)
	defi += '	return ' + return_statement + '\n'

	defi += '\n}\n\n'
	out.exec_definitions += defi
def get_init_func(out: SplittedOut, le: Leaf, lambda_name: str) -> None:
	init_name = get_leaf_name(CFunction(lambda_name, 'init'))
	exec_name = get_leaf_name(CFunction(lambda_name, 'exec'))
	decl = 'int {:<30} (struct {} *me)'.format(init_name, lambda_name)
	out.init_declarations += decl + ';\n'
	body  = '	if (me->eval_now == NULL) {\n'
	body += '		me->eval_now = {};\n'.format(exec_name)
	if out.config.use_typeid:
		typeid_name = get_leaf_name(CFunction(lambda_name, 'typeid'))
		out.typeuuids += 'const int {} = __COUNTER__ ; \n'.format(typeid_name)
		body += '\n		me->typeuuid = {};\n'.format(typeid_name)

	if out.config.do_caching:
		cache_funcname = get_leaf_name(CFunction(lambda_name, 'cache'))
		body += '\n		me->cache = {};\n'.format(cache_funcname)
		body += '\n		me->cache_key = vector<int>{};\n'
		body += '\n		me->mysize = sizeof(*me);\n'

	body += '	}\n'
	ret   = 'return 0;'
	out.init_definitions += '{} {{\n{}\n\t{}\n}}\n\n'.format(decl, body, ret)
def get_caching_func(out: SplittedOut, le: Leaf, lambda_name: str) -> None:
	if not out.config.do_caching:
		return

	funcname = get_leaf_name(CFunction(lambda_name, 'cache'))

	decl = 'bool {:<30} (ff me, {} * ret, recursion_set * set)'.format(funcname, MAPKEY_T)
	out.caching_declarations += decl + ';\n'

	lines = []

	lines.append('if (set->count(me) > 0) {')
	lines.append('	ret->push_back(-2);')
	lines.append('	return false;')
	lines.append('} else {')
	lines.append('	set->insert(me);')
	lines.append('}')

	encoded_me = le.encode_as_vector()
	for i in encoded_me:
		lines.append('ret->push_back({});'.format(i))

	# Get cache key of our x value if exists and if x is used
	if type(le) is Lambda:
		if any( map( lambda leaf: le.arg.count_usages(leaf) > 0, le.leafs ) ):
			lines.append('if (me->x) {')
			lines.append('	if(me->x->cache(me->x, ret, set)) { return true; }')
			lines.append('} else {')
			lines.append('	ret->push_back(-1);')
			lines.append('}')
		else:
			# print('{} does not use its arg {}: \n{}\n'.format(lambda_name, le.arg.name, le.print(0)))
			pass
	else:
		lines.append('if (me->x) {')
		lines.append('	if(me->x->cache(me->x, ret, set)) { return true; }')
		lines.append('} else {')
		lines.append('	ret->push_back(-1);')
		lines.append('}')

	# Get cache keys of parent abstractions arguments
	def app(s: str):
		lines.append('if({}->x->cache({}->x, ret, set)) {{ return true; }}'.format(current_str, current_str))

	current_str = 'me->parent'
	current_parent = le.parent
	names = {}
	if type(le) is Lambda:
		names[le.arg.name] = True

	while not current_parent is None:
		t = type(current_parent)

		if t is Lambda:
			arg = current_parent.arg
			if not arg.name in names:
				names[arg.name] = True
				usages = arg.count_usages(le)
				# print ("Arg [{}] used {} times in [{}]".format(arg, usages, lambda_name))
				if usages > 0:
					app(current_str)
			else:
				# print('Arg [{}] in {} redefied'.format(arg.name, lambda_name))
				pass

		current_str += '->parent'
		current_parent = current_parent.parent

	lines.append('return false;')

	re = decl + ' {\n\t' + str.join('\n\t', lines) + '\n}\n\n'
	out.caching_definitions += re

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
	get_caching_func(out, le=le, lambda_name=lambda_name)

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

	if out.config.show_debug:
		out.header += '#define SHOW_DEBUG\n'
	if out.config.use_typeid:
		out.header += '#define USE_TYPEID\n'
	if out.config.do_caching:
		out.header += '#define DO_CACHING\n'
	if out.config.count_total_exec:
		out.header += '#define COUNT_TOTAL_EXEC\n'

	proper_binds = []
	exec_expr = []
	for b in binds:
		if b.name is None:
			exec_expr.append(b)
		else:
			proper_binds.append(b)
		write(out=out, le=b)

	footer = ''
	footer += 'int main() {\n'
	footer += '\tALLOC_INIT();\n'
	footer += '\n'
	for e in exec_expr:
		name = get_leaf_name(e)
		init_name = get_leaf_name(CFunction(name, 'init'))
		varname = name + '_var';
		footer += '	struct {} * {} = ALLOC({});\n'.format(name, varname, name)
		footer += '	{}({});\n'.format(init_name, varname)

		if out.config.echo_expr:
			footer += '	puts("{}");\n'.format(e.target.to_text().replace('\\', '\\\\'))
			footer += '	printf("  = ");\n'

		footer += '	{}->eval(fin);\n\n'.format(varname)

		if out.config.echo_expr:
			footer += '	puts("");\n'

	if out.config.count_total_exec:
		footer += '\n	fprintf(stderr, "TOTAL EVAL COUNT = %d; \\n", {});\n'.format(COUNT_TOTAL_EXEC_NAME)
		if out.config.do_caching:
			footer += '	fprintf(stderr, "TOTAL CACHE HITS COUNT = %d; \\n", {});\n'.format(COUNT_CACHE_NAME)

	footer += ('\n\treturn 0; \n}')
	out.footer += footer

	out.dump()
