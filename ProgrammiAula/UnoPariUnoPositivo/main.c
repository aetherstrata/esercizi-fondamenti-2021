#include <stdio.h>

int pariPositivo(int arr[], int len)
{
	int risultato;
	
	if(len<=1)
		risultato = 0;
/*Passo induttivo*/
	else 
		risultato = ((arr[0]%2==0 && arr[1]>0)||(arr[0]>0 && arr[1])) || pariPositivo(arr+1,len-1);
		
	return risultato;
}

int main(int argc, char **argv)
{
	int lunghezza;
	
	printf("Questo programma verifica se esiste almeno una coppia di interi consecutivi di cui uno %c pari e l'altro %c positivo.\n", 138, 138);
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
	
	if (pariPositivo(sequenza, lunghezza)){
		printf("ESISTE una coppia di interi consecutivi di cui uno %c pari e l’altro %c positivo.\n", 138, 138);
	} else {
		printf("NON ESISTE una coppia di interi consecutivi di cui uno %c pari e l’altro %c positivo.\n", 138, 138);
	}
	
	return 0;
}
