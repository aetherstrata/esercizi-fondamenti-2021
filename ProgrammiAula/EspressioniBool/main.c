#include <stdio.h>

int main()
{
	int x, bl;
	printf("Introduci il valore di x: ");
	scanf("%d", &x);
	
	// Al posto dei puntini scrivi un'espressione booleana che esprime il fatto che un numero 
	// x non è divisibile per 5, è compreso tra 10 e 100 ed è un multiplo di 4.
	bl = (x%5!=0) && (10<=x) && (x<=100) && (x%4==0);
	
	if (bl==0) printf("%d non soddisfa le condizioni!\n", x);
	if (bl==1) printf("%d soddisfa le condizioni!\n", x);
	return 0;
}
