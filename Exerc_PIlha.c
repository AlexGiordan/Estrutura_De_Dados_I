#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaximoLetras 255

int ObterDeLetrasDigitas(char Texto[NumeroMaximoLetras]);
char *Push(char *Pilha, char Texto[255], int QuantidadeDeNodos);
char *Pop(char *Pilha, int QuantidadeDeNodos);
void ImprimirPilha(char *Ponteiro, int QuantidadeDeNodos);
void LiberaMemoria(void *Ponteiro);
char *AlocarMemoria(char *Ponteiro, int QuantidadeDeNodos);

int main(){
  char Texto[NumeroMaximoLetras];
  int NumeroTotalDeNodos;
  char *TextoOriginal;
  char *TextoDesempilhado;

  TextoOriginal     = NULL;
  TextoDesempilhado = NULL;

  fflush(stdin);

  printf("Informe um texto com no maximo 255 caracteres,\n");
  printf("este texto sera lido e armezado em uma pilha.\n");
  printf("O resultado final sera uma pilha impressa na tela\n");
  printf("com seu texto, note que seu texto estara impresso invertido\n");
  printf("devido a logica de pilhas(LIFO).\n");
  fgets(Texto, NumeroMaximoLetras, stdin);

  NumeroTotalDeNodos = ObterDeLetrasDigitas(Texto);

  if(NumeroTotalDeNodos >= (NumeroMaximoLetras - 1)){
    printf("\nSeu texto é maior do que o permitido...");
    printf("\nA aplicação será finalizada....");
    exit(1);
  }else{
    TextoOriginal = AlocarMemoria(TextoOriginal, NumeroTotalDeNodos);

    if(TextoOriginal == NULL)
      exit(1);
    else{
      printf("\nAplicando texto na pilha....\n");
      TextoOriginal = Push(TextoOriginal, Texto, NumeroTotalDeNodos);
      printf("Texto empilhado....\n\n");

      TextoDesempilhado = AlocarMemoria(TextoDesempilhado, NumeroTotalDeNodos);

      if(TextoDesempilhado == NULL)
	exit(1);
      else{
	printf("Desempilhado texto da pilha....\n");
	TextoDesempilhado = Pop(TextoOriginal, NumeroTotalDeNodos);

	printf("Texto desempilhado....\n");
	ImprimirPilha(TextoDesempilhado, NumeroTotalDeNodos);
      }
    }
  }

  LiberaMemoria(TextoOriginal);
  LiberaMemoria(TextoDesempilhado);

  return 0;
}

int ObterDeLetrasDigitas(char Texto[255])
{
  int x;
  int NumeroDaCaracteresDigitados;
  NumeroDaCaracteresDigitados = 0;
  x = 0;

  while(Texto[x] != '\0'){
    NumeroDaCaracteresDigitados++;
    x++;
  }

  return NumeroDaCaracteresDigitados;
}

char *Push(char *Pilha, char Texto[255], int QuantidadeDeNodos)
{
  int i;

  for(i=0;i<QuantidadeDeNodos;i++)
    Pilha[i] = Texto[i];

  return Pilha;
}

char *Pop(char *Pilha, int QuantidadeDeNodos)
{
  char *PilhaInversa;
  int i, j;

  j = QuantidadeDeNodos;

  PilhaInversa = NULL;

  PilhaInversa = AlocarMemoria(PilhaInversa, QuantidadeDeNodos);

  if(PilhaInversa == NULL)
    return PilhaInversa = NULL;
  else{
    for(i=0;i<QuantidadeDeNodos;i++){
      PilhaInversa[j-1] = Pilha[i];
      j--;
    }

    return PilhaInversa;
  }
}

void LiberaMemoria(void *Ponteiro)
{
  free(Ponteiro);
}

void ImprimirPilha(char *Ponteiro, int QuantidadeDeNodos)
{
  int i;

  for(i=0;i<QuantidadeDeNodos;i++)
    printf("%c",Ponteiro[i]);

  printf("\n\n");
}

char *AlocarMemoria(char *ponteiro, int QuantidadeDeNodos)
{
  ponteiro = malloc(QuantidadeDeNodos * sizeof(char *));

  if(ponteiro == NULL)
    printf("\nNão foi possivel alocar a memoria necessaria....");

  return ponteiro;
}
