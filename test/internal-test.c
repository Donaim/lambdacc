
#include <stdio.h>

#include "list.c"
#include "map.c"
#include "memorypool.c"

void printlist(struct list * l) {
	printf("[ ");
	while (l) {
		printf("%d ", l->value);
		l = l->next;
	}
	printf("]\n");
}

void cmp(struct list * a, struct list * b, const char * mess) {
	int eq = list_compare_two(a, b);
	printf("%s equal %d \n", mess, eq);
}

void test_list() {
	{
		struct list * al = list_alloc();
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		cmp(al, bl, "1");
	}
	{
		struct list * al = list_alloc();
		list_add(al, 3);
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 3);
		list_add(bl, 5);

		cmp(al, bl, "1");
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);
		list_add(bl, 5);

		cmp(al, bl, "0");
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		cmp(al, bl, "0");
	}
	{
		struct list * al = list_alloc();
		list_add(al, 2);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		cmp(al, bl, "0");
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);
		list_add(al, 2);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		cmp(al, bl, "0");
	}
}

int main() {
	ALLOC_INIT();

	test_list();

	puts("end");
	return 0;
}
