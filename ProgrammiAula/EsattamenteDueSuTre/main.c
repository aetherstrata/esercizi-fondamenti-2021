#include <stdio.h>

int verificaCondizione(int* array){
	return ((array[0]>=0 && array[1]>=0 && array[2]<0) ||
			(array[0]<0 && array[1]>=0 && array[2]>=0) ||
			(array[0]>=0 && array[1]<0 && array[2]>=0));
}

int esattamenteDueSuTre(int* array, int len){
	int ris;
	if(len==3){
		ris = verificaCondizione(array);
	} else {
		ris = verificaCondizione(array) && esattamenteDueSuTre(array+1,len-1);
	}
	return ris;
}

int main(int argc, char **argv)
{
	int lunghezza;
	printf("Inerisci la lunghezza della sequenza: \n");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci il %d# numero: ",i+1);
		scanf("%d",&array[i]);
	}
	if(esattamenteDueSuTre(array, lunghezza)){
		printf("Tutte le triple sono composte da esattamente due numeri positivi.\n");
	} else {
		printf("NON tutte le triple sono composte da esattamente due numeri positivi.\n");
	}
	return 0;
}
