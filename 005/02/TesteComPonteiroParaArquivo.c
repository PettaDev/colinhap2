/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Corpo do programa */
int main (){
	FILE *Arq;
	Arq = fopen ("LIXO.DAT", "r");
	if ( Arq == NULL ){
		printf ("\nArquivo LIXO.DAT n�o existe!");
		printf ("\nEndere�o de Arq = %p", &Arq);
		printf ("\nConte�do de Arq = %p", Arq);
		getch();
		exit(0);
	}
	return 0;
}
