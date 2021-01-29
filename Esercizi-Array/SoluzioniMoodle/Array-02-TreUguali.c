 /* SPECIFICA
  * Input: Una sequenza s di interi e la sua lunghezza l
  * Pre-condizione: l è la lunghezza di s 
  * Output: Un intero indice3
  * Post-condizione: indice3 è il minimo indice di un intero uguale ai due consecutivi, 
  * o è pari a -1 se tali interi non esistono 
  * TIPO DI PROBLEMA: Ricerca
  */
#include <stdio.h>

/* funzione che prende come parametro un array di interi (e la sua lunghezza) 
 * e restituisce il minimo indice di un intero uguale ai due consecutivi, oppure
 * -1 se tali tre interi non esistono */
int uguali3(int interi[], int lunghezza) {
	// pre: lunghezza è la lunghezza di interi
	int indice3;			// indice cercato
	int i;						// variabile contatore
	
	/* inizializzazione valore non significativo */
	indice3 = -1;
	
	/* guarda tutte le triple di elementi consecutivi; interrompi se ne trovi una 
	 * i cui elementi sono tutti uguali */
	i=0;
	while(i<lunghezza-2 && indice3==-1) {
		if(interi[i]==interi[i+1] && interi[i]==interi[i+2])
			indice3=i;
		else
			i++;
	}
	return indice3;
}
 
/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	int indice;				// indice richiesto
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
	printf("e trova gli indici dei primi tre consecutivi uguali.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	indice = uguali3(sequenza,lunghezza);
	if(indice==-1)
		printf("\nNon esistono tre interi consecutivi uguali!\n");
	else {
		printf("\nI primi tre interi consecutivi uguali nella sequenza ");
		printf("hanno indici %d, %d, e %d!\n", indice, indice+1, indice+2);
	}
}
