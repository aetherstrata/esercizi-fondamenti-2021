#include <stdio.h>
/* Data una sequenza di interi, verificare se per ogni tripla di elementi adiacenti
   la somma del primo e del secondo elemento della tripla è uguale al terzo.*/

/* SPECIFICA
 * INPUT: una sequenza s di interi e la sua lunghezza l
 * PRE-CONDIZIONI: l >=0
 * OUTPUT: un intero 'somma'
 * POST-CONDIZIONE: 'somma' è pari a 1 se per ogni tripla di interi consecutivi nella sequenza la somma del
 * primo e del secondo elemento  della tripla è uguale al terzo, è pari a 0 altrimenti
 *
 * TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>

/* funzione che riceve come parametri un array di interi e la sua lunghezza e restituisce 1 se per ogni tripla di
 * interi consecutivi nella sequenza la somma del primo e del secondo elemento è uguale al terzo; restituisce 0
 * altrimenti */
int verificaSequenza(int array[], int lunghezza) {
    //pre: lunghezza è la lunghezza di array
    int somma; //variabile universale
    int i; //variabile contatore

    /*inizializza la variabile universale a 1 perchè ancora non hai trovato una tripla che non soddisfa la proprietà*/
    somma=1;

    i=0; //primo elemento da guardare
    /*guarda tutte le triple finchè non termina la sequenza o finchè non hai trovato una tripla che non soddisfa la proprietà*/
    while(i<lunghezza-2 && somma) {
        /*la somma del primo e del secondo elemento non è uguale al terzo?*/
        if(array[i]+array[i+1]!=array[i+2])
            somma=0;
        else
            i++;
    }
    return somma;
}

/* funzione principale */
int main() {
    /*dichiarazione variabili*/
    int lunghezza; //dimensione dell'array

    /*INPUT*/
    printf("Programma che legge una sequenza di interi e la sua lunghezza e verifica se per ogni tripla di ");
    printf("interi consecutivi nella sequenza la somma del primo e del secondo elemento %c uguale al terzo.\n", 138);

    printf("\nQuanti interi vuoi introdurre? ");
    scanf("%d", &lunghezza);
    int array[lunghezza];

    /*riempimento array da tastiera*/
    for(int i=0; i<lunghezza; i++) {
        printf("Inserisci un elemento della sequenza: ");
        scanf("%d", &array[i]);
    }

    /*OUTPUT*/
    if(verificaSequenza(array, lunghezza))
        printf("\nOgni tripla di interi consecutivi %c tale che la somma \ndel primo e del secondo elemento %c uguale al terzo.\n", 138, 138);
    else
        printf("\nEsiste almeno una tripla di interi consecutivi in cui la somma \ndel primo e del secondo elemento non %c uguale al terzo \n", 138);
}