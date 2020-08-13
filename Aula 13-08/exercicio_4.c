// Escreva um programa que leia um vetor de números inteiros de 10 posições, aceitando apenas valores positivos. Modifique
// então o vetor de forma que tenhamos primeiro todos os números pares, depois, os números ímpares. Mostre o vetor antes e
// depois da modificação.

#include <stdio.h>

int main() {
  int tamanhoLista = 10, aux = 0, qtdImpares = 0;
  int valoresUsuario[tamanhoLista], valoresOrdenados[tamanhoLista];

  while(aux < tamanhoLista) {
    int valor = 0;
    printf("Insira o %d número: ", aux + 1);
    scanf("%d", &valor);
    if (valor > 0) {
      valoresUsuario[aux] = valor;
      aux++;
      if (valor % 2 == 1) {
        qtdImpares++;
      }
    }
  }

  int auxPar = 0, auxImpar = tamanhoLista - qtdImpares;
  for (int i = 0; i < tamanhoLista; i++) {
    int numero = valoresUsuario[i];
    if (numero % 2 == 0) {
      valoresOrdenados[auxPar] = numero;
      auxPar++;
    } else {
      valoresOrdenados[auxImpar] = numero;
      auxImpar++;
    }
  }

  printf("Valores inseridos: [ ");
  for (int i = 0; i < tamanhoLista; i++) {
    printf("%d ", valoresUsuario[i]);
  }
  printf("]\n");

  printf("Valores inseridos ordenados: [ ");
  for (int i = 0; i < tamanhoLista; i++) {
    printf("%d ", valoresOrdenados[i]);
  }
  printf("]\n");

  return 0;
}