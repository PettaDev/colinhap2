/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Prot�tipos de fun��es */
void  quadrado (void);   
int   main ();
int   capturaNum (void);

/* Constru��o das fun��es */
int   capturaNum (void)
{
   int num;
   printf ("\n Digite um n�mero: ");
   fflush(stdin); scanf ("%d" , &num);	
   return num;
}

void quadrado (void)
{
   int  x;
   x = capturaNum();
   printf ("\n O quadro de %d � %d", x, x*x);
}

/* Corpo do programa */
int main ()
{
 int  i;
 printf ("\n Teste com fun��es");
 
 for (i=1; i<=5; i++)
    quadrado();
 
 getch();
 return 0;
}
