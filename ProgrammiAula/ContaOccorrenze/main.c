#include <stdio.h>

/* legge un array e controlla quante volte compare un intero scelto*/

int main()
{
	int lunghezza, valore, conteggio;
	
	// Input
	printf("QUale valore vuoi cercare?\n");
	scanf("%d", &valore);
	
	printf("Da quanti interi %c composto l'array?\n", 138);
	scanf("%d", &lunghezza);
	
	int sequenza[lunghezza];
	
	// Popola l'array con i dati indicati dall'utente
	for(int i=0; i<lunghezza; i++){
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	
	printf("\n");
	printf("L'array %c stato popolato!\n", 138);
	
	// Conta quante volte compare il valore indicato
	for(int i=0; i<lunghezza; i++){
		if (sequenza[i]==valore)
			conteggio++;
	}
	
	printf("\n");
	printf("Ci sono %d valori che valgono %d!", conteggio, valore);
	
	return 0;
}
