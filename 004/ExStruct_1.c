/* ====================== Bibliotecas ======================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* ========== Defini��o do tipo de dados chamado registro =========*/
typedef struct
{ 
	char 	Nome [256];
 	int 	Idade;
 	char 	Sexo;
} registro;

/* ======================== Vari�veis globais =====================*/
registro Dados; /* Declara��o da vari�vel chamada Dados que � do tipo registro */

/* ================ CORPO DO PROGRAMA =============================*/
int main ()
{
 printf ("\n Digite o nome : ");
 fflush(stdin); gets (Dados.Nome);

 printf ("\n Digite a idade : ");
 fflush(stdin); scanf("%d", &Dados.Idade);

 printf ("\n Digite o sexo : ");
 fflush(stdin); scanf("%c", &Dados.Sexo);

 printf ("\n %s tem %d anos e do sexo %c ", 
         Dados.Nome, Dados.Idade, Dados.Sexo);
         
 getch();

 return 0;
}
