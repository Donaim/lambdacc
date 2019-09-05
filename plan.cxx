
#define NULL 0
typedef unsigned char bool;

struct term;

typedef struct term* termp_t;
typedef termp_t (*child_constructor_t)(termp_t*, termp_t); /* accepts parent scope and parent argument to copy to childs scope */

enum BODYPART_TYPE {
	BODYPART_TYPE_IN_SCOPE,
	BODYPART_TYPE_CONSTRUCTIBLE,
};

union child {
	int index_in_scope;
	child_constructor_t constructor;
};

typedef void* stack_t;

void stack_push(stack_t stack, void *ptr);
void* stack_pop(stack_t stack);
stack_t stack_new(void);

/* TODO: optimize in terms of size */
struct term {
	union {
		struct {
			union child left;
			enum BODYPART_TYPE left_type;

			union child right;
			enum BODYPART_TYPE right_type;
		} application;
		struct {
			union child b;
			enum BODYPART_TYPE btype;
		} abstraction;
	} body;
	bool is_abstraction;

	termp_t *scope;                                                      /* TODO: allocate together with struct */
};

/* (x . (((y . y) x) x)) (x . x)

id = (x . x)
stack:
	-                   (x . (((y . y) x) x)) (x . x)
	id                  (x . (((y . y) x) x))
	-                   ((y . y) x) x
	id                  (y . y) x
	id id               (y . y)
	id                  (x . x)
	-                   (x . x)
 */

termp_t reduce(termp_t me) {
	stack_t stack = stack_new();

	loop: {
		if (me->is_abstraction) {
			termp_t right = stack_pop(stack);
			if (right == NULL) {
				return me;
			}

			switch (me->body.abstraction.btype) {
				case BODYPART_TYPE_IN_SCOPE:
					me = me->scope[me->body.abstraction.b.index_in_scope];
					break;
				case BODYPART_TYPE_CONSTRUCTIBLE:
					me = me->body.abstraction.b.constructor(me->scope, right);
					break;
			}
		} else {
			switch (me->body.application.right_type) {
				case BODYPART_TYPE_IN_SCOPE:
					stack_push(stack, me->scope[me->body.application.right.index_in_scope]);
					break;
				case BODYPART_TYPE_CONSTRUCTIBLE:
					stack_push(stack, me->body.application.right.constructor(me->scope, NULL));
					break;
			}
			switch (me->body.application.left_type) {
				case BODYPART_TYPE_IN_SCOPE:
					me = me->scope[me->body.application.left.index_in_scope];
					break;
				case BODYPART_TYPE_CONSTRUCTIBLE:
					me = me->body.application.left.constructor(me->scope, NULL);
					break;
			}
		}

		goto loop;
	}

	return me;
}
