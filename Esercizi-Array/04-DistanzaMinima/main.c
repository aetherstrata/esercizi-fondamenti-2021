/* SPECIFICA * 
 * Input: sequenza s di interi di lunghezza l * 
 * Pre-condizione: l>=2 / l è la lunghezza di s / tutti gli elementi devono essere interi * 
 * Output: int distanza * 
 * Post-condizione: distanza = differenza minima tra due elementi adiacenti * 
 * TIPO DI PROBLEMA: Minimo */


#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int distanzaMinima(int arr[], int len){
	int minimo;
	if(arr[0]>arr[1])
		minimo = arr[0]-arr[1];
	else
		minimo = arr[1]-arr[0];
	
	int distanza;
	for(int i=1;i<len-1;i++){
		if(arr[i]>arr[i+1])
			distanza = arr[i]-arr[i+1];
		else
			distanza = arr[i+1]-arr[i];
		if(distanza<minimo)
			minimo=distanza;
	}
	
	return minimo;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma controlla che almento metà degli elementi sono interi positivi.\n");
	
	printf("Da quanti numeri %c composta la sequenza di numeri?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	
	printf("Inserisci la sequenza di interi:\n");
	for(int i=0; i<lunghezza; i++){
		scanf("%d", &array[i]);
	}
	
	printArray(array, lunghezza);
	
	printf("La distanza minima tra due valori vale %d\n", distanzaMinima(array, lunghezza));
	
	return 0;
}
