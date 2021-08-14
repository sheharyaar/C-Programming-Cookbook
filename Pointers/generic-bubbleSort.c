#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_dbl (void *a, void *b);
int cmp_flt (void *a, void *b);
int cmp_str (void *a, void *b);
int cmp_int (void *a, void *b);
void sort(void *arr, int elem, size_t elem_size, int (*cmp)(void *, void *) );

int main()
{
	int i;
/*	int *arr = malloc(8*sizeof(char *));
	if(arr == NULL){
		printf("ERROR IN MALLOC\n");
		exit(EXIT_FAILURE);
	}
	arr[0] = "lagnos";
	arr[1] = "zebra";
	arr[2] = "mistake";
	arr[3] = "london";
	arr[4] = "andras";
	arr[5] = "sleep";
	arr[6] = "code";
	arr[7] = "repeat";
*/
	int arr[8] = {'m','n','a','z','u','w','f','e'};
	sort(arr,8,sizeof(char),cmp_str);
	printf("Sorted :\n");
	for(i=0;i<8;i++){
		printf("%c\t",arr[i]);
	}printf("\n");

	exit(EXIT_SUCCESS);
}

void sort(void *arr, int elem, size_t elem_size,int (*cmp)(void *, void *) )
{
	int i, j, k;
	for(i=0;i<elem;i++){
		for(j=i+1;j<elem;j++){
			if(cmp((void *)(arr + i*elem_size),(void *)(arr + j*elem_size) )<=0){
				char *temp = malloc(sizeof(elem_size));
				for(k=0;k<(int)elem_size;k++){
					temp[k] = ((char *)(arr + i*elem_size))[k];
					((char *)(arr + i*elem_size))[k] = ((char *)(arr + j*elem_size))[k];
					((char *)(arr + j*elem_size))[k] = temp[k];
				}
			}
		}
	}
}

int cmp_int (void *a, void *b)
{
	return ( *(int *)a < *(int *)b );
}

int cmp_dbl (void *a, void *b)
{
	return ( *(double *)a < *(double *)b );

}
int cmp_flt (void *a, void *b)

{
	return ( *(float *)a < *(float *)b );
}

int cmp_str (void *a, void *b)
{
	return ( strcmp((char *)a,(char *)b) );
}
