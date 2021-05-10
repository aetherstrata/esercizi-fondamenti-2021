/* Realizzare un'applicazione per gestire una lista di rombi con diagonali parallele agli assi coordinati.
 *
 * L'applicazione deve gestire ciascun rombo come una struttura con tre campi, che rappresentano il vertice
 * in alto, il vertice in basso e la lunghezza della diagonale orizzontale. Inoltre ciascun vertice deve essere
 * gestito come una struttura con due campi, che rappresentano le coordinate del vertice nel piano.
 *
 * L'applicazione deve permettere all'utente di svolgere le seguenti funzionalit�.
 *
 * - Inserimento di un nuovo rombo in testa alla lista, dopo aver letto la lunghezza della diagonale orizzontale
 * e le coordinate dei due vertici a e b (deve essere letta la coordinata x di un solo vertice fra a e b, in
 * quanto x(a)=x(b)).
 * - Cancellazione dell'ultimo rombo della lista.
 * - Visualizzazione della lista corrente di rombi, ciascuno comprensivo di:
 *  	(*) vertice in alto, vertice in basso, lunghezza della diagonale orizzontale
 * 		(*) perimetro
 * 		(*) area e
 * 		(*) indicazione se il rombo � un quadrato oppure no.
 *
 * All'avvio dell'esecuzione l'applicazione deve inizializzare la lista di rombi con i valori letti da un file;
 * al termine dell'esecuzione l'applicazione deve salvare i dati della lista nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/

struct Punto {
	float x;
	float y;
};

struct Rombo {
	struct Punto a;
	struct Punto b;
	float d;
};

struct Nodo {
	struct Rombo r;
	struct Nodo* next;
};

typedef struct Rombo ROMBO;
typedef struct Nodo* NODO;

/*******************************************/
/*********** FUNZIONI GEOMETRICHE **********/
/*******************************************/

/* funzione che calcola la diagonale verticale di un rombo */
float diagV(ROMBO r) {
	return r.a.y-r.b.y;
}


/* funzione che calcola il lato di un rombo */
float lato(ROMBO r) {
	/* il lato � la radice quadrata della somma dei quadrati delle semidiagonali */
	return sqrt((r.d/2 * r.d/2) + (diagV(r)/2 * diagV(r)/2));
}

/* funzione che calcola il perimetro di un rombo */
float perimetro(ROMBO r) {
	return 4 * lato(r);
}

/* funzione che calcola l'area di un rombo */
float area(ROMBO r) {
	float diagonaleV = r.a.y-r.b.y;
	return diagonaleV * r.d / 2;
}

/* verifica se il rombo � un quadrato */
int isQuadrato(ROMBO r) {
	return diagV(r)==r.d;
}

/*****************************/
/*********** STAMPE **********/
/*****************************/

/* per la stampa di un punto */
void stampaPunto(struct Punto p) {
	printf("(%.2f,%.2f)", p.x, p.y);
}

/* per la stampa di un rombo */
void stampaRombo(ROMBO r) {

	/* stampa le coordinate dei vertici */
	printf("Il vertice in basso del rombo ha coordinate ");
	stampaPunto(r.b);
	printf("\n");
	printf("Il vertice in alto del rombo ha coordinate ");
	stampaPunto(r.a);
	printf("\n");

	/* stampa il perimetro e l'area */
	printf("Il rombo ha diagonale orizzontale lunga %.2f, perimetro %.2f ed area %.2f.\n", r.d, perimetro(r), area(r));

	/* stampa se � un quadrato o no */
	if(isQuadrato(r))
		printf("Il rombo %c un quadrato!\n\n", 138);
	else
		printf("Il rombo non %c un quadrato!\n\n", 138);
}

/* funzione per la stampa di una lista */
void stampa(NODO lista) {
	if(lista == NULL)
		printf("Lista vuota!\n\n");
	else {
		printf("*****************\n");
		printf("Ecco la lista: \n");
		printf("*****************\n");
		while(lista!= NULL) {
			stampaRombo(lista->r);
			lista = lista->next;
		}
		printf("*****************\n");
	}
}

/*****************************/
/********* INSERIMENTO *******/
/*****************************/

/* funzione che legge un rombo */
void leggiRombo(ROMBO* r) {

	/* leggi le coordinate dei vertici del rombo */
	printf("Qual %c la coordinata x del vertice in basso? ", 138);						// x(a)=x(b)
	scanf("%f", &(r->b.x));
	r-> a.x = r->b.x;
	printf("Qual %c la coordinata y del vertice in basso? ", 138);						// y(b)
	scanf("%f", &(r->b.y));
	do {
		printf("Qual %c la coordinata y del vertice in alto? ", 138);					// y(a)
		scanf("%f", &(r->a.y));
		if(r->a.y<= r->b.y)
			printf("Questo valore deve essere maggiore di %.2f!\n", r->b.y);
	}
	while(r->a.y<= r->b.y);

	/* leggi la lunghezza della diagonale */
	do {
		printf("Quanto %c lunga la diagonale? ", 138);
		scanf("%f", &(r->d));
		if(r->d<=0)
			printf("Questo valore deve essere positivo!\n");
	}
	while(r->d<=0);
}

/* funzione per l'inserimento di un rombo */
NODO inserimento(NODO lista) {
	/* alloca memoria per il nuovo nodo, attenzione a quanta memoria si alloca qui sotto,
	 * la dimensione deve essere struct Nodo e non NODO (o struct Nodo*) */
	NODO testa = malloc(sizeof(struct Nodo));
	/* riempi il suo campo dati */
	leggiRombo(&(testa->r));

	/* collega il nuovo nodo al successivo, che potrebbe essere NULL se la lista era vuota*/
	testa->next = lista;
	printf("Inserito!\n\n");

	/* il nuovo nodo diventa la testa della lista */
	return testa;
}

/*****************************/
/********* CANCELLAZIONE *******/
/*****************************/

/* funzione che cancella l'ultimo nodo della lista */
NODO cancellazione(NODO lista) {
	/* c'� qualcosa da cancellare? */
	if(lista==NULL)
		printf("niente da cancellare!\n\n");
	else	{ 	// almeno un nodo
		/* solo un nodo? */
		if(lista->next==NULL) {
			free(lista);				// deallocalo
			lista = NULL;			// la lista diventa vuota
		}
		else {
			/* pi� di un nodo, la testa non si tocca */
			NODO previous = lista;
			NODO current = lista->next;

			/* arriva sull'ultimo nodo */
			while(current->next!= NULL) {
				previous = current;
				current = current->next;
			}
			/* adesso current � quello da cancellare, previous diventa l'ultimo */
			previous -> next = NULL;
			free(current);
		}
		printf("Cancellato!\n\n");
	}

	return lista;
}

/**************************************/
/************* GESTIONE FILE ***********/
/**************************************/

/* funzione per l'acquisizione di una lista su file */
NODO acquisizione() {
	FILE* fp = fopen("rombi.dat", "rb");				// per la lettura di un file binario

  NODO head = NULL;										// testa della lista
	NODO current;												// nodo corrente
	NODO previous;												// nodo precedente

  ROMBO r;														// un rombo
	int letto;														// lettura OK o no

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		/* leggi il primo nodo della lista */
    letto = fread(&r, sizeof(ROMBO), 1, fp);
		if(letto) {		// almeno un ROMBO presente nel file
			/* memorizza nell'heap il primo nodo della lista */
			head = malloc(sizeof(struct Nodo)) ;
      head->r = r;

			/* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
			previous = head;
			/* adesso leggi tutti gli altri nodi */
			do {
				/* leggi un nuovo nodo */
        letto = fread(&r, sizeof(ROMBO), 1, fp);
				if(letto) {		// lo hai effettivamente letto?
					/* memorizza nell'heap il nuovo nodo */
					current = malloc(sizeof(struct Nodo)) ;
          head->r = r;

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
	FILE* fp = fopen("rombi.dat", "wb");								// per la scrittura di un file binario
  if(fp!=NULL) {
    while(lista!= NULL) {												// procedi fino a che hai nodi
  		fwrite(&(lista->r), sizeof(ROMBO), 1, fp);		// ci� che scrivi � un rombo
  		lista = lista->next;												// passa al prossimo nodo
  	}
    fclose(fp);
    printf("Salvataggio eseguito!\n\n");
  }
  else
    printf("Salvataggio non riuscito!\n\n");
}

/*****************************/
/************* MAIN ***********/
/*****************************/

/* funzione principale */
int main() {
	NODO lista = acquisizione();				// la lista
	int risposta = -1;							// per interazione con utente

	/* leggi ripetutamente cosa vuole fare l'utente */
	while(risposta !=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("1->Inserimento di un rombo in testa alla lista.\n");
		printf("2->Cancellazione dell'ultimo rombo della lista.\n");
		printf("3->Visualizzazione della lista di rombi.\n");
		printf("0->Termina l'esecuzione.\n");
		scanf("%d", &risposta);
		/* inserimento */
		if(risposta==1) {
			lista = inserimento(lista);
		}
		/* cancellazione */
		else if(risposta==2) {
			lista = cancellazione(lista);
		}
		/* visualizzazione */
		else if(risposta==3) {
			stampa(lista);
		}
		else if(risposta!=0)
			printf("Selezione non valida!\n\n");
	}

	salvataggio(lista);
	printf("Alla prossima!\n");
}
