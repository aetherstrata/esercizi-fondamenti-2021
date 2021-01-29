/* SPECIFICA * 
 * Input: sequenza s di interi di lunghezza l * 
 * Pre-condizione: l è la lunghezza di s / gli elementi di s devono essere tutti interi * 
 * Output: int indice * 
 * Post-condizione: indice = indice di un elemento della sequenza tale che gli interi con indice i, i+1 e i+2 sono uguali * 
 * TIPO DI PROBLEMA: minimo */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int TreUguali(int arr[], int len){
	for(int i=0; i<len-2; i++){
		if(arr[i]==arr[i+1] && arr[i+1]==arr[i+2])
			return i;
	}
	
	return -1;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma trova il primo indice di un elemento di una sequenza tale che gli interi con indice i, i+1 e i+2 siano uguali.\n");
	
	printf("Da quanti numeri %c composta la sequenza di numeri?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	
	printf("Inserisci la sequenza di interi:\n");
	for(int i=0; i<lunghezza; i++){
		scanf("%d", &array[i]);
	}
	
	printArray(array, lunghezza);
	
	if(TreUguali(array, lunghezza)==-1)
		printf("Non esistono tre elementi consecutivi uguali.\n");
	else
		printf("Il primo indice per cui gli interi con indice i, i+1 e i+2 sono uguali %c %d\n", 138, TreUguali(array, lunghezza));
	
	return 0;
}
