
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

