#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

uint16_t compute(FILE *str);
void errExit(char *str);

int main(int argc, char *argv[])
{
	uint16_t checksum;
	FILE* fp;

	if(argc == 1){
		checksum = compute(stdin);
		printf("STDIN : %d\n",checksum);
	}else{
		while(argv!=NULL){
			fp = fopen(*argv,"r");

			checksum = compute(fp);
			printf("%s : %d\n",*argv,checksum);
			
			fclose(fp);

			argv++;
		}
	}
	exit(EXIT_SUCCESS);
}

uint16_t compute(FILE *fp)
{
	uint16_t checksum = 0;
	char ch;
	int errvar = errno;

	while((ch=fgetc(fp))!=EOF){
		checksum += (uint16_t)(ch);
		errvar = errno;
	}

	if(errno!=errvar)
		errExit("fgetc");

	return checksum;
}

void errExit(char *str)
{
	int errvar = errno;
	printf("Error in : %s\n",str);
	printf("%s\n",strerror(errno));
	errno = errvar;
	exit(EXIT_FAILURE);
}

