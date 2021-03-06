#include <stdio.h>

int recProd(int n1, int n2);

/* programma per il calcolo del prodotto */
int main()
{
	int numero1, numero2;
	printf("Io calcolo il prodotto fra numeri interi non negativi. Dammi due numeri\n");
	scanf("%d%d", &numero1, &numero2);
	printf("Il prodotto vale %d", recProd(numero1,numero2));
}

/* funzione per il calcolo del prodotto di due numeri senza 
 * utilizzare l'operatore per la moltiplicazione */
int recProd(int n1, int n2) {
	// pre: n1,n2>=0
    int prod;		// il risultato			

    /* la ricorsione viene fatta sul secondo numero */
	if (n2==0)		
		prod = 0; 
    else 
		prod = n1 + recProd(n1,n2-1);

    return prod;
}