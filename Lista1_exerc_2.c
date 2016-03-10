#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* ConstruirVetor(int *Vetor, int Capacidade);
void ImprimirVetor(int *Vetor, int Capacidade);
int* uniao(int *v1, int n1, int *v2, int n2);

int main()
{
    int *PrimeiroVetor, *SegundoVetor, *TerceiroVetor; 
    int NumeroPosicoesPrimeiroVetor, NumeroPosicoesSegundoVetor;
    
    srand(time(NULL));
    PrimeiroVetor = NULL;
    SegundoVetor  = NULL;
    TerceiroVetor = NULL;
    
    printf("Informe o número de posições para o Primeiro Vetor: ");
    NumeroPosicoesPrimeiroVetor = 1 + rand() % 10;
    printf("%d ",NumeroPosicoesPrimeiroVetor);
    printf("\nConstruindo Vetor....\n");
    PrimeiroVetor = ConstruirVetor(PrimeiroVetor, NumeroPosicoesPrimeiroVetor);
    printf("Valores do Primeiro Vetor...\n");
    ImprimirVetor(PrimeiroVetor, NumeroPosicoesPrimeiroVetor);    
    
    printf("\n\nInforme o número de posições para o Segundo Vetor: ");
    NumeroPosicoesSegundoVetor = 1 + rand() % 10;
    printf("%d ",NumeroPosicoesSegundoVetor); 
    printf("\nConstruindo Vetor....\n");
    SegundoVetor = ConstruirVetor(SegundoVetor, NumeroPosicoesSegundoVetor);
    printf("Valores do Primeiro Vetor...\n");
    ImprimirVetor(SegundoVetor, NumeroPosicoesSegundoVetor);     
       
    printf("\n\nOs Vetores seram unidos neste momento, ");
    printf("dando origem a um Terceiro vetor com %d posicoes.\n", NumeroPosicoesPrimeiroVetor + NumeroPosicoesSegundoVetor);
    printf("O número de posições do Terceiro Vetor é a soma das posições do Primeiro com o Segundo Vetor, \n");
    printf("seguindo esta mesma ordem para os valores, Primeiro Vetor e depois Segundo Vetor.\n");
    printf("\nConstruindo Vetor....\n");
    TerceiroVetor = uniao(PrimeiroVetor, NumeroPosicoesPrimeiroVetor ,SegundoVetor, NumeroPosicoesSegundoVetor);
    printf("VALORES DO NOVO TERCEIRO VETOR:\n");
    ImprimirVetor(TerceiroVetor, (NumeroPosicoesPrimeiroVetor + NumeroPosicoesSegundoVetor));   
    
    free(PrimeiroVetor);
    free(SegundoVetor); 
    free(TerceiroVetor); 
    
    printf("\n\nFinalizando aplicação......\n"); 
    return 0;
} 


int* ConstruirVetor(int *Vetor, int Capacidade)
{
	int Posicao;
	Vetor = malloc(Capacidade * sizeof(int *));
	
	if (Vetor == NULL)
	{
		printf("\nOut of memory...");
	}
	else
	{
		for (Posicao = 0; Posicao < Capacidade; Posicao++)
			Vetor[Posicao] = 1 + rand() % 100;
	
	}
	
	return Vetor;
}

void ImprimirVetor(int *Vetor, int Capacidade)
{
	int Posicao;
	
	for (Posicao = 0; Posicao < Capacidade; Posicao++)
		printf("|%d|", Vetor[Posicao]);
	
}

int* uniao(int *v1, int n1, int *v2, int n2)
{
	int *TerceiroVetor;
	int Posicao, CapacidadeVetorNovo, CapacidadePrimeiroVetor, CapacidadeSegundoVetor;
	
	CapacidadePrimeiroVetor = n1;
	CapacidadeSegundoVetor  = n2;
	CapacidadeVetorNovo     = (CapacidadePrimeiroVetor + CapacidadeSegundoVetor);
	
	TerceiroVetor = malloc(CapacidadeVetorNovo * sizeof(int *));
	
    if (TerceiroVetor == NULL) 
    {
        printf("\nOut of memory...");
    } 
    else 
    {
        for(Posicao = 0; Posicao < CapacidadePrimeiroVetor; Posicao++)
            TerceiroVetor[Posicao] = v1[Posicao];

        for(Posicao = 0; Posicao < CapacidadeSegundoVetor; Posicao++) 
            TerceiroVetor[Posicao + CapacidadePrimeiroVetor] = v2[Posicao];
        
    }			
	
	return TerceiroVetor;
}
