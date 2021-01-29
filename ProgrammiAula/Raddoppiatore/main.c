#include <stdio.h>

// Raddoppia il valore inserito dall'utente

int main()
{
	int x;
	
	printf("Inserisci un intero da raddoppiare: ");
	scanf("%d", &x);
	
	printf("Il doppio di %d è %d.", x, 2*x);
	
	return 0;
}
