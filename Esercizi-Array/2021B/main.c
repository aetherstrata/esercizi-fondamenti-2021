/* SPECIFICA * 
 * Input: sequenza s di lunghezza l * 
 * Pre-condizione: l>=3 / l è la lunghezza di s / tutti gli elementi di s sono interi * 
 * Output: true/false * 
 * Post-condizione: true se esiste una tripla tale che esattamente due elementi siano maggiori o uguali a 5 e almeno 2 elementi siano pari, false altrimenti * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

int isPari(int arr[], int index)
{
	if(arr[index]%2==0){
		return 1;
	} else {
		return 0;
	}
}

int triplaMaggiore5Pari(int arr[], int len)
{
	for(int i=2; i<len; i++){
		if ((isPari(arr, i-2) && isPari(arr, i-1)) || (isPari(arr, i) && isPari(arr, i-1)) || (isPari(arr, i) && isPari(arr, i-2))){
			if ((arr[i-2]>=5 && arr[i-1]>=5 && !(arr[i]>=5)) || (arr[i-1]>=5 && arr[i]>=5 && !(arr[i-2]>=5)) || (arr[i-2]>=5 && arr[i]>=5 && !(arr[i-1]>=5))){
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma verifica che esiste una tripla tale che esattamente due elementi siano maggiori o uguali a 5 e almeno 2 elementi siano pari.\n");
	printf("Da quanti interi %c composta la sequenza?\n", 138);
	scanf("%d", &lunghezza);
	
	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci l'intero di indice %d: ", i);
		scanf("%d", &array[i]);
	}
	
	if(triplaMaggiore5Pari(array, lunghezza)){
		printf("Esiste una tripla tale che esattamente due elementi sono maggiori o uguali a 5 e almeno 2 elementi sono pari!\n");
	} else {
		printf("NON esiste una tripla tale che esattamente due elementi sono maggiori o uguali a 5 e almeno 2 elementi sono pari!\n");
	}
	
	return 0;
}
