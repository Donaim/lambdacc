This is a lambda-calculus to C++ translator  
You can write code in lambda-calculus and let the script generate C++ translation  

# Usage

1) Write lambda script to example.ini
2) `$ make`

# Features

- Based on True lazy untyped lambda-calculus
- Can define expression bindings
- No predefined bindings (except for ones for printing but can be disabled)
- Call stack trace is available at will

# TODO
This project is under active development

[x] lazy evaluation
[x] fix unique lambda members (each member should have its own argument x)
[x] fix Y combinator case
[x] inline bindings: do not introduce overhead from bindings (think of implications to call-trace)
[x] allow order-independent bindings
[ ] cache evalutations [hard]
[x] use simple hash map and store whole environment as cache key
[x] determine which lambda abstractions are actually used in evaluation (will get more cache hits)
[x] fix (or find reason for) cache drop when using inlining - expected to have more hits than without inlining
[ ] make base class (fun) more consistant
[x] add command line argument for caching
[ ] use more efficient map than std::map and better keys than std::vector<int>
[x] use definitional irrelevance for smarter equality [hard]
[ ] never duplicate work (using Levy's definition) [hard]
[ ] efectful expression
[x] create translator that is going to use configs as definitions for efectful expressions (customwriter)
[ ] make possible to create custom expressions with more than 1 argument (ex. add, multiply)
[ ] pass 'parent' as argument to exec
[ ] do ALLOC("X") and Init_Bind_"X" in its parent Init instead of its parent Exec
[ ] representation: find a good way to print numbers, strings
[x] make more names legal
[ ] stackoverflow: use queue instead
[ ] add garbage collector [hard]
[ ] use multithreading [hard]
[ ] maybe use C instead of C++ (faster compile-time, maybe better optimisations)
[ ] improve code quality (*.py -> *.hs)
