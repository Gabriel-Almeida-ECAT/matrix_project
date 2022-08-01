#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include "structure.h"


int input_matrix(struct matrix *mat){
	mat->flagHaveValues = 1;
	
	fflush(stdin);
	printf("\tNumber rows := ");
	scanf("%d", &mat->rows);
	
	fflush(stdin);	
	printf("\tNumber colums := ");
	scanf("%d", &mat->cols);
	
	int matSize[2] = {mat->rows, mat->cols}; 
	
	mat->values = calloc((mat->cols)*(mat->rows), sizeof(double));
	
	int i, j;
	puts("");
	for(i=0; i<mat->rows; i++){
		for(j=0; j<mat->cols; j++){
			printf("\ti%dj%d := ", i+1, j+1);
			scanf("%lf", (mat->values + (i * mat->cols) + j) );
		}
	}
	
	/*free(mat->values);*/
}

void print_matrix(struct matrix *mat){
	if(mat->flagHaveValues){
		puts("");
		int i, j, numRows = mat->rows, numCols = mat->cols;
		for(i=0; i<numRows; i++){
			printf("| ");
			for(j=0; j<numCols; j++){
				printf(" %6.3lf ", *(mat->values + ( i * numCols) + j));
			}
			printf("  |");
			printf("\n\n");
		}
	}
	else printf(" empty.\n\n");
}

/*Soma de matrizes*/
void sum_matrix(int qtdMatrix, int sizeRows, int sizeCols, struct matrix matValues[], struct matrix *matResult){
	int iterValues, iterMat;
	int qtdValues = sizeRows * sizeCols;
	//puts("in func sum");
	for(iterValues=0; iterValues<qtdValues; iterValues++){
		//puts("in loop itervalues");
		for(iterMat=0; iterMat<qtdMatrix; iterMat++){
			//puts("in loop itermat");
			//print_matrix(&matValues[iterMat]);
			//printf(" %lf ", matValues[iterMat].values[iterValues]);
			if(!iterMat) matResult->values[iterValues] = matValues[iterMat].values[iterValues];
			else matResult->values[iterValues] += matValues[iterMat].values[iterValues];
		}
	}
	matResult->flagHaveValues = 1;
}

//void matrix_sum(struct matrix mat1, struct matrix mat2, struct matrix metRes){
//		
//}

/*Calculo determinante de uma matriz -> tem que ajusatr essa funÁ„o pra funcionar com as structs*/ 
double matrix_det(double *mat, int ord){
	int ind, i, j;
	double det=0, *mat2;

	mat2 = calloc(ord*ord, sizeof(double));
	
	if(ord == 1) return *mat;
	if(ord == 2) return (*(mat+0)) * (*(mat+3)) - (*(mat+1)) * (*(mat+2));
	
	for(ind=0; ind<ord; ind++){
		int i2=0, j2=0;
		for(i=1; i<ord; i++){ /*i=1 for skipping the first line, index 0*/
			j2 = 0;
			for(j=0; j<ord; j++){
				if(j==ind) continue; 						/*skipping the current collum -> mat2 recives a matriz of 'ord-1' order*/
				*(mat2+(i2*(ord-1))+j2) = *(mat+(i*ord)+j); /*atribuiÁ„o de mat2 -> n√£o posso utilizar i e j para a mesma*/
				j2 += 1;									/*Pois sen„o ira pular as linhas e colunas dela tamb√©m.*/
			}
			i2 += 1;
		}
		//print_matrix(mat2, ord-1, ord-1);
		det += pow(-1, ind) * (*(mat+ind)) * matrix_det(mat2, ord-1);
	}
	free(mat2);
	return det;
}

int input_SN(){
	char ch = 'a';
	
	while(ch!='S' && ch!='N'){
		fflush(stdin);
		ch = getchar();
		ch = toupper(ch);
		if(ch!='S' && ch!='N'){
			puts("\nEntrada invalida.");
			ch = getchar();
			ch = 'a';
		} 
		if(ch=='N') return 0;
		else if(ch=='S') return 1;
	}
}

