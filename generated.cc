
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

der(Bind_id) {
	Bind_id() : fun(nullptr) {}

	ovv {
		return (this->x);
	}
};
der(Lambda_7) {
	Lambda_7(ff p) : fun(p) {}

	ovv {
		return (this->parent->x);
	}
};
der(Bind_true) {
	Lambda_7 m_Lambda_7;
	Bind_true() : fun(nullptr), m_Lambda_7(this) {}

	ovv {
		return ((&m_Lambda_7));
	}
};
der(Lambda_12) {
	Lambda_12(ff p) : fun(p) {}

	ovv {
		return (this->x);
	}
};
der(Bind_false) {
	Lambda_12 m_Lambda_12;
	Bind_false() : fun(nullptr), m_Lambda_12(this) {}

	ovv {
		return ((&m_Lambda_12));
	}
};
der(Bind_not) {
	Bind_false m_Bind_false;
	Bind_true m_Bind_true;
	Bind_not() : fun(nullptr) {}

	ovv {
		return (this->x->eval((&m_Bind_false))->eval((&m_Bind_true)));
	}
};
der(Lambda_22) {
	Lambda_22(ff p) : fun(p) {}

	ovv {
		return (this->parent->parent->x->eval(this->parent->x)->eval(this->x));
	}
};
der(Lambda_20) {
	Lambda_22 m_Lambda_22;
	Lambda_20(ff p) : fun(p), m_Lambda_22(this) {}

	ovv {
		return ((&m_Lambda_22));
	}
};
der(Bind_if) {
	Lambda_20 m_Lambda_20;
	Bind_if() : fun(nullptr), m_Lambda_20(this) {}

	ovv {
		return ((&m_Lambda_20));
	}
};
der(Lambda_29) {
	Lambda_29(ff p) : fun(p) {}

	ovv {
		return (this->parent->x);
	}
};
der(Lambda_27) {
	Lambda_29 m_Lambda_29;
	Lambda_27(ff p) : fun(p), m_Lambda_29(this) {}

	ovv {
		return ((&m_Lambda_29)->eval(this->parent->x));
	}
};
der(Bind_kek) {
	Lambda_27 m_Lambda_27;
	Bind_kek() : fun(nullptr), m_Lambda_27(this) {}

	ovv {
		return ((&m_Lambda_27));
	}
};
der(Lambda_36) {
	Lambda_36(ff p) : fun(p) {}

	ovv {
		return (this->x->eval(this->parent->parent->x)->eval(this->parent->x));
	}
};
der(Lambda_34) {
	Lambda_36 m_Lambda_36;
	Lambda_34(ff p) : fun(p), m_Lambda_36(this) {}

	ovv {
		return ((&m_Lambda_36));
	}
};
der(Bind_pair) {
	Lambda_34 m_Lambda_34;
	Bind_pair() : fun(nullptr), m_Lambda_34(this) {}

	ovv {
		return ((&m_Lambda_34));
	}
};
der(Bind_fst) {
	Bind_true m_Bind_true;
	Bind_fst() : fun(nullptr) {}

	ovv {
		return (this->x->eval((&m_Bind_true)));
	}
};
der(Bind_snd) {
	Bind_false m_Bind_false;
	Bind_snd() : fun(nullptr) {}

	ovv {
		return (this->x->eval((&m_Bind_false)));
	}
};
der(Bind_zero) {
	Bind_pair m_Bind_pair;
	Bind_true m_Bind_true;
	Bind_id m_Bind_id;
	Bind_zero() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_pair)->eval((&m_Bind_true))->eval((&m_Bind_id)))->eval(x);
	}
};
der(Bind_is0) {
	Bind_if m_Bind_if;
	Bind_fst m_Bind_fst;
	Bind_true m_Bind_true;
	Bind_false m_Bind_false;
	Bind_is0() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_if)->eval(((&m_Bind_fst)->eval(this->x)))->eval((&m_Bind_true))->eval((&m_Bind_false)));
	}
};
der(Bind_suc) {
	Bind_pair m_Bind_pair;
	Bind_false m_Bind_false;
	Bind_suc() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_pair)->eval((&m_Bind_false))->eval(this->x));
	}
};
der(Bind_pred) {
	Bind_snd m_Bind_snd;
	Bind_pred() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_snd)->eval(this->x));
	}
};
der(Bind_get0) {
	Bind_if m_Bind_if;
	Bind_fst m_Bind_fst;
	Bind_get0 m_Bind_get0;
	Bind_pred m_Bind_pred;
	Bind_get0() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_if)->eval(((&m_Bind_fst)->eval(this->x)))->eval(this->x)->eval(((&m_Bind_get0)->eval(((&m_Bind_pred)->eval(this->x))))));
	}
};
der(Bind_assert) {
	Bind_if m_Bind_if;
	Bind_print_true m_Bind_print_true;
	Bind_print_false m_Bind_print_false;
	Bind_assert() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_if)->eval(this->x)->eval((&m_Bind_print_true))->eval((&m_Bind_print_false)));
	}
};
der(EXPR_0) {
	Bind_assert m_Bind_assert;
	Bind_is0 m_Bind_is0;
	Bind_zero m_Bind_zero;
	EXPR_0() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_assert)->eval(((&m_Bind_is0)->eval(((&m_Bind_zero))))))->eval(x);
	}
};
der(EXPR_1) {
	Bind_assert m_Bind_assert;
	Bind_is0 m_Bind_is0;
	Bind_suc m_Bind_suc;
	Bind_zero m_Bind_zero;
	EXPR_1() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_assert)->eval(((&m_Bind_is0)->eval(((&m_Bind_suc)->eval((&m_Bind_zero)))))))->eval(x);
	}
};
der(EXPR_2) {
	Bind_assert m_Bind_assert;
	Bind_is0 m_Bind_is0;
	Bind_pred m_Bind_pred;
	Bind_suc m_Bind_suc;
	Bind_zero m_Bind_zero;
	EXPR_2() : fun(nullptr) {}

	ovv {
		return ((&m_Bind_assert)->eval(((&m_Bind_is0)->eval(((&m_Bind_pred)->eval(((&m_Bind_suc)->eval((&m_Bind_zero)))))))))->eval(x);
	}
};
int main() {
	puts("start");
	EXPR_0{}.eval(nullptr); 
	EXPR_1{}.eval(nullptr); 
	EXPR_2{}.eval(nullptr); 
	puts("end");
	return 0; 
}