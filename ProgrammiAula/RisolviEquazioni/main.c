#include <stdio.h>

// Risolve equazioni di secondo grado.
int main()
{
	// Inizializza i dati.
	int a, b, c, d;
	float x1, x2;
	
	printf("Inserisci il primo termine:");
	scanf("%d", &a);
	printf("Inserisci il primo termine:");
	scanf("%d", &b);
	printf("Inserisci il primo termine:");
	scanf("%d", &c);
	
	// Calcola il discriminante.
	d=b*b-4*a*c;
	
	printf("\nIl discriminante vale %d\n\n", d);
	
	// Distingui i casi possibili e risolvi.
	if (d < 0)
	{
		printf("Questa equazione non ammette soluzioni reali!\n");
	} 
	else if (d == 0)
	{
		x1 = -b/(2*a);
		printf("Soluzione: x=%f\n", x1);
	}
	else if (d > 0)
	{
		x1 = (-b+(sqrt(d)))/(2*a);
		x2 = (-b-(sqrt(d)))/(2*a);
		printf("Soluzione: x1 = %f\n", x1);
		printf("           x2 = %f\n", x2);
	}
	
	return 0;
}
