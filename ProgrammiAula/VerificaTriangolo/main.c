#include <stdio.h>

int main()
{
	int n1, n2, n3;
	printf("Introduci il valore di n1, n2 ed n3: ");
	scanf("%d%d%d", &n1, &n2, &n3);
	
	if (n1+n2>n3) printf("%d %d %d possono essere lati di un triangolo!\n", n1, n2, n3); 
	else printf("Questo non è un triangolo!");
	
	return 0;
}
