#include "note.c"

#include <stdio.h>

// fun PRINT_TRUE(fun x) {
//     puts("TRUE");
//     return x;
// }

void test_true() {
    // fun re = t(PRINT_TRUE, id);
    // fun print_true_ptr = PRINT_TRUE;
    
    // printf("p= %p\n", re);
    // printf("eq: %d\n", print_true_ptr == re);
}
void test_kek() {
    // fun re = kek(id)(PRINT_TRUE);
    // fun print_true_ptr = PRINT_TRUE;
    
    // printf("p= %p\n", re);
    // printf("eq: %d\n", print_true_ptr == re);
}
void test_pair() {
    // fun p = pair(PRINT_TRUE)(id);
    // fun p0 = fst(p);
    // fun p1 = snd(p);
    
    // printf("eq: %d\n", print_true_ptr == re);
}

int main() {
    puts("hello from lambda c\n");

    test_true();
    // test_kek();
    // test_pair();

    return 0;
}
