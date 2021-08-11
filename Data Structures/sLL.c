#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} node;

node* createList();
void printList(node* head);
int insertList(node** head, int num);

int main(int targc, char* argv[]){

	node* root = NULL;
	root = createList();
	printList(root);
	if(insertList(&root,12)){
		printf("Successfully inserted the node\n");
	}else{
		printf("Error in inserting the node\n");
	}
	printList(root);
	exit(EXIT_SUCCESS);
}

node* createList(){
	int i,n,data;
	node* head = NULL;

	printf("Enter the number of elements :\n");
	scanf("%d",&n);

	printf("Enter the data : \n");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		
		node* temp = malloc(sizeof(node));
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

void printList(node* head){
	printf("Data present in the list :\n");
	while(head!=NULL){
		printf("%d\n",head->data);
		head = head->link;
	}
}

int insertList(node** linkp, int num){
	node* current = *linkp;
	node* temp = malloc(sizeof(node));
	if(temp == NULL){
		printf("Error in malloc!\n");
		exit(EXIT_FAILURE);
	}
	while(current!=NULL && current->data < num){
		linkp = &current->link;
		current = *linkp;
	}
	temp->data = num;
	temp->link = current;
	*linkp = temp;
	return 1;
}
