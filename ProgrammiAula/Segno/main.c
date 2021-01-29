#include <stdio.h>

// Determina se un numero è positivo.
int main()
{
	int numero;
	printf("Inserisci un numero: ");
	scanf("%d", &numero);
	
	if (numero > 0) 
	{
		printf("Il numero è positivo!\n");
	} 
	else 
	{
		printf("Il numero non è positivo!\n");
	}
	
	return 0;
}
