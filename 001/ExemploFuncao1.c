/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Vari�veis globais */

/* Constru��o das fun��es */
int   quadrado (int num)
{
	return num*num;
}

void  quadrado2 ( void )
{
	/* Vari�veis locais a fun��o quadrado2 */
	int x;
	printf ("\nDigite um nro inteiro: ");
	fflush(stdin); scanf ("%i", &x);
	printf ("\n%i ^ 2 = %i", x, x*x) ;	
}

void  quadrado3 ( int num )
{
	printf ("\n%i ^ 2 = %i", num, num*num ) ;	
}

int  quadrado4 ( void )
{
	/* Vari�veis locais a fun��o quadrado2 */
	int x;
	printf ("\nDigite um nro inteiro: ");
	fflush(stdin); scanf ("%i", &x);
    return x*x;	
}

/* Corpo do programa */
int main(){
	/* Vari�veis locais */
	int k;
	k = quadrado4();
	printf ("\n ^ 2 = %i", k);
	
	return 0;
}
