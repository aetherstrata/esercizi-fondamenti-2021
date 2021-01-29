/* SPECIFICA * 
 * Input: sequenza s di interi e la lunghezza l  * 
 * Pre-condizione: l è la lunghezza di s e tutti i valori sono interi * 
 * Output: true/false * 
 * Post-condizione: tutte le terne di elementi adiacenti sono tali che uno dei tre elementi è pari alla somma degli altri due * 
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

void printArray(int arr[], int len)
{
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int SommaTriple(int arr[], int len)
{
	int risultato = 1;
	int i = 0;
	
	while(risultato==1 && i<len-2){
		if(arr[i]+arr[i+1]==arr[i+2] || arr[i]+arr[i+2]==arr[i+1] || arr[i+1]+arr[i+2]==arr[i])
			i++;
		else {
			risultato = 0;
		}
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	//Operazioni preliminari
	
	int lunghezza;
	
	printf("Questo programma verifca che tutte le terne di elementi adiacenti siano tali che uno dei tre elementi è pari alla somma degli altri due.\n");
	
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
	
	if(SommaTriple(array, lunghezza))
		printf("\nTutte le terne di elementi adiacenti sono tali che uno dei tre elementi %c pari alla somma degli altri due!\n", 138);
	else
		printf("\nNON tutte le terne di elementi adiacenti sono tali che uno dei tre elementi %c pari alla somma degli altri due!\n", 138);
	
	return 0;
}

