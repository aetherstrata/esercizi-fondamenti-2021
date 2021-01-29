 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero triple
  * Post-condizione: triple è pari a 1 se ogni tripla di interi consecutivi 
  * contiene due interi la cui somma è 10, è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica universale
  */
  
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se ogni tripla di interi consecutivi contiene due interi con somma 10 */
int tripleSomma10(int seq[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int triple;			// vale 1 se ogni tripla di interi consecutivi contiene due interi con somma 10
	int i;					// variabile contatore
	
	/* all'inizio ogni tripla visitata contiene due interi con somma 10 */
	triple = 1;
	
	/* guarda tutte le triple di elementi; interrompi se hai trovato tre elementi consecutivi 
	 * tale che ogni due elementi hanno somma diversa da 10  */
	i=0;
	while(i<=lunghezza-3 && triple) {
		/* verifica se ogni coppia di interi, fra quelli con indici i, i+1 e i+2, ha somma 
		 * diversa da 10 */
		if((seq[i]+seq[i+1] != 10) && (seq[i]+seq[i+2] != 10) && (seq[i+1]+seq[i+2] != 10))
			triple = 0;
		else
			i++;
	}
	return triple;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica se ogni tripla di elementi consecutivi contiene due ");
	printf("interi con somma 10.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(tripleSomma10(sequenza,lunghezza))
		printf("\nOgni tripla di interi consecutivi contiene due interi con somma 10!\n");
	else
		printf("\nEsistono delle triple di interi consecutivi senza due interi con somma 10!\n");
}
