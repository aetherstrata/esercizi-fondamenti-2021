#include <stdio.h>

int main()
{
	int a, b, c;
	
	printf("Inserisci tre numeri interi: \n");
	scanf("%d%d%d", &a, &b, &c);
	
	if (a < b) {
		if (a < c) {
			printf("Minimo: %d\n", a);
		} else {
			printf("Minimo: %d\n", c);
		}
	} else if (b < c) {
		printf("Minimo: %d\n", b);
	} else {
		printf("Minimo: %d\n", c);
	}
	
	if (a > b) {
		if (a > c) {
			printf("Massimo: %d\n", a);
		} else {
			printf("Massimo: %d\n", c);
		}
	} else if (b > c) {
		printf("Massimo: %d\n", b);
	} else {
		printf("Massimo: %d\n", c);
	}
	
	

	return 0;
}
