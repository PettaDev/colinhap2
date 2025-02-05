/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "MinhaBiblioteca.h"

FILE      *Arq;

/* Construção das funções*/
void capturaDados (void){	
    int  i;
	system ("cls");
	printf ("\n===== CADASTRO =======");
	printf ("\n Digite a pista: "); 
	fflush(stdin); gets(reg.pista);
	do{
	  printf ("\n Digite a quantidade de palavras [1 a 3]: ");
	  fflush(stdin); scanf ("%i", &reg.qtd);
    }while (reg.qtd<1 || reg.qtd>3);
	for (i=0; i<reg.qtd; i++)	{
		printf ("\nDigite a %ia. palavra: ", i+1); 
		fflush(stdin); gets(reg.palavras[i]);
	}
}

void gravarDados (void){
	/* Abre o arquivo */
    Arq = fopen ("PALAVRAS.DAT" , "a+b");
    if ( Arq==NULL ) /* NULL = 00000000*/
    { 
    	printf ("\nErro ao abrir o arquivo PALAVRAS.DAT");
    	getch();
    	exit(0);
	}
	/* Grava no arquivo */
	fwrite ( &reg, sizeof(reg), 1, Arq );
	if ( ferror (Arq) )
	{
		printf ("\nErro ao gravar em PALAVRAS.DAT");
		getch();
		exit(0);
	}
	/* Fechar o arquivo */
	fclose (Arq);
	printf ("\nDados gravados com sucesso!");
	sleep(1);
}

/* Corpo do programa */
int main (){
	capturaDados();
	gravarDados();
	return 0;
}
