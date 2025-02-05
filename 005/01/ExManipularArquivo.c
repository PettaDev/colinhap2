/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
/* Tipos de dados pré-definidos */
typedef struct
{
	char   pista[16+1];
	int    qtd;
	char   palavras[3][16+1];
}
registro;

typedef struct
{
   float	premio;
}
regpremio;

/* Variáveis globais */
registro    reg;
FILE       *Arq;
char        opc;

/* Construção das funções */
void PremiosDefault (void)
{
	regpremio rpr[12] = {
	 100.00 ,
     900.00 ,
     600.00 ,
    1000.00 ,
       0.00 ,
     400.00 ,
     200.00 ,
     800.00 ,
       0.01 ,
     300.00 ,
     500.00 ,
     700.00
    };  
    /* Cria o arquivo PREMIOS.DAT default */
    Arq = fopen ("PREMIOS.DAT", "w+b");
    if (Arq == NULL)
    {
    	printf ("\nERRO AO CRIAR PREMIOS.DAT!");
    	getch();
    	exit(0);
	}
	/* Gravar os registros dos prêmios */
	fwrite ( &rpr, sizeof (rpr), 1, Arq);
	if ( ferror(Arq) )
	{
		printf ("\nERRO AO GRAVAR EM PREMIOS.DAT");
		getch();
		exit(0);
	}
	/* Fecha o arquivo */
	fclose(Arq);
	/* Avisa que o arquivo foi criado com sucesso */
	printf ("\nArquivo PREMIOS.DAT criado com sucesso!");
	getch();
}

void MostraPremios (void)
{
	regpremio rpr;
    /* Abre o arquivo PREMIOS.DAT para leitura */
    Arq = fopen ("PREMIOS.DAT", "r+b");
    if (Arq == NULL)
    {
    	printf ("\nERRO AO ABRIR PREMIOS.DAT!");
    	getch();
    	exit(0);
	}
	/* Monta o cabeçalho da exibição */
	system ("cls");
	printf ("\n----------PRÊMIOS---------");
	/* Ler os prêmios */
	while (!feof(Arq))
	{
		fread ( &rpr, sizeof (rpr), 1, Arq);
	    if ( ferror(Arq) )
	    {
		   printf ("\nERRO AO LER PREMIOS.DAT");
		   getch();
		   exit(0);
	    }
	    if (!feof(Arq))
	    {
	       /* Mostra na tela */
	       printf ("\n\tR$ %10.2f", rpr.premio);
	    }
	}
	/* Fecha o arquivo */
	fclose(Arq);
	printf ("\n--------------------------");
	getch();
}

void LimpaReg (void)
{
    strcpy (reg.pista , "");
    reg.qtd = 0;
    strcpy (reg.palavras[0], "");
    strcpy (reg.palavras[1], "");
    strcpy (reg.palavras[2], "");
}

void capturaDados (void)
{   int i;
    /* Limpa a variável de captura dos dados */
    LimpaReg();
    /* Captura dados do registro das palavras */
	printf ("\nDigite a pista: ");
	fflush(stdin); gets(reg.pista);
	printf ("\nDigite a quantidade de palavras: ");
	fflush(stdin); scanf("%i",&reg.qtd);
    for (i=0; i<reg.qtd; i++ )
    {
    	printf ("\nDigite a palavra: ");
    	fflush(stdin); gets(reg.palavras[i]);
	}
}

void  GravaDados (void)
{ system ("cls");
  do
  { /* Captura dados do registro das palavras */
    capturaDados(); 
    /* Grava o registro no arquivo .DAT */
    Arq = fopen ("PALAVRAS.DAT" , "a+b");
    if ( Arq == NULL ) /* NULL => 00000000 */
    {
    	printf ("\nErro ao abrir PALAVRAS.DAT");
    	getch();
    	exit(0); /* o programa finaliza daqui */
	}
    fwrite ( &reg , sizeof(reg), 1, Arq );
    if ( ferror(Arq) )
    {
    	printf ("\nErro ao gravar em PALAVRAS.DAT");
    	getch();
    	exit(0);
	}
    fclose (Arq);
    /* Pergunta se quer gravar novo registro */
    printf ("\nCadastra outro registro? [n/N = não]:");
    fflush(stdin); opc = getche();
  }
  while ( opc != 'n' && opc != 'N');
}

void ConsultaDados (void)
{
	system ("cls");
    /* Lê do arquivo PALAVRAS.DAT */
    Arq = fopen ("PALAVRAS.DAT" , "r+b");
    if ( Arq == NULL ) /* NULL => 00000000 */
    {
    	printf ("\nErro ao abrir PALAVRAS.DAT");
    	getch();
    	exit(0); /* o programa finaliza daqui */
	}
	
	while ( !feof(Arq) )
	{
    	/* Lê um registro */
		fread ( &reg , sizeof(reg), 1, Arq );
		if (ferror(Arq))
		{	 
	    	printf ("\nErro ao ler PALAVRAS.DAT");
	    	getch();
	    	exit(0);
		}
	    if ( !feof(Arq) )
	    {
			/* Mostra os dados na tela */
			printf ("\n%-18s %i %-18s %-18s %-18s", 
	        reg.pista, reg.qtd, 
			reg.palavras[0], reg.palavras[1], reg.palavras[2] );
		}
	}
	
	/* fecha o arquivo */
	fclose (Arq);
	
	getch();
}

/* Corpo do programa */
int  main()
{
  setlocale (LC_ALL, "");
  do
  { /* Menu de opções */
    system ("cls");
  	printf ("\n================================");
  	printf ("\n    MANIPULANDO PALAVRAS.DAT    ");
  	printf ("\n================================");
  	printf ("\n    1. gravar dados             ");
  	printf ("\n    2. consultar dados          ");
  	printf ("\n    3. cadastro default de prêmios    ");  	
  	printf ("\n    4. mostra prêmios    ");  	
  	printf ("\n    E. Encerrar                 ");
  	printf ("\n================================");
  	printf ("\n          Sua opção: ");
  	fflush (stdin); opc = getche();
  	switch ( opc )
	{
		case '1': GravaDados(); 	break;
		case '2': ConsultaDados();	break;
		case '3': PremiosDefault(); break;
		case '4': MostraPremios(); 	break;
		case 'E':
		case 'e': exit(0);			break;
		default : 
		{
			printf ("Erro!");
			getch();
		}
	}
  }
  while (opc != 'e' && opc !='E');
  
  return 0;
}
