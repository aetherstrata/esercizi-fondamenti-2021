#include <stdio.h>

// Valutare se un anno è bisestile
int main()
{
	int anno;
	printf("Inserisci l'anno da controllare: ");
	scanf("%d", &anno);
	
	if ((anno%100 != 0 && anno%4 == 0) || (anno%400 == 0))
	{
		printf("%d è un anno bisestile!\n", anno);
	}
	else
	{
		printf("%d non è un anno bisestile!\n", anno);
	}
	
	return 0;
}
