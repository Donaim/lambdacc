
#define der(name)    struct name : fun
#define ovv(x)       ff eval(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

class fun {
protected:
    fun() {}
public:
    virtual ff eval(ff x) = 0;
};

// 1)
der(id) {
    ovv(x) {
        return x;
    }
};

// 2)
der (t1) {
    fun * a;
    ovv(b) {
        return a;
    }
};
der(t) {
    t1 next;
    ovv(a) {
        next.a = a;
        return &next;
    }
};
// 3)
der (f1) {
    ovv(b) {
        return b;
    }
};
der(f) {
    f1 next;
    ovv(a) {
        return &next;
    }
};
// 4)
der(neg) {
    f fff;
    t ttt;
    fun * bbb;
    ovv(b) {
        bbb = b;
        return bbb->eval(&fff)->eval(&ttt);
    }
};

// 6)
der(kek3) {
    fun * b;
    ovv(x) {
        return b;
    }
};
der(kek2) {
    fun * a;
    kek3 k3;
    ovv(b) {
        k3.b = b;
        return k3.eval(a);
    }
};
der(kek) {
    kek2 next;
    ovv(a) {
        next.a = a;
        return &next;
    }
};

// 7)
der(pair2) {
    fun * a;
    fun * b;
    ovv(f) {
        return f->eval(a)->eval(b);
    }
};
der(pair1) {
    fun * a;
    pair2 next;
    ovv(b) {
        next.a = a;
        next.b = b;
        return &next;
    }
};
der(pair) {
    pair1 next;
    ovv(a) {
        next.a = a;
        return &next;
    }
};
der(fst) {
    t tt;
    ovv(p) {
        return p->eval(&tt);
    }
};
der(snd) {
    f fal;
    ovv(p) {
        return p->eval(&fal);
    }
};