/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Prot�tipos de fun��es */
void  quadrado (void);   
int   main ();

/* Constru��o das fun��es */
void quadrado (void)
{
   int num;
   printf ("\n Digite um n�mero: ");
   fflush(stdin); scanf ("%d" , &num);
   printf ("\n O quadro de %d � %d", num, num*num);
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
