/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Protótipos de funções */
void  quadrado (void);   
int   main ();
int   capturaNum (void);

/* Construção das funções */
int   capturaNum (void)
{
   int num;
   printf ("\n Digite um número: ");
   fflush(stdin); scanf ("%d" , &num);	
   return num;
}

void quadrado (void)
{
   int  x;
   x = capturaNum();
   printf ("\n O quadro de %d ‚ %d", x, x*x);
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
