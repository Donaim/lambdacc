This is a lambda-calculus to C++ translator  
You can write code in lambda-calculus and let the script generate (efficient) C++ translation  

# Usage

	-- write lambda script to note.txt

	$ python3 macro_parser.py
	$ g++ generated.cc && ./a.out

# Features

- Based on True lazy untyped lambda-calculus
- Can define expression bindings
- No predefined bindings (except for ones for printing but can be disabled)
- Call stack trace is available at will
