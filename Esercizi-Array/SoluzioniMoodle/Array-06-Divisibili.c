 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero multipli
  * Post-condizione: multipli è pari ad 1 se esiste una coppia di interi uno dei quali
  * divide l'altro, è pari a 0 altrimenti
  * TIPO DI PROBLEMA: Verifica esistenziale */
  
#include <stdio.h>

/* funzione che riceve come parametro una sequenza di interi (e la sua lunghezza) 
 * e verifica se esistono due interi uno dei quali divide l'altro */
int divisibili(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	
	int i, j;					// variabili contatore
	int multipli;			// hai trovato due interi, uno dei quali divide l'altro
	multipli =0;			// inizialmente no
	
	/* fintanto che ci sono elementi da confontare con altri... */
	i = 0;
	while(i<lunghezza-1 && !multipli) {
		/* l'elemento con indice i va confrontato con tutti quelli successivi nell'array */
		j = i+1;
		while(j<lunghezza && !multipli) {
			/* verifica se l'elemento con indice i divide l'elemento con indice j o viceversa */
			if(interi[i]%interi[j]==0 || interi[j]%interi[i]==0)
				multipli=1;
			else
				j++;
		}
		i++;
	}
	return multipli;
}

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e verifica se esistono due interi che sono uno divisibile per l'altro.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(divisibili(sequenza,lunghezza))
		printf("\nEsistono due interi uno dei quali divide l'altro!\n");
	else
		printf("\nNon esistono due interi uno dei quali divide l'altro!\n");
}
