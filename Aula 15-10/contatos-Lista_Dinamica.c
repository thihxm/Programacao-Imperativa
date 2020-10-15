#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sContato
{
  char nome[200];
  char telefone[20];
  struct sContato *prox;
} tContato;

typedef struct sLista
{
  int qtde;
  tContato *ini;
  tContato *fim;
} tLista;

// cabecalhos das funcoes
// ok, função nova
tLista *criaLista();
int addContato(tLista *lista, tContato contato);

// para revisar/adaptar com novo modelo de lista dinamica
void imprimeContato(tContato c);
void imprimeListaContatos(tLista *lista);
tContato leContato();

int main()
{
  tLista *lista = NULL; // lista nao existe
  tContato contato;
  int pos = 0;
  int opcao;

  lista = criaLista(); // alocar dinamicamente uma lista vazia
  if (lista == NULL)
  {
    printf("Problema na alocacao de memoria da lista!\n");
    exit(1);
  }

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
      contato = leContato();
      //if para testar se deu certo, addContato devolve 0 se ok, 1 se erro
      if (addContato(lista, contato) != 0) {
        printf("Ocorreu um problema, %s nao pode ser adicionado!\n", contato.nome);
      } else {
        printf("%s adicionado a lista!\n", contato.nome);
      }
      break;
    case 2:

      break;
    case 3:
      imprimeListaContatos(lista);
      break;
    case 4:

      break;

    default:
      printf("Opcao inexistente! Escolha entre <0>..<4>!\n");
      break;
    }
  } while (opcao != 0);
  return 0;
}

tLista *criaLista()
{
  tLista *lista;
  lista = (tLista *)malloc(sizeof(tLista));
  if (lista == NULL)
    return NULL;
  // passou, alocacao ok, entao inicializar os campos
  lista->qtde = 0;
  lista->ini = NULL;
  lista->fim = NULL;
  //printf ("Alocou %d de espaco\n", sizeof(tLista));
  //printf ("Quantidade %d \n", lista->qtde);
  return lista;
}

int addContato(tLista *lista, tContato contato)
{
  // precisa criar um contato dinamico com malloc
  // copia contato para o criado
  // coloca na lista
  // 2 situacoes
  // eh o primeiro, coloca na frente
  // ja tem contatos, coloca no final
  tContato *novoContato;
  novoContato = (tContato *) malloc(sizeof(tContato));
  if (novoContato == NULL) {
    printf("Problema ao alocar memoria");
    return 1;
  }
  strcpy(novoContato->nome, contato.nome);
  strcpy(novoContato->telefone, contato.telefone);
  novoContato->prox = NULL;
  if (lista->ini == NULL) {
    lista->ini = novoContato;
    lista->fim = novoContato;
  } else {
    lista->fim->prox = novoContato;
    lista->fim = novoContato;
  }
  lista->qtde++;
  return 0;
}

void imprimeContato(tContato *c)
{
  printf("Nome: %s \n", c->nome);
  printf("Telefone: %s\n", c->telefone);
}

void imprimeListaContatos(tLista *lista)
{
  int i;
  tContato *contato;
  if (lista == NULL) {
    return;
  }
  if (lista->ini == NULL)
  {
    printf("Nao e possivel imprimir uma lista vazia");
    return;
  }
  contato = lista->ini;
  
  printf("\n--- Lista de Contatos ---\n");
  printf("Quantidade de contatos %d\n", lista->qtde);

  for (i = 0; i < lista->qtde; i++)
  {
    imprimeContato(contato);
    contato = contato->prox;
  }
  printf("-------------------------\n");
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
