/* SPECIFICA * 
 * Input: sequenza s di lunghezza l * 
 * Pre-condizione: l è la lunghezza di s / tutti gli elementi di s sono interi * 
 * Output: true/false * 
 * Post-condizione: true se un numero è la somma di tutti i precedenti * 
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

void printArray(int arr[], int len)
{
	printf("\nLa sequenza vale:\n");
	printf("{ ");
	for(int i=0;i<len-1;i++){
		printf("%d, ", arr[i]);
	}
	printf("%d }\n", arr[len-1]);
}

int ugualeSommaPrecedenti(int arr[], int len)
{
	int somma=arr[0]+arr[1];
	int uguale=0;
	
	for(int i=2; i<len; i++){
		if (arr[i]==somma){
			uguale=1;
			break;
		} else {
			somma+=arr[i];
		}
	}
	return uguale;
}

int main(int argc, char **argv)
{
	int lunghezza;
	printf("Questo programma verifica che un valore di una sequenza %c uguale alla somma di tutti i valori precedenti.\n", 138);
	printf("Da quanti interi %c composta la sequenza?\n", 138);
	scanf("%d", &lunghezza);
	int array[lunghezza];
	
	for(int i=0; i<lunghezza; i++){
		printf("Immetti il valore con indice %d: ", i);
		scanf("%d", &array[i]);
	}
	
	printArray(array, lunghezza);
	
	if(ugualeSommaPrecedenti(array, lunghezza)){
		printf("SI\n");
	} else{
		printf("NO\n");
	}
	
	return 0;
}
