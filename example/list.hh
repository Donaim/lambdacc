
struct list {
	list * next;
	ff value;

	list() : value{nullptr}, next{this} {}

	bool empty() const {
		return next == this;
	}

	void init_nil() {
		this->value = nullptr;
		this->next = this;
	}
	void init_cons(ff val, list * other) {
		this->value = val;
		this->next = other;
	}

};
