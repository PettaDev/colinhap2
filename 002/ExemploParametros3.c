/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Constantes */
#define   TITULO   "\n\nExemplo com funções\n\n"
#define   MAX      5

/* Construção das funções */
float  corrigeTR ( float * sal, float * tx )
{
	return  ( (*sal) * 2 * (*tx)/100);
}

float corrigeSELIC  (float * sal, float * selic )
{
	return  ( (*sal) * 2 * (*selic)/100);
}

float   salarioCORRIGIDO (float * sal, float * vlTR, float * vlSELIC )
{
	return ( (*sal) * 2 + (*vlTR) + (*vlSELIC) );
}

/* Corpo do programa */
int   main()
{
	float   aux;
    float   salario = 1839.03;
	float   correcaoTR, correcaoSELIC;
    float   matrixTRSELIC [MAX][2] = {  
		{0.1494, 	1.02},       
		{0.1507,	1.02},
		{0.2072,	1.12},
		{0.2081,	1.12},
		{0.0830,	0.92}
    };
    int linha;

	printf ("%s", TITULO);
	printf ("\nValor TR\tValor SELIC \tSalario corrigido");
	for ( aux =0, linha=0; linha<MAX; linha++ )
	{
		aux = matrixTRSELIC[linha][0];
		correcaoTR = corrigeTR ( &salario, &aux );
		aux = matrixTRSELIC[linha][1];
		correcaoSELIC = corrigeSELIC ( &salario , &aux );	
		printf("\nR$%.2f\t\tR$%.2f\t\tR$%.2f",
		correcaoTR, 
		correcaoSELIC, 
		salarioCORRIGIDO(&salario,&correcaoTR,&correcaoSELIC) );
	}
	
	return 0;
}
