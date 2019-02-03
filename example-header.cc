
#include <cstdio>

#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

#include <map>
using std::map;
#include <vector>
using std::vector;
typedef vector<int> mapkey_t;

class fun;
typedef fun * ff;

map<mapkey_t,ff> * g_caching_map = new map<mapkey_t,ff>{};

#ifdef COUNT_TOTAL_EXEC
int total_eval_count = 0;
#ifdef DO_CACHING
int g_cache_hits_count = 0;
#endif
#endif

typedef ff (*exec_t)(ff, ff);

class fun {
protected:
	fun() {}
public:
	fun * parent = nullptr;
	ff x;
	ff eval(ff x) {
		this->x = x;

#ifdef COUNT_TOTAL_EXEC
		total_eval_count++;
#endif

#ifdef DO_CACHING
		this->cache_key = this->cache(this);
		auto find = g_caching_map->find(this->cache_key);
		if (find != g_caching_map->end()) {
#ifdef COUNT_TOTAL_EXEC
			g_cache_hits_count++;
#endif
			return find->second;
		} else {
			ff ret = eval_now(this, x);
			g_caching_map->insert( std::pair<mapkey_t, ff> { this->cache_key, ret });
			return ret;
		}
#else
		return eval_now(this, x);
#endif
	}
	exec_t eval_now;

#ifdef DO_CACHING
	mapkey_t (*cache)(ff me);
	mapkey_t cache_key;
#endif

#ifdef USE_TYPEID
	int typeuuid = -1;
#endif

#ifdef SHOW_DEBUG
	virtual const char * tostr() = 0;
#endif
};

/* *** MEMORY POOL *** */

#include <cstdlib>
#include <cstdint>

#define TRACK_ALLOCS false
#define TRACK_POOL_ALLOCS true

struct ALLOCPOOL {
	uint8_t *buf;
	int index;
	int size;
	struct ALLOCPOOL *next;
};

struct ALLOCPOOL * pool_cur = nullptr;

/* FREEING THE POOL ALSO FREES THE BUFFER */
struct ALLOCPOOL * ALLOC_NEW_POOL(int size)
{
	uint8_t *mem = (uint8_t*)malloc(sizeof(ALLOCPOOL) + size);

#if TRACK_POOL_ALLOCS
	printf ("ALLOCATED NEW MEM: [%p] of size %d\n", mem, size);
#endif
	
	struct ALLOCPOOL * ret = (struct ALLOCPOOL*)mem;
	ret->buf = mem + sizeof(struct ALLOCPOOL);
	ret->index = 0;
	ret->size = size;
	ret->next = nullptr;

	return ret;
}

#if TRACK_ALLOCS
inline uint8_t * ALLOC_GET(int size, const char * name)
{
	printf ("ALLOCATING [%s]\n", name);
#else
inline uint8_t * ALLOC_GET(int size)
{
#endif
	if (pool_cur->size > pool_cur->index + size) {
		uint8_t *ret = pool_cur->buf + pool_cur->index;
		pool_cur->index += size;
		return ret;
	} else {
		struct ALLOCPOOL * np = ALLOC_NEW_POOL(pool_cur->size);
		pool_cur->next = np;
		pool_cur = np;
#if TRACK_ALLOCS
		return ALLOC_GET(size, name);
#else
		return ALLOC_GET(size);
#endif
	}
}

#define QUOTE(x) #x

/* SIZE HAS TO BE SMALLER THAN THE ALLOCPOOL->SIZE */

#if TRACK_ALLOCS
#define ALLOC(x) ((x*)ALLOC_GET(sizeof(x), QUOTE(x)))
#else
#define ALLOC(x) (new x{})
#endif

static void ALLOC_INIT()
{
	pool_cur = ALLOC_NEW_POOL(20111000);
}
