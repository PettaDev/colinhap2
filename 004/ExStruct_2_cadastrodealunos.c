/* ====================== Bibliotecas ======================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* ========== Definição do tipo de dados chamado registro =========
Com os seguintes campos: RA    Nome    P1    P2    Faltas
*/
typedef struct
{ 
	char    RA[9+1]; 
	char    Nome [200+1];
	float   P1, P2;
	int		Faltas;
} 
regalunos;

/* ======================== Variáveis globais =====================*/
regalunos   R[40]; /* Declaração da variável chamada R que é do tipo regalunos */
int			indice = -1; 

/* ======================== Construção das funções ================*/
char menu (void)
{   char  opc;
	do
	{	system ("cls");
		printf ("\n============ MENU ===========");
		printf ("\n 1=inclusão de novos alunos  ");
		printf ("\n 2=consulta (mostra todos)   ");
		printf ("\n 3=sair do programa          ");
		printf ("\n=============================");
		printf ("\n     Escolha: ");
		fflush (stdin); opc = getche();
	}
	while (opc < '1' || opc > '3');
	return  opc;
}

void capturaDados(void)
{
  system ("cls");
  printf ("\nDigite os dados a seguir: ");
  printf ("\nRA    : "); fflush(stdin); gets(R[indice].RA);
  printf ("\nNome  : "); fflush(stdin); gets(R[indice].Nome);
  printf ("\nP1    : "); fflush(stdin); scanf("%f", &R[indice].P1);
  printf ("\nP2    : "); fflush(stdin); scanf("%f", &R[indice].P2);
  printf ("\nFaltas: "); fflush(stdin); scanf("%i", &R[indice].Faltas);  
}

void   incluir  (void)
{	if ( indice < 39 )
	{	indice++; /* coloca na próxima posição válida */
		capturaDados();
	}
	else
	{	
		printf ("\nTabela cheia!");
		getch();
	}
}

void  geraRelatorio (void)
{   int i;
	FILE  * arq;
	arq = fopen("RELATORIO.TXT" , "a");
    if ( arq==NULL )
    {  	printf ("\nErro ao abrir RELATORIO.TXT");
    	getch();
    	exit(0);
	}
	else
	{ fprintf (arq, "\n--------------------------------------");
      fprintf (arq, "\n RA     Nome       P1     P2    Faltas");
      fprintf (arq, "\n--------------------------------------");
      for ( i=0; i<=indice; i++ )
       	fprintf (arq, "\n%10s %10s %5.2f %5.2f %02i", 
		         R[i].RA, R[i].Nome, R[i].P1, R[i].P2, R[i].Faltas );
	  fprintf (arq, "\n--------------------------------------");
	  fclose(arq);
	  /* Abre o arquivo para exibição em editor de texto */
	  system ("notepad  RELATORIO.TXT");
	}	
}

void   consultar  (void)
{	int   i; char resp;
    system ("cls");
    if ( indice == -1 )
	{ printf ("\nTabela vazia!");
	  getch();
	}
	else
	{ printf ("\n--------------------------------------");
      printf ("\n RA     Nome       P1     P2    Faltas");
      printf ("\n--------------------------------------");
      for ( i=0; i<=indice; i++ )
       	printf ("\n%10s %10s %5.2f %5.2f %02i", 
		         R[i].RA, R[i].Nome, R[i].P1, R[i].P2, R[i].Faltas );
	  printf ("\n--------------------------------------");
	  printf ("\n\nDeseja gerar relatorio em arquivo? [n/N]=nao -> ");
	  fflush (stdin); resp = getche();
	  if (resp != 'n' && resp != 'N')
	    geraRelatorio();
	  getch();
	}
}

/* ================ CORPO DO PROGRAMA =============================*/
int main ()
{   char escolha;
	do
    {   escolha = menu();
		switch ( escolha )	
		{	case '1': incluir ();	break;
			case '2': consultar();  break;
			case '3': exit(0);		break;
		}
	}
	while ( escolha!='3' );
	return 0;
}
