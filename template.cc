
#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

class fun {
protected:
    fun(ff p) : parent{p} {}
public:
    const fun * const  parent;
    ff x;
    ff eval(ff x) {
        this->x = x;
        return eval_now(x);
    }
    virtual ff eval_now(ff x) = 0;
};

#include <cstdio>

der(error_fun) {
	error_fun() : fun(nullptr) {}
	ovv {
		printf("error: not supposed to be evaluated");
		return nullptr;
	}
};
static error_fun * error_fun_instance = new error_fun{};

//IMPL

struct IPrintable : fun {
	virtual const char * text() const = 0;
	ovv {
		puts(this->text());
		return x;
	}
};

struct Text_True : IPrintable {
	const char * text() const override {
		return "TRUE";
	}
};
struct Text_False : IPrintable {
	const char * text() const override {
		return "TRUE";
	}
};
