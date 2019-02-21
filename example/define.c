struct CustomPriv_add_0 { };
struct Custom_add {
};

struct Custom_bnot {
};

struct Custom_booly {
	bool value;
};

struct CustomPriv_cons_0 { };
struct Custom_cons {
};

struct Custom_ec {
	int counter;
};

struct Custom_facc {
};

struct Custom_head {
};

struct Custom_mdec {
};

struct CustomPriv_meq_0 { };
struct Custom_meq {
};

struct CustomPriv_mif_0 { };
struct CustomPriv_mif_1 { };
struct Custom_mif {
};

struct Custom_mint {
	int value;
};

struct Custom_mis0 {
};

struct Custom_mlist {
	ff value;
	ff next;
};

struct Custom_mnil {
};

struct Custom_msuc {
};

struct CustomPriv_mult_0 { };
struct Custom_mult {
};

struct Custom_pbooly {
};

struct Custom_pmint {
};

struct CustomPriv_pow_0 { };
struct Custom_pow {
};

struct Custom_print_false {
};

struct Custom_print_true {
};

struct Custom_tail {
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
	me_abs->customsize = sizeof(struct Custom_add);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct CustomPriv_add_0);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_bnot);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_booly (ff me_abs) {
	me_abs->eval_now = Exec_Bind_booly;

	me_abs->custom = ALLOC(struct Custom_booly);
	struct Custom_booly * custom = me_abs->custom;
	custom->value = false;


#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_booly;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_booly;
	me_abs->customsize = sizeof(struct Custom_booly);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_cons (ff me_abs) {
	me_abs->eval_now = Exec_Bind_cons;

	me_abs->custom = ALLOC(struct Custom_cons);
	struct Custom_cons * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_cons;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_cons;
	me_abs->customsize = sizeof(struct Custom_cons);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_cons_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_cons_0;

	me_abs->custom = ALLOC(struct CustomPriv_cons_0);
	struct CustomPriv_cons_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_cons_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_cons_0;
	me_abs->customsize = sizeof(struct CustomPriv_cons_0);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_ec);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_facc);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_head (ff me_abs) {
	me_abs->eval_now = Exec_Bind_head;

	me_abs->custom = ALLOC(struct Custom_head);
	struct Custom_head * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_head;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_head;
	me_abs->customsize = sizeof(struct Custom_head);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_mdec);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_meq (ff me_abs) {
	me_abs->eval_now = Exec_Bind_meq;

	me_abs->custom = ALLOC(struct Custom_meq);
	struct Custom_meq * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_meq;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_meq;
	me_abs->customsize = sizeof(struct Custom_meq);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_meq_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_meq_0;

	me_abs->custom = ALLOC(struct CustomPriv_meq_0);
	struct CustomPriv_meq_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_meq_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_meq_0;
	me_abs->customsize = sizeof(struct CustomPriv_meq_0);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_mif (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mif;

	me_abs->custom = ALLOC(struct Custom_mif);
	struct Custom_mif * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mif;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mif;
	me_abs->customsize = sizeof(struct Custom_mif);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_mif_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_mif_0;

	me_abs->custom = ALLOC(struct CustomPriv_mif_0);
	struct CustomPriv_mif_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_mif_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_mif_0;
	me_abs->customsize = sizeof(struct CustomPriv_mif_0);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_mif_1 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_mif_1;

	me_abs->custom = ALLOC(struct CustomPriv_mif_1);
	struct CustomPriv_mif_1 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_mif_1;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_mif_1;
	me_abs->customsize = sizeof(struct CustomPriv_mif_1);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_mint);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_mis0 (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mis0;

	me_abs->custom = ALLOC(struct Custom_mis0);
	struct Custom_mis0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mis0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mis0;
	me_abs->customsize = sizeof(struct Custom_mis0);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_mlist (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mlist;

	me_abs->custom = ALLOC(struct Custom_mlist);
	struct Custom_mlist * custom = me_abs->custom;
	custom->value = NULL;
	custom->next = NULL;


#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mlist;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mlist;
	me_abs->customsize = sizeof(struct Custom_mlist);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_mnil (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mnil;

	me_abs->custom = ALLOC(struct Custom_mnil);
	struct Custom_mnil * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mnil;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mnil;
	me_abs->customsize = sizeof(struct Custom_mnil);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_msuc);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_mult (ff me_abs) {
	me_abs->eval_now = Exec_Bind_mult;

	me_abs->custom = ALLOC(struct Custom_mult);
	struct Custom_mult * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_mult;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_mult;
	me_abs->customsize = sizeof(struct Custom_mult);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_mult_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_mult_0;

	me_abs->custom = ALLOC(struct CustomPriv_mult_0);
	struct CustomPriv_mult_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_mult_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_mult_0;
	me_abs->customsize = sizeof(struct CustomPriv_mult_0);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_pbooly);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_pmint);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_pow (ff me_abs) {
	me_abs->eval_now = Exec_Bind_pow;

	me_abs->custom = ALLOC(struct Custom_pow);
	struct Custom_pow * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_pow;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_pow;
	me_abs->customsize = sizeof(struct Custom_pow);
	me_abs->leafs_count = 0;
#endif

	return 0;
}

int Init_BindPriv_pow_0 (ff me_abs) {
	me_abs->eval_now = Exec_BindPriv_pow_0;

	me_abs->custom = ALLOC(struct CustomPriv_pow_0);
	struct CustomPriv_pow_0 * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_BindPriv_pow_0;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_BindPriv_pow_0;
	me_abs->customsize = sizeof(struct CustomPriv_pow_0);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_print_false);
	me_abs->leafs_count = 0;
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
	me_abs->customsize = sizeof(struct Custom_print_true);
	me_abs->leafs_count = 0;
#endif

	return 0;
}



int Init_Bind_tail (ff me_abs) {
	me_abs->eval_now = Exec_Bind_tail;

	me_abs->custom = ALLOC(struct Custom_tail);
	struct Custom_tail * custom = me_abs->custom;



#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Bind_tail;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Bind_tail;
	me_abs->customsize = sizeof(struct Custom_tail);
	me_abs->leafs_count = 0;
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



ff Exec_Bind_cons (ff me_abs, ff __x) {
	struct Custom_cons * custom = (struct Custom_cons *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_cons_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_cons_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_cons_0 (ff me_abs, ff __x) {
	struct CustomPriv_cons_0 * custom = (struct CustomPriv_cons_0 *)me_abs->custom;
	ff val = me_abs->parent->x;
	ff l = me_abs->x;
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_mlist(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_mlist * rc = ret->custom;
	
	rc->value = val;
	rc->next = l;
	return ret;

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
	struct Custom_mint * arg = arg_base->custom;
#ifdef USE_TYPEID
	if (arg_base->typeuuid != Typeid_Bind_mint) {
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
	
	rc->value = 1;
	for (int i = 2; i <= arg->value; i++) {
		rc->value *= i;
	}
	return ret;

}



ff Exec_Bind_head (ff me_abs, ff __x) {
	struct Custom_head * custom = (struct Custom_head *)me_abs->custom;

	ff l_base = (eval(me_abs->x, fin));
	struct Custom_mlist * l = l_base->custom;
#ifdef USE_TYPEID
	if (l_base->typeuuid != Typeid_Bind_mlist) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	if (l->value == NULL) {
		return fin;
	} else {
		return l->value;
	}

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



ff Exec_Bind_meq (ff me_abs, ff __x) {
	struct Custom_meq * custom = (struct Custom_meq *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_meq_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_meq_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_meq_0 (ff me_abs, ff __x) {
	struct CustomPriv_meq_0 * custom = (struct CustomPriv_meq_0 *)me_abs->custom;

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
	if (Init_Bind_booly(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_booly * rc = ret->custom;
	
	if (a->value == b->value) {
		rc->value = true;
	} else {
		rc->value = false;
	}
	return ret;

}



ff Exec_Bind_mif (ff me_abs, ff __x) {
	struct Custom_mif * custom = (struct Custom_mif *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_mif_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mif_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_mif_0 (ff me_abs, ff __x) {
	struct CustomPriv_mif_0 * custom = (struct CustomPriv_mif_0 *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_mif_1(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mif_1 \n");
	}
	ret->parent = me_abs;

	return ret;
}

ff Exec_BindPriv_mif_1 (ff me_abs, ff __x) {
	struct CustomPriv_mif_1 * custom = (struct CustomPriv_mif_1 *)me_abs->custom;

	ff x_base = (eval(me_abs->parent->parent->x, fin));
	struct Custom_booly * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_booly) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	ff a = me_abs->parent->x;
	ff b = me_abs->x;
	
	if (x->value) {
		return a;
	} else {
		return b;
	}

}



ff Exec_Bind_mint (ff me_abs, ff __x) {
	struct Custom_mint * custom = (struct Custom_mint *)me_abs->custom;
	ff x = me_abs->x;
	
	return me_abs;

}



ff Exec_Bind_mis0 (ff me_abs, ff __x) {
	struct Custom_mis0 * custom = (struct Custom_mis0 *)me_abs->custom;

	ff x_base = (eval(me_abs->x, fin));
	struct Custom_mint * x = x_base->custom;
#ifdef USE_TYPEID
	if (x_base->typeuuid != Typeid_Bind_mint) {
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
	
	if (x->value == 0) {
		rc->value = true;
	} else {
		rc->value = false;
	}
	return ret;

}



ff Exec_Bind_mlist (ff me_abs, ff __x) {
	struct Custom_mlist * custom = (struct Custom_mlist *)me_abs->custom;
	ff x = me_abs->x;
	
	return me_abs;

}



ff Exec_Bind_mnil (ff me_abs, ff __x) {
	struct Custom_mnil * custom = (struct Custom_mnil *)me_abs->custom;

	ff l_base = (eval(me_abs->x, fin));
	struct Custom_mlist * l = l_base->custom;
#ifdef USE_TYPEID
	if (l_base->typeuuid != Typeid_Bind_mlist) {
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
	
	rc->value = l->value == NULL;
	return ret;

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



ff Exec_Bind_mult (ff me_abs, ff __x) {
	struct Custom_mult * custom = (struct Custom_mult *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_mult_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_mult_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_mult_0 (ff me_abs, ff __x) {
	struct CustomPriv_mult_0 * custom = (struct CustomPriv_mult_0 *)me_abs->custom;

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
	
	rc->value = a->value * b->value;
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



ff Exec_Bind_pow (ff me_abs, ff __x) {
	struct Custom_pow * custom = (struct Custom_pow *)me_abs->custom;

	ff ret = ALLOC(struct fun);
	if (Init_BindPriv_pow_0(ret)) {
		fprintf(stderr, "%s", "Could not initialize type BindPriv_pow_0 \n");
	}
	ret->parent = me_abs;

	return ret;
}


ff Exec_BindPriv_pow_0 (ff me_abs, ff __x) {
	struct CustomPriv_pow_0 * custom = (struct CustomPriv_pow_0 *)me_abs->custom;

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
	
	rc->value = 1;
	for (int i = 0; i < b->value; i++) {
		rc->value *= a->value;
	}
	return ret;

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



ff Exec_Bind_tail (ff me_abs, ff __x) {
	struct Custom_tail * custom = (struct Custom_tail *)me_abs->custom;

	ff l_base = (eval(me_abs->x, fin));
	struct Custom_mlist * l = l_base->custom;
#ifdef USE_TYPEID
	if (l_base->typeuuid != Typeid_Bind_mlist) {
		fprintf(stderr, "%s", "Type error\n");
		return fin;
	}
#endif
	
	ff ret = ALLOC(struct fun);
	if (Init_Bind_mlist(ret)) {
		fprintf(stderr, "%s", "Initialization failed\n");
		return fin;
	}
	struct Custom_mlist * rc = ret->custom;
	
	if (l->next == NULL) {
		return fin;
	} else {
		return l->next;
	}

}


#ifdef DO_CACHING

int Cache_Bind_add (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_add * me = (struct Custom_add *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_add);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_add_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_add_0 * me = (struct CustomPriv_add_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_add_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_bnot (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_bnot * me = (struct Custom_bnot *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_bnot);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_booly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_booly * me = (struct Custom_booly *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_booly);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	list_add(ret, me->value);
	


	return false;
}



int Cache_Bind_cons (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_cons * me = (struct Custom_cons *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_cons);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_cons_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_cons_0 * me = (struct CustomPriv_cons_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_cons_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_ec * me = (struct Custom_ec *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_ec);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	list_add(ret, me->counter);
	


	return false;
}



int Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_facc * me = (struct Custom_facc *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_facc);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_head (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_head * me = (struct Custom_head *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_head);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_mdec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mdec * me = (struct Custom_mdec *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mdec);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_meq (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_meq * me = (struct Custom_meq *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_meq);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_meq_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_meq_0 * me = (struct CustomPriv_meq_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_meq_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_mif (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mif * me = (struct Custom_mif *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mif);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_mif_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_mif_0 * me = (struct CustomPriv_mif_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_mif_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}

int Cache_BindPriv_mif_1 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_mif_1 * me = (struct CustomPriv_mif_1 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_mif_1);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));	list_add(ret, me_abs->parent->parent->x->cache(me_abs->parent->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_mint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mint * me = (struct Custom_mint *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mint);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	list_add(ret, me->value);
	


	return false;
}



int Cache_Bind_mis0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mis0 * me = (struct Custom_mis0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mis0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_mlist (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mlist * me = (struct Custom_mlist *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mlist);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}



	list_add(ret, -12);
	if (me->value != NULL) {
		if (me->value->cache(me->value, ret, set)) {
				return true;
		}
	}
	if (me->next != NULL) {
		if (me->next->cache(me->next, ret, set)) {
				return true;
		}
	}
	list_add(ret, -13);
	

	
	


	return false;
}



int Cache_Bind_mnil (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



int Cache_Bind_msuc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_msuc * me = (struct Custom_msuc *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_msuc);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}



int Cache_Bind_mult (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_mult * me = (struct Custom_mult *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_mult);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_mult_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_mult_0 * me = (struct CustomPriv_mult_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_mult_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_pbooly (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



int Cache_Bind_pmint (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



int Cache_Bind_pow (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_pow * me = (struct Custom_pow *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_pow);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}

int Cache_BindPriv_pow_0 (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct CustomPriv_pow_0 * me = (struct CustomPriv_pow_0 *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_BindPriv_pow_0);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}

	list_add(ret, me_abs->parent->x->cache(me_abs->parent->x, ret, set));


	
	


	return false;
}



int Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



int Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



int Cache_Bind_tail (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Custom_tail * me = (struct Custom_tail *)me_abs;

	if (recset_check(set, me_abs)) {
		list_add(ret, -2);
		return false;
	} else {
		recset_add(set, me_abs);
	}

	list_add(ret, -9);
	list_add(ret, Typeid_Bind_tail);

	if (me_abs->x) {
		list_add(ret, me_abs->x->cache(me_abs->x, ret, set));
	} else {
		list_add(ret, -1);
	}




	
	


	return false;
}


#endif
