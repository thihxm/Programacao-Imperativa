// Escreva um programa que leia um vetor de 10 posições com valores inteiros, aceitando apenas números entre 1 e 5
// (inclusive). Depois, empregando outro vetor calcule a distribuição de frequência das ocorrências dos valores possíveis para o
// vetor fornecido. Mostre então a distribuição calculada e uma representação “gráfica” do histograma em formato texto.

#include <stdio.h>

int main() {
  int tamanhoLista = 10, tamanhoListaDistribuicao = 5, aux = 0;
  int valoresUsuario[tamanhoLista], listaDistribuicao[tamanhoListaDistribuicao];

  for (int i = 0; i < tamanhoListaDistribuicao; i++) { listaDistribuicao[i] = 0; }

  while(aux < tamanhoLista) {
    int valor = 0;
    printf("Insira o %d número: ", aux + 1);
    scanf("%d", &valor);
    if (valor >= 1 && valor <= 5) {
      valoresUsuario[aux] = valor;
      listaDistribuicao[valor - 1] += 1;
      aux++;
    }
  }

  for (int i = 0; i < tamanhoListaDistribuicao; i++) {
    printf("%d (x%d)-> ", i + 1, listaDistribuicao[i]);
    for (int j = 0; j < listaDistribuicao[i]; j++) {
      printf("🟩 ");
    }
    printf("\n");
  }

  return 0;
}