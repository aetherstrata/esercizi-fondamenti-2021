/* SPECIFICA 
 * Input: sequenza s di lunghezza l
 * Pre-Condizione: l>=3 /l è la lunghezza di s / s contiene tutti numeri interi
 * Output: true/false
 * Post-Condizione: true se esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è 
 *                  compreso tra -10 e 10 e che contiene esattamente due multipli di 3
 * TIPO DI PROBLEMA: verifica esistenziale
 */

#include <stdio.h>

//Questa funzione controlla che un numero dato sia compreso tra -10 e 10
int compreso10(int arr[], int index){
	if(arr[index]>=-10 && arr[index]>=-10)
		return 1;
	return 0;
}

//Questa funzione controlla che un numero dato sia multiplo di 3
int multiplo3(int arr[], int index){
	if(arr[index]%3==0)
		return 1;
	return 0;
}

// Vedi specifica
int compresiMultipli3(int arr[], int len)
{
	for(int i=2; i<len; i++){
		if((compreso10(arr, i-2) && compreso10(arr, i-1)) || (compreso10(arr, i-2) && compreso10(arr, i)) || (compreso10(arr, i) && compreso10(arr, i-1))){
			if((multiplo3(arr, i-2) && multiplo3(arr, i-1) && !(multiplo3(arr, i))) || (multiplo3(arr, i-2) && multiplo3(arr, i) && !(multiplo3(arr, i-1))) || (multiplo3(arr, i) && multiplo3(arr, i-1) && !(multiplo3(arr, i-2)))){
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma verifica che in una sequenza esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	printf("Da quanti interi %c formata la sequenza?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Inserisci l'intero di indice %d: ", i);
		scanf("%d", &array[i]);
	}
	
	if(compresiMultipli3(array, lunghezza)){
		printf("In questa sequenza ESISTE una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	} else {
		printf("In questa sequenza NON ESISTE una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente due multipli di 3\n", 138);
	}
	
	return 0;
}
