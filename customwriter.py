

import inspect
import importlib.util
import os, sys
from collections import OrderedDict

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser()

	parser.add_argument('src', help='Source file of lambdas definitions')
	parser.add_argument('declarations', help='Destination file for generated declarations')
	parser.add_argument('definitions', help='Destination file for generated definitions')
	parser.add_argument('typeids', help='Destination file for generated type ids')

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

	class func:
		def __init__(self, f):
			self.f = f
			self.sign = inspect.signature(f)
			self.name = f.__name__
			self.args = OrderedDict(self.sign.parameters)

			self.code = f.__doc__

			curr_str = 'me'
			for a in reversed(self.args):
				self.code = self.code.replace('{' + a + '}', curr_str + '->x')
				curr_str += '->parent'

def loadcfg(path: str) -> list:
	mod = load_dynamic(path)
	cl = get_classes(mod)
	objs = list(map(lambda_obj, cl))

	return objs

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

def get_init_func(o: lambda_obj) -> str:
	re = ''
	if len(o.exec_func.args) <= 1:
		re += 'int Init_Bind_{} (ff me_abs) {{\n'.format(o.name)
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

def write(objs, args):
	for o in objs:
		defi = get_definition(o)
		print("defi:\n{}".format(defi))
		
		init = get_init_func(o)
		print('init:\n{}'.format(init))

		typeid = get_typeid_str(o)
		print('typeid = {}'.format(typeid))

def devel():
	args = get_arguments()
	objs = loadcfg(args.src)
	write(objs, args)

def main():
	print ('start')

if __name__ == '__main__':
	# main()
	devel()

