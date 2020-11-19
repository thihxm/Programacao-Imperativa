#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main ()
{
  time_t agora;
  struct tm * tempo;
  struct tm dia1;

  time (&agora); // pega o tempo corrente, data e hora da execucao
  tempo = localtime (&agora); // preenche a struct tm com os atributos corretos usando o time_t
  printf ("Data e hora atuais sao: %s \n", asctime (tempo));  // monta str com os dados da struct tm
  printf ("Dia do mes: %d \n", tempo->tm_mday);
  printf ("Dia da semana (comeca em 0): %d \n", tempo->tm_wday); // domingo eh 0
  printf ("Mes (comeca em 0): %d \n", tempo->tm_mon+1); // janeiro eh 0
  printf ("Ano: %d \n", tempo->tm_year+1900);  // a partir de 1900, por isso, soma 1900
  printf ("Teste divisão 9 / 10 = %d", (int) 9/10);

  // tem o dia, mes, ano de agora
  // criar uma data no mesmo mes e ano, mas dia 1
  // variavel tm, preenche os campos e usa mktime
  // ver o dia da semana que cai dia 1o.
  // imprime espacos
  // depois imprime de 1 até ultimo dia
  // quantidade de dias no mes, sugestao: vetor de meses
  // nome do mes, sugestao: vetor de ponteiros para string inicializado com os nomes
  
  // pegar antes os dados via parametros da main
  // testar ano bissexto
  // e opcionalmente salvar em arquivo texto

}
