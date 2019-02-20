
#include "header.h"

ff eval(ff me, ff x) {

#ifdef COUNT_TOTAL_EXEC
	total_eval_count++;
#endif

#ifdef DO_CACHING
	/* If we do caching, it is important to make copies of expressions,
	 * to ensure immutability */
	fun * my_copy = (fun*)ALLOC_GET(me->mysize);
	memcpy(my_copy, me, me->mysize);
	my_copy->x = x;

	my_copy->cache_key.clear();
	recursion_set set;
	bool efectful = my_copy->cache(my_copy, &(my_copy->cache_key), &set);

	if (efectful) {
		return my_copy->eval_now(my_copy, x);
	}

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
	me->x = x;
	return me->eval_now(me, x);
#endif
}
