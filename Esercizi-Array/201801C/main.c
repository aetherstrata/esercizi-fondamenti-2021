/* SPECIFICA * 
 * Input: sequenza s di numeri di lunghezza l * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori devono essere interi * 
 * Output: un valore booleano * 
 * Post-condizione: vero se ogni tripla di interi consecutivi nella sequenza contiene due interi il cui prodotto è -12, falso altrimenti. * 
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int tripleProdottoMeno12(int arr[], int len){
	int i = 0;
	int risultato = 1;
	
	while (risultato == 1 && i<len-2){
		if(arr[i]*arr[i+1]==-12 || arr[i+2]*arr[i+1]==-12 || arr[i]*arr[i+2]==-12)
			i++;
		else
			risultato = 0;
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che tutte le triple di interi consecutivi nella sequenza contengono due interi il cui prodotto %c -12.\n", 138);
	
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
	
	if(tripleProdottoMeno12(array, lunghezza))
		printf("\nTutte le triple di interi consecutivi nella sequenza contengono due interi il cui prodotto %c -12!\n", 138);
	else
		printf("\nNON tutte le triple di interi consecutivi nella sequenza contengono due interi il cui prodotto %c -12!\n", 138);
	
	return 0;
}