# Sinlge Linked List

## Optimised insertion

Generally it is taught in insertion that we take two pointers `current` and `prev` and then perform insertion. But it also brings a corner case : `insertion at head` which makes us write extra code for that process. Even tough it works it is **not the best** way to insert.

Experienced C Programmers generalise that case using their understanding of the data structure and pointers in the following way.

```c
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
	int data;
	struct Node* link;
} node;

/*
	A pointer to the pointer to the head linkp is used.
	linkp points to the address of the node which points to the current node.
	On insertion link the new node to the current node and then we assigned the 
	address of the current node to linkp.
*/

int insertList(node** linkp, int num){
	node* current = *linkp;
	node* temp = malloc(sizeof(node));
	if(temp == NULL){
		printf("Error in malloc!\n");
		return FALSE;
	}
	while(current!=NULL && current->data < num){
		linkp = &current->link;
		current = *linkp;
	}
	temp->data = num;
	temp->link = current;
	*linkp = temp;
	return TRUE;
}

```
