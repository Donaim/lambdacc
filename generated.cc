
#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

class fun {
private:
	bool first_call = false;
protected:
	fun() {}
public:
	const fun * parent = nullptr;
	ff x;
	ff eval(ff x) {
		if (first_call) {
			// initme();
		}
		this->x = x;
		return eval_now(x);
	}
	// virtual void initme() = 0;
	virtual ff eval_now(ff x) = 0;
};

#include <cstdio>

der(debug_id) {
	debug_id() {}
	ovv {
		return x;
	}
};
static debug_id debug_id_instance{};
static debug_id * debug_id_instance_ptr = &debug_id_instance;

der(error_not_lambda) {
	error_not_lambda() {}
	ovv {
		throw puts("error: this lambda is not supposed to be evaluated");
	}
};
static error_not_lambda error_not_lambda_instance{};
static error_not_lambda * error_not_lambda_ptr = &error_not_lambda_instance;

struct Bind_print_true : fun {
	Bind_print_true() {}
	ovv {
		puts("TRUE");
		return &error_not_lambda_instance;
	}
};
struct Bind_print_false : fun {
	Bind_print_false() {}
	ovv {
		puts("FALSE");
		return &error_not_lambda_instance;
	}
};

struct Bind_num : fun {
	Bind_num() {}
	ovv {
		
	}
};

der(Bind_id) {

	Bind_id()  {}

	ovv {
		return (this->x);
	}
};
der(Lambda_7) {

	Lambda_7()  {}

	ovv {
		return (this->parent->x);
	}
};
der(Bind_true) {

	Bind_true()  {}

	Lambda_7                       * m_Lambda_7;
	ovv {
		return ((m_Lambda_7));
	}
};
der(Lambda_12) {

	Lambda_12()  {}

	ovv {
		return (this->x);
	}
};
der(Bind_false) {

	Bind_false()  {}

	Lambda_12                      * m_Lambda_12;
	ovv {
		return ((m_Lambda_12));
	}
};
der(Bind_not) {

	Bind_not()  {}

	Bind_false                     * m_Bind_false;
	Bind_true                      * m_Bind_true;
	ovv {
		return (this->x->eval((m_Bind_false))->eval((m_Bind_true)));
	}
};
der(Lambda_22) {

	Lambda_22()  {}

	ovv {
		return (this->parent->parent->x->eval(this->parent->x)->eval(this->x));
	}
};
der(Lambda_20) {

	Lambda_20()  {}

	Lambda_22                      * m_Lambda_22;
	ovv {
		return ((m_Lambda_22));
	}
};
der(Bind_if) {

	Bind_if()  {}

	Lambda_20                      * m_Lambda_20;
	ovv {
		return ((m_Lambda_20));
	}
};
der(Lambda_29) {

	Lambda_29()  {}

	ovv {
		return (this->parent->x);
	}
};
der(Lambda_27) {

	Lambda_27()  {}

	Lambda_29                      * m_Lambda_29;
	ovv {
		return ((m_Lambda_29)->eval(this->parent->x));
	}
};
der(Bind_kek) {

	Bind_kek()  {}

	Lambda_27                      * m_Lambda_27;
	ovv {
		return ((m_Lambda_27));
	}
};
der(Lambda_36) {

	Lambda_36()  {}

	ovv {
		return (this->x->eval(this->parent->parent->x)->eval(this->parent->x));
	}
};
der(Lambda_34) {

	Lambda_34()  {}

	Lambda_36                      * m_Lambda_36;
	ovv {
		return ((m_Lambda_36));
	}
};
der(Bind_pair) {

	Bind_pair()  {}

	Lambda_34                      * m_Lambda_34;
	ovv {
		return ((m_Lambda_34));
	}
};
der(Bind_fst) {

	Bind_fst()  {}

	Bind_true                      * m_Bind_true;
	ovv {
		return (this->x->eval((m_Bind_true)));
	}
};
der(Bind_snd) {

	Bind_snd()  {}

	Bind_false                     * m_Bind_false;
	ovv {
		return (this->x->eval((m_Bind_false)));
	}
};
der(Bind_zero) {

	Bind_zero()  {}

	Bind_pair                      * m_Bind_pair;
	Bind_true                      * m_Bind_true;
	Bind_id                        * m_Bind_id;
	ovv {
		return ((m_Bind_pair)->eval((m_Bind_true))->eval((m_Bind_id)))->eval(x);
	}
};
der(Bind_is0) {

	Bind_is0()  {}

	Bind_if                        * m_Bind_if;
	Bind_fst                       * m_Bind_fst;
	Bind_true                      * m_Bind_true;
	Bind_false                     * m_Bind_false;
	ovv {
		return ((m_Bind_if)->eval(((m_Bind_fst)->eval(this->x)))->eval((m_Bind_true))->eval((m_Bind_false)));
	}
};
der(Bind_suc) {

	Bind_suc()  {}

	Bind_pair                      * m_Bind_pair;
	Bind_false                     * m_Bind_false;
	ovv {
		return ((m_Bind_pair)->eval((m_Bind_false))->eval(this->x));
	}
};
der(Bind_pred) {

	Bind_pred()  {}

	Bind_snd                       * m_Bind_snd;
	ovv {
		return ((m_Bind_snd)->eval(this->x));
	}
};
der(Bind_get0) {

	Bind_get0()  {}

	Bind_if                        * m_Bind_if;
	Bind_fst                       * m_Bind_fst;
	Bind_get0                      * m_Bind_get0;
	Bind_pred                      * m_Bind_pred;
	ovv {
		return ((m_Bind_if)->eval(((m_Bind_fst)->eval(this->x)))->eval(this->x)->eval(((m_Bind_get0)->eval(((m_Bind_pred)->eval(this->x))))));
	}
};
der(Bind_assert) {

	Bind_assert()  {}

	Bind_if                        * m_Bind_if;
	Bind_print_true                * m_Bind_print_true;
	Bind_print_false               * m_Bind_print_false;
	ovv {
		return ((m_Bind_if)->eval(this->x)->eval((m_Bind_print_true))->eval((m_Bind_print_false)));
	}
};
der(EXPR_0) {

	EXPR_0()  {}

	Bind_assert                    * m_Bind_assert;
	Bind_is0                       * m_Bind_is0;
	Bind_zero                      * m_Bind_zero;
	ovv {
		return ((m_Bind_assert)->eval(((m_Bind_is0)->eval(((m_Bind_zero))))))->eval(x);
	}
};
der(EXPR_1) {

	EXPR_1()  {}

	Bind_assert                    * m_Bind_assert;
	Bind_is0                       * m_Bind_is0;
	Bind_suc                       * m_Bind_suc;
	Bind_zero                      * m_Bind_zero;
	ovv {
		return ((m_Bind_assert)->eval(((m_Bind_is0)->eval(((m_Bind_suc)->eval((m_Bind_zero)))))))->eval(x);
	}
};
der(EXPR_2) {

	EXPR_2()  {}

	Bind_assert                    * m_Bind_assert;
	Bind_is0                       * m_Bind_is0;
	Bind_pred                      * m_Bind_pred;
	Bind_suc                       * m_Bind_suc;
	Bind_zero                      * m_Bind_zero;
	ovv {
		return ((m_Bind_assert)->eval(((m_Bind_is0)->eval(((m_Bind_pred)->eval(((m_Bind_suc)->eval((m_Bind_zero)))))))))->eval(x);
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