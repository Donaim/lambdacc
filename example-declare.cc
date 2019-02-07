#define Typeid_Bind_ec __COUNTER__
#define Typeid_Bind_final __COUNTER__
#define Typeid_Bind_print_false __COUNTER__
#define Typeid_Bind_print_true __COUNTER__

struct Bind_ec;

struct Bind_final;

struct Bind_print_false;

struct Bind_print_true;

bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set);

bool Cache_Bind_final (ff me_abs, mapkey_t * ret, recursion_set * set);

bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set);

bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set);

int Init_Bind_ec (ff me_abs);

int Init_Bind_final (ff me_abs);

int Init_Bind_print_false (ff me_abs);

int Init_Bind_print_true (ff me_abs);

ff Exec_Bind_ec (ff me_abs, ff x);

ff Exec_Bind_final (ff me_abs, ff x);

ff Exec_Bind_print_false (ff me_abs, ff x);

ff Exec_Bind_print_true (ff me_abs, ff x);

