#include <stdio.h>

#include <stdio.h>

/* funzione che calcola la distanza fra due interi */
int distanza(int a, int b) {
	int dist;		// valore da calcolare
	if(a>b)
		dist = a-b;
	else
		dist = b-a;
	return dist;
}

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce la distanza minima fra due interi consecutivi nell'array: REALIZZAZIONE 3 */
int distanzaMinima(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi, lunghezza>=2
	int distMin;			// la distanza minima
	int dist;					// una distanza
	int dist2;				// un'altra distanza
	
	/* CASO BASE */
	if(lunghezza==2)
		distMin = distanza(interi[0],interi[1]);
	else { // lunghezza>=3
	/* PASSO RICORSIVO */
		dist = distanzaMinima(interi+1,lunghezza-1);
		dist2 = distanza(interi[0],interi[1]);
		if(dist<=dist2)
			distMin = dist;
		else
			distMin = dist2;
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
