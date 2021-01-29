#include <stdio.h>

int main(int argc, char **argv)
{
	int n, totale, count;
	
	while (1) {
		printf("Inserisci in numero intero positivo: \n");
		scanf("%d", &n);
		
		if (n < 0) {
			printf("Questo numero non è positivo.\n");
			printf("Media dei numeri precedenti è: %d\n", totale/count);
			break;
		}
		
		totale = totale + n;
		count++;
	}
	
	printf("\nFine programma!\n");
	return 0;
}
