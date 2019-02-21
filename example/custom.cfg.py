
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


class facc:
	'''
	fast factorial
	'''

	def exec(arg: ec) -> ec:
		'''

		rc->counter = 1;
		for (int i = 2; i <= arg->counter; i++) {
			rc->counter *= i;
		}
		return ret;
		'''

	def cache():
		return []

