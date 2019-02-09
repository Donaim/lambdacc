
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

class ec:

	counter = ('int', '0')

	def exec(arg):
		'''

		if (arg == fin) {
			printf("Counter = %d\\n", me->counter);
		}

		me->counter++;
		return me;
		'''

	def cache() -> list:
		return ['me->counter']

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

# class facc:
# 	'''
# 	fast factorial
# 	'''

# 	def exec(arg: ec) -> ec:
# 		'''
# 		ret->counter = 1;

# 		for (int i = 2; i < arg->counter; i++) {
# 			ret->counter *= i;
# 		}

# 		return ret;
# 		'''

# 	def cache():
# 		return []

# class add:
# 	def exec(a: ec, b: ec) -> ec:
# 		'''
# 		ret->counter = a->counter + b->counter;
# 		return ret;
# 		'''

# 	def cache() -> list:
# 		return []
