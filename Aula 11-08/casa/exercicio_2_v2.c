#include <stdio.h>

int main() {
  int qtdNumeros = 3, soma = 0, ultimoValor = 0, aux = 0;

  while (aux < qtdNumeros) {
    int valor = 0;
    printf("Insira um número: ");
    scanf("%d", &valor);

    if (aux == 0) {
      ultimoValor = valor;
      soma += valor;
      aux++;
      continue;
    }

    if (valor > ultimoValor) {
      soma += valor;
      aux++;
    } else {
      aux = 0;
      soma = 0;
    }
  }

  float media = (float) soma / qtdNumeros;

  printf("Média dos 3 números crescentes: %f\n", media);

  return 0;
}