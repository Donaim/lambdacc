der(Bind_ec) {
	int counter;
};

der(Bind_error) {
Bind_error() { Init_Bind_error(this); } 
} Instance_Bind_error;

der(Bind_facc) {
};

der(Bind_final) {
Bind_final() { Init_Bind_final(this); } 
} Instance_Bind_final;

der(Bind_print_false) {
};

der(Bind_print_true) {
};

int Init_Bind_ec (ff me_abs){
	struct Bind_ec * me = (struct Bind_ec *)me_abs; 
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

int Init_Bind_error (ff me_abs){
	struct Bind_error * me = (struct Bind_error *)me_abs; 
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

int Init_Bind_facc (ff me_abs){
	struct Bind_facc * me = (struct Bind_facc *)me_abs; 
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

int Init_Bind_final (ff me_abs){
	struct Bind_final * me = (struct Bind_final *)me_abs; 
	me->eval_now = Exec_Bind_final; 

#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_final;
#endif

#ifdef DO_CACHING
	me->cache = Cache_Bind_final;
	me->cache_key = vector<int>{};
	me->mysize = sizeof(*me);
#endif
	return 0;
}

int Init_Bind_print_false (ff me_abs){
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs; 
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

int Init_Bind_print_true (ff me_abs){
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs; 
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
	
	
	if (arg->typeuuid == Typeid_Bind_final) {
	printf("Counter = %d\n", me->counter);
	}
	
	me->counter++;
	return me;
	
}

ff Exec_Bind_error (ff me_abs, ff __x) {
	struct Bind_error * me = (struct Bind_error *)me_abs; 
	ff x = me->x;
	
	puts("This should not be evaluated!");
	return me;
	
}

ff Exec_Bind_facc (ff me_abs, ff __x) {
	struct Bind_facc * me = (struct Bind_facc *)me_abs; 
	
	struct Bind_ec * arg = (struct Bind_ec *) (me->x->eval(&Instance_Bind_error));
	
	if (arg->typeuuid != Typeid_Bind_ec) {
	puts("Type error");
	return &Instance_Bind_error;
	}
	
	
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

ff Exec_Bind_final (ff me_abs, ff __x) {
	struct Bind_final * me = (struct Bind_final *)me_abs; 
	ff x = me->x;
	
	puts("This should not be evaluated!");
	return me;
	
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
bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs; 

	if (set->count(me_abs) > 0) {
		ret->push_back(-2);
		ret->push_back(me->typeuuid);
		return false;
	} else {
		ret->push_back(me->typeuuid);
		set->insert(me_abs);
	}
	if (me->x) {
		ret->push_back(me->x->cache(me->x, ret, set));
	} else {
		ret->push_back(-1);
	}

	ret->push_back(me->counter);

	return false;
}
bool Cache_Bind_error (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_error * me = (struct Bind_error *)me_abs; 

	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_cache_type--);
	return true;
}
bool Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_facc * me = (struct Bind_facc *)me_abs; 

	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_cache_type--);
	return true;
}
bool Cache_Bind_final (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_final * me = (struct Bind_final *)me_abs; 

	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_cache_type--);
	return true;
}
bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs; 

	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_cache_type--);
	return true;
}
bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs; 

	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_cache_type--);
	return true;
}
#endif
