
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
#define ALLOC(x) ((x*)ALLOC_GET(sizeof(x)))
#endif

static void ALLOC_INIT()
{
	pool_cur = ALLOC_NEW_POOL(20111000);
}
