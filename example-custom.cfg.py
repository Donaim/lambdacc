
# This is a config file for custom lambda expressions that may produce effects

def pure(x):
	print ("Got {}".format(x))
	return x

@pure
class ec:

	counter = 'int'

	def exec(arg : str = 'lol'):
		'''
		me->counter++;
		return me;
		'''

class print_true:
	def exec(x):
		'''
		puts("true");
		return me;
		'''
class print_false:
	def exec(x):
		'''
		puts("false");
		return me;
		'''

# @pure
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


print ('hello')
print (ec.exec('hi there'))
