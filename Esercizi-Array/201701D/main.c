/* SPECIFICA * 
 * Input: sequenza s di interi e la lunghezza l  * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori sono interi * 
 * Output: true/false * 
 * Post-condizione: presi tre elementi adiacenti, la somma o il prodotto fra i valori dei primi due elementi è pari al valore del terzo elemento * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

void printArray(int arr[], int len)
{
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int SommaProdotto(int arr[], int len){	
	for(int i=0; i<len-2; i++){
		if(arr[i]*arr[i+1]==arr[i+2] || arr[i]+arr[i+1]==arr[i+2])
			return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che, presi tre elementi adiacenti, la somma o il prodotto fra i valori dei primi due elementi %c pari al valore del terzo elemento.\n", 138);
	
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
	
	if(SommaProdotto(array, lunghezza))
		printf("\nEsiste una terna la cui somma o prodotto fra i valori dei primi due elementi %c pari al valore del terzo elemento!\n", 138);
	else
		printf("\nNON Esiste una terna la cui somma o prodotto fra i valori dei primi due elementi %c pari al valore del terzo elemento!\n", 138);
	
	return 0;
}
