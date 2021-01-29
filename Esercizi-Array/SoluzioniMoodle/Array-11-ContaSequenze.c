 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero numeroSequenze
  * Post-condizione: numeroSequenze è pari al numero di sotto-sequenze 
  * massimali di interi consecutivi che sono tutti positivi o tutti negativi
  * 
  * TIPO DI PROBLEMA: Conteggio
  */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce il numero di sotto-sequenze massimali di interi consecutivi 
 * che sono tutti positivi o tutti negativi */
int contaSequenze(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int numeroSequenze;		// il numero di sequenze
	numeroSequenze = 0; 	// nessuna sequenza inizialmente
	
	/* guarda tutti gli elementi... */
	for(int i=0; i<lunghezza; i++) {
		/* se sei sul primo elemento della sequenza, allora  sta iniziando una 
		 * nuova sequenza se l'elemento corrente è diverso da 0 */
		if(i==0) { 
			if(interi[i]!=0)
				numeroSequenze++;
		}
		else{
			/* altrimenti ti devi confrontare con il precedente: sta iniziando una nuova 
			 * sequenza se il corrente è positivo e il precedente non è positivo oppure se
			 * il corrente è negativo ed il precedente non è negativo */
			if((interi[i]>0 && interi[i-1]<=0) || (interi[i]<0 && interi[i-1]>=0)) 
				numeroSequenze++;
		}
	}
	
	return numeroSequenze;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e calcola il numero di sotto-sequenze massimali di interi consecutivi ");
	printf("che sono tutti positivi o tutti negativi.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	printf("\nIl numero di sotto-sequenze massimali di interi consecutivi che sono tutti ");
    printf("positivi o tutti negativi %c %d.\n", 138, contaSequenze(sequenza, lunghezza));
}
