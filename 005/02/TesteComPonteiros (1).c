/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Corpo do programa */
int main (){
	/* Vari�veis locais ao main */
	int    x;
	int    *y; /* y � um ponteiro para endere�os inteiros */
	
	x = 30;
	y = &x;  /* y "aponta" para o endere�o de x */
   *y = 100; /* o conte�do do endere�o apontado por y passa a ser 100 */

    printf ("\n Valor de x = %i" , x);
    printf ("\n Endere�o de x = %p", &x);
    printf ("\n Endere�o de y = %p", &y);
    printf ("\n Conte�do de y = %p", y);
    printf ("\n Conte�do do conte�do de y = %i", *y);
	
	getch();
	return 0;
}
