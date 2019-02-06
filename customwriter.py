

import inspect
import importlib.util
import os, sys
from collections import OrderedDict

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser()

	parser.add_argument('src', help='Source file of lambdas definitions')
	parser.add_argument('dest', help='Destination file for generated code')

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
		filt = filter( lambda k: type( v[k] ) is str and not k.startswith('_'), v)
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

def loadcfg(path: str):
	mod = load_dynamic(path)
	cl = get_classes(mod)
	objs = list(map(lambda_obj, cl))

	return objs

def devel():
	args = get_arguments()
	cfg = loadcfg('example-custom.cfg.py')
	print(cfg)

def main():
	print ('start')

if __name__ == '__main__':
	# main()
	devel()

