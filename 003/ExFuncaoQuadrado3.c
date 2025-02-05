/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Protótipos de funções */
void quadrado (int n);   
int   main ();

/* Construção das funções */
void quadrado (int n)
{
   printf ("\n O quadro de %d = %d", n, n*n);
}

/* Corpo do programa */
int main () {
 int  i, num;
 printf ("\n Teste com funções");
 for (i=1; i<=5; i++) {
 	printf ("\nDigite num: "); 
	fflush(stdin); scanf("%i", &num);
	quadrado(num);
 }
 getch();
 return 0;
}
