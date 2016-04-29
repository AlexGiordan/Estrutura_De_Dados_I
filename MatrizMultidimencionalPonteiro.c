#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//tetekllllllllllllllll
int main(void){
	//Variaveis
	int **Matriz;
	int Linhas, Colunas, i, j, NumeroTotalCampos;
	srand(time(NULL));
	NumeroTotalCampos = 0;

	printf("\nPrograma para preencher uma matriz multidimencional implemantada com ponteiros...\n\n");
	
	printf("Digite o número de linhas desejado para a matriz:\t");
	Linhas = 1 + rand() % 100; //Determinando o número de linhas da matriz
	printf("%d\n", Linhas);
	
	Matriz = malloc(Linhas * sizeof(int *)); //Alocando memoria para as linhas
	
	if (Matriz == NULL)
		printf("Out of Memory.....");
	
	for (i = 0; i < Linhas; i++)
	{
		printf("Informe o número de colunas desejado:\t");
		Colunas = 1 + rand() % 5; //Determinando o número de colunas da matriz
		printf("%d\n", Colunas);

		Matriz[i] = malloc(Colunas * sizeof(int *)); //Alocando memoria para as colunas
		
		for (j = 0; j < Colunas; j++){
			Matriz[i][j] = -1;
			Matriz[i][j] = rand() % 100;
			NumeroTotalCampos++;
		}
	}
	
	
	for (i = 0; i < Linhas; i++) //Imprimindo a Matriz
	{
		printf("\nEndereço da linha %d : %p ", i, &Matriz[i]);
		printf("valores -> ");
		
		for (j = 0; Matriz[i][j] > 0; j++)
			printf("%d\t",Matriz[i][j]);
	}
	
	printf("\n\nNÚMERO TOTAL DE ELEMENTOS NA MATRIZ: - > %d", NumeroTotalCampos);
	
	printf("\nLiberando Memoria.....");
	
	free(Matriz);
	
	return 0; 
}
