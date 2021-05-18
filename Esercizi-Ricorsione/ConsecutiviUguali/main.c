#include <stdio.h>

int consecutiviUguali(int* array, int len){
	int ris=0;
	if(len>1){
		ris = array[0]==array[1] || consecutiviUguali(array+1, len-1);
	}
	return ris;
}

int main(int argc, char **argv)
{
	int len=-1;
	while(len<2){
		printf("Inserisci la lunghezza della sequenza di numeri: ");
		scanf("%d", &len);
		if(len<2){
			printf("Ci devono essere almeno due elementi nella sequenza!\n");
		}
	}
	
	int array[len];
	for(int i=0; i<len; i++){
		printf("Inserisci il numero in posizione %d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	if(consecutiviUguali(array, len)){
		printf("Questa sequenza contiene due elementi consecutivi uguali!\n\n");
	} else {
		printf("Questa sequenza NON contiene due elementi consecutivi uguali!\n\n");
	}
	
	return 0;
}
