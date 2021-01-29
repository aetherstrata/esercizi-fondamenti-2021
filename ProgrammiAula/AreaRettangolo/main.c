#include <stdio.h>

// Questo programma calcola l'area di un rettangolo con le misure date dall'utente.
int main()
{
	int latoA, latoB;
	
	printf("Calcola l'area di un rettangolo!\n");
	printf("Immetti i due lati del rettangolo (interi):\n");
	scanf("%d%d", &latoA, &latoB);
	
	int area = latoA * latoB;
	
	printf("L'area del rettangolo è %d\n", area);
	return 0;
}
