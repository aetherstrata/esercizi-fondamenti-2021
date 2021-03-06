#include <stdio.h>

int disp(int n, int k);

/* programma per il calcolo del numero di disposizioni */
int main()
{
	int insieme, sottoins;
	printf("Io calcolo il numero di disposizioni. Quanti elementi ha il tuo insieme?\n");
	scanf("%d", &insieme);
	printf("Quanti di questi elementi vuoi disporre?\n");
	scanf("%d", &sottoins);
	printf("Esistono %d disposizioni con %d elementi in un insieme con %d elementi",
		disp(insieme,sottoins), sottoins, insieme);
} 

/* funzione per il calcolo del numero di disposizioni con k elementi in un insieme con n elementi */
int disp(int n, int k) {
	// pre: k<=n, k,n>=1
    int numero;		// il risultato			

	/* se devi prendere un solo elemento hai n maniere per farlo */
    if(k==1)
		numero = n; 
    else 
		/* altrimenti prendi un elemento in uno di n modi possibili e ti rimane da scegliere
			i rimanenti k-1 elementi sui rimanenti n-1 elementi dell'insieme */
		numero = n * disp(n-1,k-1);
	return numero;
}