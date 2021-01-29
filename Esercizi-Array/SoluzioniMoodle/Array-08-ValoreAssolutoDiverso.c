 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero modulo
  * Post-condizione: modulo è pari a 1 se ogni coppia di interi in l havalore assoluto diverso,
  * è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica universale
  */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e verifica che ogni coppia di elementi abbia valore assoluto diverso */
int moduloDiverso(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int modulo;			// vale 1 se ogni coppia di interi ha valore assoluto diverso
	int i, j;					// variabili contatore
	
	/* all'inizio ogni coppia ha valore assoluto diverso */
	modulo = 1;
	
	/* guarda tutte le coppie di elementi; interrompi se hai trovato due elementi
	 * con lo stesso valore assoluto */
	i=0;
	while(i<lunghezza-1 && modulo) {
		j=i+1;		// devi confrontare l'elemento con indice i con tutti quelli con indice maggiore
		while(j<lunghezza && modulo)
			/* verifica se gli interi con indici i e j hanno lo stesso valore */
			if(interi[i]==interi[j] || interi[i]==-interi[j])
				modulo =0;
			else
				j++;
		i++;		// passa al prossimo elemento
	}
	return modulo;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica che ogni coppia di elementi abbia valore assoluto diverso.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(moduloDiverso(sequenza,lunghezza))
		printf("\nOgni coppia di interi ha valore assoluto diverso!\n");
	else
		printf("\nEsistono delle coppie di interi con lo stesso valore assoluto!\n");
}
