
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
der(Lambda_6) {
	Lambda_6(ff p) : fun(p) {}

	ovv {
		return (this->parent->x);
	}
};
der(Bind_true) {
	Lambda_6 m_Lambda_6;
	Bind_true() : fun(nullptr), m_Lambda_6(this) {}

	ovv {
		return ((&m_Lambda_6));
	}
};
der(Lambda_11) {
	Lambda_11(ff p) : fun(p) {}

	ovv {
		return (this->x);
	}
};
der(Bind_false) {
	Lambda_11 m_Lambda_11;
	Bind_false() : fun(nullptr), m_Lambda_11(this) {}

	ovv {
		return ((&m_Lambda_11));
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
der(Lambda_21) {
	Lambda_21(ff p) : fun(p) {}

	ovv {
		return (this->parent->parent->x->eval(this->parent->x)->eval(this->x));
	}
};
der(Lambda_19) {
	Lambda_21 m_Lambda_21;
	Lambda_19(ff p) : fun(p), m_Lambda_21(this) {}

	ovv {
		return ((&m_Lambda_21));
	}
};
der(Bind_if) {
	Lambda_19 m_Lambda_19;
	Bind_if() : fun(nullptr), m_Lambda_19(this) {}

	ovv {
		return ((&m_Lambda_19));
	}
};
der(Lambda_28) {
	Lambda_28(ff p) : fun(p) {}

	ovv {
		return (this->parent->x);
	}
};
der(Lambda_26) {
	Lambda_28 m_Lambda_28;
	Lambda_26(ff p) : fun(p), m_Lambda_28(this) {}

	ovv {
		return ((&m_Lambda_28)->eval(this->parent->x));
	}
};
der(Bind_kek) {
	Lambda_26 m_Lambda_26;
	Bind_kek() : fun(nullptr), m_Lambda_26(this) {}

	ovv {
		return ((&m_Lambda_26));
	}
};
der(Lambda_35) {
	Lambda_35(ff p) : fun(p) {}

	ovv {
		return (this->x->eval(this->parent->parent->x)->eval(this->parent->x));
	}
};
der(Lambda_33) {
	Lambda_35 m_Lambda_35;
	Lambda_33(ff p) : fun(p), m_Lambda_35(this) {}

	ovv {
		return ((&m_Lambda_35));
	}
};
der(Bind_pair) {
	Lambda_33 m_Lambda_33;
	Bind_pair() : fun(nullptr), m_Lambda_33(this) {}

	ovv {
		return ((&m_Lambda_33));
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