/* SPECIFICA * 
 * Input: sequenza s di interi / sequenza t di interi / lunghezze  l1 e l2* 
 * Pre-condizione: l1 e l2 sono le lunghezze di s e t / * 
 * Output: .... * 
 * Post-condizione: ... *
 * TIPO DI PROBLEMA: ... */

#include <stdio.h>

void printArray(int arr[], int len){
	printf("{ ");
	for(int i=0; i<len-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[len-1]);
}

int Prefisso(int arr1[], int len1, int arr2[]){
	for(int i=0;i<len1;i++)
		if(arr1[i]!=arr2[i])
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	printf("Questo programma controlla che la prima sequenza inserita sia un prefisso della seconda sequenza.\n");
	
	int lunghezza1, lunghezza2 = 0;
	
	printf("Da quanti numeri %c composta la prima sequenza di interi?\n", 138);
	scanf("%d", &lunghezza1);
	
	int array1[lunghezza1];
	
	printf("Inserisci la prima sequenza di interi:\n");
	for(int i=0; i<lunghezza1; i++){
		scanf("%d", &array1[i]);
	}
	
	while(lunghezza1>lunghezza2){
	printf("La seconda sequenza di interi deve essere pi%c lunga della prima!\n", 151);
	printf("Da quanti numeri %c composta la seconda sequenza di interi?\n", 138);
	scanf("%d", &lunghezza2);
	}
	
	int array2[lunghezza2];
	
	printf("Inserisci la seconda sequenza di interi:\n");
	for(int i=0; i<lunghezza2; i++){
		scanf("%d", &array2[i]);
	}
	
	printf("\nQuesta %c la prima sequenza di interi:\n", 138);
	printArray(array1, lunghezza1);
	
	printf("\nQuesta %c la seconda sequenza di interi:\n", 138);
	printArray(array2, lunghezza2);
	
	if(Prefisso(array1, lunghezza1, array2))
		printf("La prima sequenza %c un prefisso della seconda!\n", 138);
	else
		printf("La prima sequenza NON %c un prefisso della seconda!\n", 138);
	
}
