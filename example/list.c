
#include "list.h"
#include "memorypool.h"

#ifndef NULL
#define NULL (void*)0
#endif

list * list_alloc() {
	list * re = ALLOC_GET(sizeof(list));
	re->next = NULL;
	return re;
}

void list_add(list * l, int value) {
	list * new = ALLOC_GET(sizeof(list));

	new->value = l->value;
	new->next = l->next;
	l->value = value;
	l->next = new;
}

int list_compare_two( list * a, list * b ) {
	while (a) {
		if (b == NULL) {
			return 0;
		}
		if (a->value != b->value) {
			return 0;
		}
		a = a->next;
		b = b->next;
	}
	return 1;
}


