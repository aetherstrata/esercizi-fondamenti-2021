#include <stdio.h>

/* 2 SOLUZIONI */

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza) 
 * e verifica se la sequenza è crescente: REALIZZAZIONE 3 */
int crescente(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int cresce;			// la sequenza è crescente?
	
	/* CASO BASE */
	if(lunghezza<=1)
		cresce = 1;
	/* PASSO RICORSIVO */
	else
		if(interi[0]>=interi[1])
			cresce =  0;
		else
			cresce = crescente(interi+1,lunghezza-1);

	return cresce;
}

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza) 
 * e verifica se la sequenza è crescente: REALIZZAZIONE 3*/
int crescente2(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int cresce;			// la sequenza è crescente?
	
	/* CASO BASE */
	if(lunghezza<=1)
		cresce = 1;
	/* PASSO RICORSIVO */
	else
		cresce = (interi[0]<interi[1]) && crescente(interi+1,lunghezza-1);

	return cresce;
}

/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io verifico se una sequenza di interi %c crescente.\n", 138);
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("\nIntroduci un intero! ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(crescente(sequenza,lunghezza))
		printf("\nSequenza crescente!\n");
	else
		printf("\nSequenza non crescente!\n");
}
