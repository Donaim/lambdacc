
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
	exec_t eval_now;

#ifdef SHOW_DEBUG
	virtual const char * tostr() = 0;
#endif
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

struct Bind_error : fun {

#ifdef SHOW_DEBUG
	const char * tostr() override { return "ERROR"; }
#endif
};
struct Bind_error * bind_err = new Bind_error;

struct Bind_print_true : fun {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_true"; }
#endif
};
struct Bind_print_false : fun {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_false"; }
#endif
};

ff Exec_Bind_error       (ff me_abs, ff x);
ff Exec_Bind_print_false (ff me_abs, ff x);
ff Exec_Bind_print_true  (ff me_abs, ff x);

int Init_Bind_error (ff me) {
	me->eval_now = Exec_Bind_error;
	return 0;
}

int Init_Bind_print_true (ff me) {
	// puts ("TRUE INITED");
	me->eval_now = Exec_Bind_print_true;
	return 0;
}
int Init_Bind_print_false (ff me) {
	// puts ("FALS INITED");
	me->eval_now = Exec_Bind_print_false;
	return 0;
}

ff Exec_Bind_print_true (ff me_abs, ff x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("TRUE");
	return me->m_Bind_error;
}
ff Exec_Bind_print_false (ff me_abs, ff x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("FALSE");
	return me->m_Bind_error;
}
ff Exec_Bind_error (ff me_abs, ff x) {
	puts("ERROR: This is not supposed to be evaluated!");
	return NULL;
}

// struct Bind_num : fun {
// 	Bind_num() {}
// 	ovv {
		
// 	}
// };

