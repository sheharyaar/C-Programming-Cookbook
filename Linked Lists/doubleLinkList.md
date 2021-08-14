# Doubly Linked List

## Optimised Insertion

A normal approach :<p>
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* fwd;
	struct NODE* bwd;
	int data;
} Node;

int insertList(Node* phead, int data){
	Node* this = phead;
	Node* next = NULL;
	Node* new = malloc(sizeof(Node));
	if(new == NULL){
		printf("Error in malloc\n");
		return -1;
	}
	new->data = data;
	while((next = this->fwd)!=NULL && next->data < data){
		this = next;
	}
	
	if(next!=NULL){ /* At the first node or in the middle */
		if(this!=phead){ /* In the middle */
			new->bwd = this;
			new->fwd = next;
			next->bwd = new;
			this->fwd = new;
		}else{ /* At the first node */
			new->bwd = NULL;
			new->fwd = next;
			next->bwd = new;
			phead->fwd = new;
		}
	}else{ /* At the end or empty list */
		if(this!=phead){ /* At the end */
			new->bwd = this;
			new->fwd = NULL;
			this->fwd = new;
			phead->bwd = new;
		}else{ /* Empty list */
			new->fwd = NULL;
			new->bwd = NULL;
			phead->fwd = new;
			phead->bwd = new;
		}
	}

	return 1;
}
```
Refactored Code :<p>
```c
int insertList(Node* phead, int data){
	Node* this = phead;
	Node* next = NULL;
	Node* new = malloc(sizeof(Node));
	if(new == NULL){
		printf("Error in malloc\n");
		return -1;
	}
	new->data = data;
	while((next = this->fwd)!=NULL && next->data < data){
		this = next;
	}
	
	this->fwd = new;
	new->fwd = next;

	if(next!=NULL){ /* At the first node or in the middle */
		next->bwd = new;
	}else{ /* At the end or empty list */
		phead->bwd = new;
	}

	if(this!=phead){ /* In the middle */
		new->bwd = this;
	}else{ /* At the first node */
		new->bwd = NULL;
	}

	return 1;
}
```
Source Code : [here](./dLL.c)
