
#include "map.h"
#include "list.h"

#include "memorypool.h"

struct node {
	struct list * key;
	struct fun * value;
	struct node * next;
};

static void node_add(struct node * last, struct list * key, struct fun * value)
{
	last->next = ALLOC_GET(sizeof(struct node));
	last->next->key = key;
	last->next->value = value;
}

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

	struct node * place = m->nodes + hash;

	if (place->key == NULL) {
		/* If this is the first key at index 'hash' */
		place->key = key;
		place->value = value;
		return 0;
	}

	do {
		if (list_compare_two(place->key, key)) {
			/* Same key already added */
			return 1;
		}
		place = place->next;
	} while (place);

	/* If not found, append to tail */
	node_add(place, key, value);

	return 0;
}

struct fun * map_get(struct map * m, struct list * key) {
	long int hash = list_to_int(key, m->size);

	struct node * place = m->nodes + hash;

	if (place->key == NULL) {
		return 0;
	}

	do {
		if (list_compare_two(place->key, key)) {
			return place->value;
		}
		place = place->next;
	} while (place);

	return 0;
}
