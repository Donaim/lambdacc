
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

ff Exec_Bind_print_true (ff me_abs, ff x) {
	puts("TRUE");
	return NULL;
}

ff Exec_Bind_print_false (ff me_abs, ff x) {
	puts("FALSE");
	return NULL;
}

int Init_Bind_print_true (ff me) {
	// puts ("TRUE INITED");
	me->eval_now = Exec_Bind_print_true;
}
int Init_Bind_print_false (ff me) {
	// puts ("FALS INITED");
	me->eval_now = Exec_Bind_print_false;
}

// struct Bind_num : fun {
// 	Bind_num() {}
// 	ovv {
		
// 	}
// };

