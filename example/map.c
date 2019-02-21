
#include "map.h"
#include "list.h"

#include "memorypool.h"

struct node {
	struct list * value;
	struct fun * key;
	struct node * next;
};

static void init_node(struct node * o) {
	o->next = o;
	o->value = NULL;
}

struct map {
	struct node * nodes;
	int size;
};

static int simple_hash(int n, long int k) {
	long int pos = 0, ret = -1;

	while (pos < n)
	{
		ret = pos;
		k = 1 + k * 2862933555777941757ULL;
		pos = ((double)(1LL << 31) / (double)((k >> 33) + 1)) * (ret + 1);
	}

	return ret % n;
}

struct map * map_alloc(const int size) {
	struct map * m = ALLOC_GET(sizeof(struct map));
	m->size = size;

	m->nodes = ALLOC_GET(sizeof(struct node) * m->size);
	for (int i = 0; i < m->size; i++) {
		init_node(m->nodes + i);
	}

	return m;
}

static long int list_to_int(struct list * l, int max) {
	if (l->next == l) {
		return 0;
	}

	long int re = 0;
	while (l) {
		re = l->value + (re << 6) + (re << 16) - re;
		l = l->next;
	}

	return re;
}

int map_add(struct map * m, struct list * key, struct fun * value) {
	long int hash = list_to_int(key, m->size);

	return 0;
}

struct fun * map_get(struct map * m, struct list * key) {
	long int hash = list_to_int(key, m->size);

	return 0;
}
