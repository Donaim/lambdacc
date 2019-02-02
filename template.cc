
#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

typedef ff (*exec_t)(ff, ff);

class fun {
protected:
	fun() {}
public:
	const fun * parent = nullptr;
	ff x;
	ff eval(ff x) {
		return eval_now(this, x);
	}
	// virtual void initme() = 0;
	// virtual ff eval_now(ff x) = 0;
	exec_t eval_now;
};

#include <cstdio>

// der(debug_id) {
// 	debug_id() {}
// 	ovv {
// 		return x;
// 	}
// };
// static debug_id debug_id_instance{};
// static debug_id * debug_id_instance_ptr = &debug_id_instance;

// der(error_not_lambda) {
// 	error_not_lambda() {}
// 	ovv {
// 		throw puts("error: this lambda is not supposed to be evaluated");
// 	}
// };
// static error_not_lambda error_not_lambda_instance{};
// static error_not_lambda * error_not_lambda_ptr = &error_not_lambda_instance;

struct Bind_print_true : fun {
	Bind_print_true() {}
};
struct Bind_print_false : fun {
	Bind_print_false() {}
};

int Init_Bind_print_true (ff me) {
	puts ("TRUE INITED");
}
int Init_Bind_print_false (ff me) {
	puts ("FALS INITED");
}

// struct Bind_num : fun {
// 	Bind_num() {}
// 	ovv {
		
// 	}
// };

