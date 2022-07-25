#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "structure.h"

void input_matrix(struct matrix *mat){
	mat->flagHaveValues = 1;
	
	int n;
	fflush(stdin);
	printf("\nNumber rows := ");
	scanf("%d", &n);
	mat->rows = n;
	
	fflush(stdin);	
	printf("Number colums := ");
	scanf("%d", &mat->cols);
	
	/*Deixar a alocação para ser feita na chamada da função em main*/
	mat->values = calloc((mat->cols)*(mat->rows), sizeof(double));
	
	int i, j;
	puts("");
	for(i=0; i<mat->rows; i++){
		for(j=0; j<mat->cols; j++){
			printf("i%dj%d := ", i+1, j+1);
			scanf("%lf", (mat->values + (i * mat->cols) + j) );
		}
	}
	
	//free(mat->values);
}

void print_matrix(double *values, int numRows, int numCols){
	puts("");
//	printf("\nNumber rows = %d\n", numRows);
//	printf("Number colums = %d\n\n", numCols);
	int i, j;
	for(i=0; i<numRows; i++){
		printf("| ");
		for(j=0; j<numCols; j++){
			printf(" %6.3lf ", *(values + ( i * numCols) + j));
		}
		printf("  |");
		printf("\n\n");
	}
}

float matrix_det(double *mat, int ord){
	int ind, i, j;
	double det=0, *mat2;
	
//	if(mat.cols != mat.rows){
//		puts("Matriz invalida");
//		return -1;
//	}

	mat2 = calloc(ord*ord, sizeof(double));
	
	if(ord == 1) return *mat;
	if(ord == 2) return (*(mat+0)) * (*(mat+3)) - (*(mat+1)) * (*(mat+2));
	
	for(ind=0; ind<ord; ind++){
		int i2=0, j2=0;
		for(i=1; i<ord; i++){ /*i=1 for skipping the first line, index 0*/
			j2 = 0;
			for(j=0; j<ord; j++){
				if(j==ind) continue;
				*(mat2+(i2*(ord-1))+j2) = *(mat+(i*ord)+j);
				j2 += 1;								
			}
			i2 += 1;
		}
		print_matrix(mat2, ord-1, ord-1);
		det += pow(-1, ind) * (*(mat+ind)) * matrix_det(mat2, ord-1);
	}
	free(mat2);
	return det;
}

int main(){
	struct matrix mat1, *matp1, *matp2;
	
	input_matrix(&mat1);

	print_matrix(mat1.values, mat1.rows, mat1.cols);
	
	printf("\n Dentro da det func: \n");
	printf("\n\n#Determinante = %.4lf", matrix_det(mat1.values, mat1.cols));

	free(matp1);
	return 0;
}
