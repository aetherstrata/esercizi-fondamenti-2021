#include <stdio.h>


/* funzione che trasforma un array i cui elementi sono interi compresi fra 0 e 9 in un
 * numero le cui cifre sono gli elementi dell'array: REALIZZAZIONE 1 */
int trasforma(int a[], int lungh){
	int numero; 		// valore da restituire 

	if (lungh==1)
		/* un solo elemento */
		numero = a[0];
	else 
		/* più elementi */
		numero = trasforma(a,lungh-1)*10+a[lungh-1];

	return numero;
}

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di cifre e la ");
	printf("trasforma in un intero, che viene poi stampato.\n\n");
	
	printf("Quante cifre vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero ad una sola cifra: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	printf("\nEcco il numero corrispondente all'array: %d", trasforma(sequenza,lunghezza));
}  
