
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

int node_get_length(struct node * n) {
	if (n->key == NULL) {
		return 0;
	}

	int re = 0;

	do {
		n = n->next;
		re++;
	} while (n);

	return re;
}

double get_avg_map_nodes_size(struct map * m) {
	double re = 0;
	int count = 0;

	for (int i = 0; i < m->size; i++) {
		struct node * n = m->nodes + i;
		if (n->key) {
			int len = node_get_length(n);
			re = (re * count + len) / ((double)(count + 1));
			count++;
		}
	}

	return re;
}

void test_map() {
	{
		struct map * m = map_alloc(99347);
		
		struct list * al = list_alloc();
		list_add(al, 3);
		list_add(al, 5);

		map_add(m, al, 0);

		printf("avg = %lf; \n", get_avg_map_nodes_size(m));
	}
}

int main() {
	ALLOC_INIT();

	test_list();
	test_map();

	puts("end");
	return 0;
}
