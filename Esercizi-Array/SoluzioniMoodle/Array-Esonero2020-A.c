 #include <stdio.h>
/* Data una sequenza di interi, verificare se esiste un elemento nella sequenza
  che è il quadrato del successivo o del precedente.
 SPECIFICA:
 * INPUT: sequenza di interi 's', e un intero dim che rappresenta la lunghezza della sequenza
 * PRE-CONDIZIONI: 'dim' >= 0
 * OUTPUT: un intero 'esiste' (come valore booleano)
 * POST-CONDIZIONI: l'intero è 1 se nella sequenza c'è almeno un elemento
 * che è il quadrato del suo precedente oppure del suo successore, 0 altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale*/

/*** DUE SOLUZIONI PROPOSTE:
        -LA PRIMA CONTROLLA A PARTE GLI ESTREMI, CHE ALTRIMENTI
         NON VERREBBERO ESAMINATI NELL'ITERAZIONE,
        -LA SECONDA CONSIDERA IL PROBLEMA COME UNA VERIFICA SU COPPIE DI ELEMENTI
         ADIACENTI E NON HA BISOGNO DI UN CONTROLLO SPECIFICO SUI VALORI ESTREMI
****/

/*Funzione che prende un array di interi e la sua lunghezza e verifica se nella sequenza un elemento è il quadrato
del suo successivo o preccedente, restituisce 1 se esiste tale elemento, 0 altrimenti.*/
int quadratoPrecSucc1(int sequenza[],  int dim){
	int esiste=0;											//variabile esistenziale
	int i=0;												//contatore

	if(sequenza[0]==sequenza[1]*sequenza[1])				//verifico da subito se il primo elemento è il quadrato del suo succesivo in quanto non ha precc., se esso lo è, allora esiste= 1 e non entro nel while
		esiste=1;

	if(sequenza[dim-1]==sequenza[dim-2]*sequenza[dim-2])	//verifico da subito se l'ultimo elemento è il quadrato del suo precc. in quanto non ha succ. se esso lo è, allora esiste= 1 e non entro nel while
		esiste=1;

	i=1;
	while(!esiste && i<dim-1){									//verifico gli elementi rimanenti
		if((sequenza[i]==sequenza[i+1]*sequenza[i+1]) || (sequenza[i]==sequenza[i-1]*sequenza[i-1]))		//verifico se l'elemento corrente e il quadrato del suo succ. o precc.
			esiste=1;
		else
			i++;
	}
	return esiste;
}

int quadratoPrecSucc2(int a[], int l){
	int i;
	int trovato=0;
	i=0;
	while(i<l-1 && !trovato)
		if ((a[i]*a[i]==a[i+1]) || (a[i]==a[i+1]*a[i+1]))
			trovato=1;
		else
			i++;
	return trovato;
}



/*Funzione principale che chiede all'utente di quanti elementi e formata la sua sequenza, e legge gli interi*/
int main()
{

	/*INPUT*/
	int lunghezza;							//lunghezza array
	printf("Caro utente quanti elementi ha la tua sequenza\n");
	scanf("%d", &lunghezza);

	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){									//leggo la sequenza e la salvo nell'array
		printf("Inserisci un elemento\n");
			scanf("%d", &array[i]);
	}

	/*OUTPUT*/
	if(quadratoPrecSucc2(array, lunghezza))
		printf("Nella sequenza c'e' un elemento che e' il quadrato del numero precedente o del numero successivo\n");
	else
		printf("Nella sequenza non esiste un elemento che e' il quadrato del numero precedente o del numero successivo\n");
	return 0;
}


