#include <stdio.h>

int recFib(int indice);

/* programma per il calcolo dell'ennesimo numero di Fibonacci */
int main()
{
	int indice;
	printf("Io calcolo numeri nella sequenza di Fibonacci. Quale indice ti interessa?\n");
	scanf("%d", &indice);
	printf("L'elemento con indice %d vale %d", indice, recFib(indice));
} 

/* funzione per il calcolo dell'elemento con un certo 
 * indice nella sequenza di Fibonacci */
int recFib(int indice) {
	// pre: indice>=0
    int numero;		// il risultato			
    if(indice==0 || indice==1)
		numero = 1; 
    else 
		numero = recFib(indice-1)+recFib(indice-2);
    return numero;
}