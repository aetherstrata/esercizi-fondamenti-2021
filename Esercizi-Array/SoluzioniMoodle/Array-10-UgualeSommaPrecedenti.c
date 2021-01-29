 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero contiene
  * Post-condizione: contiene è pari a 1 se la sequenza s contiene un elemento 
  * il cui valore è pari alla somma dei valori degli elementi precedenti, 
  * è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica esistenziale (contiene anche accumulazione) */
  
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se la sequenza contiene un elemento il cui valore è pari alla 
 * somma dei valori degli elementi precedenti  */
int ugualeSommaPrecedenti(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int contiene;			// variabile di esistenza
	int somma;			// variabile di accumulazione
	int i;						// variabile contatore
	
	/* inizialmente non hai ancora trovato l'elemento cercato e la somma
	 * degli elementi precedenti è 0 */
	contiene = 0;
	somma = 0;
	
	/* guarda tutti gli elementi a partire dal primo, fino a che non finisci
		la sequenza o ne trovi uno buono */
	i=0;
	while(i<lunghezza && !contiene) {
		/* l'elemento corrente soddisfa la proprietà? */
		if(interi[i]==somma)
			contiene =1;
		else {
			somma += interi[i];	// aggiorna la somma
			i++; 							// passa al prossimo elemento
		}
	}
	return contiene;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica se ne esiste uno pari alla somma dei precedenti.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(ugualeSommaPrecedenti(sequenza,lunghezza))
		printf("\nEsiste un intero pari alla somma dei precedenti!\n");
	else
		printf("\nNon esiste un intero pari alla somma dei precedenti!\n");
}
