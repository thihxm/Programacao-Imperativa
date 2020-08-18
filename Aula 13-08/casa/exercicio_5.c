// Escreva um programa que leia um vetor de 10 posições reais e então calcule a média aritmética do vetor. Num outro vetor
// você deverá armazenar as diferenças absolutas do valor original para a média calculada. Fazendo então o cálculo da média
// deste novo vetor, que representa a média aritmética dos valores absolutos dos desvios em relação à média, ou seja, o desvio
// médio do conjunto inicial. Mostre então ao usuário qual foi o desvio médio do conjunto que ele digitou.
// Observação: o desvio médio absoluto (DMA) é uma medida de dispersão que leva em conta todos os valores em um conjunto
// de dados. A estratégia apresentada acima resume algoritmicamente como ele é calculado através da fórmula: 

#include <stdio.h>
#include <math.h>

int main() {
  int tamanhoLista = 10;
  float valoresUsuario[tamanhoLista], diferencasAbsolutas[tamanhoLista], somaValoresUsuario = 0.0f, somaDiferencasAbsolutas = 0.0f;

  for(int i = 0; i < tamanhoLista; i++) {
    float valor = 0;
    printf("Insira o %d número: ", i + 1);
    scanf("%f", &valor);
    valoresUsuario[i] = valor;
    somaValoresUsuario += valor;
  }

  float mediaValoresUsuario = somaValoresUsuario / tamanhoLista;

  for(int i = 0; i < tamanhoLista; i++) {
    float valor = fabsf(valoresUsuario[i] - mediaValoresUsuario);
    diferencasAbsolutas[i] = valor;
    somaDiferencasAbsolutas += valor;
  }

  float desvioMedioAbsoluto = somaDiferencasAbsolutas / tamanhoLista;

  printf("Desvio médio absoluto (DMA) do seu conjunto: %f\n", desvioMedioAbsoluto);

  return 0;
}