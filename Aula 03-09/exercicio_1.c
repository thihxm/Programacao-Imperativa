// Preencher um vetor com 10 números aleatorios de 10 a 20
// Mostrar a soma do vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int randInt(int minimo, int maximo) {
  if (minimo > maximo) {
    int aux = minimo;
    minimo = maximo;
    maximo = aux;
  }
  return minimo + rand() % (maximo - minimo + 1);
}

int sum(int *vetor, int tamanho) {
  int soma = 0;
  int *i;
  for (i = vetor; i <= &vetor[tamanho - 1]; i++) {
    soma += *i;
  }
  return soma;
}

int main() {
  srand(time(NULL));
  int vetor[TAM], i;

  for (i = 0; i < TAM; i++) {
    vetor[i] = randInt(10, 20);
  }

  printf("[ ");
  for (i = 0; i < TAM; i++) {
    printf("%d ", vetor[i]);
  }
  printf("]\n");
  printf("Soma do vetor = %d\n", sum(vetor, TAM));

  return 0;
}