 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s e l>=2 
  * Output: Un intero distMin
  * Post-condizione: distMin è pari alla minima distanza fra due interi consecutivi in s
  * 
  * TIPO DI PROBLEMA: Minimo */

#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce la distanza minima fra due interi consecutivi nell'array */
int distanzaMinima(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi, lunghezza>=2
	int distMin;			// la distanza minima
	int dist;					// una distanza
	
	/* inizializza la distanza minima a quella fra i primi due interi */
	if(interi[0]>interi[1])
		distMin = interi[0]-interi[1];
	else
		distMin = interi[1]-interi[0];
		
	/* guarda tutte le altre coppie di interi */
	for(int i=1; i<lunghezza-1; i++) {
		/* calcola la distanza fra gli interi con indici i e i+1 */
		if(interi[i]>interi[i+1])
			dist = interi[i]-interi[i+1];
		else
			dist = interi[i+1]-interi[i];
		
		/* la coppia attuale ha distanza minore della distanza minima corrente? */
		if(dist<distMin)
			distMin = dist;
	}
	
	return distMin;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e calcola la distanza minima fra due interi consecutivi nella sequenza.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	printf("\nLa distanza minima fra due interi consecutivi vale %d.\n", distanzaMinima(sequenza, lunghezza));
}
