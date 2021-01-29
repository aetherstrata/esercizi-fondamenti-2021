/* SPECIFICA * 
 * Input: sequenza s di numeri e una lunghezza l * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori devono essere interi * 
 * Output: true/false * 
 * Post-condizione: ogni tripla di interi consecutivi nella sequenza deve contenere due interi la cui somma è 10 * 
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int TripleSomma10(int arr[], int len){
	int risultato = 1;
	int i = 0;
	
	while(risultato == 1 && i<len-2){
		if(arr[i]+arr[i+1]==10 || arr[i+1]+arr[i+2]==10 || arr[i]+arr[i+2]==10){
			i++;
		} 
		else
			risultato = 0;
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che ogni tripla di interi consecutivi nella sequenza contenga due interi la cui somma %c 10.\n", 138);
	
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
	
	if(TripleSomma10(array, lunghezza))
		printf("\nOgni tripla di interi consecutivi nella sequenza contiene due interi la cui somma %c 10!\n", 138);
	else
		printf("\nNON ogni tripla di interi consecutivi nella sequenza deve contiene due interi la cui somma %c 10!\n", 138);
	
	return 0;
}