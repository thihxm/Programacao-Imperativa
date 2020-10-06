// Desenvolva um programa para o “Jogo da Forca”. Para tal, crie um vetor de strings inicializado com um conjunto de
// palavras-chave (por exemplo: nomes de capitais do Brasil, ou times de futebol da Serie A ou Países da América do Sul, etc).
// Sorteie uma das palavras para ser o segredo e forneça seis vidas para o usuário acertar o segredo. A cada rodada informe o
// número de vidas disponíveis e a disposição das letras acertadas e ausentes na palavra segredo (lembre de quando brincava com
// este jogo em seu caderno escolar na infância), mostre também quais as letras que já foram usadas (e não compute acerto ou
// erro no caso do usuário repetir uma letra já fornecida).

#define VIDAS 6
#define TAM_ALFABETO 26
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int contemLetra(char *palavraSorteada, char letra) {
  int i;
  for(i = 0; i < strlen(palavraSorteada); i++) {
    if (palavraSorteada[i] == letra) {
      return 1;
    }
	}
  return 0;
}

int jaChutou(char letrasUsadas[], char letra, int chutes) {
  int i;
  for(i = 0; i < chutes; i++) {
    if (letrasUsadas[i] == letra) {
      return 1;
    }
	}
  return 0;
}

int verificarGanhou(char *palavraSorteada, char letrasUsadas[], int chutes) {
	for(int i = 0; i < strlen(palavraSorteada); i++) {
		if(palavraSorteada[i] != 32 && !jaChutou(letrasUsadas, palavraSorteada[i], chutes)) {
			return 0;
		}
	}

	return 1;
}

void imprimirLetrasUsadas(char letrasUsadas[], int chutes) {
  int i;
  printf("Letras usadas: [ ");
  for (i = 0; i < chutes; i++) {
    printf("%c ", letrasUsadas[i]);
  }
  printf("]\n");
}

void imprimirPalavra(char *palavraSorteada, char letrasUsadas[], int chutes) {
  int i;
  for(i = 0; i < strlen(palavraSorteada); i++) {
    int ja = jaChutou(letrasUsadas, palavraSorteada[i], chutes);
    if(ja || palavraSorteada[i] == 32) {
      printf("%c ", palavraSorteada[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

int main() {
  char *palavrasChave[] = {"RIO BRANCO", "MACEIO", "MACAPA", "MANAUS", "SALVADOR",
                           "FORTALEZA", "BRASILIA", "VITORIA", "GOIANIA", "SAO LUIS",
                           "CUIABA", "CAMPO GRANDE", "BELO HORIZONTE", "BELEM", "JOAO PESSOA",
                           "CURITIBA", "RECIFE", "TERESINA", "RIO DE JANEIRO", "NATAL",
                           "PORTO ALEGRE", "PORTO VELHO", "BOA VISTA", "FLORIANOPOLIS",
                           "SAO PAULO", "ARACAJU", "PALMAS"};
  int tamPalavrasChave = (int) sizeof(palavrasChave)/sizeof(palavrasChave[0]);
  int vidas = VIDAS, chutes = 0, ganhou = 0;
  char letrasUsadas[TAM_ALFABETO];

  srand(time(NULL));

  char *palavraSorteada = palavrasChave[rand() % tamPalavrasChave];

  while (vidas > 0 && !ganhou) {
    char letra;
    do {
      printf("Insira uma letra: ");
      scanf(" %c", &letra);
      letra = toupper(letra);
      while (getchar() != '\n'); // Limpar buffer de char
    } while ((letra < 65 || letra > 90));

    if (!jaChutou(letrasUsadas, letra, chutes)) {
      letrasUsadas[chutes] = letra;
      chutes++;
      if (!contemLetra(palavraSorteada, letra)) {
        vidas--;
      }
      printf("Vidas: %d\n", vidas);

      imprimirLetrasUsadas(letrasUsadas, chutes);

      imprimirPalavra(palavraSorteada, letrasUsadas, chutes);

      printf("\n");
      if (verificarGanhou(palavraSorteada, letrasUsadas, chutes)) {
        printf("Voce GANHOU em %d chutes!\n", chutes);
        ganhou = 1;
      }
    } else {
      printf("Voce ja chutou esta letra!\n\n");
    }
    if(!vidas) {
      printf("Voce PERDEU!\n");
      printf("A palavra correta era %s!\n", palavraSorteada);
    }
  }

  return 0;
}