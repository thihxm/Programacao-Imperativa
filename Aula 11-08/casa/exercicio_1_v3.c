// Elabore um algoritmo que leia um conjunto de números inteiros e somente termine a leitura quando for fornecida uma
// sequência de três números em ordem crescente. Mostre então qual a média deste conjunto de três números

#include <stdio.h>

int main() {
  int tamanhoLista = 3;
  int lista[tamanhoLista];
  int soma = 0, posicao = 0;
  lista[0] = lista[1] = lista[2] = 0;

  while (posicao < tamanhoLista) {
    printf("Insira um número: ");
    scanf("%d", &lista[posicao]);
    if (posicao - 1 > 0 && lista[posicao] < lista[posicao - 1]) {
      soma = lista[0] = lista[posicao];
      posicao = 1;
      lista[1] = lista[2] = 0;
    } else {
      soma += lista[posicao];
      posicao++;
    }
  }

  float media = (float) soma / tamanhoLista;

  printf("Média dos 3 números crescentes: %f\n", media);

  return 0;
}