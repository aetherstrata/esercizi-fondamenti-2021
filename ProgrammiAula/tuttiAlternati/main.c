#include <stdio.h>

int tuttiAlternati(int arr[], int len)
{
	int risultato;
	
	if(len<=1)
		risultato=1;
	else // passo ricorsivo
		risultato = ((arr[len-2]>0 && arr[len-1]<0) || (arr[len-2]<0 && arr[len-1]>0)) && tuttiAlternati(arr, len-1);
	
	return risultato;
}

int main(int argc, char **argv)
{
	int lunghezza;
		
	printf("Questo programma verifica se i numeri positivi e negativi si alternano nella sequenza.\n");
	printf("Da quanti interi %c composta la sequenza? ", 138);
	
	while(lunghezza<2){
		scanf("%d", &lunghezza);
		if (lunghezza<2){
			printf("La sequenza deve essere composta da minimo due elementi!");
		}
	}
	
	int sequenza[lunghezza];
	
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci l'intero con indice %d: ", i);
		scanf("%d", &sequenza[i]);
	}
	
	if (tuttiAlternati(sequenza, lunghezza)){
		printf("TUTTI gli elementi si alternano tra valori negativi e positivi.\n");
	} else {
		printf("NON TUTTI gli elementi si alternano tra valori negativi e positivi.\n");
	}
		
	return 0;
}
