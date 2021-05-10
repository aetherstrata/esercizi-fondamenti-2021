#include <stdio.h>

/* DUE SOLUZIONI sotto*/

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza)
 * e verifica l'esistenza di due interi consecutivi uguali: REALIZZAZIONE 3 */
int consecutiviUguali(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int esistono;			// esistono due interi consecutivi uguali?
	
	/* CASO BASE */
	if(lunghezza<=1)
		esistono = 0;
	/* PASSO RICORSIVO */
	else
		if(interi[0]==interi[1])
			esistono = 1;
		else
			esistono = consecutiviUguali(interi+1, lunghezza-1);
	
	return esistono;
}

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza)
 * e verifica l'esistenza di due interi consecutivi uguali: REALIZZAZIONE 3bis */
int consecutiviUguali2(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int esistono;			// esistono due interi consecutivi uguali?
	
	/* CASO BASE */
	if(lunghezza<=1)
		esistono = 0;
	/* PASSO RICORSIVO */
	else
		esistono = (interi[0]==interi[1]) || consecutiviUguali(interi+1, lunghezza-1);
	
	return esistono;
}

/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io verifico se esistono due interi consecutivi uguali in una sequenza di interi.\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("\nIntroduci un intero! ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(consecutiviUguali(sequenza,lunghezza))
		printf("\nEsistono due interi consecutivi uguali!\n");
	else
		printf("\nNon esistono due interi consecutivi uguali!\n");
}
