der(BindPriv_add_0) { };
der(BindPriv_add_1) { };
der(Bind_add) {
};

der(Bind_ec) {
	int counter;
};

der(Bind_error) {
	Bind_error() { Init_Bind_error(this); } 
} Instance_Bind_error;

der(Bind_facc) {
};

der(Bind_print_false) {
};

der(Bind_print_true) {
};

int Init_Bind_add (struct Bind_add *me) {
	me->eval_now = Exec_Bind_add;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_add;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_add;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_add_0 (struct BindPriv_add_0 *me) {
	me->eval_now = Exec_BindPriv_add_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_add_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_add_0;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_add_1 (struct BindPriv_add_1 *me) {
	me->eval_now = Exec_BindPriv_add_1;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_add_1;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_add_1;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_ec (struct Bind_ec *me) {
	me->eval_now = Exec_Bind_ec;
	me->counter = 0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_ec;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_ec;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_error (struct Bind_error *me) {
	me->eval_now = Exec_Bind_error;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_error;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_error;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_facc (struct Bind_facc *me) {
	me->eval_now = Exec_Bind_facc;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_facc;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_facc;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_print_false (struct Bind_print_false *me) {
	me->eval_now = Exec_Bind_print_false;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_print_false;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_print_false;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_print_true (struct Bind_print_true *me) {
	me->eval_now = Exec_Bind_print_true;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_print_true;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_print_true;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}




ff Exec_Bind_ec (ff me_abs, ff __x) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs; 
	ff arg = me->x;
	
	
	if (arg == fin) {
	printf("Counter(%d)\n", me->counter);
	}
	
	me->counter++;
	return me;
	
}

ff Exec_Bind_error (ff me_abs, ff __x) {
	struct Bind_error * me = (struct Bind_error *)me_abs; 
	ff x = me->x;
	
	if (x == fin) {
	puts("ERROR");
	}
	fprintf(stderr, "%s", "Error evaluated!");
	return me;
	
}

ff Exec_Bind_facc (ff me_abs, ff __x) {
	struct Bind_facc * me = (struct Bind_facc *)me_abs; 
	
	struct Bind_ec * arg = (struct Bind_ec *) (me->x->eval(&Instance_Bind_error));
	
	#ifdef USE_TYPEID
	if (arg->typeuuid != Typeid_Bind_ec) {
	puts("Type error");
	return &Instance_Bind_error;
	}
	#endif
	
	
	struct Bind_ec * ret = ALLOC(Bind_ec);
	if (Init_Bind_ec(ret)) {
	puts("Initialization failed");
	return &Instance_Bind_error;
	}
	
	ret->counter = 1;
	
	for (int i = 2; i < arg->counter; i++) {
	ret->counter *= i;
	}
	
	return ret;
	
}

ff Exec_Bind_print_false (ff me_abs, ff __x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs; 
	ff x = me->x;
	
	puts("false");
	return &Instance_Bind_error;
	
}

ff Exec_Bind_print_true (ff me_abs, ff __x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs; 
	ff x = me->x;
	
	puts("true");
	return &Instance_Bind_error;
	
}

#ifdef DO_CACHING
bool Cache_Bind_add (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_add * me = (struct Bind_add *)me_abs; 

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_add);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}


	return false;
}

bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs; 

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_ec);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->counter);

	return false;
}

bool Cache_Bind_error (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}

bool Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_facc * me = (struct Bind_facc *)me_abs; 

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_facc);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}


	return false;
}

bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}

bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}

#endif
