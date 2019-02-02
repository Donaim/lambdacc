der(Lambda_5) {
	Bind_x Bind_x_m;
	Lambda_5(ff p) : fun(p), Bind_x_m(this) {}

	ovv {
		return (&Bind_x_m)->eval(this->parent->x);
	}
};
der(Lambda_3) {
	Lambda_5 Lambda_5_m;
	Lambda_3() : fun(nullptr), Lambda_5_m(this) {}

	ovv {
		return (&Lambda_5_m);
	}
};
