/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/* Funções */
void menu (void){
    system ("cls");
	printf ("\n    MENU     ");
	printf ("\n-------------");
	printf ("\n 1. cadastro ");
	printf ("\n 2. consulta ");
	printf ("\n E. encerrar ");
	printf ("\n-------------");
	printf ("\n Escolha: ");
}

void escolha (char op){
	switch (op){
		case '1': system ("cadastro");  break;
		case '2': system ("consulta");	break;
		case 'E': 
		case 'e': exit(0);	break;
		default : 
		{
			printf ("ERROU");
			getch();
		}
	}
}

/* Corpo do programa */
int main (){
	char op;
	do
	{   menu();
		fflush (stdin); op = getche();
		escolha(op);
	}while (op!='E' && op!='e');
	return 0;
}
