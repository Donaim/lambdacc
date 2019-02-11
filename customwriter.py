#!/usr/bin/env python3

import inspect
import importlib.util
import os, sys
from collections import OrderedDict

import writer
from writer import line, lfold, tufold, block_norm

def instance(x):
	''' Flag for classes that want to have their instance predefined '''
	x._instance = True
	return x

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser()

	parser.add_argument('src', help='Source file of lambdas definitions')
	parser.add_argument('declarations', help='Destination file for generated declarations')
	parser.add_argument('definitions', help='Destination file for generated definitions')

	return parser.parse_args()

def get_module_name(path: str):
	bname = os.path.basename(path)
	split = os.path.splitext(bname)
	return split[0]

def load_dynamic(path: str):
	module_name = get_module_name(path)
	spec = importlib.util.spec_from_file_location(module_name, path)

	re = importlib.util.module_from_spec(spec)
	spec.loader.exec_module(re)

	return re

def get_classes(mod) -> list:
	ret = []
	mems = inspect.getmembers(mod)
	for name, obj in mems:
		if (inspect.isclass(obj)):
			ret.append(obj)
	return ret

class lambda_obj:
	def __init__(self, target_class):
		self.target_class = target_class
		self.name = target_class.__name__

		v    = dict ( vars (target_class) )
		filt = filter( lambda k: type( v[k] ) is tuple and not k.startswith('_'), v)
		di   = dict ( map( lambda k: (k, v[k]), filt) )
		self.mems = di

		self.exec_func = lambda_obj.func(target_class.exec)
		self.cache_func = lambda_obj.func(target_class.cache) if 'cache' in vars(target_class) else None

		self.pure = not self.cache_func is None
		self.insance = '_instance' in vars(target_class)

	class func:
		def __init__(self, f):
			self.f = f
			self.sign = inspect.signature(f)
			self.name = f.__name__
			self.args = OrderedDict(self.sign.parameters)
			self.args_pre = list(self.args)[:-1]

			self.code = f.__doc__
			if not self.code:
				return

			codepre = ''
			for arg in self.args:
				if self.args[arg].annotation is inspect._empty:
					codepre += 'ff {name} = ${name};\n'.format(name = arg)
				else:
					arg_t = self.args[arg].annotation.__name__
					codepre += '''
					struct Bind_{t} * {name} = (struct Bind_{t} *) (${name}->eval(&Instance_Bind_error));

					#ifdef USE_TYPEID
					if ({name}->typeuuid != Typeid_Bind_{t}) {{
						puts("Type error");
						return &Instance_Bind_error;
					}}
					#endif

					'''.format(t = arg_t, name = arg)

			if not self.sign.return_annotation is inspect._empty:
				arg_t = self.sign.return_annotation.__name__
				codepre += '''
				struct Bind_{t} * ret = ALLOC(Bind_{t});
				if (Init_Bind_{t}(ret)) {{
					puts("Initialization failed");
					return &Instance_Bind_error;
				}}
				'''.format(t = arg_t)

			self.code = codepre + self.code

			curr_str = 'me'
			for a in reversed(self.args):
				self.code = self.code.replace('$' + a, curr_str + '->x')
				curr_str += '->parent'

			self.code = self.code.split('\n')
			self.code = map(lambda s: '\t' + s.strip(), self.code)
			self.code = '\n'.join(self.code)

def loadcfg(path: str) -> list:
	mod = load_dynamic(path)
	cl = get_classes(mod)
	objs = list(map(lambda_obj, cl))

	return objs

def carry_bind_name(original_bind_name: str, argument_index: int) -> str:
	return 'BindPriv_{}_{}'.format(original_bind_name, argument_index)

def get_struct_decl(o: lambda_obj) -> str:
	return 'struct Bind_{}'.format(o.name)
def get_carry_struct_decl(original_bind_name: str, argument_index: int) -> str:
	return 'struct ' + carry_bind_name(original_bind_name, argument_index)

def get_carry_definition(original_bind_name: str, argument_index: int) -> str:
	return 'der(BindPriv_{}_{}) {{ }};'.format(original_bind_name, argument_index)

def get_definition(o: lambda_obj) -> str:
	re = ''
	if len(o.exec_func.args) > 1:
		for i, a in enumerate(o.exec_func.args_pre):
			re += get_carry_definition(o.name, i) + '\n'

	re += 'der(Bind_{}) {{\n'.format(o.name)
	for m in o.mems:
		re += '	{} {};\n'.format(o.mems[m][0], m)

	if o.insance:
		re += '	Bind_{name}() {{ Init_Bind_{name}(this); }} \n'.format(name=o.name)
		re += '}} Instance_Bind_{};'.format(o.name)
	else:
		re += '};'

	return re

def get_typeid_str(o: lambda_obj) -> str:
	return 'const int Typeid_Bind_{} = __COUNTER__ ;'.format(o.name)
def get_carry_typeid_str(original_bind_name: str, argument_index: int):
	return 'const int Typeid_{} = __COUNTER__;'.format(carry_bind_name(original_bind_name, argument_index))

def get_init_decl(o: lambda_obj) -> str:
	return 'int Init_Bind_{name} (struct Bind_{name} *me)'.format(name=o.name)
def get_carry_init_decl(original_bind_name: str, argument_index: int) -> str:
	return 'int Init_{name} (struct {name} *me)'.format(name=carry_bind_name(original_bind_name, argument_index))

def get_init_func(o: lambda_obj) -> str:
	def get_common_init(fullname: str, mems: dict, decl: str) -> str:
		re = [
			(0, decl + ' {'),
			(1, 'me->eval_now = Exec_{};'.format(fullname))
		]

		re += list(map(
			lambda m: (1, 'me->{} = {};'.format(m, mems[m][1])),
			mems))

		re += [
			(0, '#ifdef USE_TYPEID'),
			(1, 'me->typeuuid = Typeid_{};'.format(fullname)),
			(0, '#endif'),
			(0, '#ifdef DO_CACHING'),
			(1, 'me->cache = Cache_{};'.format(fullname)),
			(1, 'me->cache_key = vector<int>{};'),
			(1, 'me->mysize = sizeof(*me);'),
			(0, '#endif'),
			(1, 'return 0;'),
			(0, '}')
		]

		return tufold(re)

	re = get_common_init('Bind_' + o.name, o.mems, get_init_decl(o))

	if len(o.exec_func.args) > 1:
		for (i, arg) in enumerate(o.exec_func.args_pre):
			re += get_common_init(carry_bind_name(o.name, i), {}, get_carry_init_decl(o.name, i))

	return re

def get_cache_decl(o: lambda_obj) -> str:
	return 'bool Cache_Bind_{} (ff me_abs, mapkey_t * ret, recursion_set * set)'.format(o.name)
def get_carry_cache_decl(original_bind_name: str, argument_index: int) -> str:
	return 'bool Cache_{} (ff me_abs, mapkey_t * ret, recursion_set * set)'.format(carry_bind_name(original_bind_name, argument_index))
def get_cache_func(o: lambda_obj) -> str:
	if o.pure:
		def common(fullname: str, decl: str, rest: list, custom_code: str) -> list:
			# use custom code from cache function doc
			
			# call cache function to get the rest
			custom_mems = []
			for r in rest:
				custom_mems.append('ret->push_back({});'.format(r))
			custom_mems = lfold(custom_mems)
			custom_mems = tufold(block_norm(custom_mems, 1))

			custom_block = ''
			if custom_code:
				custom_block = block_norm(custom_code, 1)

			return tufold(block_norm('''
				{declaration} {{
					struct {name} * me = (struct {name} *)me_abs;

					if (set->count(me_abs) > 0) {{
						ret->push_back(-2);
						return false;
					}} else {{
						set->insert(me_abs);
					}}

					ret->push_back(-9);
					ret->push_back(Typeid_{name});

					if (me->x) {{
						ret->push_back(me->x->cache(me->x, ret, set));
					}} else {{
						ret->push_back(-1);
					}}

				{custom_block}
				{custom_mems}

					return false;
				}}
				''', 0)).format(
						declaration=decl,
						custom_block=custom_block,
						custom_mems=custom_mems,
						name=fullname)

		re = ''
		if len(o.exec_func.args) > 1:
			for (i, arg) in enumerate(o.exec_func.args_pre):
				re += common(carry_bind_name(o.name, i), get_carry_cache_decl(o.name, i), rest=[], custom_code=[])
		re += common('Bind_' + o.name, get_cache_decl(o), rest=o.cache_func.f(), custom_code=o.cache_func.code)
		return re
	else:
		return tufold(block_norm('''
			{declaration} {{
				return true;
			}}
			'''.format(declaration=get_cache_decl(o)), 0))

def get_exec_decl(o: lambda_obj) -> str:
	return 'ff Exec_Bind_{} (ff me_abs, ff __x)'.format(o.name)
def get_carry_exec_decl(original_bind_name: str, argument_index: int) -> str:
	return 'ff Exec_{} (ff me_abs, ff __x)'.format(carry_bind_name(original_bind_name, argument_index))
def get_exec_func(o: lambda_obj) -> str:
	if len(o.exec_func.args) <= 1:
		return tufold(block_norm('''
			{declaration} {{
				struct Bind_{name} * me = (struct Bind_{name} *)me_abs;
			{code}
			}}
			''', 0)).format(
						declaration=get_exec_decl(o),
						code=o.exec_func.code,
						name=o.name)
	else:
		print("not supported")
		return ''

def write(objs, args):

	with open(args.declarations, 'w') as declarations_f:
		fs = [(get_struct_decl, get_carry_struct_decl),
		      (get_init_decl, get_carry_init_decl),
		      (get_exec_decl, get_carry_exec_decl)
			  ]

		for o in objs:
			if len(o.exec_func.args) > 1:
				for (i, arg) in enumerate(o.exec_func.args_pre):
					declarations_f.write(get_carry_typeid_str(o.name, i))
					declarations_f.write('\n')
			declarations_f.write(get_typeid_str(o))
			declarations_f.write('\n')
		declarations_f.write('\n')

		for f in fs:
			(main, pre) = f
			for o in objs:
				if len(o.exec_func.args) > 1:
					for (i, arg) in enumerate(o.exec_func.args_pre):
						declarations_f.write(pre(o.name, i))
						declarations_f.write(';\n')
				declarations_f.write(main(o))
				declarations_f.write(';\n')
			declarations_f.write('\n')

		declarations_f.write('#ifdef DO_CACHING\n')
		for o in objs:
			if len(o.exec_func.args) > 1:
				for (i, arg) in enumerate(o.exec_func.args_pre):
					declarations_f.write(get_carry_cache_decl(o.name, i))
					declarations_f.write(';\n')
			declarations_f.write(get_cache_decl(o))
			declarations_f.write(';\n')
		declarations_f.write('#endif\n')

	with open(args.definitions, 'w') as definitions_f:
		fs = [get_definition,
		      get_init_func,
		      get_exec_func]

		for f in fs:
			for o in objs:
				definitions_f.write(f(o))
				definitions_f.write('\n\n')

		definitions_f.write('#ifdef DO_CACHING\n')
		for o in objs:
			definitions_f.write(get_cache_func(o))
			definitions_f.write('\n\n')
		definitions_f.write('#endif\n')

def main():
	args = get_arguments()
	objs = loadcfg(args.src)
	write(objs, args)
	print('done')

if __name__ == '__main__':
	main()

