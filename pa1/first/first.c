#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	int input;
	int checknum = 0;
	int notprime = 0;
	
	if (argc < 2 || argc > 2)
	{
		printf("error\n");
		exit(0);
	}
	
	input = atoi(argv[1]);
	
	for (checknum = 2; checknum < input; checknum++)
	{
		if (input % checknum == 0){
			notprime++;
			break;
		}
	}

	if (notprime == 1)
	{
		printf("no\n");
	}
	
	else
	{
		printf("yes\n");
	}

	return 0;
}
