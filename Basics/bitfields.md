# Bitfields

- Bitfields can be used in places where it is useful to store data in less storage as bitfields can store data generally within the size of an int.
- The special thing about bitfields in C is that even though they are structures we can access the part of an int.

```C
/* 
	This program demonstrates how a disk register can store information of the read-write data in just
	the size of an int ( 32 bit/4 byte ).
*/

#include <stdio.h>

// Defining the address used to access the disk register.(arbitary here)
#define DISK_REGISTER (unsigned int *) 0xc0200142;

struct DISK_REGISTER_FORMAT {
	unsigned	command		: 5;
	unsigned	sector		: 5;
	unsigned	track		: 9;
	unsigned	error_code	: 8;
	unsigned 	head_loaded	: 1;
	unsigned	write_protect	: 1;
	unsigned	disk_spinning	: 1;
	unsigned 	error_occured	: 1;
	unsigned 	read		: 1;
};

```
- Bitfields can be modified using bit operations like `bit shifting`, `bit mask`, etc.

## Tips

- Try to define the members as `unsigned` or `signed` exclusively as `int` size can vary by systems.

## Cautions

 - Do not use it for portable applications :
	- The size of _int_ differs on systems
	- Many compilers limit the size of bitfields to an **int** so it may happen that on different systems (16, 32, 64 bit) the bitfield may not work.
	- Members in a bit field can be located **ltr** or **rtl** so it can be difficult to access the fields.
	- In case a bitfield is large the compiler can either overlap the memory or put the field in second word.
