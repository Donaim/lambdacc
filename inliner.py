
import parser
from parser import *

def anyeqrec(target: Leaf, bind: Bind, mem: dict) -> bool:
	if target.unique_id in mem:
		return True
	else:
		mem[target.unique_id] = True

	if target is None:
		return False
	if type(target) is Bind:
		print('visiting {}; its target is {};'.format(target.name, type(target.target)))
		if target == bind:
			return True
		return anyeqrec(target.target, bind, mem) or any ( [ anyeqrec(l, bind=bind, mem=mem) for l in target.leafs ] )
	else:
		return any ( [ anyeqrec(l, bind=bind, mem=mem) for l in target.leafs ] )

def is_binding_recursive(bind: Bind) -> bool:
	if bind.target is None:
		return False
	if bind.target == bind:
		return True
	else:
		print('has {} leafs: {}'.format(bind.name, len(bind.leafs) > 0))
		return anyeqrec(target=bind.target, bind=bind, mem = {})

def get_leaf_text(le: Leaf) -> str:
	t = type(le)
	if t is Lambda:
		ret = LAMBDA_DECL + le.arg.name + ' ' + LAMBDA_SYMBOL + ' '
		leafs = list(map(get_leaf_text, le.leafs))
		ret += ' '.join(leafs)
		return '(' + ret + ')'
	if t is Argument:
		return le.name
	if t is Bind:
		if le.target is None:
			if le.predefined:
				return '$' + le.name
			else:
				raise Exception ("Cannot inline binding: {}".format(le.name))
		elif is_binding_recursive(bind=le):
			print ("Biding is recursive: {}".format(le))
			return le.name
		else:
			# return le.name
			return get_leaf_text(le=le.target)
	if t is Leaf:
		leafs = list(map(get_leaf_text, le.leafs))
		ret = ' '.join(leafs)
		return '(' + ret + ')'
	else:
		raise Exception("Unexpected leaf type: {}".format(t))
