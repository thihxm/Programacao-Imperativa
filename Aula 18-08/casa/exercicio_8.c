// Elabore um programa que leia um vetor de 10 posições reais e que então coloque-o em ordem crescente. Utilize como
// estratégia de ordenação a comparação de pares de elementos adjacentes, permutando-os quando estiverem fora de ordem, até
// que todos estejam ordenados.
// Observação: este método de ordenação é conhecido como “Buble Sort”, método da bolha, ou ordenação por trocas.

#include <stdio.h>

int main() {
  int tamanhoLista = 10;
  float valoresUsuario[tamanhoLista];

  for (int i = 0; i < tamanhoLista; i++) {
    printf("Insira o %d número: ", i + 1);
    scanf("%f", &valoresUsuario[i]);
  }

  for (int i = 1; i < tamanhoLista; i++) {
    for (int j = 0; j < tamanhoLista; j++) {
      if (valoresUsuario[i] < valoresUsuario[j]) {
        float bufferValor = valoresUsuario[i];
        valoresUsuario[i] = valoresUsuario[j];
        valoresUsuario[j] = bufferValor;
      }
    }
  }

  printf("Valores inseridos ordenados: [ ");
  for (int i = 0; i < tamanhoLista; i++) {
    printf("%f ", valoresUsuario[i]);
  }
  printf("]\n");

  return 0;
}