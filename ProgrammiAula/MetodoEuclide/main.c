#include <stdio.h>

// Calcola l'MCD usando l'algoritmo di Euclide
int main()
{
	int a, b, r;
	printf("Inserisci due numeri su cui calcolare l'MCD (prima il numero più grande!):\n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	r = a%b;
	
	while (r!=0) {
		a = b;
		b = r;
		r = a%b;
	}
	
	printf("Il massimo comune divisore vale %d!\n", b);
	
	return 0;
}
