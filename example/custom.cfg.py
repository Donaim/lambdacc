
class print_true:
	def exec(x):
		'''
		puts("true");
		return fin;
		'''

class print_false:
	def exec(x):
		'''
		puts("false");
		return fin;
		'''

class ec:

	counter = ('int', '0')

	def exec(arg):
		'''
		if (arg == fin) {
			printf("Counter(%d)\\n", custom->counter);
		}
		custom->counter++;
		return me_abs;
		'''

	def cache():
		return ['me->counter']

class booly:

	value = ('bool', 'false')

	def exec(x):
		'''
		return me_abs;
		'''

	def cache():
		return ['me->value']

class bnot:

	def exec(x: booly) -> booly:
		'''
		rc->value = ! x->value;
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
		return x_base;
		'''

class mint:
	''' Machine integer '''

	value = ('int', '0')

	def exec(x):
		'''
		return me_abs;
		'''

	def cache():
		return ['me->value']

class pmint:
	''' Print machine integer '''
	def exec(x: mint):
		'''
		printf("%d\\n", x->value);
		return x_base;
		'''

class msuc:
	''' Increment machine integer '''
	def exec(x: mint) -> mint:
		'''
		rc->value = x->value + 1;
		return ret;
		'''
	def cache():
		return []

class mdec:
	''' Decrement machine integer '''
	def exec(x: mint) -> mint:
		'''
		rc->value = x->value - 1;
		return ret;
		'''
	def cache():
		return []

class facc:
	'''
	fast factorial
	'''

	def exec(arg: ec) -> ec:
		'''
		rc->counter = 1;
		for (int i = 2; i < arg->counter; i++) {
			rc->counter *= i;
		}
		return ret;
		'''

	def cache():
		return []


class add:
	def exec(a: mint, b: mint) -> mint:
		'''
		rc->value = a->value + b->value;
		return ret;
		'''

	def cache() -> list:
		return []
