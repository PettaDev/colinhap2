/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Prot�tipos de fun��es */
void quadrado (int n);   
int   main ();

/* Constru��o das fun��es */
void quadrado (int n)
{
   printf ("\n O quadro de %d = %d", n, n*n);
}

/* Corpo do programa */
int main () {
 int  i, num;
 printf ("\n Teste com fun��es");
 for (i=1; i<=5; i++) {
 	printf ("\nDigite num: "); 
	fflush(stdin); scanf("%i", &num);
	quadrado(num);
 }
 getch();
 return 0;
}
