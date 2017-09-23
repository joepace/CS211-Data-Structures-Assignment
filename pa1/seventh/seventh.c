#include<stdio.h>
#include<string.h>

int main(int argc, char** argv){
	char newWord[argc];
	char* string = NULL;
	int i;
	size_t strleng;
	
	newWord[argc-1] = '\0';

	for(i = 1; i < argc; i++){
		string = argv[i];
		strleng = strlen(string);
		
		newWord[i-1] = string[strleng - 1];
	}
	
	i = 0;
	
	while (i < (argc - 1))
	{
		printf("%c", newWord[i]);
		i++;
	}
	printf("\n");

	return 0;
}
