#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	char* filename = argv[1];
	FILE* file;
	file = fopen(filename, "r");
	
	int rows;
	int columns;
	int num;
	int i;
	int j;
	
	fscanf(file, "%d %d\n", &rows, &columns);
	
	int ** matrix;
	
	matrix = (int **) malloc(sizeof(int*) * rows);
	
	for (i = 0; i < rows; i++){
		matrix[i] = (int *) malloc(sizeof(int) * columns);
	}
	
	for (i = 0; i < rows; i++){
		for (j = 0; j < columns; j++){
			fscanf(file, "%d", &num);
			matrix[i][j] = num;
		}
	}
	
	int * nump = (int *) malloc(sizeof(int)); 
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			*nump = matrix[i][j];
			fscanf(file, "%d", &num);
			*nump = *nump + num;
			matrix[i][j] = *nump;
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	fclose(file);
	return 0;
}
