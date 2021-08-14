#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* fwd;
	struct NODE* bwd;
	int data;
} Node;

void printList(Node* head);
int insertList(Node* phead, int data);
int createList(Node* head, int* arr, int n);

int main(int argc, char* argv[]){
	int n,i;
	Node* head = malloc(sizeof(Node));
	if(head == NULL){
		printf("Error in malloc\n");
		exit(EXIT_FAILURE);
	}
	head->fwd = NULL;
	head->bwd = NULL;
	head->data = 0;

	printf("Enter the number of elements :\n");
	scanf("%d",&n);

	int *arr = malloc(n*sizeof(int));
	if(arr == NULL){
		printf("Error in allocating array for data\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0, printf("Enter the elements:\n");  i<n ; i++){
		scanf("%d",&arr[i]);
	}

	if(createList(head,arr,n) == -1)
		printf("Error in creating list!\n");

	printf("Created Liost\n");
	free(arr);
	
	printList(head);

	exit(EXIT_SUCCESS);
}

int createList(Node *phead, int* arr, int n){
	int i;
	for(i=0;i<n;i++){
		if(insertList(phead,arr[i])==-1)
			return -1;
	}
	return 1;
}

void printList(Node* head){
	Node* temp;
	temp = head->fwd;
	printf("Traversing List Data using forward :\n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->fwd;
	}
	temp = head->bwd;
	printf("Traversing List Data using backward :\n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->bwd;
	}
}

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
