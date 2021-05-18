#include <stdio.h>

int isCrescente(int* array, int len){
	int ris;
	if(len==1){
		ris = 1;
	} else {
		ris = array[0]<=array[1] && isCrescente(array+1, len-1);
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
	
	if(isCrescente(array, len)){
		printf("Questa sequenza %c crescente!\n\n", 138);
	} else {
		printf("Questa sequenza NON %c crescente!\n\n", 138);
	}
	
	return 0;
}
