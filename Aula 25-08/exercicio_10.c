// Escreva um programa que leia uma matriz (4x4) de números inteiros. Modifique então a matriz de forma que, caminhando
// da esquerda para a direita, de cima para baixo, tenhamos primeiro todos os números pares, depois, os números impares. Mostre
// a matriz antes e depois da modificação.

#define TAM 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matriz[TAM][TAM];
  int *esquerda = &matriz[0][0], *direita = &matriz[TAM][TAM];
  int impar = 0, par = 0;
  int aux = 0;

  srand(time(NULL));

  for (int i = 0; i < TAM; i++) {
    printf("[ ");
    for (int j = 0; j < TAM; j++) {
      matriz[i][j] = 1 + rand() % 100;
      printf("%d ", matriz[i][j]);
    }
    printf("]\n");
  }

  do {
    if (*esquerda % 2 != 0) {
      impar = 1;
    } else {
      esquerda++;
    }
    if (*direita % 2 == 0) {
      par = 1;
    } else {
      direita--;
    }
    if (impar && par) {
      aux = *esquerda;
      *esquerda = *direita;
      *direita = aux;
      impar = 0;
      par = 0;
      esquerda++;
      direita--;
    }
  } while(esquerda < direita);

  printf("-------------\n");
  for (int i = 0; i < TAM; i++) {
    printf("[ ");
    for (int j = 0; j < TAM; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("]\n");
  }
  
  return 0;
}