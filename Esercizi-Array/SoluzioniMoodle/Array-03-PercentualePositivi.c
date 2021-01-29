 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero a
  * Post-condizione: a è pari ad 1 se almeno la metà degli interi in s 
  * sono positivi, è pari a 0 altrimenti 
  * 
  * TIPO DI PROBLEMA: Conteggio */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce 1 se almeno la metà degli interi nell'array sono positivi, restituisce 
 * 0 altrimenti */
int percentualePositivi(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int numeroPos;				// il numero di positivi
	numeroPos = 0;			 	// nessun positivo inizialmente
	
	/* guarda tutti gli elementi... */
	for(int i=0; i<lunghezza; i++) {
		/* incrementa la variabile di conteggio se l'elemento è positivo */
		if(interi[i]>0)
			numeroPos++;
	}
	
	return (numeroPos>=(lunghezza-numeroPos));
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e determina se almeno la met%c degli interi sono positivi\n\n", 133);
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(percentualePositivi(sequenza, lunghezza))
		printf("\nAlmeno la met%c degli interi sono positivi!", 133);
	else
		printf("\nPi%c della met%c degli interi sono negativi!", 151, 133);
}
