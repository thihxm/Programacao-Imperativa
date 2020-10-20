#define TAM 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char nome[200];
  char telefone[20];
} tContato;

// cabecalhos das funcoes
void imprimeContato(tContato c);
void imprimeListaContatos(tContato lista[], int tam);
void buscaContato(tContato lista[], char busca[]);
void ordenarContatos(tContato lista[]);
tContato leContato();

int main()
{
  tContato lista[TAM];
  int pos = 0;
  int opcao;
  int i = 0;
  char nomePesquisa[200];

  do
  {
    printf("\n--- Menu---\n\n");
    printf("0 - sair\n");
    printf("1 - incluir contato\n");
    printf("2 - procurar contato\n");
    printf("3 - listar todos contatos\n");
    printf("4 - ordenar contatos A..Z\n");
    printf("\nQual sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 0:
      exit(0);
      break;
    case 1:
      if (pos < TAM)
      {
        lista[pos] = leContato();
        pos++;
      }
      break;
    case 2:
      printf("Insira o nome do contato: ");
      scanf("%s", &nomePesquisa);

      buscaContato(lista, nomePesquisa);
      break;
    case 3:
      imprimeListaContatos(lista, TAM);
      break;
    case 4:
      ordenarContatos(lista);
      imprimeListaContatos(lista, TAM);
      break;
    default:
      printf("Opcao inexistente! Escolha entre <0>..<4>!\n");
      break;
    }

  } while (opcao != 0);

  return 0;
}

void imprimeContato(tContato c)
{
  printf("Nome: %s \n", c.nome);
  printf("Telefone: %s\n", c.telefone);
}

void imprimeListaContatos(tContato lista[], int tam)
{
  int i;
  printf("\n--- Lista de Contatos ---\n", tam);
  for (i = 0; i < tam; i++)
  {
    imprimeContato(lista[i]);
  }
}

void buscaContato(tContato lista[], char busca[])
{
  int i, j;
  char nomeLower[200], buscaLower[200];
  strcpy(buscaLower, busca);
  strlwr(buscaLower);
  for (i = 0; i < TAM; i++)
  {
    tContato contato = lista[i];
    strcpy(nomeLower, contato.nome);
    strlwr(nomeLower);
    char *ptr = strstr(nomeLower, buscaLower);
    if (ptr != NULL)
    {
      imprimeContato(contato);
    }
  }
}

void ordenarContatos(tContato lista[]) {
  int i, j, menor;
  tContato aux;
  for (j = 0; j < TAM - 1; j++)
  {
    menor = j;
    for (i = j + 1; i < TAM; i++)
    {
      if (strcmp(lista[i].nome, lista[menor].nome) < 0)
        menor = i;
    }
    aux = lista[j];
    lista[j] = lista[menor];
    lista[menor] = aux;
  }
}

tContato leContato()
{
  tContato c;
  setbuf(stdin, NULL);
  printf("Nome contato: ");
  fgets(c.nome, 200, stdin);
  c.nome[strcspn(c.nome, "\n")] = 0;
  printf("Telefone do contato: ");
  fgets(c.telefone, 20, stdin);
  c.telefone[strcspn(c.telefone, "\n")] = 0;

  return c;
}
