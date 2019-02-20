
struct list {
	int value;
	list * next;
};

/* Alloc empty list */
list * list_alloc(void);

void list_add(list * l, int value);

/* a == b -> return 1 */
int list_compare_two( list * a, list * b );
