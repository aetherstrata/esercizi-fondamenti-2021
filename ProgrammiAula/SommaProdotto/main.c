#include <stdio.h>

/* funzione che verifica se nell'array parametro esiste una tripla di elementi consecutivi
 * tali che la somma o il prodotto dei primi due sia pari al terzo: REALIZZAZIONE 1 */
 int sommaProdotto(int interi[], int lung){
	// Pre: lunghezza è la lunghezza di interi
    int esiste; 		// il risultato da restituire
	
    if (lung<=2) 
		/* non hai abbastanza interi */
        esiste = 0; 
    else 
		/* hai ancora triple da controllare */
        esiste = (interi[lung-3] + interi[lung-2]==interi[lung-1]) ||
					(interi[lung-3] * interi[lung-2]==interi[lung-1]) ||  
					sommaProdotto(interi,lung-1);

  return esiste; 
}

/* funzione principale */
int main() {
	int lunghezza;		// numero di elementi dell'array
	
	/* INPUT */
	printf("Ciao utente, sono un programma che legge una sequenza di interi e verifica se ne ");
	printf("esistono tre consecutivi tali che la somma o il prodotto dei primi due %c ", 138);
	printf("pari al terzo.\n\n");
	
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	if(sommaProdotto(sequenza,lunghezza)) 
		printf("\nEsistono tre interi consecutivi tali la somma o il prodotto dei primi due %c pari al terzo", 138);
	else 		
		printf("\nNon esistono tre interi consecutivi tali la somma o il prodotto dei primi due %c pari al terzo", 138);
}  
