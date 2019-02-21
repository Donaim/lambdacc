#include "flags.h"

struct fun;
typedef struct fun * ff;

#ifdef DO_CACHING

#include "map.h"
#include "list.h"

typedef struct list mapkey_t;
typedef struct map recursion_set;

struct map * g_caching_map;

#endif

#ifdef COUNT_TOTAL_EXEC
#include <stdio.h>
extern int total_eval_count;
#ifdef DO_CACHING
extern int g_cache_hits_count;
#endif
#endif

typedef char bool;
#define true  1
#define false 0

struct fun {
	ff parent;
	ff x;
	ff * leafs;

	ff (*eval_now)(ff, ff);

	void * custom; /* For custom expressions */

#ifdef USE_TYPEID
	int typeuuid;
#endif
#ifdef DO_CACHING
	int customsize;  /* For copying */
	int leafs_count; /* For copying */
	bool (*cache)(ff me, mapkey_t * ret, recursion_set * set);
#endif
};

ff eval(ff me, ff x);

#include "fin.h"

#include "memorypool.h"

#define NULL ((void*)0)
