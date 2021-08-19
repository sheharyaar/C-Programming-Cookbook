/*
 * 	 INCOMPLETE : Implement the search String which returns
 * 	 an array of strings
 */

/*
 * 	An implementation of Trie Data Structure in C
 *
 * 	Author : Mohammad Shehar Yaar Tausif
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CHARACTER_MAX 64
#define CHARACTER_SIZE 26
#define PREFIX 0
#define MATCH 1
#define TRUE 1
#define FALSE 0

#define DEBUG(x) printf("Reached : %d\n",(x))

typedef struct NODE {
	struct NODE* character[CHARACTER_SIZE]; 
	char data;
	// word - true if a word is completed here else false.
	int word;
} Node;

/* Function to insert a string in trie. */
void insertString(Node* root , char *str);

/*
 *  	Function to search string in a trie.
 *	
 *	Arguments : 	pointer to root node of trie
 *			int mode : defines the mode in which you want to search
 *				PREFIX : prints all strings with prefix the string provided
 *				MATCH : returns true if the string passed is found.
 *
 */
char **searchString(Node* root, char* str,int mode);

/* Function to print the trie structure in alphabetical order */
void printTrie(Node* root);

int main()
{
	int i,n;
	char **arr;
	
	/* Initialising root */
	Node* root = malloc(sizeof(Node));
	assert(root!=NULL);

	root->word = FALSE;
	for( i=0 ; i < CHARACTER_SIZE ; i++ ){
		(root->character)[i] = NULL;
	}
	
	/* Input strings to add to trie */
	printf("Enter the number of strings : \n");
	scanf("%d",&n);
	arr = malloc(n*sizeof(char *));
	assert( arr != NULL);

	printf("Enter the strings : \n");
	for(i=0;i<n;i++){
		arr[i] = malloc((CHARACTER_MAX+1)*sizeof(char));
		assert(arr[i] != NULL);
		scanf("%s",arr[i]);
	}
	
	DEBUG(1);

	/* Call insert function for all strings */
	for(i=0;i<n;i++){
		insertString(root, arr[i]);
	}
	
	DEBUG(2);

	/* Allocate string for searching */

	char *str = malloc((CHARACTER_MAX+1)*sizeof(char));
	assert(str!=NULL);

	printf("Enter the string to be searched : \n");
	scanf("%s",str);

	DEBUG(3);

	/* Call search function in MATCH mode */
	searchString(root,str,MATCH);
	DEBUG(4);

	/* Call search function in PREFIX mode */
	searchString(root,str,PREFIX);
	DEBUG(5);
	
	//printTrie(root);

	exit(EXIT_SUCCESS);
}

void insertString(Node* root, char *str)
{
	int ch;
	while(*str!='\0'){
		ch = (int)(*str-'a');

		/* 	If the node with the character is not available
		 *	allocate memory for the node and initialise it.
		 */
		if(root->character[ch] == NULL ){

			Node* new = malloc(sizeof(Node));
			assert(new != NULL);
			
			new->data = *str;
			new->word = FALSE;
			for(int i=0;i<CHARACTER_SIZE;i++)
				new->character[i] = NULL;

			root->character[ch] = new;
		}

		root = root->character[ch];

		++str;

		/* If the string ends here, mark word value TRUE */
		if(*str == '\0')
			root->word = TRUE;
		
	}
}

void printTrie(Node* root)
{
	if(root==NULL)
		return ;

	printf("%c",root->data);

	if(root->word == TRUE){
		printf("\n");
	}

	for(int i=0;i<CHARACTER_SIZE;i++){
		printTrie(root->character[i]);
	}

	return ;
}

char **searchString(Node* root,char *inp,int mode)
{
	char *str = inp;
	char **res = NULL;
	int ch;

	while((*str)!='\0'){
		ch = (int)(*str-'a');

		if(root->character[ch] == NULL)
			return NULL;	
		
		root = root->character[ch];
		str++;
	}
	--str;
	if(root->word == TRUE){
		res = malloc(2*sizeof(char *));
		assert(res!=NULL);
		
		// Adding the word to the list
		*res = str;
		// Adding null at the end
		*(res+1) = NULL;

	}

	// Add to the pointer list
	if(mode == MATCH)
		return res;

	// Adding strings with prefix str
	printTrie(root);
	
	return res;
}

