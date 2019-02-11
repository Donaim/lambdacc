const int Typeid_Bind_add = __COUNTER__ ;
const int Typeid_Bind_ec = __COUNTER__ ;
const int Typeid_Bind_error = __COUNTER__ ;
const int Typeid_Bind_facc = __COUNTER__ ;
const int Typeid_Bind_print_false = __COUNTER__ ;
const int Typeid_Bind_print_true = __COUNTER__ ;

struct Bind_add;
struct Bind_ec;
struct Bind_error;
struct Bind_facc;
struct Bind_print_false;
struct Bind_print_true;

int Init_Bind_add (struct Bind_add *me);
int Init_Bind_ec (struct Bind_ec *me);
int Init_Bind_error (struct Bind_error *me);
int Init_Bind_facc (struct Bind_facc *me);
int Init_Bind_print_false (struct Bind_print_false *me);
int Init_Bind_print_true (struct Bind_print_true *me);

ff Exec_Bind_add (ff me_abs, ff __x);
ff Exec_Bind_ec (ff me_abs, ff __x);
ff Exec_Bind_error (ff me_abs, ff __x);
ff Exec_Bind_facc (ff me_abs, ff __x);
ff Exec_Bind_print_false (ff me_abs, ff __x);
ff Exec_Bind_print_true (ff me_abs, ff __x);

#ifdef DO_CACHING
bool Cache_Bind_add (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_error (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set);
#endif
