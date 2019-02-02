
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

static bool debug_id_muted = false;
static int debug_id_counter = 0;
der(debug_id) {
	debug_id() : fun(nullptr) {}
	ovv {
		++debug_id_counter;
		if (debug_id_muted);
		else {
			printf("[debug id called %d times]\n", debug_id_counter);
		}
		return (this->x);
	}
};
static debug_id * debug_id_instance = new debug_id{};

der(error_fun) {
	error_fun() : fun(nullptr) {}
	ovv {
		printf("error: not supposed to be evaluated");
		return nullptr;
	}
};
static error_fun * error_fun_instance = new error_fun{};

der(print_true_id) {
	print_true_id() : fun(nullptr) {}
	ovv {
		printf("TRUE\n");
		return error_fun_instance;
	}
};
static print_true_id * print_true_id_instance = new print_true_id{};
der(print_false_id) {
	print_false_id() : fun(nullptr) {}
	ovv {
		printf("FALSE\n");
		return error_fun_instance;
	}
};
static print_false_id * print_false_id_instance = new print_false_id{};

/* END OF TEMPLATE */
der(Bind_id) {
	Bind_id(ff p) : fun(p) {}

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
	Lambda_6 Lambda_6_m;
	Bind_true(ff p) : fun(p), Lambda_6_m(this) {}

	ovv {
		return ((&Lambda_6_m));
	}
};
der(Lambda_11) {
	Lambda_11(ff p) : fun(p) {}

	ovv {
		return (this->x);
	}
};
der(Bind_false) {
	Lambda_11 Lambda_11_m;
	Bind_false(ff p) : fun(p), Lambda_11_m(this) {}

	ovv {
		return ((&Lambda_11_m));
	}
};
der(Bind_not) {
	Bind_false Bind_false_m;
	Bind_true Bind_true_m;
	Bind_not(ff p) : fun(p), Bind_false_m(this), Bind_true_m(this) {}

	ovv {
		return (this->x->eval((&Bind_false_m))->eval((&Bind_true_m)));
	}
};
der(Lambda_21) {
	Lambda_21(ff p) : fun(p) {}

	ovv {
		return (this->parent->parent->x->eval(this->parent->x)->eval(this->x));
	}
};
der(Lambda_19) {
	Lambda_21 Lambda_21_m;
	Lambda_19(ff p) : fun(p), Lambda_21_m(this) {}

	ovv {
		return ((&Lambda_21_m));
	}
};
der(Bind_if) {
	Lambda_19 Lambda_19_m;
	Bind_if(ff p) : fun(p), Lambda_19_m(this) {}

	ovv {
		return ((&Lambda_19_m));
	}
};
der(Lambda_28) {
	Lambda_28(ff p) : fun(p) {}

	ovv {
		return (this->parent->x);
	}
};
der(Lambda_26) {
	Lambda_28 Lambda_28_m;
	Lambda_26(ff p) : fun(p), Lambda_28_m(this) {}

	ovv {
		return ((&Lambda_28_m)->eval(this->parent->x));
	}
};
der(Bind_kek) {
	Lambda_26 Lambda_26_m;
	Bind_kek(ff p) : fun(p), Lambda_26_m(this) {}

	ovv {
		return ((&Lambda_26_m));
	}
};
der(Lambda_35) {
	Lambda_35(ff p) : fun(p) {}

	ovv {
		return (this->x->eval(this->parent->parent->x)->eval(this->parent->x));
	}
};
der(Lambda_33) {
	Lambda_35 Lambda_35_m;
	Lambda_33(ff p) : fun(p), Lambda_35_m(this) {}

	ovv {
		return ((&Lambda_35_m));
	}
};
der(Bind_pair) {
	Lambda_33 Lambda_33_m;
	Bind_pair(ff p) : fun(p), Lambda_33_m(this) {}

	ovv {
		return ((&Lambda_33_m));
	}
};
der(Bind_fst) {
	Bind_true Bind_true_m;
	Bind_fst(ff p) : fun(p), Bind_true_m(this) {}

	ovv {
		return (this->x->eval((&Bind_true_m)));
	}
};
der(Bind_snd) {
	Bind_false Bind_false_m;
	Bind_snd(ff p) : fun(p), Bind_false_m(this) {}

	ovv {
		return (this->x->eval((&Bind_false_m)));
	}
};
der(Bind_zero) {
	Bind_pair Bind_pair_m;
	Bind_true Bind_true_m;
	Bind_id Bind_id_m;
	Bind_zero(ff p) : fun(p), Bind_pair_m(this), Bind_true_m(this), Bind_id_m(this) {}

	ovv {
		return ((&Bind_pair_m)->eval((&Bind_true_m))->eval((&Bind_id_m)));
	}
};
der(EXPR_0) {
	Bind_id Bind_id_m;
	Bind_not Bind_not_m;
	Bind_true Bind_true_m;
	EXPR_0(ff p) : fun(p), Bind_id_m(this), Bind_not_m(this), Bind_true_m(this) {}

	ovv {
		return ((&Bind_id_m)->eval((&Bind_not_m))->eval((&Bind_true_m)));
	}
};
der(EXPR_1) {
	Bind_true Bind_true_m;
	EXPR_1(ff p) : fun(p), Bind_true_m(this) {}

	ovv {
		return ((&Bind_true_m));
	}
};
void assert(fun * b) {
	Bind_if iff{nullptr};
	iff.eval(b)->eval(print_true_id_instance)->eval(print_false_id_instance)->eval(error_fun_instance);
}
int main() {
	printf("start\n");

	auto fff = new Bind_true {nullptr};
	auto nnn = new Bind_not{nullptr};
	assert( nnn->eval(nnn->eval(fff)) );

	printf("end\n");
	return 0; 
}