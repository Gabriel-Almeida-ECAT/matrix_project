/* Programa de Operação de Matrizes
- Autor: Gabriel Almeida - ECAT_IFAM - CMDI - mar 2022*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include "mat_funcs.h"


void main(void){
	
	char ch[3], str[3], ch12[3]="12", ch0[3]="0";
	int i, j, n=3, key=1, cin;
	struct matrix matMemory;
	matMemory.flagHaveValues = 0;
	
	for(;;){
		puts("-------------------------------------------------\n");
		puts("-= Algoritmo de Operações Matriciais =-\n");
		puts("É possivel com esse programa fazer leitura e operações");
		puts("basicas com matrizes como soma multriplicação, cálculo do");
		puts("determinante etc. Ficara disponivel ao final de toda operação");
		puts("uma opcao de salvar a matriz em mamória (enquanto aberto o programa),");	
		puts("possibilitando multiplas operações seguidas com a mesma matriz.\n");
		puts("-------------------------------------------------\n");
		
		/*Na função de atribuição da matrixMemoria fazer a alocação*/
		puts("Matriz em memoria: ");
		if(matMemory.flagHaveValues){
			for(i=0; i<matMemory.rows ; i++){
				printf("| ");
				for(j=0; i<matMemory.cols; i++){
					printf(" %d ", *(matMemory.values + ( i * matMemory.rows) + j));	
				}
				printf(" |");
				printf("\n");
			}
		}
		else printf(" empty.\n\n");
		
		do{
			puts("|| MENU SELECAO - Digite a operacao deseja ||\n");
			puts("[1] - Leitura Matriz Memória / Info."); /*Mostar a atual matriz salva e perguntar se deseja sobreescrever*/
			puts("[2] - Soma de Matrizes.");
			puts("[3] - Multiplicação / Divisão por escalar.");
			puts("[4] - Multiplicação de Matrizes.");
			puts("[5] - Determinante");
			puts("[6] - Matriz Transposta.");
			puts("[7] - Matriz Inversa.");
			puts("[8] - Matriz Adjunta");
			puts("[9] - Resolução de Sistemas");
			puts("[10] - [...]");
			puts("[11] - retirar-se");
			printf("\n= Selecao: ");
			fflush(stdin);
			gets(ch);
			int key2=1;
			
			for(i=0;i<strlen(ch);i++){
				if(!isdigit(ch[i])){
					key2=0;
					break;
				}
			}
			
			cin = atoi(ch);
						
			if( key2 && cin > atoi(ch0) && cin < atoi(ch12) ){
				key = 0;
			} else{
				printf("\n\n- Valor Invalido! - Selecione um numero de 1 a 11.\n\n");
			}
		}while(key);
		
	
		/*printf("\n%d\n", cin);*/
		switch(cin){
			case 1: /*-=| Leitura Matriz Memoria / Info. |=-*/
				printf("\n=| Leitura Matriz Memória | Info. |=\n\n");
				
				//int numRows = matMemory.rows, numCols = matMemory.cols;
				input_matrix(&matMemory);
				
				print_matrix(matMemory.values, matMemory.rows, matMemory.cols);
				
				free(matMemory.values);
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			break;
//
//			case 2: /*=|  |=*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;
//
//			case 3: /*=|  |=*/
//				printf("\n=|  |=\n\n");
//
//				
//				puts("\nPressione enter para continuar.");
//				fflush(stdin);
//				while(getch() != '\r');
//			break;
//			
//			case 4: /*=|  |=*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;

			case 5: /*=| DETERMINANTE |=*/
				{
					printf("\n=| DETERMINANTE |=\n");
					struct matrix mat1;
					
					puts("Digite a Matriz: ");
					input_matrix(&mat1);
					
					if(mat1.cols != mat1.rows) puts("Matriz invalida!");
					else printf("\n# Determinante = %.4lf", matrix_det(mat1.values, mat1.cols));
					
//					puts("Gostaria de salvar a matriz em memória?[S/N]: ");
//					if(input_SN) save_in_matMemory(mat1.values);
	
					free(mat1.values);
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;

//			case 6: /*=|  |=*/
//				{
//					printf("\n=|  |=\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;
//
//			case 7: /*-=|  |=-*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;
//
//			case 8: /*-=|  |=-*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;
//
//			case 9: /*-=|  |=-*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;
//			
//			case 10: /*-=|  |=-*/
//				{
//					printf("\n=|  |=\n\n");
//					
//					
//					puts("\nPressione enter para continuar.");
//					fflush(stdin);
//					while(getch() != '\r');
//				}
//			break;			

			case 11: /*-=| EXIT |=-*/
				printf("Saindo.");
				free(matMemory.values);
				exit(1);
			break;
		}
		system("cls");
	}
	
}



