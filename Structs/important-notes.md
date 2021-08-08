# Struct Notes :

- Do not pass structs as function arguments generally -> call-by-value requires a copy of the variable to be allocated on the stack so if the struct size is large, it can cause **_stack overflow_**. Instead pass pointers to struct.

```C
struct Transaction {
	char	product[PRODUCT_SIZE];
	int	quantity;
	float	unit_price;
	float	total_amount;
};

// Try to avoid this...
print_receipt ( struct Transaction trans )

// This is better...
print_receipt ( struct Transaction* trans )

```
- For tighter padding ( less size ) for the struct try to place member variables in **_increasing/decreasing_** order of their sizes
