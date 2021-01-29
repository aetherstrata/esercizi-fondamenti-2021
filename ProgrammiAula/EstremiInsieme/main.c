#include <stdio.h>

int main()
{
	int a, b;
	printf("Inserisci gli estremi dell'insieme: \n");
	scanf("%d%d", &a, &b);
	printf("-------------------------------------\n");
	
	if (a > b) 
	{
		a = a - b;   
		b = a + b;
		a = b - a;
	}
	
	for (int i = a; i <= b; i++) {
		if (i%3!=0)
			printf("%d\n", i);
	}
	
	return 0;
}
