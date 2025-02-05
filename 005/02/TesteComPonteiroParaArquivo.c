/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Corpo do programa */
int main (){
	FILE *Arq;
	Arq = fopen ("LIXO.DAT", "r");
	if ( Arq == NULL ){
		printf ("\nArquivo LIXO.DAT não existe!");
		printf ("\nEndereço de Arq = %p", &Arq);
		printf ("\nConteúdo de Arq = %p", Arq);
		getch();
		exit(0);
	}
	return 0;
}
