## Restricct keyword in C

It tells the C compiler that the object pointed to by the pointer will be accessed by the pointer itself or its derivative ( pointer + 1) only and not by any other means.

<p>
Example - 
```c
sstruct sockaddr *restrict addr;
```

