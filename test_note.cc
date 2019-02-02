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
    white() : id{counter++} {}
    ovv(x) {
        cout << "white id is: " << id << "; " << endl;
    }
};
der(black) {
private:
    static int counter;
public:
    const int id;
    black() : id{counter++} {}
    ovv(x) {
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
void test_true() {
    white * a = new white{};
    black * b = new black{};
    
    fun * c = (t{}.eval(a))->eval(b);
    c->eval(b);
    fun * d = (f{}.eval(a))->eval(b);
    d->eval(b);
}
void test_pair() {
    white * a = new white{};
    black * b = new black{};
    
    fun * p = pair{}.eval(a)->eval(b);
    fun * fs = fst{}.eval(p);
    fun * sn = snd{}.eval(p);
    
    fs->eval(a);
    sn->eval(b);
}
int main() {

    cout << "hello from cpp lambda" << endl << endl;

    // test_id();
    // test_true();
    test_pair();

    return 0;
}