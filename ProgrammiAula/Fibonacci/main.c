#include <stdio.h>

int main()
{
	int n, r; 
	int a = 1;
	int b = 1;
	printf("Inserisci la lunchezza della sequenza:\n");
	scanf("%d", &n);
	
	printf("-\n");
	printf("%d\n", 1);
	printf("%d\n", 1);
	
	for (int i = 0; i < n-2; i++) {
		r = a + b;
		b = r;
		a = b;
		printf("%d\n", r);
	}
	
	return 0;
}
