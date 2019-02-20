struct Custom_ec {
	int counter;
};

struct Custom_print_false {
};

struct Custom_print_true {
};


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



ff Exec_Bind_ec (ff me_abs, ff __x) {
	struct Custom_ec * custom = (struct Custom_ec *)me_abs->custom;
	ff arg = me_abs->x;
	
	if (arg == fin) {
		printf("Counter(%d)\n", custom->counter);
	}
	custom->counter++;
	return me_abs;

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



bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}


#endif
