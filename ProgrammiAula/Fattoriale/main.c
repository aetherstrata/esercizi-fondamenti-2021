#include <stdio.h>

int main()
{
	int numero, fattoriale;
	printf("Inserisci un numero sul quale eseguire il fattoriale: ");
	scanf("%d", &numero);
	
	fattoriale = 1;
	
	for (int i = 1; i<=numero; i++){
		fattoriale = fattoriale * i;
	}
	
	printf("Il fattoriale di %d vale %d.\n", numero, fattoriale);
	return 0;
}
