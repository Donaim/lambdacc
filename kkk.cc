
#include <iostream>

using namespace std;

struct A {
    virtual void hi() {
        cout << "hi A" << endl;
    }
};

struct B : A {
    void hi() override {
        cout << "hello B" << endl;
    }  
};

A get_b() {
    return B{};
}
A * get_b_ptr() {
    return new B{};
}
void ptrs() {
    A * a = new A{};
    A * b = new B{};
    A * c = get_b_ptr();

    a->hi();
    b->hi();
    c->hi();
}
void conv() {
    A a{};
    A b{B{}};
    A c{get_b()};

    a.hi();
    b.hi();
    c.hi();
}
int main() {
    // ptrs();
    conv();
    
    return 0;
}