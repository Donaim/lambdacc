

import inspect
import importlib.util
import os, sys
from collections import OrderedDict

# Purity tag
def pure(x):
	x._pure = True
	print ("Got {}".format(x))
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

	class func:
		def __init__(self, f):
			self.f = f
			self.sign = inspect.signature(f)
			self.name = f.__name__
			self.args = OrderedDict(self.sign.parameters)

			self.code = f.__doc__
			if not self.code:
				return

			curr_str = 'me'
			for a in reversed(self.args):
				self.code = self.code.replace('{' + a + '}', curr_str + '->x')
				curr_str += '->parent'

			self.code = self.code.split('\n')
			self.code = map(lambda s: '\t' + s.strip(), self.code)
			self.code = '\n'.join(self.code)

def loadcfg(path: str) -> list:
	mod = load_dynamic(path)
	cl = get_classes(mod)
	objs = list(map(lambda_obj, cl))

	return objs

def get_struct_decl(o: lambda_obj) -> str:
	return 'struct Bind_{}'.format(o.name)

def get_definition(o: lambda_obj) -> str:
	re = ''
	if len(o.exec_func.args) <= 1:
		re += 'der(Bind_{}) {{\n'.format(o.name)
		for m in o.mems:
			re += '	{} {};\n'.format(o.mems[m][0], m)
		re += '};\n'
	else:
		pass
		# raise Exception('not supported yet')
	return re

def get_typeid_str(o: lambda_obj) -> str:
	return '#define Typeid_Bind_{} __COUNTER__\n'.format(o.name)

def get_init_decl(o: lambda_obj) -> str:
	return 'int Init_Bind_{} (ff me_abs)'.format(o.name)
def get_init_func(o: lambda_obj) -> str:
	re = ''
	if len(o.exec_func.args) <= 1:
		re += get_init_decl(o) + '{\n'
		re += '	struct Bind_{} * me = (struct Bind_{} *)me_abs; \n'.format(o.name, o.name)
		re += '	me->eval_now = Exec_Bind_{}; \n'.format(o.name)

		for m in o.mems:
			re += '	me->{} = {};\n'.format(m, o.mems[m][1])

		re += '#ifdef USE_TYPEID\n'
		re += '	me->typeuuid = Typeid_Bind_{}; \n'.format(o.name)
		re += '#endif\n'

		re += '};\n'
	else:
		pass
		# raise Exception('not supported yet')
	return re

def get_cache_decl(o: lambda_obj) -> str:
	return 'bool Cache_Bind_{} (ff me_abs, mapkey_t * ret, recursion_set * set)'.format(o.name)
def get_cache_func(o: lambda_obj) -> str:
	re = ''
	re += get_cache_decl(o) + ' {\n'
	re += '	struct Bind_{} * me = (struct Bind_{} *)me_abs; \n'.format(o.name, o.name)

	if o.pure:
		re += '''
	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		ret->push_back(me->typeuuid);
		return false;
	} else {
		ret->push_back(me->typeuuid);
		set->insert(me_abs);
	}
	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}\n\n'''

		# use custom code from cache function doc
		if o.cache_func.code:
			re += o.cache_func.code

		# call cache function to get the rest
		rest = o.cache_func.f()

		for r in rest:
			re += '	ret->push_back({});\n'.format(r)

		re += '\n'
		re += '	return false;'
		re += '\n}'

		if len(o.exec_func.args) > 1:
			print("not supported")
	else:
		re += '''
	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_ret--);
	return true;
}\n'''

	return re

def get_exec_decl(o: lambda_obj) -> str:
	return 'ff Exec_Bind_{} (ff me_abs, ff x)'.format(o.name)
def get_exec_func(o: lambda_obj) -> str:
	re = ''
	if len(o.exec_func.args) <= 1:
		re += get_exec_decl(o) + ' {\n'
		re += '	struct Bind_{} * me = (struct Bind_{} *)me_abs; \n'.format(o.name, o.name)
		re += o.exec_func.code
		re += '\n}'
	else:
		print("not supported")

	return re

def write(objs, args):

	with open(args.declarations) as declarations_f:
		for o in objs:
			typeid = get_typeid_str(o)
			declarations_f.write(typeid)

		for o in objs:
			decl = get_struct_decl(o)
			declarations_f.write(decl)

		for o in objs:
			cache_decl = get_cache_decl(o)
			declarations_f.write(cache_decl)

		for o in objs:
			init_decl = get_init_decl(o)
			declarations_f.write(init_decl)

		for o in objs:
			exec_decl = get_exec_decl(o)
			declarations_f.write(exec_decl)

	with open(args.definitions) as definitions_f:
		for o in objs:
			defi = get_definition(o)
			definitions_f.write(defi)

		for o in objs:
			code = get_cache_func(o)
			definitions_f.write(code)

		for o in objs:
			code = get_init_func(o)
			definitions_f.write(code)

		for o in objs:
			code = get_exec_func(o)
			definitions_f.write(code)

def devel():
	args = get_arguments()
	objs = loadcfg(args.src)
	write(objs, args)

def main():
	print ('start')

if __name__ == '__main__':
	# main()
	devel()

