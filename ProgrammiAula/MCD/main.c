#include <stdio.h>

int recMcd(int n1, int n2);

/* programma per il calcolo del massimo comun divisore di due numeri */
int main()
{
	int numero1, numero2;
	printf("Io calcolo il massimo comun divisore di due numeri interi positivi. Dammi due numeri\n");
	scanf("%d%d", &numero1, &numero2);
	printf("Il massimo comun divisore vale %d", recMcd(numero1,numero2));
}

/* funzione per il calcolo del massimo comun divisore fra due numeri tramite
    l'algoritmo di euclide */
int recMcd(int n1, int n2) {
	// pre: n1,n2>=1
    int mcd;		// il risultato			

    /* se i numeri sono uguali allora quello è il mcd */
	if (n1==n2)		
		mcd = n1; 
    /* altrimenti il mcd è pari al mcd fra il più piccolo e il più grande meno il più piccolo */
    else 
		if(n1>n2)
			mcd = recMcd(n2,n1-n2);
		else
			mcd = recMcd(n1,n2-n1);
    return mcd;
}