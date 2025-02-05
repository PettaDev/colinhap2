#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int sorteiaNum (int limite)
{
	int numero_sorteado;
   	// Sorteia um n�mero entre 0 e o limite
	numero_sorteado = rand() % limite; 
	if (numero_sorteado==0)
	   numero_sorteado=1;
   	// Exibe o n�mero sorteado 
   	printf("\nN�mero sorteado: %d\n", numero_sorteado); 
}

int main() { 
   int numero_sorteado;
   char op;
   // Inicializa o gerador de n�meros aleat�rios: chamar srand UMA VEZ S� 
   srand(time(0)); 
   do{
   	    numero_sorteado=sorteiaNum (6);
   		printf ("\nSorteia outro [n/N=n�o]: ");
   		fflush(stdin);
   		op=getche();
   	}while (op!='N' && op!='n');
   return 0;
}
