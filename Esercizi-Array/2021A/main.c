/* SPECIFICA * 
 * Input: sequenza s di lunghezza l * 
 * Pre-condizione: l>=3 / l è la lunghezza di s / tutti gli elementi di s sono interi * 
 * Output: true/false * 
 * Post-condizione: true se esiste una tripla tale che la somma di almeno due elementi è compresa tra 10 e 20 e che esattamente 2 elementi siano uguali, false altrimenti * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

int sommaCompresa(int arr[], int a, int b)
{
	if (arr[a]+arr[b]<=20 && arr[a]+arr[b]>=10){
		return 1;
	} 
	else {
		return 0;
	}
}

int TriplaSommaDueUguali(int arr[], int len)
{
	for(int i=0; i<len; i++){
		if(sommaCompresa(arr, i-2, i-1) || sommaCompresa(arr, i-2, i) || sommaCompresa(arr, i, i-1)){
			if (arr[i-2]==arr[i] || arr[i-2]==arr[i-1] || arr[i]==arr[i-1]){
				return 1;
			}
		}
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma verifica che esiste una tripla tale che la somma di almeno due elementi %c compresa tra 10 e 20 e che esattamente 2 elementi siano uguali\n", 138);
	printf("Da quanti interi %c composta la sequenza?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci l'intero di indice %d: ", i);
		scanf("%d", &array[i]);
	}
	
	if(TriplaSommaDueUguali(array, lunghezza)){
		printf("Esiste una tripla tale che la somma di almeno due elementi %c compresa tra 10 e 20 e che esattamente 2 elementi siano uguali!\n", 138);
	} else {
		printf("NON esiste una tripla tale che la somma di almeno due elementi %c compresa tra 10 e 20 e che esattamente 2 elementi siano uguali!\n", 138);
	}
	
	return 0;
}
