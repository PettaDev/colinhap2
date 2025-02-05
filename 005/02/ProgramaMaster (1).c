/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/* Corpo do programa */
int main (){
	char op;
	do
	{   system ("cls");
		printf ("\n    MENU     ");
		printf ("\n-------------");
		printf ("\n 1. cadastro ");
		printf ("\n 2. consulta ");
		printf ("\n E. encerrar ");
		printf ("\n-------------");
		printf ("\n Escolha: ");
		fflush (stdin); op = getche();
		switch (op){
			case '1': system ("cadastro");  break;
			case '2': {
				system ("consulta");
				sleep(3);
			}  
			break;
			case 'E': 
			case 'e': exit(0);	break;
			default : {
				printf ("ERROU");
				getch();
			}
		}
	}while (op!='E' || op!='e');
	return 0;
}
