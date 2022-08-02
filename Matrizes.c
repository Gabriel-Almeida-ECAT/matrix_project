/*- Autor: Gabriel Almeida - ECAT_IFAM - CMDI - mar 2022*/
/* Programa de Operações de Matrizes*/

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
		puts("-= Algoritmo de operacoes Matriciais =-\n");
		puts("E possivel com esse programa fazer leitura e operacoes");
		puts("basicas com matrizes como soma multriplicao, calculo do");
		puts("determinante etc. Ficara disponivel ao final de toda operacoes");
		puts("uma opcao de salvar a matriz em mamoria (enquanto aberto o programa),");	
		puts("possibilitando multiplas operacoes seguidas com a mesma matriz.\n");
		puts("-------------------------------------------------\n");
		
		puts("# Matriz em memoria =  ");
		print_matrix(&matMemory);
		
		do{
			puts("|| MENU SELECAO - Digite a operacao deseja ||\n");
			puts("[1] - Leitura Matriz Memoria / Info."); /*Mostar a atual matriz salva e perguntar se deseja sobreescrever*/
			puts("[2] - Soma de Matrizes.");
			puts("[3] - Multiplicao por escalar.");
			puts("[4] - Multiplicao de Matrizes.");
			puts("[5] - Determinante");
			puts("[6] - Matriz Transposta.");
			puts("[7] - Matriz Inversa.");
			puts("[8] - Matriz Adjunta");
			puts("[9] - Resolucao de Sistemas");
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
				printf("\n=| Leitura Matriz Memoria | Info. |=\n\n");
				
				//int numRows = matMemory.rows, numCols = matMemory.cols;
				input_matrix(&matMemory);
				
				puts("#Matriz em memoria = ");
				print_matrix(&matMemory);
				
				puts("\nPressione enter para continuar.");
				fflush(stdin);
				while(getch() != '\r');
			break;

			case 2: /*=| Soma Matrizes |=*/
				{
					printf("\n=| Soma Matrizes |=\n\n");
					printf("#Quantidade de matrizes para somar: ");
					int qtdM, ind, key=1, keyMemo=1;
					scanf("%d", &qtdM);
					
					struct matrix matResult, matSoma[qtdM];
					matResult.flagHaveValues = 0;
					
					for(ind=0; ind<qtdM; ind++){
						printf("\n= Matriz %i:\n", ind + 1);
						
						printf("\tUsar matriz em memoria [S/N]: ");
						if(input_SN()){
							if(matMemory.flagHaveValues){
								matSoma[ind] = matMemory; /*this will bee a shallow copy, think there is no problem, think...*/
								keyMemo = 0;						
							}
							else{
								puts("\n\t=> Matriz em memoria nao possui nenhum valor!");
								key = 0;
								break;
							}					
						}
						else{
							if(!ind)
								input_matrix(matSoma + ind);
							else{
								input_matrix(matSoma + ind);
								if(matSoma[ind].rows != matSoma[ind-1].rows || matSoma[ind].cols != matSoma[ind-1].cols){
									puts("\nResultado = Idefinido.");
									key = 0;
									break;
								} 
							}
						}
						//print_matrix(&matSoma[ind]);
					}
					
					matResult.rows = matSoma[0].rows;
					matResult.cols = matSoma[0].cols;
					
					if(key) sum_matrix(qtdM, matSoma[0].rows, matSoma[0].cols, &matSoma, &matResult);
					puts("\n#Matriz resultado = ");
					print_matrix(&matResult);
					
					printf("Salvar a matriz resultado em memoria [S/N]: "); /*criar func disso*/
					if(input_SN()){
						matMemory.cols = matResult.cols;
						matMemory.rows = matResult.rows;
						int i, j;
						for(i=0; i<matResult.rows; i++){
							for(i=0; i<matResult.cols; i++){
								inputValueMatrix(getValueMatrix(&matResult, i, j), &matMemory, i, j);
							}
						}
					}
					
					if(key && keyMemo){ /*precisa da keymemo pois a atribuição da matriz memoria é uma shallowcopy*/
						for(ind=0; ind<qtdM; ind++) free(matSoma[ind].values);
						free(matResult.values);
					}
						
					puts("\nPressione enter para continuar.");
					fflush(stdin);
					while(getch() != '\r');
				}
			break;
//
//			case 3: /*=| Mutiplicação por escalar |=*/
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
					
//					puts("Gostaria de salvar a matriz em memÃ³ria?[S/N]: ");
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



