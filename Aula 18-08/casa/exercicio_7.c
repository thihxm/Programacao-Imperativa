// Desenvolva um programa que leia um vetor de 20 posições inteiras e o coloque em ordem crescente, utilizando a seguinte
// estratégia de ordenação:
// • selecione o elemento do vetor de 20 posições que apresenta o menor valor;
// • troque este elemento pelo primeiro;
// • repita estas operações, envolvendo agora apenas os 19 elementos restantes (trocando o de menor valor com a segunda
// posição), depois os 18 elementos (trocando o de menor valor com a terceira posição), depois os 17, 16 e assim por diante,
// até restar um único elemento, o maior deles.
// Observação: este método de ordenação é conhecido como “Seleção Direta”.

#define TAM 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int posMenorValor = 0;
  int valoresUsuario[TAM];

  srand(time(NULL));

  for (int i = 0; i < TAM; i++) {
    // printf("Insira o %d número: ", i + 1);
    valoresUsuario[i] = rand() % 100;
    // scanf("%d", &valoresUsuario[i]);
  }

  for (int i = 0; i < TAM - 1; i++) {
    posMenorValor = i;
    for (int j = i + 1; j < TAM; j++) {
      if (valoresUsuario[j] < valoresUsuario[posMenorValor]) {
        posMenorValor = j;
      }
    }
    int bufferValor = valoresUsuario[i];
    valoresUsuario[i] = valoresUsuario[posMenorValor];
    valoresUsuario[posMenorValor] = bufferValor;
  }

  printf("Valores inseridos ordenados: [ ");
  for (int i = 0; i < TAM; i++) {
    printf("%d ", valoresUsuario[i]);
  }
  printf("]\n");

  return 0;
}