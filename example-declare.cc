
der(Bind_error) {
#ifdef SHOW_DEBUG
	const char * tostr() override { return "ERROR"; }
#endif
};
struct Bind_error * bind_err = new Bind_error;

der(Bind_print_true) {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_true"; }
#endif
};

der(Bind_print_false) {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_false"; }
#endif
};

ff Exec_Bind_error       (ff me_abs, ff x);
ff Exec_Bind_print_false (ff me_abs, ff x);
ff Exec_Bind_print_true  (ff me_abs, ff x);

int Init_Bind_error (ff me) {
	me->eval_now = Exec_Bind_error;
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

ff Exec_Bind_print_true (ff me_abs, ff x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("TRUE");
	return me->m_Bind_error;
}
ff Exec_Bind_print_false (ff me_abs, ff x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("FALSE");
	return me->m_Bind_error;
}
ff Exec_Bind_error (ff me_abs, ff x) {
	puts("ERROR: This is not supposed to be evaluated!");
	return NULL;
}