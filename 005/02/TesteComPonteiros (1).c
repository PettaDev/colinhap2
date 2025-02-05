/* Bibliotecas */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Corpo do programa */
int main (){
	/* Variáveis locais ao main */
	int    x;
	int    *y; /* y é um ponteiro para endereços inteiros */
	
	x = 30;
	y = &x;  /* y "aponta" para o endereço de x */
   *y = 100; /* o conteúdo do endereço apontado por y passa a ser 100 */

    printf ("\n Valor de x = %i" , x);
    printf ("\n Endereço de x = %p", &x);
    printf ("\n Endereço de y = %p", &y);
    printf ("\n Conteúdo de y = %p", y);
    printf ("\n Conteúdo do conteúdo de y = %i", *y);
	
	getch();
	return 0;
}
