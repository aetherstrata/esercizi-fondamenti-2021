#include <stdio.h>
#include <stdlib.h>

int massimo(int* arr, int len)
{
	int max = arr[0];
	
	for(int i=0; i<len; i++){
		if(*(arr+i)>max){
			max = *(arr+i);
		}
	}
	
	return max;
}

int main(int argc, char **argv)
{
	printf("Inserisci una sequenza di interi.\n");
	
	int* seq = malloc(sizeof(int));
	char risposta = 'n';
	int lunghezza = 0;
	
	do {
		printf("#%d: ", lunghezza);
		scanf("%d%*c", seq+lunghezza);
		lunghezza++;
		
		printf("Vuoi aggiungere un altro intero?\n");
		printf("(y/N) ");
		scanf("%c", &risposta);
		
		if (risposta == 'Y' || risposta == 'y'){
			seq = (int*) realloc(seq,sizeof(seq)+sizeof(int));
		}
	} 
	while (risposta == 'Y' || risposta == 'y');
	
	printf("Valori inseriti: | ");
	for(int i=0; i<lunghezza; i++){
		printf("%d | ", seq[i]);
	}
	printf("\n");
	
	int max = massimo(seq, lunghezza);
	
	printf("Il massimo valore della sequenza vale %d.\n", max);
	
	return 0;
}
