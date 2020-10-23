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
void imprimeContato(tContato *contato);
void imprimeListaContatos(tLista *lista);
tContato* getContato(tLista *lista, int pos);
tContato leContato();

int main()
{
  tLista *lista = NULL; // lista nao existe
  tContato contato;
  tContato *pContato;
  int pos = 0;
  int opcao;
  char nomeArquivo[30];
  FILE *arquivoExportar, *arquivoImportar;

  lista = criaLista(); // alocar dinamicamente uma lista vazia
  if (lista == NULL)
  {
    printf("Problema na alocacao de memoria da lista!\n");
    exit(1);
  }

  do
  {
    printf("\n--- Menu---\n\n");
    printf ("\n--- Menu---\n\n");
    printf ("0 - sair\n");
    printf ("1 - cadastrar um contato\n");
    printf ("2 - consultar contato pelo indice\n");
    printf ("3 - consultar contato pelo nome\n");
    printf ("4 - remover contato pelo indice\n");
    printf ("5 - imprimir lista de contatos\n");
    printf ("6 - ordenar em ordem alfabetica A-Z\n");
    printf ("7 - exportar para arquivo CSV\n");
    printf ("8 - importar de arquivo CSV\n");
    printf("\nQual sua opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 0:
      exit(0);
      break;
    case 1:   // cadastrar um contato
      contato = leContato();
      //if para testar se deu certo, addContato devolve 0 se ok, 1 se erro
      if (addContato(lista, contato) != 0) {
        printf("Ocorreu um problema, %s nao pode ser adicionado!\n", contato.nome);
      } else {
        printf("%s adicionado a lista!\n", contato.nome);
      }
      break;
    case 2:   // consultar contato pelo indice
      printf("\n--- Consulta contato pelo indice ---\n");
      printf("\nQual a posicao: ");
      scanf("%d", &pos);
      pContato = getContato(lista, pos);
      if (pContato != NULL) {
        imprimeContato(pContato);
      }
      break;
      break;
    case 3:   // consultar contato pelo nome
      break;
    case 4:   // remover contato pelo indice
      break;
    case 5:  // imprimir lista de contatos
      imprimeListaContatos(lista);
      break;
    case 6:  // ordenar em ordem alfabetica A-Z
      break;
    case 7:  // exportar para arquivo CSV
      printf("\n--- Exportar para arquivo CSV ---\n");
      printf("\nQual o nome do arquivo (sem espaco e com extensao): ");
      scanf("%s", &nomeArquivo);
      arquivoExportar = fopen(nomeArquivo, "w");
      if (arquivoExportar == NULL) {
        printf("Nao foi possivel criar o arquivo de saida <%s>", nomeArquivo);
      } else {
        pContato = lista->ini;
        while (pContato != NULL)
        { 
          fprintf(arquivoExportar, "%s;%s;\n", pContato->nome, pContato->telefone);
          pContato = pContato->prox;
        }
        fclose(arquivoExportar);
      }
      break;
    case 8:  // importar de arquivo CSV
      printf("\n--- Importar para arquivo CSV ---\n");
      printf("\nQual o nome do arquivo (sem espaco e com extensao): ");
      scanf("%s", &nomeArquivo);
      arquivoImportar = fopen(nomeArquivo, "r");
      if (arquivoImportar == NULL) {
        printf("Nao foi possivel criar o arquivo de entrada <%s>", nomeArquivo);
      } else {
        lista = criaLista(); // reset, o ideal é fazer uma função clear (free de todas as structs)
        while (!feof(arquivoImportar)) {
          fscanf(arquivoImportar, "%[^;];%[^;];\n", &contato.nome, &contato.telefone);
          addContato(lista, contato);
        }
        fclose(arquivoImportar);
      }
      break;
    default:
      printf("Opcao inexistente! Escolha entre <0>..<8>!\n");
      break;
    }
  } while (opcao != 0);
  return 0;
}

tLista *criaLista()
{
  tLista *lista;
  lista = (tLista *)malloc(sizeof(tLista));
  if (lista == NULL) {
    return NULL;
  }
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
  if (lista == NULL) {
    printf("Lista inexistente!\n");
    return 1;
  }
  novoContato = (tContato *) malloc(sizeof(tContato));
  if (novoContato == NULL) {
    printf("Problema ao alocar memoria!\n");
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

tContato* getContato(tLista *lista, int pos)
{
  tContato *contato;
  int i = 0;
  if (lista == NULL) {
    printf("Lista inexistente!\n");
    return NULL;
  }
  if (lista->qtde == 0) {
    printf("Lista esta vazia!\n");
    return NULL;
  }
  if (pos < 0 || pos >= lista->qtde) {
    printf("Posicao solicitada inexistente!\n");
    return NULL;
  }
  contato = lista->ini;
  while (i < pos) {
    contato = contato->prox;
    i++;
  }
  return contato;
}

void imprimeContato(tContato *contato)
{
  printf("Nome: %s \n", contato->nome);
  printf("Telefone: %s\n", contato->telefone);
}

void imprimeListaContatos(tLista *lista)
{
  int i;
  tContato *contato;
  if (lista == NULL) {
    printf("Lista inexistente!\n");
    return;
  }
  if (lista->ini == NULL)
  {
    printf("Nao e possivel imprimir uma lista vazia!\n");
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
