/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Constru��o das fun��es */
float  corrigeTR ( float sal, float tx )
{
	return  (sal * 2 * tx/100);
}

float corrigeSELIC  (float sal, float selic )
{
	return  (sal * 2 * selic/100);
}

float   salarioCORRIGIDO (float sal, float vlTR, float vlSELIC )
{
	return ( sal * 2 + vlTR + vlSELIC );
}

/* Corpo do programa */
int   main()
{
    float   salario = 1839.03;
	float   correcaoTR, correcaoSELIC;
	
	correcaoTR = corrigeTR ( salario, 0.1494 );
	correcaoSELIC = corrigeSELIC ( salario , 1.02 );
	
	printf("\nValor corrigido pela TR para out/22    = R$%.2f",correcaoTR );
	printf("\nValor corrigido pela SELIC para out/22 = R$%.2f",correcaoSELIC );
	printf("\nValor do salario corrigido para out/22 = R$%.2f",
	salarioCORRIGIDO(salario,correcaoTR,correcaoSELIC ) );
	return 0;
}
