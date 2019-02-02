
import parser
from parser import *

def anyeqrec(leafs: list, bind: Bind) -> bool:
	def anyeq(leaf: Leaf):
		if leaf.unique_id == bind.unique_id:
			return True
		else:
			return anyeqrec(leafs=leaf.leafs, bind=bind)
	if len(leafs) == 0:
		return False
	return any ( map (anyeq, leafs) )

def is_binding_recursive(bind: Bind) -> bool:
	if bind.target is None:
		return False
	else:
		return anyeqrec(leafs=bind.target.leafs, bind=bind)

def get_leaf_text(le: Leaf) -> str:
	t = type(le)
	if t is Lambda:
		ret = LAMBDA_DECL + le.arg.name + ' ' + LAMBDA_SYMBOL + ' '
		leafs = list(map(get_leaf_text, le.leafs))
		ret += ' '.join(leafs)
		return '(((' + ret + ')))'
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
		return '(((' + ret + ')))'
	else:
		raise Exception("Unexpected leaf type: {}".format(t))
