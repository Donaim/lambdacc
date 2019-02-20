struct Custom_print_false {
};

struct Custom_print_true {
};

int Init_Bind_print_false (ff me_abs) {
	struct Custom_print_false * custom = (struct Custom_print_false *)me_abs->custom;
	me_abs->eval_now = Exec_Custom_print_false;
#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Custom_print_false;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Custom_print_false;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_print_false);
#endif
	return 0;
}


int Init_Bind_print_true (ff me_abs) {
	struct Custom_print_true * custom = (struct Custom_print_true *)me_abs->custom;
	me_abs->eval_now = Exec_Custom_print_true;
#ifdef USE_TYPEID
	me_abs->typeuuid = Typeid_Custom_print_true;
#endif
#ifdef DO_CACHING
	me_abs->cache = Cache_Custom_print_true;
	me_abs->cache_key = vector<int>{};
	me_abs->mysize = sizeof(struct Custom_print_true);
#endif
	return 0;
}



ff Exec_Bind_print_false (ff me_abs, ff __x) {
	struct Custom_print_false * custom = (struct Custom_print_false *)me_abs->custom;
	ff x = me->x;
	
	puts("false");
	return fin;

}



ff Exec_Bind_print_true (ff me_abs, ff __x) {
	struct Custom_print_true * custom = (struct Custom_print_true *)me_abs->custom;
	ff x = me->x;
	
	puts("true");
	return fin;

}


#ifdef DO_CACHING

bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}



bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}


#endif
