#include <stdio.h>

int main()
{
	int a, b, c, d, count;
	printf("Inserisci quattro numeri interi: \n");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	count = 1;
	
	if (a==b) {
		count++;
		if (a==c) {
			count++;
			if (a==d) {
				count++;
			} 
		} 
	} else if (b==c) {
		count++;
		if (b==d) {
			count++;
		}
	} else if (c==d) {
		count++;
	}
	
	printf("Ci sono %d interi uguali\n", count);
	
	return 0;
}
