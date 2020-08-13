#include <stdio.h>
#define TAMANHO_LISTA 10;

int main() {
  int tamanhoLista = TAMANHO_LISTA;
  int lista[tamanhoLista];
  int amplitudeAmostral = 0, valorMinimo = 0, valorMaximo = 0;

  for (int i = 0; i < tamanhoLista; i++) {
    printf("Insira o %d número: ", i + 1);
    scanf("%d", &lista[i]);
    if (i == 0) {
      valorMinimo = lista[i];
    }
  }

  for (int i = 0; i < tamanhoLista; i++) {
    int numero = lista[i];

    if (numero < valorMinimo) {
      valorMinimo = numero;
    } else if(numero > valorMaximo) {
      valorMaximo = numero;
    }
  }

  amplitudeAmostral = valorMaximo - valorMinimo;

  printf("Valor mínimo: %d\n", valorMinimo);
  printf("Valor máximo: %d\n", valorMaximo);
  printf("Amplitude amostral: %d\n", amplitudeAmostral);

  return 0;
}