
#include "fin.h"

#include <stdio.h>

ff fin_eval_now(ff me, ff x) {
	// Init leafs
	fprintf(stderr, "%s", "fin should not be evaluated!");
	return me;
}

struct fun Instance_fin = {
	.parent = 0,
	.x = 0,
	.leafs = 0,
	.eval_now = fin_eval_now,
};

ff fin = &Instance_fin;
