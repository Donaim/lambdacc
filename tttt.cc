
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

/// testing

#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

der(white) {
private:
    static int counter;
public:
    const int id;
    white() : id{counter++}, fun{nullptr} {}
    ovv {
        cout << "white id is: " << id << "; " << endl;
    }
};
der(black) {
private:
    static int counter;
public:
    const int id;
    black() : id{counter++}, fun{nullptr} {}
    ovv {
        cout << "black id is: " << id << "; " << endl;
    }
};
int black::counter = 0;
int white::counter = 0;

static bool debug_id_muted = false;
static int debug_id_counter = 0;
der(debug_id) {
	debug_id() : fun(nullptr) {}
	ovv {
		if (debug_id_muted);
		else {
			printf("[debug id called]\n");
			++debug_id_counter;
		}
		return (this->x);
	}
};
static debug_id * debug_id_instance = new debug_id{};

void test_pair() {
    white * a = new white{};
    black * b = new black{};
    
    fun * p = Bind_pair{nullptr}.eval(a)->eval(b);
    fun * fs = Bind_fst{nullptr}.eval(p);
    fun * sn = Bind_snd{nullptr}.eval(p);
    
    fs->eval(debug_id_instance);
    sn->eval(debug_id_instance);
}


int main() {
	cout << "testing tttt" << endl;
	test_pair();

	return 0;
}