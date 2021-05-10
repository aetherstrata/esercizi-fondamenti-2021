#include <stdio.h>

/* funzione che calcola la massima somma di una tripla di interi 
 * adiacenti nell'array parametro */
int triplaMax(int array[], int l) {
	// pre: l>=3
	int risultato;		// per il risultato
	int max1;			// per la prima tripla

	/* calcola la somma della prima tripla */
	max1 =array[0]+array[1]+array[2];
	
	/* CASO BASE */
	if(l==3)
		risultato=max1;
	/* PASSO RICORSIVO */
	else {
		risultato = triplaMax(array+1,l-1);
		if(max1>risultato)
			risultato=max1; 
	}
	return risultato;	
}
 
/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io calcola la massima somma di tre interi consecutivi in una sequenza.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	printf("\nLa massima somma vale %d!\n", triplaMax(sequenza,lunghezza));
}
