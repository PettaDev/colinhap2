/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Prot�tipos de fun��es */
int   quadrado (int n);   
int   main (void);

/* Constru��o das fun��es */
int   quadrado (int n)
{
   return n*n;
}

/* Corpo do programa */
int main (void) {
 int  i, num;
 printf ("\n Teste com fun��es");
 for (i=1; i<=5; i++) {
  printf ("\nDigite num: "); 
  fflush(stdin); scanf("%i", &num);
  printf ("\n%d ao quadrado = %d", num, quadrado(num));
 }
 getch();
 return 0;
}
