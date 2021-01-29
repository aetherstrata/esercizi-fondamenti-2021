 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s, ciascuna intero in s è pari a 0 o 1 
  * Output: Un intero numero
  * Post-condizione: numero è la rappresentazione decimale del numero
  * la cui rappresentazione binaria è data dalla sequenza l
  *
  * TIPO DI PROBLEMA: Accumulazione */
  
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * che corrisponde alla rappresentazione binaria di un numero e calcola la 
 * rappresentazione decimale del numero stesso */
int decodifica(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi, ciascun intero nella sequenza è pari a 0 o 1
	int decimale;					// la rappresentazione decimale del numero
	int potenza;					// la potenza di due corrente
	decimale = 0;				 	// inizialmente la rappresentazione decimale è 0
	potenza = 1;					// la cifra meno significativa rappresenta 2^0
	
	/* guarda tutti gli elementi... */
	for(int i=0; i<lunghezza; i++) {
		/* aggiorna il totale con la cifra ad 'i' posizioni dal fondo; tale cifra è un fattore per 
			una potenza di 2 che vale 'potenza' */
		decimale += (interi[lunghezza-i-1] * potenza);
		potenza *=2;				// aggiorna la potenza di 2 per il prossimo giro
	}
	
	return decimale;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge la rappresentazione binaria ");
	printf("di un numero e ne calcola la rappresentazione decimale.\n\n");
	printf("Quanti cifre binarie ha il numero? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci uno 0 o un 1: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	printf("\nLa rappresentazione decimale del numero %c %d.\n", 138, decodifica(sequenza, lunghezza));
}
