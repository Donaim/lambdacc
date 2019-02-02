
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

// 1)
der(id) {
	id() : fun{nullptr} {}
	ovv {
		return x;
	}
};

// 2)
der (t1) {
	t1(ff p) : fun{p} {}
	ovv {
		return parent->x;
	}
};
der(t) {
	t() : fun{nullptr}, leaf_0{this} {}
	t1 leaf_0;
	ovv {
		return &leaf_0;
	}
};
// 3)
der (f1) {
	f1(ff p) : fun{p} {}
	ovv {
		return x;
	}
};
der(f) {
	f() : fun{nullptr}, leaf_0{this} {}
	f1 leaf_0;
	ovv {
		return &leaf_0;
	}
};
// 4)
der(neg) {
	neg() : fun{nullptr} {}
	f leaf_0;
	t leaf_1;
	ovv {
		return x->eval(&leaf_0)->eval(&leaf_1);
	}
};

// 6)
der(kek2) {
	kek2(ff p) : fun{p} {}
	ovv {
		return parent->x;
	}
};
der(kek1) {
	kek1(ff p) : fun{p}, leaf_0{this} {}
	kek2 leaf_0;
	ovv {
		return leaf_0.eval( parent->x );
	}
};
der(kek) {
	kek() : fun{nullptr}, leaf_0{this} {}
	kek1 leaf_0;
	ovv {
		return &leaf_0;
	}
};

// // 7)
// der(pair2) {
//     fun * a;
//     fun * b;
//     ovv(f) {
//         return f->eval(a)->eval(b);
//     }
// };
// der(pair1) {
//     fun * a;
//     pair2 next;
//     ovv(b) {
//         next.a = a;
//         next.b = b;
//         return &next;
//     }
// };
// der(pair) {
//     pair1 next;
//     ovv(a) {
//         next.a = a;
//         return &next;
//     }
// };
// der(fst) {
//     t tt;
//     ovv(p) {
//         return p->eval(&tt);
//     }
// };
// der(snd) {
//     f fal;
//     ovv(p) {
//         return p->eval(&fal);
//     }
// };