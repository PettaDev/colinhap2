/* Bibliotecas utilizadas */
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "MinhaBiblioteca.h"


/* Variáveis globais */
FILE      *Rel;
FILE      *Arq;

/* Construção das funções */
void consultarDados (void){
	/* Abre o arquivo */
    Arq = fopen ("PALAVRAS.DAT" , "r+b");
    if ( Arq==NULL ) /* NULL = 00000000*/
    { 
    	printf ("\nErro ao abrir o arquivo PALAVRAS.DAT");
    	getch();
    	exit(0);
	}
	/* Cria o arquivo RELATPALAVRAS.TXT */
	Rel = fopen ("RELATPALAVRAS.TXT" , "w");
    if ( Rel==NULL ) { 
    	printf ("\nErro ao abrir o arquivo RELATPALAVRAS.TXT");
    	getch();
    	exit(0);
	}
	/* Gera o cabeçalho da consulta na tela */
	printf ("\nPista     Qtd palavras  Palavra 1         Palavra 2        Palavra 3");
	printf ("\n--------------------------------------------------------------------");
	/* Gera o cabeçalho no RELATPALAVRAS.TXT */
	fprintf (Rel, "\nPista     Qtd palavras  Palavra 1         Palavra 2        Palavra 3");
	fprintf (Rel, "\n--------------------------------------------------------------------");
	/* Ler o arquivo PALAVRAS.DAT */
	while (!feof(Arq)){
   	   fread ( &reg, sizeof(reg), 1, Arq );
	   if ( ferror (Arq) ) {
		printf ("\nErro ao ler PALAVRAS.DAT");
		getch();
		exit(0);
	   }
       if ( !feof(Arq) ){
	   	   /* Mostrar na tela */
	       printf ("\n%-17s %03i   %-17s %-17s %-17s", 
	       reg.pista, reg.qtd, reg.palavras[0], reg.palavras[1], reg.palavras[2]);
	       /* Grava o que mostrou na tela dentro de RELATPALAVRAS.TXT */
	       fprintf (Rel, "\n%-17s %03i   %-17s %-17s %-17s", 
	       reg.pista, reg.qtd, reg.palavras[0], reg.palavras[1], reg.palavras[2]);
	   }
    }
    printf ("\n--------------------------------------------------------------------");
    fprintf (Rel, "\n--------------------------------------------------------------------");
	/* Fechar os arquivos */
	fclose (Arq);
	fclose (Rel);
	/* Mostra o arquivo RELATPALAVRAS.TXT num editor de texto */
    system ("notepad  RELATPALAVRAS.TXT");
}

/* Corpo do programa */
int main (){
	system ("cls");
	printf ("\n----------------------------CONSULTA--------------------------------\n");
	consultarDados();
	return 0;
}
