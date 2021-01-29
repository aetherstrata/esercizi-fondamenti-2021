/* Data una sequenza di interi, verificare se esiste una tripla di elementi consecutivi
   tali che la loro somma sia un quadrato perfetto. */

/*** DUE SOLUZIONI PROPOSTE:
        -LA PRIMA USA UNA FUNZIONE AUSILIARIA CHE VERIFICA SE UN QUADRATO E' PERFETTO,
        -LA SECONDA NON FA USO DI FUNZIONI AUSILIARIE
****/

/*SPECIFICHE:
 * INPUT: una sequenza di numeri interi e la sua lunghezza
 * PRE-CONDIZIONI: lunghezza >=0
 * OUTPUT: un valore intero 'esiste'
 * POST-CONDIZIONI: esiste vale 1 se nella sequenza esiste almeno una tripla la cui somma
   e' un quadrato perfetto, 0 altrimenti.
 * TIPO DI PROBLEMA: problema di verifica esistenziale*/
#include <stdio.h>
#include <math.h>

/*funzione che determina se un numero è un quadrato perfetto*/
int isQuadrato(int n){
    int perfetto = 0; //varabile di esistenzza
    for(int i=0; i<=n; i++)
        if(n==(i*i))
            perfetto=1;
    return perfetto;
}

/*funzione che data una sequenza restituisce 1 se la sequenza ha una tripla la cui somma è
  un quadrato perfetto, 0 altrimenti; la funzione fa uso di una funzione ausiliaria che
  verifica se un intero e' un quadrato perfetto*/
int quadratoPerfetto1(int sequenza[], int lunghezza){
    int i=0;        //variablie contatore
    int esiste=0;   //variabile di verifica esistenziale
    while(i<lunghezza-2 && !esiste)
            if (isQuadrato(sequenza[i]+sequenza[i+1]+sequenza[i+2]))
                esiste=1;
            else
	            i++;
    return esiste;
}

/* funzione alternativa che non richiede la definizione di funzioni ausiliarie */
int quadratoPerfetto2(int a[], int l){
	int i=0;
	int quad;
	int esiste=0;
	while(i<l-2 && !esiste)
		quad=a[i]+a[i+1]+a[i+2];
		if (quad==(int)sqrt(quad)*(int)sqrt(quad)) //condizione per un quadrato perfetto
			esiste=1;
		else
			i++;

	return esiste;
}

/*funzione principale*/
int main(int argc, char **argv)
{/*dichiaro variabili*/
    int lunghezza;  //lunghezza dell array
    /*input*/
	printf("Inserire la lungehzza della sequenza\n");
	scanf("%d", &lunghezza);
    int seq[lunghezza];
    for(int i=0; i<lunghezza; i++){
        printf("inserire un elemento della sequenza: ");
        scanf("%d", &seq[i]);
    }
    /*output*/
    if(quadratoPerfetto2(seq, lunghezza))
        printf("La sequenza contiene almeno una tripla la cui somma %c un quadrato perfetto\n", 138);
    else
        printf("Nella sequenza, nessuna tripla ha la somma pari a un quadrato perfetto\n");
}
