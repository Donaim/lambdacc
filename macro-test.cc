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
	Lambda_6 Lambda_6_m;
	Bind_true() : fun(nullptr), Lambda_6_m(this) {}

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
	Bind_false() : fun(nullptr), Lambda_11_m(this) {}

	ovv {
		return ((&Lambda_11_m));
	}
};
der(Bind_not) {
	Bind_false Bind_false_m;
	Bind_true Bind_true_m;
	Bind_not() : fun(nullptr), Bind_false_m(this), Bind_true_m(this) {}

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
	Bind_if() : fun(nullptr), Lambda_19_m(this) {}

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
	Bind_kek() : fun(nullptr), Lambda_26_m(this) {}

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
	Bind_pair() : fun(nullptr), Lambda_33_m(this) {}

	ovv {
		return ((&Lambda_33_m));
	}
};
der(Bind_fst) {
	Bind_true Bind_true_m;
	Bind_fst() : fun(nullptr), Bind_true_m(this) {}

	ovv {
		return (this->x->eval((&Bind_true_m)));
	}
};
der(Bind_snd) {
	Bind_false Bind_false_m;
	Bind_snd() : fun(nullptr), Bind_false_m(this) {}

	ovv {
		return (this->x->eval((&Bind_false_m)));
	}
};
der(Bind_zero) {
	Bind_pair Bind_pair_m;
	Bind_true Bind_true_m;
	Bind_id Bind_id_m;
	Bind_zero() : fun(nullptr), Bind_pair_m(this), Bind_true_m(this), Bind_id_m(this) {}

	ovv {
		return ((&Bind_pair_m)->eval((&Bind_true_m))->eval((&Bind_id_m)));
	}
};
