#include <stdio.h>

int recFatt(int n);

/* programma per il calcolo del fattoriale */
int main()
{
	int numero;
	printf("Io calcolo fattoriali. Di che numero vuoi il fattoriale?\n");
	scanf("%d", &numero);
	printf("Il fattoriale vale %d", recFatt(numero));
}

/* funzione per il calcolo del fattoriale di un numero */
int recFatt(int n) {
	// pre: n>=1
    int fatt;		// il risultato			
    if (n==1)
		fatt = 1; 
    else 
		fatt = n * recFatt(n-1);
    return fatt;
}