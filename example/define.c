struct CustomPriv_add_0 { };
struct Custom_add {
};

struct Custom_bnot {
};

struct Custom_booly {
	int value;
};

struct Custom_ec {
	int counter;
};

struct Custom_facc {
};

struct Custom_mdec {
};

struct Custom_mint {
	int value;
};

struct Custom_msuc {
};

struct Custom_pbooly {
};

struct Custom_pmint {
};

struct Custom_print_false {
};

struct Custom_print_true {
};


int Init_Bind_add (ff me_abs) {
	me_abs->eval_now = Exec_Bind_add;

	me_abs->custom = ALLOC(struct Custom_add);
	struct Custom_add * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_add;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_add;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_add);
#endif

	return 0;
}

int Init_BindPriv_add_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_add_0;

	me_abs->custom = ALLOC(struct CustomPriv_add_0);
	struct CustomPriv_add_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_add_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_add_0;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct CustomPriv_add_0);
#endif

	return 0;
}



int Init_Bind_bnot (ff me_abs) {
	me_abs->eval_now = Exec_Bind_bnot;

	me_abs->custom = ALLOC(struct Custom_bnot);
	struct Custom_bnot * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_bnot;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_bnot;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_bnot);
#endif

	return 0;
}



int Init_Bind_booly (ff me_abs) {
	me_abs->eval_now = Exec_Bind_booly;

	me_abs->custom = ALLOC(struct Custom_booly);
	struct Custom_booly * custom = me_abs->custom;
	custom->value = 0;


#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_booly;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_booly;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_booly);
#endif

	return 0;
}



int Init_Bind_ec (ff me_abs) {
	me_abs->eval_now = Exec_Bind_ec;

	me_abs->custom = ALLOC(struct Custom_ec);
	struct Custom_ec * custom = me_abs->custom;
	custom->counter = 0;


#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_ec;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_ec;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_ec);
#endif

	return 0;
}



int Init_Bind_facc (ff me_abs) {
	me_abs->eval_now = Exec_Bind_facc;

	me_abs->custom = ALLOC(struct Custom_facc);
	struct Custom_facc * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_facc;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_facc;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_facc);
#endif

	return 0;
}



int Init_Bind_mdec (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mdec;

	me_abs->custom = ALLOC(struct Custom_mdec);
	struct Custom_mdec * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mdec;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mdec;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_mdec);
#endif

	return 0;
}



int Init_Bind_mint (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mint;

	me_abs->custom = ALLOC(struct Custom_mint);
	struct Custom_mint * custom = me_abs->custom;
	custom->value = 0;


#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mint;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mint;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_mint);
#endif

	return 0;
}



int Init_Bind_msuc (ff me_abs) {
	me_abs->eval_now = Exec_Bind_msuc;

	me_abs->custom = ALLOC(struct Custom_msuc);
	struct Custom_msuc * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_msuc;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_msuc;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_msuc);
#endif

	return 0;
}



int Init_Bind_pbooly (ff me_abs) {
	me_abs->eval_now = Exec_Bind_pbooly;

	me_abs->custom = ALLOC(struct Custom_pbooly);
	struct Custom_pbooly * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_pbooly;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_pbooly;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_pbooly);
#endif

	return 0;
}



int Init_Bind_pmint (ff me_abs) {
	me_abs->eval_now = Exec_Bind_pmint;

	me_abs->custom = ALLOC(struct Custom_pmint);
	struct Custom_pmint * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_pmint;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_pmint;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_pmint);
#endif

	return 0;
}



int Init_Bind_print_false (ff me_abs) {
	me_abs->eval_now = Exec_Bind_print_false;

	me_abs->custom = ALLOC(struct Custom_print_false);
	struct Custom_print_false * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_print_false;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_print_false;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_print_false);
#endif

	return 0;
}



int Init_Bind_print_true (ff me_abs) {
	me_abs->eval_now = Exec_Bind_print_true;

	me_abs->custom = ALLOC(struct Custom_print_true);
	struct Custom_print_true * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_print_true;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_print_true;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_print_true);
#endif

	return 0;
}



ff Exec_Bind_add (ff me_abs, ff __x) {
	struct Custom_add * custom = (struct Custom_add *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_add_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_add_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_add_0 (ff me_abs, ff __x) {
	struct CustomPriv_add_0 * custom = (struct CustomPriv_add_0 *)me_abs->custom;

	ff a_base = (eval(me_abs->parent->x, fin));
	struct Custom_mint * a = a_base->custom;
#ifdef USE_TYPEID
	if (a_base->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif

	ff b_base = (eval(me_abs->x, fin));
	struct Custom_mint * b = b_base->custom;
#ifdef USE_TYPEID
	if (b_base->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_mint * rc = ret->custom;
	
	rc->value = a->value + b->value;
	return ret;

}



ff Exec_Bind_bnot (ff me_abs, ff __x) {
	struct Custom_bnot * custom = (struct Custom_bnot *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_booly * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_booly(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_booly * rc = ret->custom;
	
	rc->value = ! x->value;
	return ret;

}



ff Exec_Bind_booly (ff me_abs, ff __x) {
	struct Custom_booly * custom = (struct Custom_booly *)me_abs->custom;
	ff x = me_abs->x;
	
	return me_abs;

}



ff Exec_Bind_ec (ff me_abs, ff __x) {
	struct Custom_ec * custom = (struct Custom_ec *)me_abs->custom;
	ff arg = me_abs->x;
	
	if (arg == fin) {
		printf("Counter(%d)\n", custom->counter);
	}
	custom->counter++;
	return me_abs;

}



ff Exec_Bind_facc (ff me_abs, ff __x) {
	struct Custom_facc * custom = (struct Custom_facc *)me_abs->custom;

	ff arg_base = (eval(me_abs->x, fin));
	struct Custom_ec * arg = arg_base->custom;
#ifdef USE_TYPEID
	if (arg_base->typeuuid != Typeid_Bind_ec) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_ec(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_ec * rc = ret->custom;
	
	rc->counter = 1;
	for (int i = 2; i < arg->counter; i++) {
		rc->counter *= i;
	}
	return ret;

}



ff Exec_Bind_mdec (ff me_abs, ff __x) {
	struct Custom_mdec * custom = (struct Custom_mdec *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_mint * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_mint * rc = ret->custom;
	
	rc->value = x->value - 1;
	return ret;

}



ff Exec_Bind_mint (ff me_abs, ff __x) {
	struct Custom_mint * custom = (struct Custom_mint *)me_abs->custom;
	ff x = me_abs->x;
	
	return me_abs;

}



ff Exec_Bind_msuc (ff me_abs, ff __x) {
	struct Custom_msuc * custom = (struct Custom_msuc *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_mint * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_mint * rc = ret->custom;
	
	rc->value = x->value + 1;
	return ret;

}



ff Exec_Bind_pbooly (ff me_abs, ff __x) {
	struct Custom_pbooly * custom = (struct Custom_pbooly *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_booly * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	if (x->value) {
		puts("true");
	} else {
		puts("false");
	}
	return x_base;

}



ff Exec_Bind_pmint (ff me_abs, ff __x) {
	struct Custom_pmint * custom = (struct Custom_pmint *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_mint * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	printf("%d\n", x->value);
	return x_base;

}



ff Exec_Bind_print_false (ff me_abs, ff __x) {
	struct Custom_print_false * custom = (struct Custom_print_false *)me_abs->custom;
	ff x = me_abs->x;
	
	puts("false");
	return fin;

}



ff Exec_Bind_print_true (ff me_abs, ff __x) {
	struct Custom_print_true * custom = (struct Custom_print_true *)me_abs->custom;
	ff x = me_abs->x;
	
	puts("true");
	return fin;

}


#ifdef DO_CACHING

bool Cache_Bind_add (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_add * me = (struct Custom_add *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_add);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_add_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_add_0 * me = (struct BindPriv_add_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_add_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


	return false;
}



bool Cache_Bind_bnot (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_bnot * me = (struct Custom_bnot *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_bnot);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_booly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_booly * me = (struct Custom_booly *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_booly);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	ret->push_back(me->value);
	


	return false;
}



bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_ec * me = (struct Custom_ec *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_ec);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	ret->push_back(me->counter);
	


	return false;
}



bool Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_facc * me = (struct Custom_facc *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_facc);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_mdec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mdec * me = (struct Custom_mdec *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_mdec);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_mint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mint * me = (struct Custom_mint *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_mint);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	ret->push_back(me->value);
	


	return false;
}



bool Cache_Bind_msuc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_msuc * me = (struct Custom_msuc *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Custom_msuc);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_pbooly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_pmint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}


#endif
