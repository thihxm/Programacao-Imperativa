// Um número na forma n3 é igual a soma de n ímpares consecutivos.
//  Exemplo: 1³ = 1, 2³ = 3+5, 3³ = 7+9+11, 4³ = 13+15+17+19 etc.
// Dado um limite superior ls fornecido pelo usuário, mostre os ímpares consecutivos cuja soma é igual a n³ para n variando de
// 1 até ls

#include <stdio.h>
#include <math.h>

int main() {
  int tamanhoLista = 10, ultimoImpar = 1, ls = 0;
  int valoresUsuario[tamanhoLista], valoresOrdenados[tamanhoLista];

  printf("Insira o limite superior: ");
  scanf("%d", &ls);

  for (int i = 1; i <= ls; i++) {
    printf("%d³ = ", i);
    
    for (int aux = 0; aux < i; aux++) {
      if (aux + 1 < i) {
        printf("%d+", ultimoImpar);
      } else {
        printf("%d", ultimoImpar);  
      }
      ultimoImpar += 2;
    }
    printf(" = %d\n", (int) pow((double) i, 3.0f));
  }

  return 0;
}