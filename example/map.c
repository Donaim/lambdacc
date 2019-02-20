
#include "map.h"
#include "list.h"

#include "memorypool.h"

struct node {
	struct list * value;
	struct node * next;
};

static void init_node(struct node * o) {
	o->next = o;
}

struct map {
	struct node * nodes;
	int size;
};

static void mcpy(void * _dest, void * _src, int len) {
	char * dest = _dest, * src = _src;
	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
}
static void enlarge(struct map * m) {
	int prevsize = m->size;
	int newsize = (m->size + 10) * 2;

	struct node * prev_nodes = m->nodes;

	m->nodes = ALLOC_GET(sizeof(struct node) * newsize);
	mcpy(m->nodes, prev_nodes, sizeof(struct node) * prevsize);

	for (int i = prevsize; i < newsize; i++) {
		init_node(m->nodes + i);
	}
}

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

struct map * map_alloc(void) {
	struct map * m = ALLOC_GET(sizeof(struct map));
	m->size = 0;
	return m;
}

static int list_to_int(struct list * l, int max) {
	if (l->next == l) {
		return 0;
	}

	int re = 0;
	while (l) {
		re = re + (l->value ^ re);
		l = l->next;
	}

	return re;
}

int map_add(struct map * m, struct list * l) {
	int hash = list_to_int(l, m->size);

	return 0;
}
