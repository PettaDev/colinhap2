/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Protótipos de funções */
void  quadrado (void);   
int   main ();

/* Construção das funções */
void quadrado (void)
{
   int num;
   printf ("\n Digite um número: ");
   fflush(stdin); scanf ("%d" , &num);
   printf ("\n O quadro de %d ‚ %d", num, num*num);
}

/* Corpo do programa */
int main ()
{
 int  i;
 printf ("\n Teste com funções");
 
 for (i=1; i<=5; i++)
    quadrado();
 
 getch();
 return 0;
}
