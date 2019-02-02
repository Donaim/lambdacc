
import parser
from parser import *

def get_leaf_text(le: Leaf, recids: list) -> str:
	if le.unique_id in recids:
		return le.name

	t = type(le)
	if t is Lambda:
		ret = LAMBDA_DECL + le.arg.name + ' ' + LAMBDA_SYMBOL
		for children in le.leafs:
			ret += ' ' + get_leaf_text(le=children, recids=recids)
		if le.parent is None or le.parent.unique_id == recids[0]:
			return ret
		else:
			return '(' + ret + ')'
	if t is Argument:
		return le.name
	if t is Bind:
		if le.target is None:
			if le.predefined:
				return '$' + le.name
			else:
				raise Exception ("Cannot inline binding: {}".format(le.name))
		else:
			# return le.name
			return get_leaf_text(le=le.target, recids=recids + [le.unique_id])
	if t is Leaf:
		leafs = list(map(lambda l: get_leaf_text(le=l, recids=recids), le.leafs))
		ret = ' '.join(leafs)
		if le.parent is None or le.parent.unique_id == recids[0]:
			return ret
		else:
			return '(' + ret + ')'
	else:
		raise Exception("Unexpected leaf type: {}".format(t))
