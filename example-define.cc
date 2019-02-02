
int Init_Bind_ec (ff me_abs) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs;
	me->eval_now = Exec_Bind_ec;
	return 0;
}

ff Exec_Bind_ec (ff me_abs, ff x) {
	struct Bind_ec * me = (struct Bind_ec *)me_abs;

	if (x == bind_err) {
		printf ("Counter = %d\n", me->counter);
	}

	me->x = x;
	me->counter++;

	return me;
}
