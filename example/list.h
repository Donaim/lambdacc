
#pragma once

struct list {
	int value;
	struct list * next;
};

/* Alloc empty list */
struct list * list_alloc(void);

void list_add(struct list * l, int value);

/* a == b -> return 1 */
int list_compare_two(struct list * a, struct list * b);
