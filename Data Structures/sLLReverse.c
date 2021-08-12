#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* link;
} Node;

Node* sll_reverse(Node* first);
Node* createList();
void printList(Node* head);

int main(int targc, char* argv[]){

	Node* root = NULL;
	root = createList();
	printList(root);
	root = sll_reverse(root);
	printf("Data after reversing list:\n");
	printList(root);
	exit(EXIT_SUCCESS);
}

Node* createList(){
	int i,n,data;
	Node* head = NULL;

	printf("Enter the number of elements :\n");
	scanf("%d",&n);

	printf("Enter the data : \n");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		
		Node* temp = malloc(sizeof(Node));
		if(temp == NULL){
			printf("Error in malloc!\n");
			exit(EXIT_FAILURE);
		}

		temp->data = data;
		temp->link = head;
		head = temp;
	}

	return head;
}

void printList(Node* head){
	printf("Data present in the list :\n");
	while(head!=NULL){
		printf("%d\n",head->data);
		head = head->link;
	}
}

Node* sll_reverse(Node* first){
	Node* next = NULL;
	Node* prev = NULL;
	while(first!=NULL){
		next = first->link;
		first->link = prev;
		prev=first;
		first = next;
	}
	return prev;
}
