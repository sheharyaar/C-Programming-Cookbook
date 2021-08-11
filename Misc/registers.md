# Register Variables

- Declared using the keyword `register`
- Provide ** faster access ** than memory
- Can be used with pointers to store addresses ( See : Single Link List insertion optimisaition [here](../Data%20Structures/singleLinkList.md) )<p>
- Can be used <mark>within a block only</mark> and </mark>not globally</mark>

:warning: Cannot be used with `static`
:warning: Dereferencing a register is illegal ( as they are not stored in memory )
