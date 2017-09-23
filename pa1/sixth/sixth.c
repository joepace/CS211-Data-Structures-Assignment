#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	if(argc > 1){
		char newWord[argc];
		char* string = NULL;
		int i;
	
		for(i = 1; i < argc; i++)
		{
			string = argv[i];
			newWord[i-1] = string[0];		
		}
		newWord[argc] = '\0';
		i=0;
		while(i < (argc - 1))
		{
			printf("%c", newWord[i]);
			i++;
		}
		
		printf("\n");
		
		return 0;
	}
	printf("error\n");

	return 0;
}
