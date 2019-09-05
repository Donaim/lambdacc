
typedef unsigned char bool;
struct term;

typedef struct term* termp_t;
typedef termp_t (*child_constructor_t)(termp_t, termp_t); /* accepts parent and parent argument to copy to scope */

enum BODYPART_TYPE {
	BODYPART_TYPE_IN_SCOPE,
	BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT,
	BODYPART_TYPE_CONSTRUCTIBLE,
	BODYPART_TYPE_EMPTY,
};

union child {
	int index_in_scope;
	child_constructor_t constructor;
};

typedef void stack;

struct term {
	union child left;
	enum BODYPART_TYPE left_type;                                /* TODO: use single type right (reuse index_in_scope) */

	union child right;
	enum BODYPART_TYPE right_type;                               /* TODO: use single type right (reuse index_in_scope) */

	termp_t *scope;                                              /* TODO: allocate together with struct */
};

termp_t reduce(termp_t me0, termp_t x0) {
	termp_t me = me0;
	termp_t x = x0;

	while (1) {
		termp_t right;
		termp_t left;

		switch (me->left_type) {
			case BODYPART_TYPE_IN_SCOPE:
				left = me->scope[me->left.index_in_scope];
				break;
			case BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT:
				left = x;
				break;
			case BODYPART_TYPE_CONSTRUCTIBLE:
				left = me->left.constructor(me, x);
				break;
		}
		switch (me->right_type) {
			case BODYPART_TYPE_IN_SCOPE:
				right = me->scope[me->right.index_in_scope];
				break;
			case BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT:
				right = x;
				break;
			case BODYPART_TYPE_CONSTRUCTIBLE:
				right = me->right.constructor(me, x);
				break;
		}

		if (me->right_type == BODYPART_TYPE_EMPTY) {
			me = left;
			break;
		} else {
			me = left;
			x = right;
		}
	}

	return me;
}
