#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int sorteiaNum (int limite)
{
	int numero_sorteado;
   	// Sorteia um número entre 0 e o limite
	numero_sorteado = rand() % limite; 
	if (numero_sorteado==0)
	   numero_sorteado=1;
   	// Exibe o número sorteado 
   	printf("\nNúmero sorteado: %d\n", numero_sorteado); 
}

int main() { 
   int numero_sorteado;
   char op;
   // Inicializa o gerador de números aleatórios: chamar srand UMA VEZ SÓ 
   srand(time(0)); 
   do{
   	    numero_sorteado=sorteiaNum (6);
   		printf ("\nSorteia outro [n/N=não]: ");
   		fflush(stdin);
   		op=getche();
   	}while (op!='N' && op!='n');
   return 0;
}
