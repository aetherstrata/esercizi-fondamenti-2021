/* SPECIFICA * 
 * Input: sequenza s di interi e la lunghezza l  * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori sono interi * 
 * Output: vero/falso *
 * Post-condizione: un valore della sequenza deve essere la differenza dei due elementi adiacenti * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int differenzaAdiacenti(int arr[], int len){
	
	for(int i=0; i<len; i++){
		if((arr[i-1]-arr[i+1]==arr[i]) || (arr[i+1]-arr[i-1]==arr[i])){
			return 1;
		}
	}
	
	return 0;
	
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che almeno un valore della sequenza sia uguale alla la differenza dei due valori adiacenti.\n");
	
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
	
	// Verifica condizione
	
	if(differenzaAdiacenti(array, lunghezza))
		printf("\nEsistono tre elementi adiacenti tali che il valore dell%c elemento intermedio %c pari alla differenza fra i valori degli elementi adiacenti!\n", 39, 138);
	else
		printf("\nNON esistono tre elementi adiacenti tali che il valore dell%c elemento intermedio %c pari alla differenza fra i valori degli elementi adiacenti!\n", 39, 138);
	
	return 0;
}
