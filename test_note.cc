#include "note.cc"
#include <iostream>

// using namespace std;
using std::cout;
using std::endl;

der(white) {
private:
    static int counter;
public:
    const int id;
    white() : id{counter++}, fun{nullptr} {}
    ovv {
        cout << "white id is: " << id << "; " << endl;
    }
};
der(black) {
private:
    static int counter;
public:
    const int id;
    black() : id{counter++}, fun{nullptr} {}
    ovv {
        cout << "black id is: " << id << "; " << endl;
    }
};
int black::counter = 0;
int white::counter = 0;

#define assert(expr) cout << #expr << ": " << (expr) << endl;

void test_id() {
    white * a = new white{};
    id i{};
    auto b = i.eval(a);

    b->eval(a);
    a->eval(a);
}
void test_bool() {
    white * a = new white{};
    black * b = new black{};
    
    fun * c = (t{}.eval(a))->eval(b);
    c->eval(nullptr);
    fun * d = (f{}.eval(a))->eval(b);
    d->eval(nullptr);

    f fal{};
    fun * e = ( (neg{}.eval(&fal))->eval(a))->eval(b);
    e->eval(nullptr);
}
void test_pair() {
    // white * a = new white{};
    // black * b = new black{};
    
    // fun * p = pair{}.eval(a)->eval(b);
    // fun * fs = fst{}.eval(p);
    // fun * sn = snd{}.eval(p);
    
    // fs->eval(a);
    // sn->eval(b);
}
void test_kek() {
    white * a = new white{};
    black * b = new black{};
    
    fun * c = (kek{}.eval(a))->eval(b);
    c->eval(nullptr);
    fun * d = (f{}.eval(a))->eval(b);
    d->eval(nullptr);
}
int main() {

    cout << "hello from cpp lambda" << endl << endl;

    // test_id();
    // test_bool();
    // test_pair();
    test_kek();

    return 0;
}