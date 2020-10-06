#define TAM 3

#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[200];
  char telefone[20];
} tContato;

// cabecalhos das funcoes
void imprimeContato(tContato c);
void imprimeListaContatos(tContato lista[], int tam);
tContato leContato();

int main()
{
  tContato lista[TAM];
  int pos = 0;
  int opcao;
  char nomePesquisa[200];
  int i = 0;

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
      for (i = 0; i < TAM; i++)
      {
        tContato contato = lista[i];
        char *ptr = strstr(contato.nome, nomePesquisa);
        if (ptr != NULL)
        {
          imprimeContato(contato);
        }
      }

      break;
    case 3:
      imprimeListaContatos(lista, TAM);
      break;
    default:
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
