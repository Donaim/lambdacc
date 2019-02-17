der(BindPriv_add_0) { };
der(Bind_add) {
};

der(Bind_bnot) {
};

der(Bind_booly) {
	bool value;
};

der(BindPriv_cons_0) { };
der(Bind_cons) {
};

der(Bind_ec) {
	int counter;
};

der(Bind_error) {
	Bind_error() { Init_Bind_error(this); } 
} Instance_Bind_error;

der(Bind_facc) {
};

der(Bind_head) {
};

der(Bind_mdec) {
};

der(BindPriv_meq_0) { };
der(Bind_meq) {
};

der(BindPriv_mif_0) { };
der(BindPriv_mif_1) { };
der(Bind_mif) {
};

der(Bind_mint) {
	int value;
};

der(Bind_mis0) {
};

der(Bind_mlist) {
	list * listt;
};

der(Bind_msuc) {
};

der(BindPriv_mult_0) { };
der(Bind_mult) {
};

der(Bind_pbooly) {
};

der(Bind_pmint) {
};

der(BindPriv_pow_0) { };
der(Bind_pow) {
};

der(Bind_print_false) {
};

der(Bind_print_true) {
};

der(Bind_tail) {
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


int Init_Bind_bnot (struct Bind_bnot *me) {
	me->eval_now = Exec_Bind_bnot;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_bnot;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_bnot;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_booly (struct Bind_booly *me) {
	me->eval_now = Exec_Bind_booly;
	me->value = false;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_booly;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_booly;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_cons (struct Bind_cons *me) {
	me->eval_now = Exec_Bind_cons;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_cons;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_cons;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_cons_0 (struct BindPriv_cons_0 *me) {
	me->eval_now = Exec_BindPriv_cons_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_cons_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_cons_0;
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


int Init_Bind_head (struct Bind_head *me) {
	me->eval_now = Exec_Bind_head;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_head;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_head;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mdec (struct Bind_mdec *me) {
	me->eval_now = Exec_Bind_mdec;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mdec;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mdec;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_meq (struct Bind_meq *me) {
	me->eval_now = Exec_Bind_meq;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_meq;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_meq;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_meq_0 (struct BindPriv_meq_0 *me) {
	me->eval_now = Exec_BindPriv_meq_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_meq_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_meq_0;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mif (struct Bind_mif *me) {
	me->eval_now = Exec_Bind_mif;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mif;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mif;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_mif_0 (struct BindPriv_mif_0 *me) {
	me->eval_now = Exec_BindPriv_mif_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_mif_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_mif_0;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_mif_1 (struct BindPriv_mif_1 *me) {
	me->eval_now = Exec_BindPriv_mif_1;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_mif_1;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_mif_1;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mint (struct Bind_mint *me) {
	me->eval_now = Exec_Bind_mint;
	me->value = 0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mint;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mint;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mis0 (struct Bind_mis0 *me) {
	me->eval_now = Exec_Bind_mis0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mis0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mis0;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mlist (struct Bind_mlist *me) {
	me->eval_now = Exec_Bind_mlist;
	me->listt = new list;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mlist;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mlist;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_msuc (struct Bind_msuc *me) {
	me->eval_now = Exec_Bind_msuc;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_msuc;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_msuc;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_mult (struct Bind_mult *me) {
	me->eval_now = Exec_Bind_mult;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_mult;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_mult;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_mult_0 (struct BindPriv_mult_0 *me) {
	me->eval_now = Exec_BindPriv_mult_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_mult_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_mult_0;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_pbooly (struct Bind_pbooly *me) {
	me->eval_now = Exec_Bind_pbooly;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_pbooly;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_pbooly;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_pmint (struct Bind_pmint *me) {
	me->eval_now = Exec_Bind_pmint;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_pmint;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_pmint;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}


int Init_Bind_pow (struct Bind_pow *me) {
	me->eval_now = Exec_Bind_pow;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_pow;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_pow;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}
int Init_BindPriv_pow_0 (struct BindPriv_pow_0 *me) {
	me->eval_now = Exec_BindPriv_pow_0;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_BindPriv_pow_0;
#endif
#ifdef DO_CACHING
	me->cache = Cache_BindPriv_pow_0;
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


int Init_Bind_tail (struct Bind_tail *me) {
	me->eval_now = Exec_Bind_tail;
#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_tail;
#endif
#ifdef DO_CACHING
	me->cache = Cache_Bind_tail;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}



ff Exec_Bind_add (ff me_abs, ff __x) {
	struct Bind_add * me = (struct Bind_add *)me_abs;

	struct BindPriv_add_0 * ret = ALLOC(BindPriv_add_0);
	if (Init_BindPriv_add_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_add_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_add_0 (ff me_abs, ff __x) {
	struct BindPriv_add_0 * me = (struct BindPriv_add_0 *)me_abs;

	struct Bind_mint * a = (struct Bind_mint *) (me->parent->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (a->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif

	struct Bind_mint * b = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (b->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = a->value + b->value;
	return ret;

}



ff Exec_Bind_bnot (ff me_abs, ff __x) {
	struct Bind_bnot * me = (struct Bind_bnot *)me_abs;

	struct Bind_booly * x = (struct Bind_booly *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_booly * ret = ALLOC(Bind_booly);
	if (Init_Bind_booly(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = ! x->value;
	return ret;

}



ff Exec_Bind_booly (ff me_abs, ff __x) {
	struct Bind_booly * me = (struct Bind_booly *)me_abs;
	ff x = me->x;
	
	return me;

}



ff Exec_Bind_cons (ff me_abs, ff __x) {
	struct Bind_cons * me = (struct Bind_cons *)me_abs;

	struct BindPriv_cons_0 * ret = ALLOC(BindPriv_cons_0);
	if (Init_BindPriv_cons_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_cons_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_cons_0 (ff me_abs, ff __x) {
	struct BindPriv_cons_0 * me = (struct BindPriv_cons_0 *)me_abs;
	ff val = me->parent->x;

	struct Bind_mlist * l = (struct Bind_mlist *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (l->typeuuid != Typeid_Bind_mlist) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mlist * ret = ALLOC(Bind_mlist);
	if (Init_Bind_mlist(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->listt->init_cons(val, l->listt);
	return ret;

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

	struct Bind_mint * arg = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (arg->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = 1;
	
	for (int i = 2; i <= arg->value; i++) {
		ret->value *= i;
	}
	
	return ret;

}



ff Exec_Bind_head (ff me_abs, ff __x) {
	struct Bind_head * me = (struct Bind_head *)me_abs;

	struct Bind_mlist * l = (struct Bind_mlist *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (l->typeuuid != Typeid_Bind_mlist) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	if (l->listt->value == nullptr) {
		return &Instance_Bind_error;
	} else {
		return l->listt->value;
	}

}



ff Exec_Bind_mdec (ff me_abs, ff __x) {
	struct Bind_mdec * me = (struct Bind_mdec *)me_abs;

	struct Bind_mint * x = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = x->value - 1;
	return ret;

}



ff Exec_Bind_meq (ff me_abs, ff __x) {
	struct Bind_meq * me = (struct Bind_meq *)me_abs;

	struct BindPriv_meq_0 * ret = ALLOC(BindPriv_meq_0);
	if (Init_BindPriv_meq_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_meq_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_meq_0 (ff me_abs, ff __x) {
	struct BindPriv_meq_0 * me = (struct BindPriv_meq_0 *)me_abs;

	struct Bind_mint * a = (struct Bind_mint *) (me->parent->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (a->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif

	struct Bind_mint * b = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (b->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_booly * ret = ALLOC(Bind_booly);
	if (Init_Bind_booly(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	if (a->value == b->value) {
		ret->value = true;
	} else {
		ret->value = false;
	}
	return ret;

}



ff Exec_Bind_mif (ff me_abs, ff __x) {
	struct Bind_mif * me = (struct Bind_mif *)me_abs;

	struct BindPriv_mif_0 * ret = ALLOC(BindPriv_mif_0);
	if (Init_BindPriv_mif_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mif_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_mif_0 (ff me_abs, ff __x) {
	struct BindPriv_mif_0 * me = (struct BindPriv_mif_0 *)me_abs;

	struct BindPriv_mif_1 * ret = ALLOC(BindPriv_mif_1);
	if (Init_BindPriv_mif_1(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mif_1 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}

ff Exec_BindPriv_mif_1 (ff me_abs, ff __x) {
	struct BindPriv_mif_1 * me = (struct BindPriv_mif_1 *)me_abs;

	struct Bind_booly * x = (struct Bind_booly *) (me->parent->parent->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	ff a = me->parent->x;
	ff b = me->x;
	
	if (x->value) {
		return a;
	} else {
		return b;
	}

}



ff Exec_Bind_mint (ff me_abs, ff __x) {
	struct Bind_mint * me = (struct Bind_mint *)me_abs;
	ff x = me->x;
	
	return me;

}



ff Exec_Bind_mis0 (ff me_abs, ff __x) {
	struct Bind_mis0 * me = (struct Bind_mis0 *)me_abs;

	struct Bind_mint * x = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_booly * ret = ALLOC(Bind_booly);
	if (Init_Bind_booly(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	if (x->value == 0) {
		ret->value = true;
	} else {
		ret->value = false;
	}
	return ret;

}



ff Exec_Bind_mlist (ff me_abs, ff __x) {
	struct Bind_mlist * me = (struct Bind_mlist *)me_abs;
	ff x = me->x;
	
	return me;

}



ff Exec_Bind_msuc (ff me_abs, ff __x) {
	struct Bind_msuc * me = (struct Bind_msuc *)me_abs;

	struct Bind_mint * x = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = x->value + 1;
	return ret;

}



ff Exec_Bind_mult (ff me_abs, ff __x) {
	struct Bind_mult * me = (struct Bind_mult *)me_abs;

	struct BindPriv_mult_0 * ret = ALLOC(BindPriv_mult_0);
	if (Init_BindPriv_mult_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mult_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_mult_0 (ff me_abs, ff __x) {
	struct BindPriv_mult_0 * me = (struct BindPriv_mult_0 *)me_abs;

	struct Bind_mint * a = (struct Bind_mint *) (me->parent->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (a->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif

	struct Bind_mint * b = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (b->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = a->value * b->value;
	return ret;

}



ff Exec_Bind_pbooly (ff me_abs, ff __x) {
	struct Bind_pbooly * me = (struct Bind_pbooly *)me_abs;

	struct Bind_booly * x = (struct Bind_booly *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	if (x->value) {
		puts("true");
	} else {
		puts("false");
	}
	return x;

}



ff Exec_Bind_pmint (ff me_abs, ff __x) {
	struct Bind_pmint * me = (struct Bind_pmint *)me_abs;

	struct Bind_mint * x = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (x->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	printf("%d\n", x->value);
	return x;

}



ff Exec_Bind_pow (ff me_abs, ff __x) {
	struct Bind_pow * me = (struct Bind_pow *)me_abs;

	struct BindPriv_pow_0 * ret = ALLOC(BindPriv_pow_0);
	if (Init_BindPriv_pow_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_pow_0 \n");
	}
	ret->parent = me_abs;
	ret->x = nullptr;

	return ret;
}


ff Exec_BindPriv_pow_0 (ff me_abs, ff __x) {
	struct BindPriv_pow_0 * me = (struct BindPriv_pow_0 *)me_abs;

	struct Bind_mint * a = (struct Bind_mint *) (me->parent->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (a->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif

	struct Bind_mint * b = (struct Bind_mint *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (b->typeuuid != Typeid_Bind_mint) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mint * ret = ALLOC(Bind_mint);
	if (Init_Bind_mint(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	ret->value = 1;
	
	for (int i = 0; i < b->value; i++) {
		ret->value *= a->value;
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



ff Exec_Bind_tail (ff me_abs, ff __x) {
	struct Bind_tail * me = (struct Bind_tail *)me_abs;

	struct Bind_mlist * l = (struct Bind_mlist *) (me->x->eval(&Instance_Bind_error));
#ifdef USE_TYPEID
	if (l->typeuuid != Typeid_Bind_mlist) {
		fprintf(stderr, "%s", "Type error\n");
		return &Instance_Bind_error;
	}
#endif
	
	struct Bind_mlist * ret = ALLOC(Bind_mlist);
	if (Init_Bind_mlist(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return &Instance_Bind_error;
	}
	
	if (l->listt->value == nullptr) {
		return &Instance_Bind_error;
	} else {
		ret->listt = l->listt->next;
		return ret;
	}

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
	struct Bind_bnot * me = (struct Bind_bnot *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_bnot);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_booly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_booly * me = (struct Bind_booly *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_booly);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	ret->push_back(me->value);
	


	return false;
}



bool Cache_Bind_cons (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_cons * me = (struct Bind_cons *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_cons);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_cons_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_cons_0 * me = (struct BindPriv_cons_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_cons_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


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



bool Cache_Bind_head (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_head * me = (struct Bind_head *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_head);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_mdec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mdec * me = (struct Bind_mdec *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mdec);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_meq (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_meq * me = (struct Bind_meq *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_meq);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_meq_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_meq_0 * me = (struct BindPriv_meq_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_meq_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


	return false;
}



bool Cache_Bind_mif (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mif * me = (struct Bind_mif *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mif);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_mif_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_mif_0 * me = (struct BindPriv_mif_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_mif_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


	return false;
}

bool Cache_BindPriv_mif_1 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_mif_1 * me = (struct BindPriv_mif_1 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_mif_1);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));	ret->push_back(me->parent->parent->x->cache(me->parent->parent->x, ret, set));


	
	


	return false;
}



bool Cache_Bind_mint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mint * me = (struct Bind_mint *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mint);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	ret->push_back(me->value);
	


	return false;
}



bool Cache_Bind_mis0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mis0 * me = (struct Bind_mis0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mis0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_mlist (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mlist * me = (struct Bind_mlist *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mlist);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}



	ret->push_back(-12);
	for (list * cur = me->listt; cur != nullptr; cur = cur->next) {
		if (cur->empty()) { break; }
		if (cur->value->cache(cur->value, ret, set)) {
			// return true;
			// ... don't care
		}
	}
	ret->push_back(-13);
	

	
	


	return false;
}



bool Cache_Bind_msuc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_msuc * me = (struct Bind_msuc *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_msuc);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}



bool Cache_Bind_mult (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_mult * me = (struct Bind_mult *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_mult);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_mult_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_mult_0 * me = (struct BindPriv_mult_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_mult_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


	return false;
}



bool Cache_Bind_pbooly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_pmint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_pow (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_pow * me = (struct Bind_pow *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_pow);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}

bool Cache_BindPriv_pow_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct BindPriv_pow_0 * me = (struct BindPriv_pow_0 *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_BindPriv_pow_0);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->parent->x->cache(me->parent->x, ret, set));


	
	


	return false;
}



bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_tail (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_tail * me = (struct Bind_tail *)me_abs;

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		return false;
	} else {
		set->insert(me_abs);
	}

	ret->push_back(-9);
	ret->push_back(Typeid_Bind_tail);

	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}




	
	


	return false;
}


#endif
