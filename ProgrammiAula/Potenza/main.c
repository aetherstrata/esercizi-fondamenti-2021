#include <stdio.h>

int recPot(int n1, int n2);

/* programma per il calcolo della potenza di due numeri */
int main()
{
	int numero1, numero2;
	printf("Io calcolo la potenza di due numeri interi non negativi. Dammi due numeri\n");
	scanf("%d%d", &numero1, &numero2);
	printf("Il primo numero elevato al secondo vale %d", recPot(numero1,numero2));
}

/* funzione per il calcolo della potenza di due numeri senza 
 * utilizzare la funzione pow */
int recPot(int n1, int n2) {
	// pre: n1,n2>=0
    int pot;		// il risultato			

    /* la ricorsione viene fatta sul secondo numero */
	if (n2==0)		
		pot = 1; 
    else 
		pot = n1 * recPot(n1,n2-1);

    return pot;
}