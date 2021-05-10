#include <stdio.h>
#include <stdio.h>

/* 3 DIVERSE FUNZIONI numeroPositivi sotto*/
 
/* funzione che riceve come parametro una sequenza di interi e calcola e restituisce 
 * il numero di valori positivi nella sequenza: REALIZZAZIONE 3 */
int numeroPositivi(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int quanti;		// numero di elementi positivi dell'array

	/* CASO BASE */
	if(lunghezza == 0)
		quanti = 0;
	else
	/* PASSO RICORSIVO */
		if(interi[lunghezza-1]>0)
			quanti = 1 + numeroPositivi(interi,lunghezza-1);
		else 
			quanti = numeroPositivi(interi,lunghezza-1);
			
	return quanti;
}

/* funzione che riceve come parametro una sequenza di interi e calcola e restituisce 
 * il numero di valori positivi nella sequenza: REALIZZAZIONE 3 */
int numeroPositivi2(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int quanti;		// numero di elementi positivi dell'array

	/* CASO BASE */
	if(lunghezza == 0)
		quanti = 0;
	else
	/* PASSO RICORSIVO */
		if(interi[0]>0)
			quanti = 1 + numeroPositivi(interi+1,lunghezza-1);
		else 
			quanti = numeroPositivi(interi+1,lunghezza-1);

	return quanti;
}

/* funzione che riceve come parametro una sequenza di interi e calcola e 
 * restituisce il numero di valori positivi nella sequenza: REALIZZAZIONE 3bis */
int numeroPositivi3(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int quanti;		// numero di elementi positivi dell'array

	/* CASO BASE */
	if(lunghezza == 0)
		quanti = 0;
	else
	/* PASSO RICORSIVO */
		quanti = (interi[0]>0) + numeroPositivi(interi+1,lunghezza-1);
		
	return quanti;
}

/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io calcolo il numero di valori positivi di una sequenza di interi.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("\nIntroduci un intero! ");
		scanf("%d", &sequenza[i]);
	}

	/* output */
	printf("\nHai introdotto %d numeri positivi!\n", numeroPositivi(sequenza,lunghezza));
}
