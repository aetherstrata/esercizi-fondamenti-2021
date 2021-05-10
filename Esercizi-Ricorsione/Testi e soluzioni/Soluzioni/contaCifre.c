#include <stdio.h>

/* funzione che dato un intero restituisce il numero di cifre che lo compongono */
int contacifre(int n){
		int res;			// il valore da restituire
		if (n/10==0) 
			/* Il numero ha una solo cifra */
			res = 1;         		   			//Caso Base
		else 
			/* Il numero ha più cifre */
			res = 1+contacifre(n/10);    //Passo ricorsivo

		return res;
	}
    
/* funzione principale */
int main() {
	int numero;
	printf("Ciao, io calcolo il numero di cifre in un numero. Che numero mi proponi?\n");
	scanf("%d", &numero);
	printf("Il numero di cifre %c %d", 138, contacifre(numero));
}


