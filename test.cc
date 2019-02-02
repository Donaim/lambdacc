der(Lambda_7) {
	Bind_x Bind_x_m;
	Lambda_7(ff p) : fun(p), Bind_x_m(this) {}

	ovv {
		return ((&Bind_x_m)->eval((this->parent->parent->x->eval(this->parent->x)))->eval(this->x));
	}
};
der(Lambda_5) {
	Lambda_7 Lambda_7_m;
	Lambda_5(ff p) : fun(p), Lambda_7_m(this) {}

	ovv {
		return ((&Lambda_7_m));
	}
};
der(Lambda_3) {
	Lambda_5 Lambda_5_m;
	Lambda_3() : fun(nullptr), Lambda_5_m(this) {}

	ovv {
		return ((&Lambda_5_m));
	}
};
