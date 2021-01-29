 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero sommabile
  * Post-condizione: sommabile è pari a 1 se tre elementi consecutivi nella sequenza sono
  * tali che uno è pari alla somma degli altri due, è pari a 0 altrimenti.
  * 
  * TIPO DI PROBLEMA: Verifica universale */

#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) e verifica 
 * se ogni tre elementi consecutivi nella sequenza sono tali che uno è pari alla somma degli altri due. */
int sommaTriple(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int sommabile;			// variabile di universalità
	int i;							// variabile contatore
	
	/* inizialmente tutte le triple di elementi verificate sono buone */
	sommabile = 1;
	
	/* guarda tutte le triple di elementi consecutivi, fino a che non finisci la sequenza o 
	 * trovi tre elementi tali che nessuno dei tre è pari alla somma degli altri due */
	i=0;
	while(i<lunghezza-2 && sommabile) {
		/* i tre elementi correnti soddisfano la proprietà? */
		if(interi[i]!=interi[i+1]+interi[i+2] && interi[i+1]!=interi[i]+interi[i+2]  && interi[i+2]!=interi[i]+interi[i+1])
			sommabile = 0;
		else 
			i++; 							// passa alla prossima tripla di elementi
	}
	return sommabile;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi e verifica se ");
	printf("ogni tre elementi consecutivi nella sequenza sono tali che uno %c pari ", 138);
	printf("alla somma degli altri due.\n\n");
	
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(sommaTriple(sequenza,lunghezza)){
		printf("\nOgni tre elementi consecutivi nella sequenza sono tali che uno %c pari ", 138);
		printf("alla somma degli altri due.\n");
	}
	else{
		printf("\nEsistono tre elementi consecutivi nella sequenza tali che nessuno %c pari ", 138);
		printf("alla somma degli altri due.\n");
	}
}  
