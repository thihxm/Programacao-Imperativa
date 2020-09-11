// Cálculo dos Dígitos Verificadores do CPF

#include <stdio.h>

int main() {
  int cpf[15], cpfValido[15];
  int *ponteiro = cpf;
  int fator, soma = 0, valido = 0, i;

  for (i = 0; i < 11; i++) {
    printf("Insira o %d digito do cpf: ", i + 1);
    scanf("%d", &cpf[i]);
    if (i <= 8) {
      cpfValido[i] = cpf[i];
    }
  }

  for (fator = 10; fator >= 2; fator--) {
    soma += *ponteiro * fator;
    ponteiro++;
  }

  printf("Soma = %d\n", soma);
  printf("Valor 1º digito = %d\n", *ponteiro);

  if (soma % 11 < 2) {
    cpfValido[9] = 0;
  } else {
    cpfValido[9] = 11 - (soma % 11);
  }

  if (cpfValido[9] == *ponteiro) {
    valido = 1;
  } else {
    valido = 0;
  }
  ponteiro = cpf;
  soma = 0;
  for (fator = 11; fator >= 2; fator--) {
    soma += *ponteiro * fator;
    ponteiro++;
  }

  printf("Soma = %d\n", soma);
  printf("Valor 2º digito = %d\n", *ponteiro);

  if (soma % 11 < 2) {
    cpfValido[9] = 0;
  } else {
    cpfValido[9] = 11 - (soma % 11);
  }

  if (cpfValido[9] == *ponteiro) {
    valido = 1;
  } else {
    valido = 0;
  }

  if (soma % 11 < 2 && *ponteiro == 0) {
    valido = 1;
  } else if (*ponteiro == 11 - (soma % 11)) {
    valido = 1;
  } else {
    valido = 0;
  }

  if (valido) {
    printf("CPF válido\n");
  } else {
    printf("CPF inválido\n");
  }

  printf("CPF digitado -> ");
  for (i = 0; i < 14; i++) {
    printf("%d", cpf[i]);
    if ((i + 1) % 9 == 0) {
      printf("-");
    } else if ((i + 1) % 3 == 0) {
      printf(".");
    }
  }
  printf("\nCPF válido -> ");
  for (i = 0; i < 14; i++) {
    printf("%d", cpfValido[i]);
    if ((i + 1) % 9 == 0) {
      printf("-");
    } else if ((i + 1) % 3 == 0) {
      printf(".");
    }
  }
  printf("\n");
  
  return 0;
}