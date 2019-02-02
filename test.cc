der(Lambda_5) {
	Bind_1 Bind_1_m;
	ovv {
		return (&Bind_1_m)->eval(this->parent->x);
	}
};
der(Lambda_3) {
	Lambda_5 Lambda_5_m;
	ovv {
		return (&Lambda_5_m);
	}
};
