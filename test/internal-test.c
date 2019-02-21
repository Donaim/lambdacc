
#include <stdio.h>
#include <assert.h>

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

int cmp(struct list * a, struct list * b, const char * mess) {
	int eq = list_compare_two(a, b);
	printf("%s equal %d \n", mess, eq);
	return eq;
}

void test_list() {
	{
		struct list * al = list_alloc();
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		assert(cmp(al, bl, "1") == 1);
	}
	{
		struct list * al = list_alloc();
		list_add(al, 3);
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 3);
		list_add(bl, 5);

		assert(cmp(al, bl, "1") == 1);
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);
		list_add(bl, 5);

		assert(cmp(al, bl, "0") == 0);
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);
		list_add(al, 5);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		assert(cmp(al, bl, "0") == 0);
	}
	{
		struct list * al = list_alloc();
		list_add(al, 2);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		assert(cmp(al, bl, "0") == 0);
	}
	{
		struct list * al = list_alloc();
		list_add(al, 5);
		list_add(al, 2);

		struct list * bl = list_alloc();
		list_add(bl, 5);

		assert(cmp(al, bl, "0") == 0);
	}
}

void test_map() {

}

int main() {
	ALLOC_INIT();

	test_list();

	puts("end");
	return 0;
}
