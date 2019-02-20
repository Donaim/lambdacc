
#include "fin.h"

#include <stdio.h>

static const ff fin_leafs[] = {
	0, 0, 0,
};

ff fin_eval_now(ff me, ff x) {
	// Init leafs
	fprintf(stderr, "%s", "fin should not be evaluated!");
	return me;
}

static struct fun fin = {
	.parent = 0,
	.x = 0,
	.leafs = fin_leafs,
	.eval_now = fin_eval_now,
};
