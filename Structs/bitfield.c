/* Write a declaration that will allow a program to interpret a
 * computer instruction (16 bit) in these formats. It must also have a
 * unsigned short field called addr that access all 16 bits. Use
 * typedef to create a new type machine_inst. Bits are number right to left.
 * 	
 * 	Single Operand (sgl_op)
 *	+------+------------+
 *	| Bits | Field Name |
 *	+------+------------+
 *	| 0-2  | dst_reg    |
 *	| 3-5  | dst_mode   |
 *	| 6-15 | opcode     |
 *	+------+------------+
 *
 * 	Double Operand (dbl_op)
 *	+-------+------------+
 *	| Bits  | Field Name |
 *	+-------+------------+
 *	| 0-2   | dst_reg    |
 *	| 3-5   | dst_mode   |
 *	| 6-8   | src_reg    |
 *	| 9-11  | src_mode   |
 *	| 12-15 | opcode     |
 *	+-------+------------+
 *
 *	Branch(branch)
 *	+------+------------+
 *	| Bits | Field Name |
 *	+------+------------+
 *	| 0-7  | offset     |
 *	| 8-15 | opcode     |
 *	+------+------------+
 *	
 *	Rgister Source(rsg_src)
 *	+------+------------+
 *	| Bits | Field Name |
 *	+------+------------+
 *	| 0-2  | dst_reg    |
 *	| 3-5  | dst_mode   |
 *	| 6-8  | src_reg    |
 *	| 9-15 | opcode     |
 *	+------+------------+
 *
 * 	Miscellaneous(misc)
 *	+------+------------+
 *	| Bits | Field Name |
 *	+------+------------+
 *	| 0-15 | opcode     |
 *	+------+------------+
 */

#include <stdio.h>

struct sgl_op	{
	unsigned 	dst_reg 	: 3;
	unsigned 	dst_mode	: 3;
	unsigned 	opcode		: 10;
};

struct 	dbl_op	{
	unsigned 	dst_reg 	: 3;
	unsigned 	dst_mode	: 3;
	unsigned 	src_reg		: 3;
	unsigned 	src_mode	: 3;
	unsigned 	opcode 		: 4;
};

struct 	branch 	{
	unsigned 	offset		: 8;
	unsigned 	opcode 		: 8;
};

struct 	reg_src {
	unsigned 	dst_reg 	: 3;
	unsigned 	dst_mode 	: 3;
	unsigned 	src_reg 	: 3;
	unsigned 	opcode 		: 7;
};

struct 	misc 	{
	unsigned 	opcode 		: 16;
};

typedef struct {
	enum { SGL_OP, DBL_OP, BRANCH, REG_SRC, MISC } type;
	union {
		struct sgl_op ;
		struct dbl_op;
		struct branch;
		struct reg_src;
		struct misc;
	}abc ;
} machine_inst;
