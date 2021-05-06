#include <stdio.h>

// Funziona solo con una cifra per cella di array
// Questo voleva l'esercizio :/

int ConvertiArrayNumero(int* array, int len)
{
	int n;
	
	if(len==1){
		n=array[0];
	} else {
		n = array[len-1] + ConvertiArrayNumero(array, len-1) * 10;
	}
	
	return n;
}

int main(int argc, char **argv)
{
	int len=-1;
	while(len<0){
		printf("Inerisci la lunghezza della sequenza di numeri:\n");
		scanf("%d", &len);
		if(len<0){
			printf("La lunghezza deve essere maggiore di zero.\n");
		}
	}
	
	int array[len];
	
	for(int i=0; i<len; i++){
		printf("Inserisci il numero in posizione #%d ", i);
		scanf("%d", &array[i]);
	}
	
	int n = ConvertiArrayNumero(array,len);
	printf("%d", n);
	
	return 0;
}
