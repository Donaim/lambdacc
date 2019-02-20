
ff fin_eval_now(ff, ff);
void fin_init(ff);

struct fun Instance_fin = {
	.parent = 0,
	.x = 0,
	.leafs = 0,
	.eval_now = fin_eval_now,
};

ff fin = &Instance_fin;
