#include <stdio.h>

void printBomDia() {
  printf("\nOlá, bom dia, tudo bem?\n");
}

void printMensagem(char *mensagem) {
  printf("\n%s\n", mensagem);
}

float scanAltura() {
  float altura;
  printf("\nInsira a sua altura: \n");
  scanf("%f", &altura);
  return altura;
}

float aumentaPorcentagem(float valor, float porcentagem) {
  return valor + (valor * porcentagem / 100);
}

int main() {
  char superMensagem[] = "Está funcionando!";

  printBomDia();
  printMensagem(superMensagem);

  float h = scanAltura();
  printf("A sua altura é %.2f\n", h);
  float novoValor = aumentaPorcentagem(10, 1);
  printf("Seu novo valor é %.2f\n", novoValor);

  return 0;
}