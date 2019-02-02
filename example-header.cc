
#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

typedef ff (*exec_t)(ff, ff);

class fun {
protected:
	fun() {}
public:
	fun * parent = nullptr;
	ff x;
	ff eval(ff x) {
		return eval_now(this, x);
	}
	exec_t eval_now;

#ifdef USE_TYPEID
	int typeuuid = -1;
#endif

#ifdef SHOW_DEBUG
	virtual const char * tostr() = 0;
#endif
};

#include <cstdio>
