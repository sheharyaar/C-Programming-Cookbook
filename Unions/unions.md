# Unions

- All the members refer to the same location in memory.
- Unions can be used in palces where we can store different type of data at different time.
- The memory occupied by union is the size of largest member of the union.
```C

/*
	This program shows an example of union. The value union can hold any type of data at 
	any time which can be accessed using proper typecasting.
*/

#include <stdio.h>

struct VARIABLE {
	enum	{ INT, FLOAT, STRING } type;
	union	{
		int i;
		float f;
		char *s;
	} value;
};

```
## Tips

- As the size of the union is same as the largest member, if a union contains members which have a large different in size can cause wastage of memory. So in that case use pointers to the datatypes as member s of the union as they have the same size.
