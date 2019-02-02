typedef void * obj;

// 1)
obj id(obj x) {
    return x;
}

// 2)
obj t1(obj b) {

}
obj t(obj a) {

}

// // 3
// fun f(fun a, fun b) {
//     return b;
// }
// // 4
// fun not(fun b) {
//     return ((fun)b(f))(t);
// }

// // 5
// fun cond2(fun b) {
//     stack[2] = b;
//     return ((fun)stack[0](stack[1]))(stack[2]);
// }
// fun cond1(fun a) {
//     stack[1] = a;
//     return cond2;
// }
// fun cond(fun i) {
//     stack[0] = i;
//     return cond1;
// }

// // 6)
// fun kek2(fun x) {
//     stack[2] = x;
//     return stack[1];
// }
// fun kek1(fun b) {
//     stack[1] = b;
//     return kek2(stack[1]);
// }
// fun kek(fun a) {
//     stack[0] = a;
//     return kek1;
// }

// // 7)
// fun pair_s[3]; // pair_stack
// fun pair2(fun f) {
//     pair_s[2] = f;
//     return ((fun)f(stack[0]))(stack[1]);
// }
// fun pair1(fun b) {
//     stack[1] = b;
//     return pair2;
// }
// fun pair(fun a) {
//     stack[0] = a;
//     return pair1;
// }
// fun fst(fun p) {
//     return p(t);
// }
// fun snd(fun p) {
//     return p(f);
// }
