 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s, l>=1 
  * Output: Un intero cresMas
  * Post-condizione: cresMas è pari alla massima lunghezza di una sotto-sequenza
  * crescente di interi in s
  * TIPO DI PROBLEMA: Massimo
  */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce la massima lunghezza di una sotto-sequenza crescente di interi in s */
int crescentePiuLunga(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi, lunghezza>=1
	int cresMas;		// la lunghezza massima
	int cresCorr;		// la lunghezza corrente 
	
	/* la lunghezza massima e corrente inizialmente vale 0 */
	cresMas = 1;
	cresCorr = 1;
	
	/* guarda tutti gli interi dal secondo */
	for(int i=1; i<lunghezza; i++) {
		/* l'intero continua una sequenza crescente? */
		if(interi[i]>interi[i-1]) {
			cresCorr++;
			/* nuova sequenza più lunga? */
			if(cresCorr>cresMas) 
				cresMas = cresCorr;
		}
		else  /* inizia una nuova sequenza crescente */
			cresCorr = 1;
	}
	
	return cresMas;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e calcola la massima lunghezza di una sotto-sequenza crescente di interi.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	printf("\nLa massima lunghezza di una sotto-sequenza crescente %c %d.\n", 138, crescentePiuLunga(sequenza, lunghezza));
}
