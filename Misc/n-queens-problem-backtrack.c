/*
 * 	Solution to the Eight Queens Problem using Backtracking
 *	
 *	Algorithm :
 *		Place a queen in the first column of a row,
 *		If it does not conflict, recursively call a functuion
 *		and place a queen in another row. If no column satisfy
 *		return the function
 *
 *	Only a 1D-array of size n is used here in contrast to the 2d array used as it increases the
 *	space required to store the configuration.
 */

#include	<stdio.h>
#include 	<stdlib.h>

#define 	TRUE 	1
#define 	FALSE 	0

void printBoard(int *arr,int n);
void solve(int *arr,int pos,int n);
int check(int *arr,int pos);

int sol;

int main()
{
	int n,i;
	int *arr; 

	printf("Enter the value of n :\n");
	scanf("%d",&n);

	arr = malloc(n*sizeof(int));
	if(arr == NULL){
		printf("Error in malloc!\n");
		exit(EXIT_FAILURE);
	}
	
	/* Initialising the array */
	for(i=0;i<n;i++){
		arr[i] = 1;
	}

	sol=0;
	solve(arr,0,n);

	free(arr);

	exit(EXIT_SUCCESS);
}

void printBoard(int *arr,int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			printf("%c\t",( j == arr[i])? 'Q' : '*' );
		}
		printf("\n\n");
	}
}

int check(int *arr,int pos)
{
	int i;
	for(i=pos-1;i>=0;i--){
		if(
		(arr[pos] - arr[i] == 0) ||
		(arr[pos] - arr[i] == i-pos) ||
		(arr[pos] - arr[i] == pos-i)
		){
			return FALSE;
		}
	}
	return TRUE;
}

void solve(int *arr,int pos,int n)
{
	while(arr[pos]<(n+1)){
		if(check(arr,pos) == TRUE){
			if(pos == n-1){
				sol++;
				printf("Solution : %d\n\n",sol);
				printBoard(arr,n);
			}else{
				solve(arr,pos+1,n);
			}
		}
		arr[pos]++;
	}
	arr[pos] = 1;
}
