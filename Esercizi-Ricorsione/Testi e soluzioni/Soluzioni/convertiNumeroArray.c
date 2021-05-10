#include <stdio.h>

/* funzione che dato un intero calcola il numero delle sue cifre */
int ncifre(int numero){
    int cont;		// il risultato
	
    if (numero/10==0)  
		/* caso base, una sola cifra */
		cont=1;
    else 
		/* passo induttivo, più di una cifra */
		cont = 1 + ncifre(numero/10);   
    return cont;
}

/* funzione per la stampa di un array */    
void stampaArray(int a[], int dim){
	int i;
	printf("Array:");
	for(i=0; i<dim; i++)
		printf(" %d ",a[i]);
	printf("\n");
}

/* funzione che memorizza dentro all'array v le cifre del numero n a partire da quella 
 * con indice i: REALIZZAZIONE 2 */
void arrayDaNumero(int v[], int n, int i){
	if (i==0)
		/* il numero ha una sola cifra */
		v[i] = n;
	else{
		/* più cifre, passo induttivo, inserisco l'ultima e ricorro */
		v[i] = n%10;
		arrayDaNumero(v,n/10,i-1);  // il numero  senza l'ultima cifra e i-1
	}
}     

/* funzione che dato un numero intero crea e stampa l'array i cui elementi 
 * sono le cifre del numero */
void numero2array(int n){
	int lungh;		// lunghezza array
	
	/* calcolo il numero di cifre di n e creo l'array della corrispondente dimensione */
	lungh=ncifre(n);
	int vett[lungh];
	
	/* invoco la funzione ricorsiva che memorizza nell'array v le cifre di n */
	arrayDaNumero(vett,n,lungh-1);
	
	/* stampo l'array */
	stampaArray(vett,lungh);
}
  
/* funzione principale */
int main() {
	int numero;
	printf("Ciao, io calcolo trasformo un intero in un array di interi ad una cifra. Che numero mi proponi?\n");
	scanf("%d", &numero);
	numero2array(numero);
}

