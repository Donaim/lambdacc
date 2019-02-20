
struct fun;
typedef struct fun * ff;

#ifdef DO_CACHING

#include <map>
using std::map;
#include <vector>
using std::vector;
typedef vector<int> mapkey_t;
#include <unordered_set>
typedef std::unordered_set<void*> recursion_set;

map<mapkey_t,ff> * g_caching_map = new map<mapkey_t,ff>{};

#endif

#ifdef COUNT_TOTAL_EXEC
#include <stdio.h>
extern int total_eval_count;
#ifdef DO_CACHING
extern int g_cache_hits_count;
#endif
#endif

struct fun {
	ff parent;
	ff x;
	ff * leafs;
	// int leafs_count;

	ff (*eval_now)(ff, ff);

	void * custom; /* For custom expressions */

#ifdef USE_TYPEID
	int typeuuid;
#endif
#ifdef DO_CACHING
	int customsize; /* For copying */
	bool (*cache)(ff me, mapkey_t * ret, recursion_set * set);
	mapkey_t cache_key;
#endif
};

ff eval(ff me, ff x);

#include "fin.h"

#include "memorypool.h"

#define NULL ((void*)0)
