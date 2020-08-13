#include <stdio.h>

int main() {
  int tamanhoLista = 3;
  int lista[tamanhoLista];
  int soma = 0, qtdAcimaMedia = 0, qtdAbaixoMedia = 0;

  for (int i = 0; i < tamanhoLista; i++) {
    printf("Insira o %d número: ", i + 1);
    scanf("%d", &lista[i]);
    soma += lista[i];
  }

  float media = (float) soma / tamanhoLista;

  for (int i = 0; i < tamanhoLista; i++) {
    int numero = lista[i];

    if (numero > media) {
      qtdAcimaMedia++;
    } else if(numero < media) {
      qtdAbaixoMedia++;
    }

    soma += numero;
  }

  printf("Média: %f\n", media);
  printf("Acima da média: %d\n", qtdAcimaMedia);
  printf("Abaixo da média: %d\n", qtdAbaixoMedia);

  return 0;
}