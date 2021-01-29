 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero pali
  * Post-condizione: pali è pari a 1 se la sequenza s è palindroma, è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica universale */
  
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se la sequenza è palindroma */
int palindroma(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int pali;			// vale 1 se la sequenza è palindroma
	int i;				// variabile contatore
	
	/* inizialmente non hai ancora trovato una contraddizione 
	 * al fatto che la sequenza sia palindroma */
	pali = 1;
	
	/* confronta l'elemento con indice i con quello con indice lunghezza-1-i */
	i=0;
	/* se la sequenza ha lunghezza pari, la variabile contatore deve arrivare 
	 * fino a (lunghezza-2)/2, altrimenti fino a (lunghezza-3)/2, in quanto 
	 * l'elemento centrale non va confrontato */
	while(i<lunghezza/2 && pali) {
		/* verifica se gli interi con indici i e lunghezza-1-i hanno lo stesso valore */
		if(interi[i]!=interi[lunghezza-1-i])
			pali =0;
		else
			i++; // passa al prossimo elemento
	}
	return pali;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica se la sequenza %c palindroma.\n\n", 138);
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(palindroma(sequenza,lunghezza))
		printf("\nLa sequenza %c palindroma!\n", 138);
	else
		printf("\nLa sequenza non %c palindroma!\n", 138);
}
