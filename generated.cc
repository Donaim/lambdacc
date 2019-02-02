
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
		this->x = x;
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

// struct Bind_print_true : fun {
// 	Bind_print_true() {}
// 	ovv {
// 		puts("TRUE");
// 		return &error_not_lambda_instance;
// 	}
// };
// struct Bind_print_false : fun {
// 	Bind_print_false() {}
// 	ovv {
// 		puts("FALSE");
// 		return &error_not_lambda_instance;
// 	}
// };

// struct Bind_num : fun {
// 	Bind_num() {}
// 	ovv {
		
// 	}
// };



struct Bind_id;
struct Lambda_7;
struct Bind_true;
struct Lambda_12;
struct Bind_false;
struct Bind_not;
struct Lambda_22;
struct Lambda_20;
struct Bind_if;
struct Lambda_29;
struct Lambda_27;
struct Bind_kek;
struct Lambda_36;
struct Lambda_34;
struct Bind_pair;
struct Bind_fst;
struct Bind_snd;
struct Bind_zero;
struct Bind_is0;
struct Bind_suc;
struct Bind_pred;
struct Lambda_59;
struct Bind_get0;


int Init_Bind_id                   (struct Bind_id *me);
int Init_Lambda_7                  (struct Lambda_7 *me);
int Init_Bind_true                 (struct Bind_true *me);
int Init_Lambda_12                 (struct Lambda_12 *me);
int Init_Bind_false                (struct Bind_false *me);
int Init_Bind_not                  (struct Bind_not *me);
int Init_Lambda_22                 (struct Lambda_22 *me);
int Init_Lambda_20                 (struct Lambda_20 *me);
int Init_Bind_if                   (struct Bind_if *me);
int Init_Lambda_29                 (struct Lambda_29 *me);
int Init_Lambda_27                 (struct Lambda_27 *me);
int Init_Bind_kek                  (struct Bind_kek *me);
int Init_Lambda_36                 (struct Lambda_36 *me);
int Init_Lambda_34                 (struct Lambda_34 *me);
int Init_Bind_pair                 (struct Bind_pair *me);
int Init_Bind_fst                  (struct Bind_fst *me);
int Init_Bind_snd                  (struct Bind_snd *me);
int Init_Bind_zero                 (struct Bind_zero *me);
int Init_Bind_is0                  (struct Bind_is0 *me);
int Init_Bind_suc                  (struct Bind_suc *me);
int Init_Bind_pred                 (struct Bind_pred *me);
int Init_Lambda_59                 (struct Lambda_59 *me);
int Init_Bind_get0                 (struct Bind_get0 *me);


ff Exec_Bind_id                   (ff me_abs, ff x);
ff Exec_Lambda_7                  (ff me_abs, ff x);
ff Exec_Bind_true                 (ff me_abs, ff x);
ff Exec_Lambda_12                 (ff me_abs, ff x);
ff Exec_Bind_false                (ff me_abs, ff x);
ff Exec_Bind_not                  (ff me_abs, ff x);
ff Exec_Lambda_22                 (ff me_abs, ff x);
ff Exec_Lambda_20                 (ff me_abs, ff x);
ff Exec_Bind_if                   (ff me_abs, ff x);
ff Exec_Lambda_29                 (ff me_abs, ff x);
ff Exec_Lambda_27                 (ff me_abs, ff x);
ff Exec_Bind_kek                  (ff me_abs, ff x);
ff Exec_Lambda_36                 (ff me_abs, ff x);
ff Exec_Lambda_34                 (ff me_abs, ff x);
ff Exec_Bind_pair                 (ff me_abs, ff x);
ff Exec_Bind_fst                  (ff me_abs, ff x);
ff Exec_Bind_snd                  (ff me_abs, ff x);
ff Exec_Bind_zero                 (ff me_abs, ff x);
ff Exec_Bind_is0                  (ff me_abs, ff x);
ff Exec_Bind_suc                  (ff me_abs, ff x);
ff Exec_Bind_pred                 (ff me_abs, ff x);
ff Exec_Lambda_59                 (ff me_abs, ff x);
ff Exec_Bind_get0                 (ff me_abs, ff x);


der(Bind_id) {

	Bind_id()  {}

};
der(Lambda_7) {

	Lambda_7()  {}

};
der(Bind_true) {

	Bind_true()  {}

	Lambda_7                       * m_Lambda_7;
};
der(Lambda_12) {

	Lambda_12()  {}

};
der(Bind_false) {

	Bind_false()  {}

	Lambda_12                      * m_Lambda_12;
};
der(Bind_not) {

	Bind_not()  {}

	Bind_false                     * m_Bind_false;
	Bind_true                      * m_Bind_true;
};
der(Lambda_22) {

	Lambda_22()  {}

};
der(Lambda_20) {

	Lambda_20()  {}

	Lambda_22                      * m_Lambda_22;
};
der(Bind_if) {

	Bind_if()  {}

	Lambda_20                      * m_Lambda_20;
};
der(Lambda_29) {

	Lambda_29()  {}

};
der(Lambda_27) {

	Lambda_27()  {}

	Lambda_29                      * m_Lambda_29;
};
der(Bind_kek) {

	Bind_kek()  {}

	Lambda_27                      * m_Lambda_27;
};
der(Lambda_36) {

	Lambda_36()  {}

};
der(Lambda_34) {

	Lambda_34()  {}

	Lambda_36                      * m_Lambda_36;
};
der(Bind_pair) {

	Bind_pair()  {}

	Lambda_34                      * m_Lambda_34;
};
der(Bind_fst) {

	Bind_fst()  {}

	Bind_true                      * m_Bind_true;
};
der(Bind_snd) {

	Bind_snd()  {}

	Bind_false                     * m_Bind_false;
};
der(Bind_zero) {

	Bind_zero()  {}

	Bind_pair                      * m_Bind_pair;
	Bind_true                      * m_Bind_true;
	Bind_id                        * m_Bind_id;
};
der(Bind_is0) {

	Bind_is0()  {}

	Bind_if                        * m_Bind_if;
	Bind_fst                       * m_Bind_fst;
	Bind_true                      * m_Bind_true;
	Bind_false                     * m_Bind_false;
};
der(Bind_suc) {

	Bind_suc()  {}

	Bind_pair                      * m_Bind_pair;
	Bind_false                     * m_Bind_false;
};
der(Bind_pred) {

	Bind_pred()  {}

	Bind_snd                       * m_Bind_snd;
};
der(Lambda_59) {

	Lambda_59()  {}

	Bind_if                        * m_Bind_if;
	Bind_fst                       * m_Bind_fst;
	Bind_get0                      * m_Bind_get0;
	Bind_pred                      * m_Bind_pred;
};
der(Bind_get0) {

	Bind_get0()  {}

	Lambda_59                      * m_Lambda_59;
};


int Init_Bind_id                   (struct Bind_id *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_id;
	}

	return 0;
}

int Init_Lambda_7                  (struct Lambda_7 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_7;
	}

	return 0;
}

int Init_Bind_true                 (struct Bind_true *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_true;
	}

	return 0;
}

int Init_Lambda_12                 (struct Lambda_12 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_12;
	}

	return 0;
}

int Init_Bind_false                (struct Bind_false *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_false;
	}

	return 0;
}

int Init_Bind_not                  (struct Bind_not *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_not;
	}

	return 0;
}

int Init_Lambda_22                 (struct Lambda_22 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_22;
	}

	return 0;
}

int Init_Lambda_20                 (struct Lambda_20 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_20;
	}

	return 0;
}

int Init_Bind_if                   (struct Bind_if *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_if;
	}

	return 0;
}

int Init_Lambda_29                 (struct Lambda_29 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_29;
	}

	return 0;
}

int Init_Lambda_27                 (struct Lambda_27 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_27;
	}

	return 0;
}

int Init_Bind_kek                  (struct Bind_kek *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_kek;
	}

	return 0;
}

int Init_Lambda_36                 (struct Lambda_36 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_36;
	}

	return 0;
}

int Init_Lambda_34                 (struct Lambda_34 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_34;
	}

	return 0;
}

int Init_Bind_pair                 (struct Bind_pair *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_pair;
	}

	return 0;
}

int Init_Bind_fst                  (struct Bind_fst *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_fst;
	}

	return 0;
}

int Init_Bind_snd                  (struct Bind_snd *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_snd;
	}

	return 0;
}

int Init_Bind_zero                 (struct Bind_zero *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_zero;
	}

	return 0;
}

int Init_Bind_is0                  (struct Bind_is0 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_is0;
	}

	return 0;
}

int Init_Bind_suc                  (struct Bind_suc *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_suc;
	}

	return 0;
}

int Init_Bind_pred                 (struct Bind_pred *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_pred;
	}

	return 0;
}

int Init_Lambda_59                 (struct Lambda_59 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_59;
	}

	return 0;
}

int Init_Bind_get0                 (struct Bind_get0 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_get0;
	}

	return 0;
}



ff Exec_Bind_id                   (ff me_abs, ff x) {
	struct Bind_id * me = (struct Bind_id *)me_abs;
	return (me->x);
}

ff Exec_Lambda_7                  (ff me_abs, ff x) {
	struct Lambda_7 * me = (struct Lambda_7 *)me_abs;
	return (me->parent->x);
}

ff Exec_Bind_true                 (ff me_abs, ff x) {
	struct Bind_true * me = (struct Bind_true *)me_abs;
	return ((me->m_Lambda_7));
}

ff Exec_Lambda_12                 (ff me_abs, ff x) {
	struct Lambda_12 * me = (struct Lambda_12 *)me_abs;
	return (me->x);
}

ff Exec_Bind_false                (ff me_abs, ff x) {
	struct Bind_false * me = (struct Bind_false *)me_abs;
	return ((me->m_Lambda_12));
}

ff Exec_Bind_not                  (ff me_abs, ff x) {
	struct Bind_not * me = (struct Bind_not *)me_abs;
	return (me->x->eval((me->m_Bind_false))->eval((me->m_Bind_true)));
}

ff Exec_Lambda_22                 (ff me_abs, ff x) {
	struct Lambda_22 * me = (struct Lambda_22 *)me_abs;
	return (me->parent->parent->x->eval(me->parent->x)->eval(me->x));
}

ff Exec_Lambda_20                 (ff me_abs, ff x) {
	struct Lambda_20 * me = (struct Lambda_20 *)me_abs;
	return ((me->m_Lambda_22));
}

ff Exec_Bind_if                   (ff me_abs, ff x) {
	struct Bind_if * me = (struct Bind_if *)me_abs;
	return ((me->m_Lambda_20));
}

ff Exec_Lambda_29                 (ff me_abs, ff x) {
	struct Lambda_29 * me = (struct Lambda_29 *)me_abs;
	return (me->parent->x);
}

ff Exec_Lambda_27                 (ff me_abs, ff x) {
	struct Lambda_27 * me = (struct Lambda_27 *)me_abs;
	return ((me->m_Lambda_29)->eval(me->parent->x));
}

ff Exec_Bind_kek                  (ff me_abs, ff x) {
	struct Bind_kek * me = (struct Bind_kek *)me_abs;
	return ((me->m_Lambda_27));
}

ff Exec_Lambda_36                 (ff me_abs, ff x) {
	struct Lambda_36 * me = (struct Lambda_36 *)me_abs;
	return (me->x->eval(me->parent->parent->x)->eval(me->parent->x));
}

ff Exec_Lambda_34                 (ff me_abs, ff x) {
	struct Lambda_34 * me = (struct Lambda_34 *)me_abs;
	return ((me->m_Lambda_36));
}

ff Exec_Bind_pair                 (ff me_abs, ff x) {
	struct Bind_pair * me = (struct Bind_pair *)me_abs;
	return ((me->m_Lambda_34));
}

ff Exec_Bind_fst                  (ff me_abs, ff x) {
	struct Bind_fst * me = (struct Bind_fst *)me_abs;
	return (me->x->eval((me->m_Bind_true)));
}

ff Exec_Bind_snd                  (ff me_abs, ff x) {
	struct Bind_snd * me = (struct Bind_snd *)me_abs;
	return (me->x->eval((me->m_Bind_false)));
}

ff Exec_Bind_zero                 (ff me_abs, ff x) {
	struct Bind_zero * me = (struct Bind_zero *)me_abs;
	return ((me->m_Bind_pair)->eval((me->m_Bind_true))->eval((me->m_Bind_id)))->eval(x);
}

ff Exec_Bind_is0                  (ff me_abs, ff x) {
	struct Bind_is0 * me = (struct Bind_is0 *)me_abs;
	return ((me->m_Bind_if)->eval(((me->m_Bind_fst)->eval(me->x)))->eval((me->m_Bind_true))->eval((me->m_Bind_false)));
}

ff Exec_Bind_suc                  (ff me_abs, ff x) {
	struct Bind_suc * me = (struct Bind_suc *)me_abs;
	return ((me->m_Bind_pair)->eval((me->m_Bind_false))->eval(me->x));
}

ff Exec_Bind_pred                 (ff me_abs, ff x) {
	struct Bind_pred * me = (struct Bind_pred *)me_abs;
	return ((me->m_Bind_snd)->eval(me->x));
}

ff Exec_Lambda_59                 (ff me_abs, ff x) {
	struct Lambda_59 * me = (struct Lambda_59 *)me_abs;
	return ((me->m_Bind_if)->eval(((me->m_Bind_fst)->eval(me->parent->x)))->eval(me->parent->x)->eval(((me->m_Bind_get0)->eval(((me->m_Bind_pred)->eval(me->x))))));
}

ff Exec_Bind_get0                 (ff me_abs, ff x) {
	struct Bind_get0 * me = (struct Bind_get0 *)me_abs;
	return ((me->m_Lambda_59));
}



int main() {
	puts("start");
	puts("end");
	return 0; 
}

