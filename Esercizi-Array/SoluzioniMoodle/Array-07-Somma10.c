 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero coppia10
  * Post-condizione: coppia10 è pari ad 1 se esiste una coppia di interi la cui somma è 10,
  * è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica esistenziale
  */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica se esiste una coppia di elementi la cui somma è 10 */
int somma10(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int coppia10;			// vale 1 se esiste una coppia di interi con somma 10
	int i, j;					// variabili contatore
	
	/* all'inizio nessuna coppia di interi è stata trovata la cui somma 10 */
	coppia10 = 0;
	
	/* guarda tutte le coppie di elementi; interrompi se hai trovato due interi
	 * la cui somma è 10 */
	i=0;
	while(i<lunghezza-1 && !coppia10) {
		j=i+1;		// devi confrontare l'elemento con indice i con tutti quelli con indice maggiore
		while(j<lunghezza && !coppia10)
			/* verifica se gli interi con indici i e j hanno somma 10 */
			if(interi[i]+interi[j]==10)
				coppia10 =1;
			else
				j++;
		i++;		// passa al prossimo elemento
	}
	return coppia10;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica che esiste una coppia di elementi con somma 10.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(somma10(sequenza,lunghezza))
		printf("\nEsiste una coppia di interi la cui somma %c 10!\n", 138);
	else
		printf("\nNon esiste una coppia di interi la cui somma %c 10!\n", 138);
}
