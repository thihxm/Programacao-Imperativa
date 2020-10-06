// Escreva um programa que leia um número inteiro, caso ele esteja dentro do intervalo de 1 a 999, mostre seu valor por
// extenso, caso contrário mostre “valor fornecido fora dos limites operacionais”. Ou seja, se o usuário digitar 158, o programa
// mostra “158: cento e cinquenta e oito”
// DICA: Utilize vetor de strings para representar as unidades (1..9), dezenas especiais (10..19), dezenas gerais (10, 20 etc) e
// centenas (100, 200 etc). Separe, usando mod e div, o valor da unidade, da dezena e da centena do número fornecido e use
// estes valores como índices de consulta aos vetores contendo as strings equivalentes. Serão necessários vários testes para
// verificar o uso da letra “e” entre os valores. Para testar sua implementação, faça uma repetição de 1 a 999, e veja se todos
// estão grafados corretamente.

#include <stdio.h>

int main() {
  char *unidades[] = {"", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
  char *dezenas[] = {"", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
  char *dezenasEspeciais[] = {"", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
  char *centenas[] = {"cem", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
  int numero = 0, unidade, dezena, centena;

  printf("Insira um numero de 1 a 999: ");
  scanf("%d", &numero);

  if (numero < 1 || numero > 999) {
    printf("valor fornecido fora dos limites operacionais\n");
  } else {
    unidade = numero % 10;
    dezena = (numero / 10) % 10;
    centena = numero / 100;

    if (centena) {
      if (centena == 1 && (!dezena && !unidade)) {
        printf("%s", centenas[0]);
      } else {
        printf("%s", centenas[centena]);
      }
      if(dezena || unidade) {
        printf(" e ");
      }
    }
    if (dezena) {
      if (dezena == 1 && (unidade != 0)) {
        printf("%s", dezenasEspeciais[unidade]);
      } else {
        printf("%s", dezenas[dezena]);
        if(unidade) {
          printf(" e ");
        }
      }
    }
    if (unidade) {
      if (dezena != 1) {
        printf("%s", unidades[unidade]);
      }
    }
    printf("\n");
  }

  
  return 0;
}