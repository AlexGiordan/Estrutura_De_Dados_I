#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	int *Vetor;
	int Default_Alocacao, Default_Vetor, ValorDeEntrada, ValorParaVerificacao, Posicao, Sair, NumeroDeRegistro;
	Sair = 0;
	Default_Alocacao = Default_Vetor = 5;
	NumeroDeRegistro = 0;
	
	printf("Digite uma letra para sair do programa ou inteiros para continuar entrando com valores...");
	
	Vetor = malloc(Default_Alocacao * sizeof (int *)); //Alocando memoria
	if (Vetor == NULL)
	{
		printf("Out of memory...");
		return 0;
	}
	
	printf("\n");
	
	do{
		for (Posicao = 0; Posicao <= Default_Vetor; Posicao++)
		{
			printf("Digite o valor desejado para a posição %d: ", Posicao + 1); //Preenche as posições
			ValorParaVerificacao = scanf("%d", &ValorDeEntrada);			
		
			if (ValorParaVerificacao == 0) //Verifica se foi digitado um número
			{
				printf("\nVocê escolheu finalizar o programa...");
				Sair = 1;
				break;
			}
			else
			{
				if (Posicao == Default_Vetor) // Verifica se necessario a realocação
				{
					Default_Vetor = Default_Vetor + Default_Alocacao;
					
					Vetor = realloc(Vetor, Default_Vetor * sizeof(int *)); //Realocando memoria
					
					if (Vetor == NULL)
					{
						printf("Out of memory...");
						return 0;
					}
				}
				Vetor[Posicao] = ValorDeEntrada;
				NumeroDeRegistro++;
			}
		}			
	}while (Sair == 0);	
	
	printf("\nRESUMO DE INFORMAÇÕES\n");
	printf("FORAM INSERIDOS %d VALORES:\n", NumeroDeRegistro);
	printf("ABAIXO ESTA A LISTA DO VALORES:\n");
	
	for (Posicao = 0; Posicao < NumeroDeRegistro; Posicao++)
	{
		printf("POSIÇÃO %d VALOR > %d\n", Posicao + 1, Vetor[Posicao]); //Imprime os números coletados
	}
	
  free(Vetor);
  return 0;
}
