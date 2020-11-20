// O programa para imprimir (e eventualmente gravar) o calendario conforme foi chamado em linha de comando (terminal):

// Opções de chamada (exemplos), são três formas de chamar o programa:
// calendario         => mostra o calendario do mes corrente
// calendario m 10    => mostra o calendario de outubro do ano corrente, sendo m para month e 10 o numero
// calendario y 2004  =>  calendario do ano inteiro (todos os meses), sendo y para year e 2004 o numero

// Exibição exemplo:
// - Chamada: calendario
// - Mostra: calendário do mes corrente do ano corrente, novembro de 2020

// Novembro - 2020
// D    S    T    Q    Q    S    S
// 1    2    3    4    5    6    7
// 8    9    10   11   12   13   14
// 15   16   17   18   19   20   21
// 22   23   24   25   26   27   28
// 29   30

// BONUS (nota a mais), salvar o calendario em arquivo txt, idem as chamadas de base, mas com f (de file) e nome do arquivo texto de saida, exemplos
// calendario f cal.txt
// calendario m 10 f cal.txt
// calendario y 2004 f cal.txt
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define QTD_MESES 12
#define MES_LEN 64

int getUltimoDiaFev(int);
int getPosValorComando(char *, int , char *[]);
void imprimirCalendario(struct tm);
void imprimirCalendarioArquivo(FILE *, struct tm);

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  time_t agora;
  struct tm *tempo;
  struct tm dia1;

  int argMes = 0, argAno = 0;
  char *argNomeArquivo;
  FILE *arquivoExportar;

  time(&agora);
  tempo = localtime(&agora);

  dia1.tm_mday = 1;
  dia1.tm_mon = tempo->tm_mon;
  dia1.tm_year = tempo->tm_year;
  dia1.tm_hour = 12;
  dia1.tm_min = 0;
  dia1.tm_sec = 0;

  if (argc >= 3)
  {
    int posMes = getPosValorComando("m", argc, argv);
    int posAno = getPosValorComando("y", argc, argv);
    int posNomeArquivo = getPosValorComando("f", argc, argv);

    if (posMes > 0)
    {
      argMes = atoi(argv[posMes]);
      if (argMes >= 1 && argMes <= 12)
        dia1.tm_mon = argMes - 1;
      else
        printf("O mes informado eh invalido!\n");
    }
    if (posAno > 0)
    {
      argAno = atoi(argv[posAno]);
      if (argAno >= 1900)
        dia1.tm_year = argAno - 1900;
      else
        printf("O ano informado eh muito baixo!\n");
    }
    if (posNomeArquivo > 0)
    {
      argNomeArquivo = argv[posNomeArquivo];
    }
  }

  if (argAno && !argMes) {
    int i = 0;
    if (argNomeArquivo) {
      arquivoExportar = fopen(argNomeArquivo, "w");
      if (arquivoExportar == NULL) {
        printf("Nao foi possivel criar o arquivo de saida <%s>", argNomeArquivo);
      }
    }
    for (i = 0; i < 12; i++) {
      dia1.tm_mon = i;
      mktime(&dia1);

      if (argNomeArquivo && arquivoExportar != NULL) {
        imprimirCalendarioArquivo(arquivoExportar, dia1);
      } else {
        imprimirCalendario(dia1);
      }
    }
    if (argNomeArquivo && arquivoExportar != NULL) {
      fclose(arquivoExportar);
    }
  } else {
    mktime(&dia1);

    if (argNomeArquivo) {
      arquivoExportar = fopen(argNomeArquivo, "w");
      if (arquivoExportar == NULL) {
        printf("Nao foi possivel criar o arquivo de saida <%s>", argNomeArquivo);
      } else {
        imprimirCalendarioArquivo(arquivoExportar, dia1);
        fclose(arquivoExportar);
      }
    } else {
      imprimirCalendario(dia1);
    }
  }
}

int getUltimoDiaFev(int ano)
{
  if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))
    return 29;
  else
    return 28;
}

int getPosValorComando(char *comando, int argc, char *argv[])
{
  int i = 0;
  if ((argc - 1) % 2 != 0)
    return 0;
  for (i = 1; i < argc; i++)
  {
    char *parametro = argv[i];
    if (strcmp(parametro, comando) == 0)
    {
      return i + 1;
    }
  }
  return 0;
}

void imprimirCalendario(struct tm dia1)
{
  const int ultimoDiaMeses[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i = 0, j = 0;
  char mesString[MES_LEN] = {0};
  int mesAtual = dia1.tm_mon;
  int anoAtual = dia1.tm_year + 1900;
  int ultimoDiaMes;

  // Buscar último dia do mês
  if (mesAtual != 1)
    ultimoDiaMes = ultimoDiaMeses[mesAtual];
  else
    ultimoDiaMes = getUltimoDiaFev(anoAtual);

  // Pegar o nome do mês atual e deixar a primeira letra maiúscula
  strftime(mesString, MES_LEN, "%B", &dia1);
  mesString[0] = toupper(mesString[0]);

  printf("%s - %d\n", mesString, anoAtual);
  printf("D    S    T    Q    Q    S    S\n");

  for (i = 0; i < ultimoDiaMes; i++)
  {
    mktime(&dia1);
    int dia = dia1.tm_mday;
    int diaSemana = dia1.tm_wday; // domingo eh 0
    if (dia == 1)
    {
      j = 0;
      while (j < diaSemana)
      {
        printf("     ");
        j++;
      }
    }
    // Imprimir dia
    printf("%d", dia);

    // Corrigir espaçamento entre dias.
    // Caso o dia tiver apenas um dígito imprimir 4 espaçoes,
    // caso contrário apenas 3.
    if (dia1.tm_mday != ultimoDiaMes) {
      if ((int)dia / 10 >= 1)
      {
        printf("   ");
      }
      else if(dia1.tm_mday != ultimoDiaMes)
      {
        printf("    ");
      }
    }    

    // Quebrar linha a cada 7 dias
    if ((diaSemana + 1) % 7 == 0)
    {
      printf("\n");
    }

    dia1.tm_mday = dia1.tm_mday + 1;
  }
  printf("\n\n");
}

void imprimirCalendarioArquivo(FILE *arquivoExportar, struct tm dia1)
{
  const int ultimoDiaMeses[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i = 0, j = 0;
  char mesString[MES_LEN] = {0};
  int mesAtual = dia1.tm_mon;
  int anoAtual = dia1.tm_year + 1900;
  int ultimoDiaMes;

  // Buscar último dia do mês
  if (mesAtual != 1)
    ultimoDiaMes = ultimoDiaMeses[mesAtual];
  else
    ultimoDiaMes = getUltimoDiaFev(anoAtual);

  // Pegar o nome do mês atual e deixar a primeira letra maiúscula
  strftime(mesString, MES_LEN, "%B", &dia1);
  mesString[0] = toupper(mesString[0]);

  fprintf(arquivoExportar, "%s - %d\n", mesString, anoAtual);
  fprintf(arquivoExportar, "D    S    T    Q    Q    S    S\n");

  for (i = 0; i < ultimoDiaMes; i++)
  {
    mktime(&dia1);
    int dia = dia1.tm_mday;
    int diaSemana = dia1.tm_wday; // domingo eh 0
    if (dia == 1)
    {
      j = 0;
      while (j < diaSemana)
      {
        fprintf(arquivoExportar, "     ");
        j++;
      }
    }
    // Imprimir dia
    fprintf(arquivoExportar, "%d", dia);

    // Corrigir espaçamento entre dias.
    // Caso o dia tiver apenas um dígito imprimir 4 espaçoes,
    // caso contrário apenas 3.
    if (dia1.tm_mday != ultimoDiaMes) {
      if ((int)dia / 10 >= 1)
      {
        fprintf(arquivoExportar, "   ");
      }
      else
      {
        fprintf(arquivoExportar, "    ");
      }
    }

    // Quebrar linha a cada 7 dias
    if ((diaSemana + 1) % 7 == 0)
    {
      fprintf(arquivoExportar, "\n");
    }

    dia1.tm_mday = dia1.tm_mday + 1;
  }
  fprintf(arquivoExportar, "\n\n");
}
