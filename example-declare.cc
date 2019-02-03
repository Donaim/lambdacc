
der(Bind_error) {
#ifdef SHOW_DEBUG
	const char * tostr() override { return "ERROR"; }
#endif
};
struct Bind_error * bind_err = nullptr;

der(Bind_print_true) {
#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_true"; }
#endif
};

der(Bind_print_false) {
#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_false"; }
#endif
};

der(Bind_ec) {
	/* EVALUATION COUNTER */

	int counter = 0;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$ec"; }
#endif
};

ff Exec_Bind_error       (ff me_abs, ff x);
ff Exec_Bind_print_false (ff me_abs, ff x);
ff Exec_Bind_print_true  (ff me_abs, ff x);
ff Exec_Bind_ec          (ff me_abs, ff x);

int g_unique_ret = -1000;

#ifdef DO_CACHING
bool _simple_cache(ff me, mapkey_t * ret, recursion_set * set) {
	ret->push_back(me->typeuuid);
	ret->push_back(g_unique_ret--);
	return true;
}
#endif

#define BIND_ERROR_TYPEUUID (-4)

int Init_Bind_error (ff me_abs) {
	struct Bind_print_true * me = (struct Bind_print_true *) me_abs;
	me->eval_now = Exec_Bind_error;

#ifdef USE_TYPEID
	me->typeuuid = BIND_ERROR_TYPEUUID;
#endif
#ifdef DO_CACHING
	me->cache = _simple_cache;
#endif
	return 0;
}

ff Exec_Bind_error (ff me_abs, ff x) {
	puts("ERROR: This is not supposed to be evaluated!");
	me_abs->x = x;
	return me_abs;
}

int Init_Bind_print_true (ff me) {
	// puts ("TRUE INITED");
	me->eval_now = Exec_Bind_print_true;
#ifdef USE_TYPEID
	me->typeuuid = -10;
#endif
#ifdef DO_CACHING
	me->cache = _simple_cache;
#endif
	return 0;
}

int Init_Bind_print_false (ff me) {
	// puts ("FALS INITED");
	me->eval_now = Exec_Bind_print_false;
#ifdef USE_TYPEID
	me->typeuuid = -11;
#endif
#ifdef DO_CACHING
	me->cache = _simple_cache;
#endif
	return 0;
}

ff Exec_Bind_print_true (ff me_abs, ff x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs;
	if (me->x == NULL) {
	}
	me->x = x;
	puts("TRUE");
	return bind_err;
}
ff Exec_Bind_print_false (ff me_abs, ff x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs;
	if (me->x == NULL) {
	}
	me->x = x;
	puts("FALSE");
	return bind_err;
}

int Init_Bind_ec (ff me_abs) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs;
	me->eval_now = Exec_Bind_ec;
#ifdef USE_TYPEID
	me->typeuuid = -12;
#endif
#ifdef DO_CACHING
	me->cache = _simple_cache;
#endif
	return 0;
}
ff Exec_Bind_ec (ff me_abs, ff x) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs;

	if (x == bind_err) {
		printf ("Counter = %d\n", me->counter);
	}

	me->x = x;

	struct Bind_ec * newme = ALLOC(Bind_ec);
	newme->parent = me->parent;
	newme->x = nullptr;
	Init_Bind_ec(newme);

	newme->counter = me->counter + 1;

	return newme;
}
