#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

struct matrix{
	int rows;
	int cols;
	int flagHaveValues;
	int flagSquare;
	double *values;
};

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

//void save_in_matMemory(){
//	fazer a alocação do espaço da matriz memória aqui.
//}

//void matrix_sum(struct matrix mat1, struct matrix mat2, struct matrix metRes){
//		
//}

float matrix_det(double *mat, int ord){
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
				*(mat2+(i2*(ord-1))+j2) = *(mat+(i*ord)+j); /*atribuição de mat2 -> não posso utilizar i e j para a mesma*/
				j2 += 1;									/*Pois senão ira pular as linhas e colunas dela também.*/
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

