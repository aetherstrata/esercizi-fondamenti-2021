/*SPECIFICA
 * Input: una sequenza di interi 'sequenza' ed un intero 'lunghezza'
 * Pre-condizione: 'lunghezza' è la dimensione della sequenza
 * Output: un intero 'contiene'
 * Post-condizione: 'contiene' è pari ad 1 nel caso in cui esiste una tripla di interi consecutivi 
 * nella sequenza che contiene esattamente due interi dispari, è pari a 0 altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

/* funzione che verifica se esiste una tripla di interi consecutivi in un array che contiene 
 * esattamente due interi dispari */
int tripleDueDis(int seq[], int lunghezza)
{
	int contiene=0;				// variabile di esistenza
	int i=0;							// variabile contatore
	
	/* vai avanti fino a che ci sono elementi dell'array o non hai trovato la risposta*/
	while(i<=lunghezza-3 && !contiene)	
		/* la tripla corrente soddisfa la proprietà desiderata? */
		if((seq[i]%2!=0 && seq[i+1]%2!=0 && seq[i+2]%2==0) || 
			(seq[i]%2!=0 && seq[i+2]%2!=0 && seq[i+1]%2==0) ||
 			(seq[i+1]%2!=0 && seq[i+2]%2!=0 && seq[i]%2==0))
			/* la tripla corrente soddisfa la proprietà desiderata! */
			contiene=1;
			/* altrimenti passa alla prossima */
		else	
			i++;

	return contiene;
}

/*funzione principale*/
int main(int argc, char **argv)
{
	/*Dichiarazione variabili*/
	int lunghezza;
	/*INPUT*/
	printf("Benvenuto, questo programma ti permette di verificare, in una sequenza di interi, ");
	printf("la presenza di tre interi consecutivi di cui esattamente due sono dispari\n");
	
	printf("Inserisci il numero di elementi che compongono la sequenza: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];	

	/*Riempimento array da tastiera*/
	for (int i=0; i<lunghezza;i++)	{
		printf("Inserisci un elemento: ");
		scanf("%d",&sequenza[i]);
	}
	
	/*OUTPUT*/
	if(tripleDueDis(sequenza, lunghezza))	{
		printf("\nLa sequenza contiene una tripla di interi consecutivi tale che ");
		printf("esattamente due interi sono dispari\n");
	}
	else {
		printf("\nLa sequenza non contiene alcuna tripla di interi consecutivi tale che ");
		printf("esattamente due interi sono dispari\n");
	}
}
