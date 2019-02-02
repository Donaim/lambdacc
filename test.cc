der(Lambda_7) {
	Bind_x m_Bind_x;
	Lambda_7(ff p) : fun(p) {}

	ovv {
		return ((&m_Bind_x)->eval((this->parent->parent->x->eval(this->parent->x)))->eval(this->x));
	}
};
der(Lambda_5) {
	Lambda_7 m_Lambda_7;
	Lambda_5(ff p) : fun(p), m_Lambda_7(this) {}

	ovv {
		return ((&m_Lambda_7));
	}
};
der(Lambda_3) {
	Lambda_5 m_Lambda_5;
	Lambda_3() : fun(nullptr), m_Lambda_5(this) {}

	ovv {
		return ((&m_Lambda_5));
	}
};
