/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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

/* Construção das funções*/
void capturaDados (void){	
    int  i;
	system ("cls");
	printf ("\n===== CADASTRO =======");
	printf ("\n Digite a pista: "); 
	fflush(stdin); gets(reg.pista);
	printf ("\n Digite a quantidade de palavras [1 a 3]: ");
	fflush(stdin); scanf ("%i", &reg.qtd);
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
	getch();
}

void consultarDados (void){
	/* Abre o arquivo */
    Arq = fopen ("PALAVRAS.DAT" , "r+b");
    if ( Arq==NULL ) /* NULL = 00000000*/
    { 
    	printf ("\nErro ao abrir o arquivo PALAVRAS.DAT");
    	getch();
    	exit(0);
	}
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
	       printf ("\n%s %i %s %s %s", 
	       reg.pista, reg.qtd, reg.palavras[0], reg.palavras[1], reg.palavras[2]);
	   }
    }
	/* Fechar o arquivo */
	fclose (Arq);
	getch();
}

/* Corpo do programa */
int main (){
	capturaDados();
	gravarDados();
	consultarDados();
	return 0;
}
