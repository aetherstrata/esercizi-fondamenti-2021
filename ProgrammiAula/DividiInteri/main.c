#include <stdio.h>
#include <stdlib.h>

int* allocaMemoria()
{
	int* indirizzo = malloc(sizeof(int));
	
	return indirizzo;
}

void leggiValore(int* var)
{
	scanf("%d", var);
}

void riordina(int* a, int* b)
{
	if (*a < *b){
		int* c = allocaMemoria();
		
		*c = *a;
		*a = *b;
		*b = *c;
	}
}

void calcolaQuoziente(int* n, int* div, int* qzt)
{
	*qzt = *n / *div;
}

void calcolaResto(int* n, int* div, int* resto)
{
	*resto = *n % *div;
}

int main(int argc, char **argv)
{
	printf("Questo programma legge due interi e stampa quoziente e resto tra il pi%c grande e il pi%c piccolo.\n", 151, 151);
	
	printf("Introduci il primo intero: ");
	
	int* primo = allocaMemoria();
	leggiValore(primo);
	
	printf("Introduci il secondo intero: ");
	
	int* secondo = allocaMemoria();
	leggiValore(secondo);
	
	riordina(primo, secondo);
	
	printf("Hai inserito %d e %d\n", *primo, *secondo);
	
	int* risultato = allocaMemoria();
	calcolaQuoziente(primo, secondo, risultato);
	
	int* resto = allocaMemoria();
	calcolaResto(primo, secondo, resto);
	
	printf("Il quoziente della divisione vale %d con resto %d\n", *risultato, *resto);
	
	return 0;
}
