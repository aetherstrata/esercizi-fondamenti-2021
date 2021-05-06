#include <stdio.h>

int distanzaMinima(int* array, int len)
{
	int risultato;
	int distanza1;
	
	if(array[0]>array[1]){
		distanza1=array[0]-array[1];
	} else {
		distanza1=array[1]-array[0];
	}
	
	if(len==2){
		risultato=distanza1;
	} else {
		risultato=distanzaMinima(array+1, len-1);
		if(distanza1<risultato){
			risultato=distanza1;
		}
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	int len=-1;
	while(len<2){
		printf("Inserisci la lunghezza della sequenza di numeri: ");
		scanf("%d", &len);
		if(len<2){
			printf("Ci devono essere almeno due elementi nella sequenza!");
		}
	}
	
	int array[len];
	for(int i=0; i<len; i++){
		printf("Inserisci il numero in posizione %d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	printf("La distanza minima tra due interi della sequenza vale: %d\n", distanzaMinima(array, len));
	return 0;
}
