#include <stdio.h>

int main() {
  int tamanhoLista = 3;
  int lista[tamanhoLista];
  int soma = 0, posicao = 0;
  lista[0] = lista[1] = lista[2] = 0;

  while (1 == 1) {
    if (posicao >= 3) break;

    printf("Insira um número: ");
    scanf("%d", &lista[posicao]);
    if (posicao == 2) {
      if (lista[0] < lista[1] && lista[1] < lista[2]) {
        break;
      } else {
        posicao = 0;
        lista[0] = lista[1] = lista[2] = 0;
        continue;
      }
    }
    posicao++;
  }

  for (int i = 0; i < tamanhoLista; i++) {
    soma += lista[i];
  }

  float media = (float) soma / tamanhoLista;

  printf("Média dos 3 números crescentes: %f\n", media);

  return 0;
}