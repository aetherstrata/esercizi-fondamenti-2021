#include <stdio.h>
#include <string.h>

int ContaCifre(int n)
{
	int cifre;
	
	if(n/10==0){
		cifre=1;
	} else {
		cifre = 1+ContaCifre(n/10);
	}
	
	return cifre;
}

int main(int argc, char **argv)
{
	int numero=-1;
	
	while(numero<0){
		printf("Inserisci un numero intero positivo: ");
		scanf("%d", &numero);
	}
	
	int conto = ContaCifre(numero);
	printf("Il numero %d ha %d cifre.\n", numero, conto);
	
	return 0;
}
