
#include <cstdio>

#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override

class fun;
typedef fun * ff;

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

typedef ff (*exec_t)(ff, ff);

#include "memorypool.cc"
#include <cstring>

class fun {
protected:
	fun() {}
public:
	fun * parent = nullptr;
	ff x;

	int mysize;

	ff eval(ff x) {

		fun * my_copy = (fun*)ALLOC_GET(this->mysize);
		memcpy(my_copy, this, this->mysize);

		my_copy->x = x;

#ifdef COUNT_TOTAL_EXEC
		total_eval_count++;
#endif

#ifdef DO_CACHING
		my_copy->cache_key.clear();
		recursion_set set;
		my_copy->cache(my_copy, &(my_copy->cache_key), &set);

		auto find = g_caching_map->find(my_copy->cache_key);
		if (find != g_caching_map->end()) {
#ifdef COUNT_TOTAL_EXEC
			g_cache_hits_count++;
#endif
			// return my_copy->eval_now(my_copy, x);
			return find->second;
		} else {
			ff ret = my_copy->eval_now(my_copy, x);
			g_caching_map->insert( std::pair<mapkey_t, ff> { my_copy->cache_key, ret });
			return ret;
		}
#else
		return eval_now(my_copy, x);
#endif
	}
	exec_t eval_now;

#ifdef DO_CACHING
	bool (*cache)(ff me, mapkey_t * ret, recursion_set * set);
	mapkey_t cache_key;
#endif

#ifdef USE_TYPEID
	int typeuuid = -1;
#endif

#ifdef SHOW_DEBUG
	virtual const char * tostr() = 0;
#endif
};
