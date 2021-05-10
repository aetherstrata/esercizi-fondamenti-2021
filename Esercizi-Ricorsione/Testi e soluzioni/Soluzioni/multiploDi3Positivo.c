#include <stdio.h>

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza)
 * e verifica l'esistenza di un intero positivo multiplo di 3: REALIZZAZIONE 1 */
int multiplo3Positivo(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int esiste;			// esiste un intero positivo multiplo di 3?
	
	/* CASO BASE */
	if(lunghezza==0)
		esiste = 0;
	else 
		if(interi[lunghezza-1]>0 && interi[lunghezza-1]%3==0)
			esiste = 1;
		else
			esiste = multiplo3Positivo(interi, lunghezza-1);
	return esiste; 
}

/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io verifico se esiste un elemento positivo multiplo di 3 in una sequenza di interi.\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("\nIntroduci un intero! ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(multiplo3Positivo(sequenza,lunghezza))
		printf("\nEsiste un numero positivo multiplo di 3!\n");
	else
		printf("\nNon esiste un numero positivo multiplo di 3!\n");
}
