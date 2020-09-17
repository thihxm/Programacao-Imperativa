// Cálculo dos Dígitos Verificadores do CPF
#define TAM_CPF 11
#include <stdio.h>
#include <string.h>

void imprimirLinha(tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("-");
  }
  printf("\n");
}

int main() {
  char *cpfChar;
  int cpf[TAM_CPF], cpfValido[TAM_CPF];
  int *ponteiro = cpf;
  int fator, soma = 0, valido = 0, i, pos = 0, tamCpfInserido;

  do {
    printf("Insira o cpf: ");
    scanf("%s", cpfChar);
    tamCpfInserido = (int) strlen(cpfChar);
  } while(tamCpfInserido != TAM_CPF && tamCpfInserido != TAM_CPF + 3);
  printf("\n");

  for (i = 0; i <= tamCpfInserido - 1; i++) {
    if (48 <= cpfChar[i] && cpfChar[i] <= 57) {
      cpf[pos] = cpfChar[i] - 48;
      if (pos <= 8) {
        cpfValido[pos] = cpf[pos];
      }
      pos++;
    }
  }

  for (fator = 10; fator >= 2; fator--) {
    soma += *ponteiro * fator;
    ponteiro++;
  }

  if (soma % TAM_CPF < 2) {
    cpfValido[9] = 0;
  } else {
    cpfValido[9] = TAM_CPF - (soma % TAM_CPF);
  }

  if (cpfValido[9] == *ponteiro) {
    valido = 1;
  } else {
    valido = 0;
  }
  ponteiro = cpf;
  soma = 0;
  for (fator = TAM_CPF; fator >= 2; fator--) {
    soma += *ponteiro * fator;
    ponteiro++;
  }

  if (soma % TAM_CPF < 2) {
    cpfValido[10] = 0;
  } else {
    cpfValido[10] = TAM_CPF - (soma % TAM_CPF);
  }

  if (cpfValido[9] == *ponteiro) {
    valido = 1;
  } else {
    valido = 0;
  }

  if (soma % TAM_CPF < 2 && *ponteiro == 0) {
    valido = 1;
  } else if (*ponteiro == TAM_CPF - (soma % TAM_CPF)) {
    valido = 1;
  } else {
    valido = 0;
  }

  imprimirLinha(TAM_CPF * 3);
  printf("O CPF digitado é ");
  if (valido) {
    printf("\033[1;32m");
    printf("VÁLIDO\n");
    printf("\033[0m");
  } else {
    printf("\033[1;31m");
    printf("INVÁLIDO\n");
    printf("\033[0m");
  }
  imprimirLinha(TAM_CPF * 3);

  printf("CPF digitado -> ");
  for (i = 0; i <= TAM_CPF - 1; i++) {
    printf("%d", cpf[i]);
    if ((i + 1) % 9 == 0) {
      printf("-");
    } else if ((i + 1) % 3 == 0) {
      printf(".");
    }
  }
  printf("\nCPF válido -> ");
  for (i = 0; i <= TAM_CPF - 1; i++) {
    printf("%d", cpfValido[i]);
    if ((i + 1) % 9 == 0) {
      printf("-");
    } else if ((i + 1) % 3 == 0) {
      printf(".");
    }
  }
  printf("\n");
  imprimirLinha(TAM_CPF * 3);
  
  return 0;
}
