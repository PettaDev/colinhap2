/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Tipos pré-definidos */
typedef struct 
{
	char    pista[16+1];
	int		qtd;
	char	palavras[3][16+1];
} 
registro;

/* Variáveis globais */
registro   reg;
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
	printf ("\nPista     Qtd palavras  Palavra 1  Palavra 2  Palavra 3");
	printf ("\n---------------------------------------------------------");
	/* Ler o arquivo */
	while (!feof(Arq)){
   	   fread ( &reg, sizeof(reg), 1, Arq );
	   if ( ferror (Arq) )
	   {
		printf ("\nErro ao ler PALAVRAS.DAT");
		getch();
		exit(0);
	   }
       if ( !feof(Arq) ){
	   	   /* Mostrar na tela */
	       printf ("\n%-17s %3i \t%-17s \t%-17s \t%-17s", 
	       reg.pista, reg.qtd, reg.palavras[0], reg.palavras[1], reg.palavras[2]);
	   }
    }
	/* Fechar o arquivo */
	fclose (Arq);
	getch();
}

/* Corpo do programa */
int main (){
	system ("cls");
	printf ("\n===== CONSULTA =======");
	consultarDados();
	getch();
	return 0;
}
