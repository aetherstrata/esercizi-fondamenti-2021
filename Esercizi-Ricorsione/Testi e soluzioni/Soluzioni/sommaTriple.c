#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) e verifica se ogni tre elementi 
 * consecutivi nella sequenza sono tali che uno è pari alla somma degli altri due: REALIZZAZIONE 1 */
int sommaTriple(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int sommabile;			// tutte le triple soddisfano la proprietà?
	
	/* CASO BASE */
	if(lunghezza<=2)
		sommabile = 1;
	else
	/* PASSO RICORSIVO */
		sommabile = ((interi[0]==interi[1]+interi[2]) ||
		(interi[1]==interi[0]+interi[2]) || (interi[2]==interi[0]+interi[1])) 
		&& sommaTriple(interi+1,lunghezza-1);

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
