#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* un punto del piano */
struct Punto{
    float x;
    float y;
};

typedef struct Punto PUNTO;

/* un cerchio del piano */
struct Cerchio{
    PUNTO centro;
    float raggio;
};

typedef struct Cerchio CERCHIO;

/* lista di cerchi */
struct Nodo{
    CERCHIO c;
    struct Nodo* next;
};

typedef struct Nodo* NODO;

/**********************************************
 ******************** STAMPE ******************
 **********************************************/

/* per stampare un cerchio */
void stampaCerchio(struct Cerchio c) {
	printf("Il cerchio ha centro (%.2f,%.2f)", c.centro.x, c.centro.y);
	printf(" e raggio %.2f\n", c.raggio);
}

/* per stampare una lista di cerchi */
void stampa(struct Nodo* lista) {
	/* vai avanti fino a che ci sono cerchi */
	if(lista==NULL)
		printf("La lista %c vuota\n\n", 138);
	else {
		printf("Ecco la lista di cerchi\n\n");
		while(lista!= NULL) {
			stampaCerchio(lista->c);
			lista = lista->next;
		}
		printf("\n");
	}
}

/**********************************************
 ************ INSERIMENTO IN TESTA ************
 **********************************************/

/* leggi i campi di un cerchio */
CERCHIO leggiCerchio() {
	CERCHIO c; 		// da leggere
	printf("Introduci la coordinata x del centro: ");
	scanf("%f", &c.centro.x);
	printf("Introduci la coordinata y del centro: ");
	scanf("%f", &c.centro.y);
	do {
		printf("Introduci il raggio: ");
		scanf("%f", &c.raggio);
		if(c.raggio<=0)
			printf("Il raggio deve essere positivo!\n");
	}
	while(c.raggio<=0);
	return c;
}

/* inserimento di un cerchio in testa */
NODO inserimento(NODO head) {
	/* alloca memoria per il nodo */
	NODO testa = malloc(sizeof(struct Nodo));
	/* riempi il campo dati */
	testa->c = leggiCerchio();

	/* collega il nuovo nodo alla lista */
	testa->next = head;
	printf("Inserimento effettuato!\n\n");

	/* aggiorna dentro main la testa della lista */
	return testa;
}

/******************************************
 ************ CANCELLAZIONE ***************
 ******************************************/

NODO cancellazione(NODO head) {
	int risposta = 0;						// per l'interazione con l'utente
	NODO nodoCorrente;				// nodo da investigare
	NODO nodoPrec;						// nodo precedente

	/* se la lista � vuota non cancelli niente */
	if(head!=NULL) {
		printf("Ecco il primo cerchio della lista:\n");
		stampaCerchio(head->c);
		printf("E' questo il cerchio che vuoi cancellare? (1=SI, 0=NO)\n");
		scanf("%d", &risposta);

		/* cancellazione del primo nodo della lista */
		if(risposta) {
			nodoCorrente = head;			// nodo da deallocare
			head = head->next;			// indirizzo da restituire
			free(nodoCorrente);
		}
		/* cancellazione di un nodo della lista che non � il primo */
		else {
			nodoCorrente = head -> next;		// parti dal secondo nodo
			nodoPrec = head;						// dovrai collegare il precedente al successivo
			while(nodoCorrente!=NULL && risposta!=1) {
				printf("Ecco un nuovo cerchio della lista:\n");
				stampaCerchio(nodoCorrente->c);
				printf("E' questo il cerchio che vuoi cancellare? (1=SI, 0=NO)\n");
				scanf("%d", &risposta);
				if(risposta){			// cancella il nodo!
					nodoPrec->next = nodoCorrente -> next; 	// collegamento del precedente al successivo
					free(nodoCorrente);									// deallocazione nodo
				}
				else {	// proponi all'utente il prossimo nodo
					nodoCorrente = nodoCorrente->next;
					nodoPrec = nodoPrec -> next;
				}
			}
		}
	}
	/* messaggio di uscita per l'utente */
	if(risposta==1)
		printf("Nodo cancellato!\n\n");
	else
		printf("Non ho cancellato niente!\n\n");
	return head;
}

/**********************************************
 ************ VERIFICA CONTENIMENTO ************
 **********************************************/

/* distanza fra due punti */
float distanza(PUNTO p1,PUNTO p2) {
	return sqrt(pow(p1.x -p2.x,2) + pow(p1.y -p2.y,2));
}

/* restituisce 1 se il primo cerchio � contenuto nel secondo */
int contenuto(CERCHIO c1, CERCHIO c2) {
	/* il primo � contenuto nel secondo se e solo se: la distanza fra i centri
	 * pi� il raggio del cerchio c1 � minore o uguale al raggio del cerchio c2 */
	return distanza(c1.centro, c2.centro) + c1.raggio <= c2.raggio;
}

/* per la verifica di contenimento fra cerchi */
void verificaContenimento(NODO head) {
	if(head== NULL || head->next==NULL)
		printf("Non ci sono abbastanza cerchi per la verifica\n\n");
	else 	// si pu� fare la verifica
		if(contenuto(head->c, head->next->c))
			printf("Il primo %c contenuto nel secondo\n\n", 138);
		else
			printf("Il primo NON %c contenuto nel secondo\n\n", 138);
}

/**********************************************
 **************** GESTIONE FILE ****************
 **********************************************/

/* funzione per l'acquisizione di una lista su file */
struct Nodo* acquisizione() {
	FILE* fp = fopen("cerchi.dat", "rb");					// per la lettura di un file binario
	NODO head = NULL;										// testa della lista
	NODO current;												// nodo corrente
	NODO previous;												// nodo precedente

	CERCHIO cerchio;										// un cerchio
	int letto;														// lettura OK o no

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		/* leggi il primo nodo della lista */
		letto = fread(&cerchio, sizeof(CERCHIO), 1, fp);
		if(letto) {		// almeno un cerchio � presente nel file
			/* memorizza nell'heap il primo nodo della lista */
			head = malloc(sizeof(struct Nodo)) ;
			head->c = cerchio;

			/* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
			previous = head;
			/* adesso leggi tutti gli altri nodi */
			do {
				/* leggi un nuovo nodo */
				letto = fread(&cerchio, sizeof(CERCHIO), 1, fp);
				if(letto) {		// lo hai effettivamente letto?
					/* memorizza nell'heap il nuovo nodo */
					current = malloc(sizeof(struct Nodo)) ;
					current->c = cerchio;

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
	FILE* fp = fopen("cerchi.dat", "wb");						// per la scrittura di un file binario
  if(fp!=NULL) {
    while(lista!= NULL) {												// procedi fino a che hai nodi
  		fwrite(&(lista->c), sizeof(CERCHIO), 1, fp);		// ci� che scrivi � un cerchio
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
	struct Nodo* lista = acquisizione();

	int risposta = -1;			// per interazione con utente

	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserisci un cerchio nella lista\n");
		printf("2 -> Cancella un cerchio dalla lista\n");
		printf("3 -> Visualizza la lista\n");
		printf("4 -> Verifica se il primo cerchio della lista %c contenuto nel secondo\n", 138);
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1) {
			lista = inserimento(lista);
		}
		else if(risposta==2) {
			lista = cancellazione(lista);
		}
		else if(risposta==3) {
			stampa(lista);
		}
		else if(risposta==4)
			verificaContenimento(lista);
		else if(risposta==0) {
			printf("Adios!\n\n");
		}
		else printf("Selezione non valida!\n\n");
	}
	salvataggio(lista);
}
