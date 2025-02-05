/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* para manipular vetores de char (strings)*/

/* variáveis globais */
  float notas[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char  nomes[20][200] = {
  	"Ana da Silva",
  	"Beatriz Souza",
  	"Cleo",
  	"Ze",
  	"Bia",
  	"Tavares",
  	"Eurides",
  	"Josceli",
  	"Vianei",
  	"Bernardo Gomes",
  	"Airton Palladino",
  	"Evandro",
  	"Daniela",
  	"Claudete Alves de Oliveira",
  	"Daniel",
  	"Margarete Santos Silva",
  	"",
  	"",
  	"",
  	""
  };

  int indice, qtd, i;

/* Construção das funções */
void mostradados (void)
{
  /* Mostra os elementos dos dois vetores */
  for (indice=0;  indice<20; indice++)
  {
  	/* Calcula a quantidade de caracteres de cada nome */
	qtd = strlen (nomes[indice]);	
  	/* Mostra o resultado na tela */
  	printf ("\n%-50s %.2f [%3i]", nomes[indice], notas[indice], qtd  );
  }	
}

void preenche4ultimos (void)
{
  for (indice=16;  indice<20; indice++)
  {
    printf ("\nDigite o nome: "); 
	fflush(stdin); 
	gets(nomes[indice]);
  }	
}

void alteraumdosnomes (void)
{
  do
  {
  	/* Pede para alterar algum dos nomes */
  	printf ("\nO nome de qual indice voce quer alterar? ");
  	fflush(stdin);
  	scanf("%i", &indice);
  }
  while (indice<0 || indice>19);
  
  /* Tenho um índice válido */
  printf("\nDigite o novo nome que ficara na posicao %i", indice);
  fflush(stdin);
  gets(nomes[indice]);
}

/* Corpo do programa */
int main(){	
  /* Mostra os elementos dos dois vetores */
  mostradados ();
  /* Preenche os 4 últimos nomes */
  preenche4ultimos ();  
  /* Mostra os elementos dos dois vetores */
  mostradados ();
  /* Altera um dos nomes */
  alteraumdosnomes();
  /* Mostra os elementos dos dois vetores */
  mostradados ();  
  return 0;
}
