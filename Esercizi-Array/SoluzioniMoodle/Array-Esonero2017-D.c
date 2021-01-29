 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero contiene
  * Post-condizione: contiene è pari a 1 se la sequenza s contiene tre elementi consecutivi
  * tali che la somma o il prodotto dei valori dei primi due elementi è pari al valore del
  * terzo elemento; è pari a 0 altrimenti.
  * 
  * TIPO DI PROBLEMA: Verifica esistenziale */

#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se esistono tre interi consecutivi tali che la somma o il prodotto dei valori
 * dei primi due elementi è pari al valore del terzo elemento */
int sommaProdotto(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int contiene;			// variabile di esistenza
	int i;						// variabile contatore
	
	/* inizialmente non hai ancora trovato una tripla di elementi cercati */
	contiene = 0;
	
	/* guarda tutte le triple di elementi, fino a che non finisci la sequenza o ne trovi una buona */
	i=0;
	while(i<lunghezza-2 && !contiene) {
		/* la tripla corrente soddisfa la proprietà? */
		if(interi[i+2]==interi[i]+interi[i+1] || interi[i+2]==interi[i]*interi[i+1])
			contiene =1;
		else 
			i++; 							// passa al prossimo elemento
	}
	return contiene;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi e verifica se ne ");
	printf("esistono tre consecutivi tali che la somma o il prodotto dei primi due %c ", 138);
	printf("pari al terzo.\n\n");
	
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(sommaProdotto(sequenza,lunghezza)) 
		printf("\nEsistono tre interi consecutivi tali la somma o il prodotto dei primi due %c pari al terzo", 138);
	else 		
		printf("\nNon esistono tre interi consecutivi tali la somma o il prodotto dei primi due %c pari al terzo", 138);
}  
