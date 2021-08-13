## Advanced Pointer Expressions
:information_source: Basic precedence of operators should be used even for complex syntax present here <p> 
- `int \*f()` 	:	Function returning pointer to integer.
- `int (\*f)()`	:	Pointer to a function.
- `int \*(\*f)()`	:	Pointer to function that returns a pointer to an integer.
- `int \*f[]` 	: 	Array of pointer to integer
- `int f()[]`	: 	:x: ILLEGAL - Appears to be a function that returns an array of integers.<p>
:warning: Functions can return ONLY SCALARS.<p>

- `int f[]()` 	: 	:x: ILLEGAL - Appears to be an array of functions.<p>
:warning: Every element of array should be of same size, but in case of functions the size depends on the variables of the functions.

- `int  (\*f[])()`	:	Array of pointers to functions that return integer.
- `int \*(\*f[])()`	:	Array of pointers to functions that return pointer to integers.<p>

- `int (\*f)(int, float)`		: 	Pointer to a function that takes 2 arguments, int and float.
- `int \*(\*g[])(int, float)`	:	Array of pointers to function that returns a pointer to integer and takes in two arguments, int and float.  
