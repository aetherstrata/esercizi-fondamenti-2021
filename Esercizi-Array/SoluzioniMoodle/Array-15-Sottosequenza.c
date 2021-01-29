 /* SPECIFICA
  * Input: una sequenza di interi s e la sua lunghezza ls, 
  * 		   una sequenza di interi t e la sua lunghezza lt
  * Pre-condizione: ls è la lunghezza di s e lt è la lunghezza di t, ls>=1
  * Output: Un intero index
  * Post-condizione: index è pari al più piccolo indice di un elemento di t
  * a partire dal quale inizia una copia di s, è pari a -1 altrimenti
  * TIPO DI PROBLEMA: Ricerca (contiene anche un problema di verifica universale) */
#include <stdio.h>

/* funzione che prende come parametro un array di interi s (e la sua lunghezza) ed un array
 * di interi t (e la sua lunghezza) e restituisce il più piccolo indice di un elemento di t
 * a partire dal quale inizia una copia di s, oppure -1 se tale indice non esiste */
int sottosequenza(int s[], int ls, int t[], int lt) {
	// pre: ls è la lunghezza di s e lt è la lunghezza di t, ls >=1 
	int index = -1;			// valore da restituire
	int i, j;						// variabili contatore
	int uguali;					// variabile di universalità
	
	/* guarda tutti i possibili indici di t dai quali può iniziare una copia di s; visto che s
	 * è lunga ls, l'ultima sottosequenza di t da controllare ha indici lt-ls, lt-ls+1, ..., lt-1 */ 
	while(i<=lt-ls && index==-1) {
		/* verifica universale che la sottosequenza di t con indici i, i+1, ..., 
		 * i-1+lunghezza di s coincida con s */
		j = 0;
		uguali = 1;
		/* confronta i caratteri di s e t ad uno ad uno */ 
		while(j<ls && uguali) {
			if(s[j]!=t[i+j])
				uguali = 0;
			else
				j++;
		}
		/* se uguali è vero, hai trovato l'indice buono! */
		if(uguali)
			index = i;
		else
		/* altrimenti passa al prossimo elemento */
			i++;
	}
	return index;
}
 
/* funzione principale */
int main() {
	int lunghezza1;		// numero di elementi del primo array
	int lunghezza2;		// numero di elementi del secondo array
	int indice;				// valore da calcolare
	
	/* INPUT */ 
	printf("Ciao utente, sono un programma che legge due sequenze di interi ");
	printf("e determina l'indice del primo elemento della seconda sequenza ");
	printf("a partire dal quale inizia una copia della prima sequenza.");
	printf("\n\nQuanti interi ha la prima sequenza? ");
	scanf("%d", &lunghezza1);
	
	int sequenza1[lunghezza1];
	printf("\n");
	for(int i=0; i<lunghezza1; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza1[i]);
	}

	printf("\nQuanti interi ha la seconda sequenza? ");
	scanf("%d", &lunghezza2);
	
	int sequenza2[lunghezza2];
	printf("\n");
	for(int i=0; i<lunghezza2; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza2[i]);
	}

	/* OUTPUT */
	indice = sottosequenza(sequenza1, lunghezza1, sequenza2, lunghezza2);
	if(indice!=-1) {
		printf("\nA partire dall'elemento della seconda sequenza con indice %d ", indice);
		printf("inizia una copia della prima sequenza.");
	}
	else
		printf("\nLa prima sequenza non %c contenuta nella seconda.\n", 138);
}
