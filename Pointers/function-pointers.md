# Function Pointers

Uses of pointer to functions generally are:
- Callback Functions
- Jump Tables

```c
int f(int);
int (*fp)(int) = &f;
//or
int (*fp)(int) = f;
```
:information_source: `&` is optional. The compiler always converts function names to function pointers.<p>
:warning: Always use a function pointer only after declaring a prototype of the function so that the compiler can verify the type of the function.
</p><p>
The function  can be called using the function pointer:
```c
ans = f(25);
// or
ans = *(pf)(25);
// or
ans = pf(25);
```
:information_source: `*` is optional. The compiler converts a normal function call `f(25)` to a pointer to a function and then the function call operator `()` invokes the function by executing the code begining at the address.
</p>
## Callback Functions

## Jump Tables
