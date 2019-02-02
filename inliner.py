
import parser
from parser import *

def get_leaf_text(le: Leaf, main: Bind) -> str:
	if le.unique_id == main.unique_id:
		return le.name

	t = type(le)
	if t is Lambda:
		ret = '('
		ret += LAMBDA_DECL + le.arg.name + ' ' + LAMBDA_SYMBOL
		for children in le.leafs:
			ret += ' ' + get_leaf_text(le=children, main=main)
		return ret + ')'
	if t is Argument:
		return le.name
	if t is Bind:
		if le.target is None:
			if le.predefined:
				return '$' + le.name
			else:
				raise Exception ("Cannot inline binding: {}".format(le.name))
		else:
			return le.name
			return get_leaf_text(le=le.target, main=main)
	if t is Leaf:
		leafs = list(map(lambda l: get_leaf_text(le=l, main=main), le.leafs))
		return '(' + ' '.join(leafs) + ')'
	else:
		raise Exception("Unexpected leaf type: {}".format(t))
