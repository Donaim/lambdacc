
# This is a config file for custom lambda expressions that may produce effects

from customwriter import instance

@instance
class error:
	def exec(x):
		'''
		if (x == fin) {
			puts("ERROR");
		}
		fprintf(stderr, "%s", "Error evaluated!");
		return me;
		'''

class print_true:
	def exec(x):
		'''
		puts("true");
		return &Instance_Bind_error;
		'''
class print_false:
	def exec(x):
		'''
		puts("false");
		return &Instance_Bind_error;
		'''

class ec:

	counter = ('int', '0')

	def exec(arg):
		'''

		if (arg == fin) {
			printf("Counter(%d)\\n", me->counter);
		}

		me->counter++;
		return me;
		'''

	def cache():
		return ['me->counter']


class booly:

	value = ('bool', 'false')

	def exec(x):
		'''
		return me;
		'''

	def cache():
		return ['me->value']

class bnot:

	def exec(x: booly) -> booly:
		'''
		ret->value = ! x->value;
		return ret;
		'''
	def cache():
		return []

class pbooly:
	def exec(x: booly):
		'''
		if (x->value) {
			puts("true");
		} else {
			puts("false");
		}
		return x;
		'''

class mif:
	def exec(x: booly, a, b):
		'''
		if (x->value) {
			return a;
		} else {
			return b;
		}
		'''
	def cache():
		return []

class mint:
	''' Machine integer '''

	value = ('int', '0')

	def exec(x):
		'''
		return me;
		'''

	def cache():
		return ['me->value']

class pmint:
	''' Print machine integer '''
	def exec(x: mint):
		'''
		printf("%d\\n", x->value);
		return x;
		'''

class msuc:
	''' Increment machine integer '''
	def exec(x: mint) -> mint:
		'''
		ret->value = x->value + 1;
		return ret;
		'''
	def cache():
		return []

class mdec:
	''' Decrement machine integer '''
	def exec(x: mint) -> mint:
		'''
		ret->value = x->value - 1;
		return ret;
		'''
	def cache():
		return []

class mis0:
	''' Tells if machine integer is 0 '''
	def exec(x: mint) -> booly:
		'''
		if (x->value == 0) {
			ret->value = true;
		} else {
			ret->value = false;
		}
		return ret;
		'''
	def cache():
		return []

class meq:
	''' Tells if two machine integers are equal '''
	def exec(a: mint, b: mint) -> booly:
		'''
		if (a->value == b->value) {
			ret->value = true;
		} else {
			ret->value = false;
		}
		return ret;
		'''
	def cache():
		return []

class facc:
	'''
	fast factorial
	'''

	def exec(arg: mint) -> mint:
		'''
		ret->value = 1;

		for (int i = 2; i <= arg->value; i++) {
			ret->value *= i;
		}

		return ret;
		'''

	def cache():
		return []

class add:
	def exec(a: mint, b: mint) -> mint:
		'''
		ret->value = a->value + b->value;
		return ret;
		'''

	def cache():
		return []

class mult:
	def exec(a: mint, b: mint) -> mint:
		'''
		ret->value = a->value * b->value;
		return ret;
		'''

	def cache():
		return []

class pow:
	''' Positive power '''
	def exec(a: mint, b: mint) -> mint:
		'''
		ret->value = 1;

		for (int i = 0; i < b->value; i++) {
			ret->value *= a->value;
		}
		return ret;
		'''

	def cache():
		return []

class mlist:
	''' Empty list '''

	listt = ('list *', 'new list')

	def exec(x):
		'''
		return me;
		'''

	def cache():
		'''
		ret->push_back(-12);
		for (list * cur = me->listt; cur != nullptr; cur = cur->next) {
			if (cur->empty()) { break; }
			if (cur->value->cache(cur->value, ret, set)) {
				// return true;
				// ... don't care
			}
		}
		ret->push_back(-13);
		'''
		return []

class cons:
	''' Append to head of the list '''

	def exec(val, l: mlist) -> mlist:
		'''
		ret->listt->init_cons(val, l->listt);
		return ret;
		'''

	def cache():
		return []

class head:
	''' Get head of the list '''

	def exec(l: mlist):
		'''
		if (l->listt->value == nullptr) {
			return &Instance_Bind_error;
		} else {
			return l->listt->value;
		}
		'''

	def cache():
		return []

class tail:
	''' Get the rest of the list '''

	def exec(l: mlist) -> mlist:
		'''
		if (l->listt->value == nullptr) {
			return &Instance_Bind_error;
		} else {
			ret->listt = l->listt->next;
			return ret;
		}
		'''

	def cache():
		return []
