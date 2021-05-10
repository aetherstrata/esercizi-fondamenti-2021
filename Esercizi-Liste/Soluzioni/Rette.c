#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* un numero razionale */
struct Numero{
    int num;
    int den;
};

typedef struct Numero NUMERO;

/* una retta */
struct Retta {
    int verticale;
	NUMERO coefficiente;
	NUMERO intercetta;
};

typedef struct Retta RETTA;

/* per la lista di rette */
struct Nodo{
    RETTA retta;
    struct Nodo* next;
};

typedef struct Nodo* NODO;

/**********************************************
 ******************** STAMPE ******************
 **********************************************/

/* per stampare una retta */
void stampaRetta(RETTA retta) {
	/* sappiamo che il denominatore di coefficiente e intercetta sono diversi da zero */
	if(retta.verticale == 1) { // non c'� il termine con la y
		printf("L'equazione della retta %c x =", 138);
		if(retta.intercetta.num==0)
			printf(" 0\n");
		else {
			/* segno */
			if((retta.intercetta.num>0 && retta.intercetta.den<0) ||
			   (retta.intercetta.num<0 && retta.intercetta.den>0))
				   printf(" -");
			/* num e den positivi */
			if(retta.intercetta.num<0)
				retta.intercetta.num= -retta.intercetta.num;
			printf(" %d", retta.intercetta.num);
			if(retta.intercetta.den<0)
				retta.intercetta.den= -retta.intercetta.den;
			if(retta.intercetta.den!= 1)
				printf("/%d\n", retta.intercetta.den);
			else
				printf("\n");
		}
	} // c'� il termine con la y
	else {
		printf("L'equazione della retta %c y =", 138);
		/* stampa il termine mx se c'� */
		if(retta.coefficiente.num!=0) {	// il termine c'�
			/* segno */
			if((retta.coefficiente.num>0 && retta.coefficiente.den<0) ||
			   (retta.coefficiente.num<0 && retta.coefficiente.den>0))
				   printf(" -");
			/* num e den positivi */
			if(retta.coefficiente.num<0)
				retta.coefficiente.num= -retta.coefficiente.num;
			printf(" %d", retta.coefficiente.num);
			if(retta.coefficiente.den<0)
				retta.coefficiente.den= -retta.coefficiente.den;
			if(retta.coefficiente.den!= 1)
				printf("/%d", retta.coefficiente.den);
		}
		/* stampa il termine q se c'� */
		if(retta.intercetta.num==0)
			if(retta.coefficiente.num==0)
				printf(" 0\n");
			else
				printf("\n");
		else {
			/* segno */
			if((retta.intercetta.num>0 && retta.intercetta.den<0) ||
			   (retta.intercetta.num<0 && retta.intercetta.den>0))
				printf(" -");
			else  {
				if(retta.coefficiente.num!=0)
					printf(" +");
			}
			/* num e den positivi */
			if(retta.intercetta.num<0)
				retta.intercetta.num= -retta.intercetta.num;
			printf(" %d", retta.intercetta.num);
			if(retta.intercetta.den<0)
				retta.intercetta.den= -retta.intercetta.den;
			if(retta.intercetta.den!= 1)
				printf("/%d\n", retta.intercetta.den);
			else
				printf("\n");
		}
	}
}

/* per stampare una lista di numeri razionali */
void stampa(NODO lista) {
	/* vai avanti fino a che ci sono numeri */
	if(lista==NULL)
		printf("La lista %c vuota\n\n", 138);
	else {
		printf("Ecco la lista di rette\n\n");
		while(lista!= NULL) {
			stampaRetta(lista->retta);
			lista = lista->next;
		}
		printf("\n");
	}
}

/**********************************************
 ************ INSERIMENTO ORDINATO ************
 **********************************************/

/* verifica se una retta precede un'altra */
int precede(RETTA r1, RETTA r2) {
	int vero;			// da restituire
	/* se la seconda � verticale, allora s� */
	if(r2.verticale==1)
		vero = 1;
	else
		/* se la prima � verticale, allora no */
		if(r1.verticale==1)
			vero = 0;
		/* puoi confrontare i coefficienti */
		else
			vero = ((float)r1.coefficiente.num)/((float)r1.coefficiente.den) <=
			((float)r2.coefficiente.num)/((float)r2.coefficiente.den);
	return vero;
}

/* lettura di una retta */
RETTA leggiRetta() {
	RETTA r;		// da leggere
	printf("Caro utente, la retta %c verticale (1=SI, 0=NO)?  ", 138);
	scanf("%d", &r.verticale);
	if(r.verticale) {

		/* intercetta con x */
		printf("Caro utente, qual %c il numeratore dell'intercetta con l'asse delle x? ", 138);
		scanf("%d", &r.intercetta.num);
		do{
			printf("Caro utente, qual %c il denominatore dell'intercetta? ", 138);
			scanf("%d", &r.intercetta.den);
			if(r.intercetta.den==0)
				printf("Questo valore deve essere diverso da zero\n");
		}
		while(r.intercetta.den==0);
	}
	else {
		/* coefficiente */
		printf("Caro utente, qual %c il numeratore del coefficiente angolare? ", 138);
		scanf("%d", &r.coefficiente.num);
		do{
		printf("Caro utente, qual %c il denominatore del coefficiente angolare? ", 138);
		scanf("%d", &r.coefficiente.den);
			if(r.coefficiente.den==0)
				printf("Questo valore deve essere diverso da zero\n");
		}
		while(r.coefficiente.den==0);

		/* intercetta */
		printf("Caro utente, qual %c il numeratore dell'intercetta? ", 138);
		scanf("%d", &r.intercetta.num);
		do{
			printf("Caro utente, qual %c il denominatore dell'intercetta? ", 138);
			scanf("%d", &r.intercetta.den);
			if(r.intercetta.den==0)
				printf("Questo valore deve essere diverso da zero\n");
		}
		while(r.intercetta.den==0);
	}
	return r;
}


/* inserimento di una retta nella lista ordinata; implementa soluzione
 * con doppio puntatore */
void inserimento(NODO* lista) {
	/* alloca memoria per il nodo */
	NODO nodo = malloc(sizeof(struct Nodo));
	/* riempi il campo dati */
	nodo->retta = leggiRetta();

	/* cerca il posto giusto per l'inserimento */

	/* se la lista � vuota devi inserirlo subito*/
	if(*lista==NULL) {
		nodo->next = NULL;
		*lista = nodo;
	}
	/* altrimenti la lista non � vuota */
	else {
		/* il nuovo elemento diventa il primo? */
		if(precede(nodo->retta,(*lista)->retta)) {
			nodo->next = *lista;
			*lista = nodo;
		}
		/* il nuovo elemento non diventa il primo */
		else {
			NODO nodoPrec = *lista;
			NODO nodoCurr = nodoPrec->next;
			/* adesso cicla fino a che nodoPrec e nodoCurr sono i due elementi fra i quali inserire nodo */
			int trovato = 0;
			while(nodoCurr!= NULL && !trovato) {
				if(precede(nodo->retta,nodoCurr->retta)) {
					trovato = 1;
				}
				else {
					nodoPrec = nodoCurr;
					nodoCurr = nodoCurr->next;
				}
			}
			/* inserisci fra i nodi */
			nodoPrec->next = nodo;
			nodo->next = nodoCurr;		// pu� essere NULL
		}
	}
	printf("Retta inserita!\n\n");
}


/*********************************************
 ************** CANCELLAZIONE *****************
 *********************************************/

/* funzione che elimina un nodo dalla testa della lista */
void cancellazione(NODO* lista) {
	NODO nodo;											// il nuovo primo nodo della lista

	/* se la lista � vuota non fare niente */
	if(*lista!=NULL) {
		/* salva il nuovo primo nodo */
		nodo = (*lista)->next;
		/* dealloca la memoria del primo nodo */
		free(*lista);
		/* nuova testa della lista */
		*lista = nodo;
		printf("Cancellata!\n\n");
	}
	else
		printf("La lista %c vuota!\n\n", 138);
}

/**********************************************
 **************** GESTIONE FILE ****************
 **********************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
	FILE* fp = fopen("rette.dat", "rb");					// per la lettura di un file binario

  NODO head = NULL;										// testa della lista
	NODO current;												// nodo corrente
	NODO previous;												// nodo precedente

  RETTA r;														// una retta
	int letto;														// lettura OK o no

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		/* leggi il primo nodo della lista */
    letto = fread(&r, sizeof(RETTA), 1, fp);
		if(letto) {		// almeno una retta presente nel file
			/* memorizza nell'heap il primo nodo della lista */
			head = malloc(sizeof(struct Nodo)) ;
      head->retta = r;

			/* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
			previous = head;
			/* adesso leggi tutti gli altri nodi */
			do {
				/* leggi un nuovo nodo */
        letto = fread(&r, sizeof(RETTA), 1, fp);
				if(letto) {		// lo hai effettivamente letto?
					/* memorizza nell'heap il nuovo nodo */
					current = malloc(sizeof(struct Nodo)) ;
          head->retta = r;

					/* collega il nuovo nodo al precedente */
					previous->next = current;

					/* il nuovo nodo diventa il precedente */
					previous = current;
				}
				else // il file � terminato, setta il campo next dell'ultimo nodo
					previous -> next = NULL;
			}
			while(letto);
      printf("Lista recuperata da file!\n\n");
		}
    else
      printf("Lista vuota, niente da recuperare!\n\n");
    fclose(fp);
	}
  else
    printf("Apertura file non riuscita!\n\n");
	return head;
}

/* funzione per il salvataggio di una lista su file */
void salvataggio(NODO lista) {
	FILE* fp = fopen("rette.dat", "wb");								// per la scrittura di un file binario
  if(fp!=NULL) {
    while(lista!= NULL) {												// procedi fino a che hai nodi
  		fwrite(&(lista->retta), sizeof(RETTA), 1, fp);		// ci� che scrivi � una retta
  		lista = lista->next;												// passa al prossimo nodo
  	}
    fclose(fp);
    printf("Salvataggio eseguito!\n\n");
  }
  else
    printf("Salvataggio non riuscito!\n\n");
}

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* crea la lista */
	NODO lista = acquisizione();

	int risposta = -1;			// per interazione con utente
	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserisci una retta nella lista ordinata\n");
		printf("2 -> Cancella la prima retta della lista\n");
		printf("3 -> Visualizza la lista\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1) {
			inserimento(&lista);
		}
		else if(risposta==2) {
			cancellazione(&lista);
		}
		else if(risposta==3) {
			stampa(lista);
		}
		else if(risposta==0) {
			printf("Adios!\n\n");
		}
		else printf("Selezione non valida!\n\n");
	}
	salvataggio(lista);
}
