/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Protótipos de funções */
int   quadrado (int n);   
int   main (void);

/* Construção das funções */
int   quadrado (int n)
{
   return n*n;
}

/* Corpo do programa */
int main (void) {
 int  i, num;
 printf ("\n Teste com funções");
 for (i=1; i<=5; i++) {
  printf ("\nDigite num: "); 
  fflush(stdin); scanf("%i", &num);
  printf ("\n%d ao quadrado = %d", num, quadrado(num));
 }
 getch();
 return 0;
}
