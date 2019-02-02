
#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

class fun {
protected:
	fun(ff p) : parent{p} {}
public:
	const fun * const  parent;
	ff x;
	ff eval(ff x) {
		this->x = x;
		return eval_now(x);
	}
	virtual ff eval_now(ff x) = 0;
};

#include <cstdio>

der(debug_id) {
	debug_id() : fun(nullptr) {}
	ovv {
		return x;
	}
};
static debug_id debug_id_instance{};
static debug_id * debug_id_instance_ptr = &debug_id_instance;

der(error_not_lambda) {
	error_not_lambda() : fun(nullptr) {}
	ovv {
		throw puts("error: this lambda is not supposed to be evaluated");
	}
};
static error_not_lambda error_not_lambda_instance{};
static error_not_lambda * error_not_lambda_ptr = &error_not_lambda_instance;

struct Bind_print_true : fun {
	Bind_print_true() : fun(nullptr) {}
	ovv {
		puts("TRUE");
		return &error_not_lambda_instance;
	}
};
struct Bind_print_false : fun {
	Bind_print_false() : fun(nullptr) {}
	ovv {
		puts("FALSE");
		return &error_not_lambda_instance;
	}
};

struct Bind_num : fun {
	Bind_num() : fun(nullptr) {}
	ovv {
		
	}
};

