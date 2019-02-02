
ff Exec_Bind_error (ff me_abs, ff x) {
	puts("ERROR: This is not supposed to be evaluated!");
	me_abs->x = x;
	return me_abs;
}

#define BIND_ERROR_TYPEUUID (-4)

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

int Init_Bind_error (ff me_abs) {
	struct Bind_print_true * me = (struct Bind_print_true *) me_abs;
	me->eval_now = Exec_Bind_error;

#ifdef USE_TYPEID
	me->typeuuid = BIND_ERROR_TYPEUUID;
#endif
	return 0;
}

int Init_Bind_print_true (ff me) {
	// puts ("TRUE INITED");
	me->eval_now = Exec_Bind_print_true;
	return 0;
}
int Init_Bind_print_false (ff me) {
	// puts ("FALS INITED");
	me->eval_now = Exec_Bind_print_false;
	return 0;
}

int Init_Bind_ec        (ff me);

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