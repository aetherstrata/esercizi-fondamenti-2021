#include <stdio.h>

int isQuadrato(int* array, int len)
{
	int risultato;
	
	if(len==0){
		risultato=0;
	} else {
		if(array[len]==array[len-1]*array[len-1]||array[len-1]==array[len]*array[len]){
			risultato=1;
		} else {
			risultato=isQuadrato(array,len-1);
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
	
	if(isQuadrato(array, len-1)){
		printf("Esiste un numero tale che %c il quadrato del precedente!\n", 138);
	} else {
		printf("NON esiste un numero tale che %c il quadrato del precedente!\n", 138);
	}
	
	return 0;
}
