/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Variáveis globais */

/* Construção das funções */
int   quadrado (int num)
{
	return num*num;
}

void  quadrado2 ( void )
{
	/* Variáveis locais a função quadrado2 */
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
	/* Variáveis locais a função quadrado2 */
	int x;
	printf ("\nDigite um nro inteiro: ");
	fflush(stdin); scanf ("%i", &x);
    return x*x;	
}

/* Corpo do programa */
int main(){
	/* Variáveis locais */
	int k;
	k = quadrado4();
	printf ("\n ^ 2 = %i", k);
	
	return 0;
}
