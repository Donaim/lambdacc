der(Bind_ec) {
	int counter;
};

der(Bind_final) {
};

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
#endif
}

int Init_Bind_final (ff me_abs){
	struct Bind_final * me = (struct Bind_final *)me_abs; 
	me->eval_now = Exec_Bind_final; 

#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_final;
#endif

#ifdef DO_CACHING
	me->cache = Cache_Bind_final;
#endif
}

int Init_Bind_print_false (ff me_abs){
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs; 
	me->eval_now = Exec_Bind_print_false; 

#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_print_false;
#endif

#ifdef DO_CACHING
	me->cache = Cache_Bind_print_false;
#endif
}

int Init_Bind_print_true (ff me_abs){
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs; 
	me->eval_now = Exec_Bind_print_true; 

#ifdef USE_TYPEID
	me->typeuuid = Typeid_Bind_print_true;
#endif

#ifdef DO_CACHING
	me->cache = Cache_Bind_print_true;
#endif
}

ff Exec_Bind_ec (ff me_abs, ff x) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs; 
	
	
	if (me->x->typeuuid == Typeid_Bind_final) {
	printf("Counter = %d\n", me->counter);
	}
	
	me->counter++;
	return me;
	
}

ff Exec_Bind_final (ff me_abs, ff x) {
	struct Bind_final * me = (struct Bind_final *)me_abs; 
	
	puts("This should not be evaluated!");
	return me;
	
}

ff Exec_Bind_print_false (ff me_abs, ff x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs; 
	
	puts("false");
	return me;
	
}

ff Exec_Bind_print_true (ff me_abs, ff x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs; 
	
	puts("true");
	return me;
	
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
