#include <stdio.h>

/* funzione ricorsiva per la verifica dell'esistenza di due interi
 * consecutivi tali che uno è il quadrato dell'altro in una
 * sequenza, a partire da un certo indice */
int quadratoRic(int sequenza[], int lunghezza, int i) {
	int risultato;		// per il risultato
	/* CASO BASE */
	if(i>=lunghezza-1)
		risultato = 0;
	else
	/* PASSO RICORSIVO */
		risultato = (sequenza[i]==sequenza[i+1]*sequenza[i+1]) || 
					(sequenza[i+1]==sequenza[i]*sequenza[i]) || 
					quadratoRic(sequenza, lunghezza, i+1);
	return risultato;
}


/* funzione che verifica se esiste un elemento che è 
 * il quadrato dell'elemento precedente o dell'elemento successivo */
int quadratoPrecSucc(int sequenza[], int lunghezza) {
	return quadratoRic(sequenza,lunghezza,0);
} 

/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io verifico se una sequenza di interi ne contiene due consecutivi ");
	printf("tali che uno %c il quadrato dell'altro.\n\n", 138);
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(quadratoPrecSucc(sequenza,lunghezza))
		printf("Esistono due interi consecutivi tali che uno %c il quadrato dell'altro!\n", 138);
	else
		printf("Non esistono due interi consecutivi tali che uno %c il quadrato dell'altro!\n", 138);
}
