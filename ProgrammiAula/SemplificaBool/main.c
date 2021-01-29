#include <stdio.h>

int main()
{
	int x, bl;
	
	printf("Valore x: ");
	scanf("%d", &x);
	
	bl = x!=1 && x!=7;
	
	printf("Condizione x: %d", bl);
	
	return 0;
}
