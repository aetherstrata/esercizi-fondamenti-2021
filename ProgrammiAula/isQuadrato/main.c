#include <stdio.h>

/* verifica se un numero è un quadrato perfetto */ 

int isQuadrato(int numero)
{
	int quadrato=0;
	int radice=1;
	
	// Controlla ogni numero minore per vedere se siano sue radici
	while(radice*radice<=numero && quadrato==0){
		if(radice*radice==numero)
			quadrato=1;
		else
			radice++;
	}
	
	return quadrato;
}

int main()
{
	
	int valore;
	printf("Questo programma verifica se un numero %c quadrato perfetto.\n", 130);
	printf("Digita un numero da verificare:");
	scanf("%d", &valore);
	
	if (isQuadrato(valore))
		printf("%d %c un quadrato!\n", valore, 130);
	else
		printf("%d NON %c un quadrato!\n", valore, 130);
	
	return 0;
}