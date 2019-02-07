
# This is a config file for custom lambda expressions that may produce effects

from customwriter import instance

@instance
class final:
	def exec(x):
		'''
		puts("This should not be evaluated!");
		return me;
		'''

@instance
class error(final):
	pass

class ec:

	counter = ('int', '0')

	def exec(arg):
		'''

		if (arg->typeuuid == Typeid_Bind_final) {
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

class facc:
	'''
	fast factorial
	'''

	def exec(arg: ec) -> ec:
		'''
		struct Bind_ec * ret = ALLOC(Bind_ec);
		Init_Bind_ec(ret);
		ret->counter = 1;

		for (int i = 2; i < arg->counter; i++) {
			ret->counter *= i;
		}

		return ret;
		'''

# class add:

# 	def exec(a, b):
# 		'''
# 		struct Bind_ec * re = ALLOC(Bind_ec);
# 		Init_Bind_ec(re);

# 		if ({a}->typeuuid != re->typeuuid || {b}->typeuuid != re->typeuuid) {
# 			puts ("Expected numbers but got some shit!");
# 		}

# 		struct Bind_ec * a = (struct Bind_ec *){a};
# 		struct Bind_ec * b = (struct Bind_ec *){b};

# 		re->counter = a->counter + b->counter;

# 		return re;
# 		'''

# 	def cache() -> list:
# 		return []
