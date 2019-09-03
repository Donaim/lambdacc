
struct abs;

typedef struct abs* absp_t;
typedef absp_t (*child_constructor_t)(absp_t, absp_t); /* accepts parent and parent argument to copy to scope */

enum BODYPART_TYPE {
	BODYPART_TYPE_IN_SCOPE,
	BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT,
	BODYPART_TYPE_CONSTRUCTIBLE,
	BODYPART_TYPE_NOT_APPLICATION,
};

struct abs {
	union {
		int application_index_in_scope;
		child_constructor_t application_constructor;
	} application;
	enum BODYPART_TYPE application_type;                                /* TODO: use single type variable (reuse application_index_in_scope) */

	union {
		int variable_index_in_scope;
		child_constructor_t variable_constructor;
	} variable;
	enum BODYPART_TYPE variable_type;                                   /* TODO: use single type variable (reuse application_index_in_scope) */

	absp_t *scope;                                                      /* TODO: allocate together with struct */
};

absp_t reduce(absp_t me0, absp_t x0) {
	absp_t me = me0;
	absp_t x = x0;

	while (1) {
		absp_t variable;
		absp_t application;

		switch (me->application_type) {
			case BODYPART_TYPE_IN_SCOPE:
				application = me->scope[me->application.application_index_in_scope];
				break;
			case BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT:
				application = x;
				break;
			case BODYPART_TYPE_CONSTRUCTIBLE:
				application = me->application.application_constructor(me, x);
				break;
		}
		switch (me->variable_type) {
			case BODYPART_TYPE_IN_SCOPE:
				variable = me->scope[me->variable.variable_index_in_scope];
				break;
			case BODYPART_TYPE_IS_ABSTRACTION_ARGUMENT:
				variable = x;
				break;
			case BODYPART_TYPE_CONSTRUCTIBLE:
				variable = me->variable.variable_constructor(me, x);
				break;
		}

		if (me->application_type == BODYPART_TYPE_NOT_APPLICATION) {
			me = variable;
			break;
		} else {
			me = application;
			x = variable;
		}
	}

	return me;
}
