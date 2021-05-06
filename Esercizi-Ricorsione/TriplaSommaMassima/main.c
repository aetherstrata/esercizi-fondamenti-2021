#include <stdio.h>

int TriplaSommaMassima(int* array, int len)
{
	int risultato;
	int tripla = array[0]+array[1]+array[2];
	
	if(len==3){
		risultato=tripla;
	} else {
		risultato = TriplaSommaMassima(array+1,len-1);
		if(risultato<tripla){
			risultato=tripla;
		}
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	int len=-1;
	while(len<3){
		printf("Inserisci la lunghezza della sequenza di numeri: ");
		scanf("%d", &len);
		if(len<3){
			printf("Ci devono essere almeno tre elementi nella sequenza!");
		}
	}
	
	int array[len];
	for(int i=0; i<len; i++){
		printf("Inserisci il numero in posizione %d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	printf("La massima tripla consecutiva vale %d\n", TriplaSommaMassima(array, len));
	return 0;
}
