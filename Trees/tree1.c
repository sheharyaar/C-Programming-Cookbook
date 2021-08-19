#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG(x) printf("Reached here : %d\n",(x))

typedef struct NODE {
	struct NODE* left;
	struct NODE* right;
	int data;
} Node;

/* Constructing a binary tree from array */
Node* createTree(int *arr,int i,int n);

/* Inserting a node in a binary tree */
void insertNode(Node** root, int data);

void printTree_r(Node* root);
void clearTree(Node* root);

int main()
{
	Node* root = NULL;
	int n,i,*arr;

	printf("Enter the number of elements in array : \n");
	scanf("%d",&n);

	arr = malloc(n*sizeof(int));
	assert(arr != NULL);
	
	printf("Enter the elements :\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	root = createTree(arr,0,n);
	printTree_r(root);

	int num;
	printf("Enter the number to insert : \n");
	scanf("%d",&num);

	insertNode(&root,num);

	printTree_r(root);

	free(arr);
	clearTree(root);
	
	exit(EXIT_SUCCESS);
}



void printTree_r(Node* root)
{
	if(root==NULL)
		return;

	printf("%d\n",root->data);

	printTree_r(root->left);
	printTree_r(root->right);
	return ;
}

Node* createTree(int *arr,int i,int n)
{

	if(i>=n)
		return NULL;

	Node* new = malloc(sizeof(Node));
	assert(new!=NULL);
	

	new->data = arr[i];
	new->left = createTree(arr,(2*i+1),n);
	new->right = createTree(arr,(2*i+2),n);


	return new;
}

void clearTree(Node* root)
{
	if(root == NULL)
		return;

	clearTree(root->left);
	clearTree(root->right);

	free(root);

}

void insertNode(Node** root, int data)
{
	Node* head = *root;
	
	Node* new = malloc(sizeof(Node));
	assert(new != NULL);
	
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	while(head!=NULL){

		if(data < head->data){
			root = &head->left;
			head = *root;
		}else{
			root = &head->right;
			head = *root;
		}
	}
	*root = new;

}
