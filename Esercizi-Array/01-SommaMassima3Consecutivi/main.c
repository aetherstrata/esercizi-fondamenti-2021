/* SPECIFICA * 
 * Input: sequenza s di interi di lunghezza l * 
 * Pre-condizione: l >= 3 / l è la lunghezza di s / gli elementi di s devono essere tutti interi * 
 * Output: (int)massimo * 
 * Post-condizione: massimo è la somma massima di tre interi consecutivi nella sequenza * 
 * TIPO DI PROBLEMA: massimo */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int SommaMassima3Consecutivi(int arr[], int len){
	//Si inizializza il massimo alla somma dei primi tre elementi
	int massimo=arr[0]+arr[1]+arr[2];
	
	for(int i=1; i<len-2;i++){
		if(arr[i]+arr[i+1]+arr[i+2]>massimo)
			massimo = arr[i]+arr[i+1]+arr[i+2];
	}
	
	return massimo;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma calcola la somma massima di tre interi consecutivi di una sequenza di numeri.\n");
	
	printf("Da quanti numeri %c composta la sequenza di numeri?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	
	printf("Inserisci la sequenza di interi:\n");
	for(int i=0; i<lunghezza; i++){
		scanf("%d", &array[i]);
	}
	
	printArray(array, lunghezza);
	
	printf("La somma massima di tre interi consecutivi della sequenza %c %d\n", 138, SommaMassima3Consecutivi(array, lunghezza));
	
	return 0;
}
