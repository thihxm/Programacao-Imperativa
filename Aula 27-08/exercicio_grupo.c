// Elabore um programa que preeencha uma matriz quadrada (4x4) de números inteiros
// aleatórios (1 a 100), garantindo que não haverá nenhuma repetição
// (os 16 números devem ser únicos).

#define TAM 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matriz[TAM][TAM];
  int igual = 0;
  int aux = 0;

  srand(time(NULL));

  for (int *i = &matriz[0][0]; i < &matriz[TAM][TAM]; i++) {
    aux = 1 + rand() % 100;
    for (int *j = &matriz[0][0]; j < i; j++) {
      if (*j == aux) {
        igual = 1;
      }
    }
    if (!igual) {
      *i = aux;
    } else {
      i--;
    }
    igual = 0;
  }

  for (int i = 0; i < TAM; i++) {
    printf("[ ");
    for (int j = 0; j < TAM; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("]\n");
  }
  printf("\n");
  
  return 0;
}