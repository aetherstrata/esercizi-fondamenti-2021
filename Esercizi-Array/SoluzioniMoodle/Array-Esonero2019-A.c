/*SPECIFICA
 * Input: una sequenza di interi 'sequenza' ed un intero 'lunghezza'
 * Pre-condizione: 'lunghezza' è la dimensione della sequenza
 * Output: un intero 'duePari'
 * Post-condizione: 'duePari' è pari ad 1 nel caso in cui ogni tripla di interi consecutivi nella 
 * sequenza contiene esattamente due interi pari, è pari a 0 altrimenti
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

/* funzione che verifica se ogni tripla di interi consecutivi in un array contiene 
 * esattamente due interi pari */
int tripleDuePari(int seq[], int lunghezza)
{
	int duePari=1;				// variabile di universalità
	int i=0;							// variabile contatore
	
	/* vai avanti fino a che ci sono elementi dell'array o non hai trovato la risposta*/
	while(i<=lunghezza-3 && duePari)	
		/* la tripla corrente non soddisfa la proprietà desiderata? */
		if(!((seq[i]%2==0 && seq[i+1]%2==0 && seq[i+2]%2!=0) || 
			(seq[i]%2==0 && seq[i+2]%2==0 && seq[i+1]%2!=0) ||
 			(seq[i+1]%2==0 && seq[i+2]%2==0 && seq[i]%2!=0)))
			/* la tripla corrente non soddisfa la proprietà desiderata! */
			duePari=0;
			/* altrimenti passa alla prossima */
		else	
			i++;

	return duePari;
}

/*funzione principale*/
int main(int argc, char **argv)
{
	/*Dichiarazione variabili*/
	int lunghezza;
	/*INPUT*/
	printf("Benvenuto, questo programma ti permette di verificare, in una sequenza di interi, ");
	printf("se ogni tripla di interi consecutivi nella sequenza contiene esattamente due interi pari\n");
	
	printf("Inserisci il numero di elementi che compongono la sequenza: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];	

	/*Riempimento array da tastiera*/
	for (int i=0; i<lunghezza;i++)	{
		printf("Inserisci un elemento: ");
		scanf("%d",&sequenza[i]);
	}
	
	/*OUTPUT*/
	if(tripleDuePari(sequenza, lunghezza))	{
		printf("\nOgni tripla di interi consecutivi nella sequenza contiene ");
		printf("esattamente due interi pari\n");
	}
	else {
		printf("\nNon tutte le triple di interi consecutivi nella sequenza contengono ");
		printf("esattamente due interi pari\n");
	}
}
