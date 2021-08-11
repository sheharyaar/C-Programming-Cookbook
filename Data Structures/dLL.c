#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct NODE {
	struct NODE* fw;
	struct NODE* bw;
	int data;
} Node;

void printList(Node* head);
int insertList();
int createList(Node** head, int* arr, int n);

int main(int argc, char* argv[]){
	int n,i;
	Node* head = NULL;

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

	if(createList(&head,arr,n))
		printf("List created successfully!\n");
	else
		printf("Error in creating list!\n");

	free(arr);
	
	printList(head);

	exit(EXIT_SUCCESS);
}

int createList(Node **headp, int* arr, int n){
	*headp = malloc(sizeof(Node));
	if(*headp == NULL)
		return FALSE;

	(*headp)->data = 0;
	(*headp)->fw = NULL;
	(*headp)->bw = NULL;

	for(int i=0; i<n ; i++){
		Node* new = malloc(sizeof(Node));
		if(new == NULL)
			return FALSE;

		new->data = arr[i];
		new->bw = NULL;
		new->fw = (*headp)->fw;
		(*headp)->fw = new;
		(*headp)->fw->bw = new;

		if(new->fw == NULL)
			(*headp)->bw = new;

	}
	return TRUE;
}

void printList(Node* head){
	Node* temp;
	temp = head->fw;
	printf("Traversing List Data using forward :\n");
	while(head!=NULL){
		printf("%d\n",temp->data);
		temp = temp->fw;
	}
	temp = head->bw;
	printf("Traversing List Data using backward :\n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->bw;
	}
}
