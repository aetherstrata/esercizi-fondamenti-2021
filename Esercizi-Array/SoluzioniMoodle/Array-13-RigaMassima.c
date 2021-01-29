 /* SPECIFICA
  * Input: Una matrice m di interi ed il numero r delle sue righe
  * Pre-condizione: r è il numero di righe di m e r >=1 
  * Output: Un intero riga
  * Post-condizione: riga è pari alla somma massima degli elementi su una singola riga di m 
  * TIPO DI PROBLEMA: Massimo (con dei problemi di accumulazione all'interno) */

#include <stdio.h>

/* funzione che prende come parametro una matrice di interi (ed il numero delle sue righe) 
 * e restituisce la somma massima degli elementi su una singola riga della matrice */
int rigaMassima(int m[][3], int righe) {
	// pre: righe è il numero di righe di m, righe >=1
	int riga;			// la somma massima
	
	/* inizializza la somma a quella degli elementi della prima riga */
	riga = m[0][0]+m[0][1]+m[0][2];
	
	/* guarda tutte le altre righe della matrice di interi */
	for(int i=1; i<righe; i++) {
		/* la tripla attuale ha somma maggiore del massimo corrente? */
		if(m[i][0]+m[i][1]+m[i][2]>riga)
			riga = m[i][0]+m[i][1]+m[i][2];
	}
	
	return riga;
}
 
/* funzione principale */
int main() {
	int righe;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una matrice di interi n x 3 ");
	printf("e calcola la somma massima degli elementi su una stessa riga.\n\n");
	printf("Quante righe ha la tua matrice? ");
	scanf("%d", &righe);
	
	int matrice[righe][3];
	printf("\n");
	for(int i=0; i<righe; i++) {
		printf("Introduci il primo intero sulla riga con indice %d: ", i);
		scanf("%d", &matrice[i][0]);
		printf("Introduci il secondo intero sulla riga con indice %d: ", i);
		scanf("%d", &matrice[i][1]);
		printf("Introduci il terzo intero sulla riga con indice %d: ", i);
		scanf("%d", &matrice[i][2]);
		printf("\n");
	}

	/* OUTPUT */
	printf("La somma massima degli elementi di una singola riga vale %d.\n", rigaMassima(matrice, righe));
}
