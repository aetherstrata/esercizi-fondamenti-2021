#include <stdio.h>

int numeroPositivi(int* array, int len){
	int ris;
	if(len==1){
		ris=array[0]>=0;
	} else {
		ris = (array[0]>=0) + numeroPositivi(array+1, len-1);
	}
	return ris;
}

int main(int argc, char **argv)
{
	int len=-1;
	while(len<1){
		printf("Inserisci la lunghezza della sequenza di numeri: ");
		scanf("%d", &len);
		if(len<1){
			printf("Ci deve essere almeno un elemento nella sequenza!\n");
		}
	}
	
	int array[len];
	for(int i=0; i<len; i++){
		printf("Inserisci il numero in posizione %d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	printf("La sequenza contiene %d numeri positivi!\n",numeroPositivi(array, len));
	return 0;
}
