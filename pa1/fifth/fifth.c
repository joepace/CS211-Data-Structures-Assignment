#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	char* filename = argv[1];
	FILE* file;
	file = fopen(filename, "r");
	
	int rows;
	int columns;
	int rows2;
	int columns2;
	int num;
	int i;
	int j;
	int k;
	int ** matrix;
	int ** matrix2;
	int ** prodmatrix;
	int product;
	
	fscanf(file, "%d %d\n", &rows, &columns);
	
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
	
	fscanf(file, "%d %d\n", &rows2, &columns2);
	
	matrix2 = (int **) malloc(sizeof(int*) * rows2);
	
	for (i = 0; i < rows2; i++){
		matrix2[i] = (int *) malloc(sizeof(int) * columns2);
	}
	
	for (i = 0; i < rows2; i++){
		for (j = 0; j < columns2; j++){
			fscanf(file, "%d", &num);
			matrix2[i][j] = num;
		}
	}
	
	prodmatrix = (int **) malloc(sizeof(int*) * rows);
	
	for (i = 0; i < rows; i++){
		prodmatrix[i] = (int *) malloc(sizeof(int) * columns2);
	}
	
	for (i = 0; i < rows; i++){
		for (j = 0; j < columns2; j++){
			product = 0;
			
			for(k = 0; k < columns; k++){
				product = product + (matrix[i][k] * matrix2[k][j]);
			}
			
			prodmatrix[i][j] = product;
			printf("%d\t", prodmatrix[i][j]);
			
		}
		printf("\n");
	}
	
	
	fclose(file);
	return 0;
}
