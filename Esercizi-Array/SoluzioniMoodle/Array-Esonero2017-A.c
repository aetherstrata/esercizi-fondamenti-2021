 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero contiene
  * Post-condizione: contiene è pari a 1 se la sequenza s contiene un elemento 
  * il cui valore è pari alla differenza fra il valore dell'elemento precedente ed 
  * il valore dell'elemento successivo, oppure alla differenza fra il valore 
  * dell'elemento successivo ed il valore dell'elemento precedente; è pari a 0 altrimenti.
  * 
  * TIPO DI PROBLEMA: Verifica esistenziale */

#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se esistono tre interi consecutivi tali che il valore dell'elemento intermedio
 * è pari alla differenza fra i valori degli elementi adiacenti. */
int differenzaAdiacenti(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int contiene;			// variabile di esistenza
	int i;						// variabile contatore
	
	/* inizialmente non hai ancora trovato una tripla di elementi cercati */
	contiene = 0;
	
	/* guarda tutti gli elementi intermedi, fino a che non finisci la sequenza o ne trovi uno buono */
	i=1;
	while(i<lunghezza-1 && !contiene) {
		/* l'elemento corrente soddisfa la proprietà? */
		if(interi[i]==interi[i-1]-interi[i+1] || interi[i]==interi[i+1]-interi[i-1])
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
	printf("esistono tre consecutivi tali che il valore dell'elemento intermedio %c pari ", 138);
	printf("alla differenza fra i valori degli elementi adiacenti.\n\n");
	
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(differenzaAdiacenti(sequenza,lunghezza)) {
		printf("\nEsistono tre elementi consecutivi tali che il valore dell'elemento intermedio %c pari ", 138);
		printf("alla differenza fra i valori degli elementi adiacenti.\n\n");
	}
	else {		
		printf("\nNon esistono tre elementi consecutivi tali che il valore dell'elemento intermedio %c pari ", 138);
		printf("alla differenza fra i valori degli elementi adiacenti.\n\n");
	}
}  
