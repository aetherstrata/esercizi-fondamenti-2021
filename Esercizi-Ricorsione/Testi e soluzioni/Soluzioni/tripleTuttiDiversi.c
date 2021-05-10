#include <stdio.h>

/* funzione che verifica se ogni tripla di interi adiacenti nell'array parametro è 
 * composta da interi tutti diversi fra loro. */
int tripleDiverse(int sequenza[], int l) {
	// pre: l è la lunghezza di sequenza
	int risultato;			// per il risultato
	/* CASO BASE */
	if(l<=2)
		risultato = 1;
	/* PASSO RICORSIVO */
	else
		risultato = tripleDiverse(sequenza,l-1) && 
					(sequenza[l-3]!= sequenza[l-2]) &&
					(sequenza[l-3]!= sequenza[l-1]) &&
					(sequenza[l-2]!= sequenza[l-1]);
	return risultato;
} 
 
 
/* funzione principale */ 
int main() {
	int lunghezza;		// numero elementi array
	
	/* input */
	printf("Ciao, io verifico se, in una sequenza di interi, ogni tre interi ");
	printf("consecutivi sono fra loro diversi.\n\n");
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	/* output */
	if(tripleDiverse(sequenza,lunghezza))
		printf("\nOgni tre interi consecutivi sono fra loro diversi!\n");
	else
		printf("\nEsiste una tripla di interi consecutivi con due interi uguali!\n");
}
