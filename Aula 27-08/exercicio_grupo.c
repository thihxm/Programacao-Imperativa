// Elabore um programa que preeencha uma matriz quadrada (4x4) de números inteiros
// aleatórios (1 a 100), garantindo que não haverá nenhuma repetição
// (os 16 números devem ser únicos).

#define TAM 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matriz[TAM][TAM];
  int igual, *i, *j;
  int a, b;
  
  srand(time(NULL));

  for (i = matriz; i <= &matriz[TAM - 1][TAM - 1]; i++) {
    *i = 1 + rand() % 16;
    igual = 0;
    for (j = matriz; j < i; j++) {
      if (*j == *i) {
        igual = 1;
      }
    }
    if (igual) {
      i--;
    }
  }

  for (a = 0; a < TAM; a++) {
    printf("[ ");
    for (b = 0; b < TAM; b++) {
      printf("%3d ", matriz[a][b]);
    }
    printf("]\n");
  }
  printf("\n");
  
  return 0;
}