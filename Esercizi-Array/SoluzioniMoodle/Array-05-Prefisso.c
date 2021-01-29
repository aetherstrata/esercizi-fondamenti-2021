 /* SPECIFICA
  * Input: una sequenza di interi s e la sua lunghezza ls, 
  * 		   una sequenza di interi t e la sua lunghezza lt
  * Pre-condizione: ls è la lunghezza di s e lt è la lunghezza di t 
  * Output: Un intero pref
  * Post-condizione: pref è pari a 1 se s è un prefisso di t, a 0 altrimenti
  * TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>

/* funzione che prende come parametro un array di interi s (e la sua lunghezza) 
 * ed un array di interi t (e la sua lunghezza) e restituisce 1 
 * se s è un prefisso di t, 0 altrimenti */
int prefisso(int s[], int ls, int t[], int lt) {
	// pre: ls è la lunghezza di s e lt è la lunghezza di t 
	int pref;			// variabile universale
	int i;				// variabile contatore
	
	/* se s è più lunga di t, non ne può essere un prefisso */
	if(ls>lt)
		pref=0;
	else
		pref=1;
	
	/* confronta tutti i caratteri di s con i corrispondenti di t; interrompi
		se hai concluso che s non è un prefisso di t */
	i=0;
	while(i<ls && pref)
		/* carattere diverso? */
		if(s[i]!=t[i])
			pref=0;
		else
			i++;
	
	return pref;
}
 
/* funzione principale */
int main() {
	int lunghezza1;		// numero di elementi del primo array
	int lunghezza2;		// numero di elementi del secondo array
	
	/* INPUT */ 
	printf("Ciao utente, sono un programma che legge due sequenze di interi ");
	printf("e verifica se la prima %c un prefisso della seconda.", 138);
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
	if(prefisso(sequenza1, lunghezza1, sequenza2, lunghezza2))
		printf("\nLa prima sequenza %c prefisso della seconda.\n", 138);
	else
		printf("\nLa prima sequenza non %c prefisso della seconda.\n", 138);
}
