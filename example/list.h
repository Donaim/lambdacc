
#pragma once

struct list;

/* Alloc empty list */
struct list * list_alloc(void);

void list_add(struct list * l, int value);

/* a == b -> return 1 */
int list_compare_two(struct list * a, struct list * b);

long unsigned int list_to_int(struct list * l);
