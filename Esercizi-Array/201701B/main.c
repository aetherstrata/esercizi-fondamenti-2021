/* SPECIFICA * 
 * Input: sequenza s di interi e la lunghezza l  * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori sono interi * 
 * Output: vero/falso *
 * Post-condizione: tutti i valori della sequenza devono essere divisori di (almeno) un elemento adiacente * 
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int adiacentiDivisibili(int arr[], int len){
	int risultato = 1;
	int i = 0;
	
	while (risultato == 1 && i<len-1){		
		if(arr[i]%arr[i+1]!=0 &&  arr[i+1]%arr[i]!=0) 
			risultato = 0;
		i++;
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che tutti i valori della sequenza siano divisori di (almeno) un elemento adiacente.\n");
	
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
	
	if(adiacentiDivisibili(array, lunghezza))
		printf("\nTutti i valori della sequenza sono divisori di un elemento adiacente!\n");
	else
		printf("\nNON tutti i valori della sequenza sono divisori di un elemento adiacente!\n");
	
	return 0;
}
