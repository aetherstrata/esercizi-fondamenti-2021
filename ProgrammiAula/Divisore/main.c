#include <stdio.h>

int main()
{
	int a, b;
	printf("Inserisci due numeri interi:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("Quoziente: %d\n", a/b);
	printf("Resto: %d\n", a%b);
	return 0;
}
