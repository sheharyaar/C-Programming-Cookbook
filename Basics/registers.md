# Register Variables

- Declared using the keyword `register`
- Provide **faster access** than memory
- Can be used with pointers to store addresses ( See : Single Link List insertion optimisaition [here](../Data%20Structures/singleLinkList.md) )<p>
- Can be used **within a block only** and **not globally**

:warning: Cannot be used with `static`<p>
:warning: Dereferencing a register is illegal ( as they are not stored in memory )

<p> Registers can be use to improve code fragments like :

```c
Transaction *trans;
trans->product->orders += 1;
trans->product->quantity_on_hand -= trans->quantity;
trans->product->supplier->reorder_quantity += trans->quantity;
if(trans->product->export_restricted){
	...
}

/* Improvements:
	Declare a variable trans->product;
	Use registers
*/

register Product *the_product;
the_product = trans->product;
		
```
