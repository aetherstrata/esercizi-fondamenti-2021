/* SPECIFICA * 
 * Input: sequenza s di interi di lunghezza l * 
 * Pre-condizione: l è la lunghezza di s / tutti gli elementi devono essere interi * 
 * Output: true/false * 
 * Post-condizione: vero se almento metà degli elementi sono interi positivi, falso altimenti * 
 * TIPO DI PROBLEMA: Conteggio */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

//Lo zero non è considerato un elemento positivo
int PercentualePositivi(int arr[], int len){
	int conto=0;
	for(int i=0;i<len;i++){
		if(arr[i]>0)
			conto++;
	}
	if(conto>=(float)len/2)
		return 1;
	else
		return 0;
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
	
	if(PercentualePositivi(array, lunghezza)){
		printf("Almeno la metà degli elementi sono interi positivi!");
	} else {
		printf("Non ci sono abbastanza interi positivi.");
	}
	
	return 0;
}
