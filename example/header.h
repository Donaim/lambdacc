
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
int total_eval_count = 0;
#ifdef DO_CACHING
int g_cache_hits_count = 0;
#endif
#endif

struct fun {
	ff parent;
	ff x;
	const ff * leafs;
	// int leafs_count;

	ff (*eval_now)(ff, ff);

#ifdef USE_TYPEID
	int typeuuid = -1;
#endif
#ifdef DO_CACHING
	int mysize; /* For copying */
	bool (*cache)(ff me, mapkey_t * ret, recursion_set * set);
	mapkey_t cache_key;
#endif
};

ff eval(ff me, ff x);
