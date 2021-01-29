/* SPECIFICA * 
 * Input: sequenza s di numeri di lunghezza l * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori devono essere interi * 
 * Output: un valore booleano * 
 * Post-condizione: vero se esiste una tripla di interi consecutivi nella sequenza che contiene due interi il cui prodotto è 12, falso altrimenti. * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int triplaProdotto12(int arr[], int len){
	for(int i=0; i<len-2; i++)
		if(arr[i]*arr[i+1]==12 || arr[i+1]*arr[i+2]==12 || arr[i]*arr[i+2]==12)
			return 1;
	return 0;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che esiste una tripla di interi consecutivi nella sequenza che contiene due interi il cui prodotto %c 12.\n", 138);
	
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d", &lunghezza);
	printf("Inserisci una sequena di interi!\n");
	
	int array[lunghezza];
	
	for(int i=0; i<lunghezza; i++){
		scanf("%d", &array[i]);
	}

	//Stampa l'array

	printf("\nQuesta %c la tua sequenza:\n", 138);
	printArray(array, lunghezza);
	
	//Verifica condizione
	
	if(triplaProdotto12(array, lunghezza))
		printf("\nEsiste una tripla di interi consecutivi nella sequenza che contiene due interi il cui prodotto %c 12!\n", 138);
	else
		printf("\nNON esiste una tripla di interi consecutivi nella sequenza che contiene due interi il cui prodotto %c 12!\n", 138);
	
	return 0;
}
