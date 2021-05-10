/* Realizzare un'applicazione per gestire una lista di parallelogrammi con base parallela all'asse x.
 *
 * L'applicazione deve gestire ciascun parallelogramma come una struttura con tre campi, che
 * rappresentano il vertice in basso a sinistra, il vertice in alto a destra e la lunghezza della
 * base. Inoltre ciascun vertice deve essere gestito come una struttura
 * con due campi, che rappresentano le coordinate del vertice nel piano.
 *
 * L'applicazione deve permettere all'utente di svolgere le seguenti funzionalit�.
 *
 * - Inserimento di un nuovo parallelogramma in testa alla lista, dopo aver letto la lunghezza
 * della base e le coordinate dei due vertici bs e ad.
 * - Cancellazione dell'ultimo parallelogramma della lista.
 * - Visualizzazione della lista corrente di parallelogrammi, ciascuno comprensivo di:
 * 		(*) vertice in basso a sinistra, vertice in alto a destra e lunghezza della base
 * 		(*) perimetro
 * 		(*) area e
 * 		(*) indicazione se il parallelogramma � un rettangolo oppure no.
 *
 * All'avvio dell'esecuzione l'applicazione deve inizializzare la lista di parallelogrammi con i valori letti
 * da un file; al termine dell'esecuzione l'applicazione deve salvare i dati della lista nello stesso file. */

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

struct Parallelogramma {
	struct Punto bs;
	struct Punto ad;
	float b;
};

struct Nodo {
	struct Parallelogramma p;
	struct Nodo* next;
};

typedef struct Parallelogramma PARA;
typedef struct Nodo* NODO;

/*******************************************/
/*********** FUNZIONI GEOMETRICHE **********/
/*******************************************/

/* funzione che calcola l'altezza di un parallelogramma */
float altezza(PARA p) {
	return p.ad.y-p.bs.y;
}

/* funzione che calcola il lato obliquo di un parallelogramma */
float lato(PARA p) {
	/* il lato � la radice quadrata della somma dei quadrati dell'altezza e della differenza
	 * fra la coordinata x dei due vertici sinistri */
	return sqrt(pow(altezza(p),2) + pow(p.bs.x-(p.ad.x-p.b),2));
}

/* funzione che calcola il perimetro di un parallelogramma */
float perimetro(PARA p) {
	return 2 * lato(p) + 2 * p.b;
}

/* funzione che calcola l'area di un parallelogramma */
float area(PARA p) {
	return p.b * altezza(p);
}

/* verifica se il parallelogramma � un rettangolo */
int isRettangolo(PARA p) {
	return p.ad.x-p.b == p.bs.x;
}

/*****************************/
/*********** STAMPE **********/
/*****************************/

/* per la stampa di un punto */
void stampaPunto(struct Punto p) {
	printf("(%.2f,%.2f)", p.x, p.y);
}

/* per la stampa di un parallelogramma */
void stampaParallelogramma(PARA p) {

	/* stampa le coordinate dei vertici */
	printf("Il vertice in basso a sinistra del parallelogramma ha coordinate ");
	stampaPunto(p.bs);
	printf("\n");
	printf("Il vertice in alto a destra del parallelogramma ha coordinate ");
	stampaPunto(p.ad);
	printf("\n");

	/* stampa il perimetro e l'area */
	printf("Il parallelogramma ha base %.2f, perimetro %.2f ed area %.2f.\n", p.b, perimetro(p), area(p));

	/* stampa se � un rettangolo o no */
	if(isRettangolo(p))
		printf("Il parallelogramma %c un rettangolo!\n\n", 138);
	else
		printf("Il parallelogramma non %c un rettangolo!\n\n", 138);
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
			stampaParallelogramma(lista->p);
			lista = lista->next;
		}
		printf("*****************\n");
	}
}

/*****************************/
/********* INSERIMENTO *******/
/*****************************/

/* funzione che legge e restituisce un parallelogramma */
PARA leggiParallelogramma() {
	PARA p;			// da leggere

	/* leggi le coordinate dei vertici del parallelogramma */
	printf("Qual %c la coordinata x del vertice in basso a sinistra? ", 138);		// x(bs)
	scanf("%f", &p.bs.x);
	printf("Qual %c la coordinata y del vertice in basso a sinistra? ", 138);		// y(bs)
	scanf("%f", &p.bs.y);
	printf("Qual %c la coordinata x del vertice in alto a destra? ", 138);			// x(ad)
	scanf("%f", &p.ad.x);
	do {
		printf("Qual %c la coordinata y del vertice in alto a destra? ", 138);		// y(ad)
		scanf("%f", &p.ad.y);
		if(p.ad.y<= p.bs.y)
			printf("Questo valore deve essere maggiore di %.2f!\n", p.bs.y);
	}
	while(p.ad.y<= p.bs.y);

	/* leggi la lunghezza della base */
	do {
		printf("Quanto %c lunga la base? ", 138);
		scanf("%f", &p.b);
		if(p.b<=0)
			printf("Questo valore deve essere positivo!\n");
	}
	while(p.b<=0);

	return p;
}

NODO inserimento(NODO lista) {
	/* alloca memoria per il nuovo nodo, attenzione a quanta memoria si alloca qui sotto,
	 * la dimensione deve essere struct Nodo e non NODO (o struct Nodo*) */
	NODO testa = malloc(sizeof(struct Nodo));
	/* riempi il suo campo dati */
	testa->p = leggiParallelogramma();

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

/* legge la lista da file */
NODO acquisisci() {
	NODO lista = NULL;				// la lista da leggere

	/* prova ad aprire il file per la lettura */
	FILE* fp = fopen("parallelogrammi.dat", "rb");
	if(fp!=NULL) {	// se l'apertura � andata male, restituisci NULL
		/* prova a leggere un parallelogramma */
		PARA par;
		int letto = fread(&par, sizeof(PARA), 1, fp);
		/* se non hai letto niente, lista vuota */
		if(letto) {
			/* se hai letto, hai almeno un nodo */
			lista = malloc(sizeof(struct Nodo));
			lista->p = par;		// campo dati

			/* adesso puoi leggere tutti i nodi successivi */
			NODO nodo = lista;
			while(letto) {
				/* leggi un parallelogramma */
				letto = fread(&par, sizeof(PARA), 1, fp);
				if(letto){	// lo hai letto?
					/* memorizzalo, collegalo al precedente e passa a leggere il prossimo */
					nodo->next = malloc(sizeof(struct Nodo));
					nodo = nodo->next;
					nodo->p = par;
				}
			}
			/* adesso ultimo nodo ha campo next pari a NULL */
			nodo->next = NULL;
			printf("Lista recuperata da file!\n\n");
		}
		else
			printf("Lista vuota, niente da recuperare!\n\n");
		fclose(fp);
	}
	else
    printf("Apertura file non riuscita!\n\n");
	return lista;
}

/* scrive la lista su file */
void salvataggio(NODO lista) {
	FILE* fp = fopen("parallelogrammi.dat", "wb");
	if(fp!=NULL) {
    while(lista!=NULL) {			// prosegui fino a che hai parallelogrammi da salvare
			fwrite(&lista->p, sizeof(PARA), 1, fp);		// salvane uno
			lista = lista->next;														// passa al prossimo
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
	NODO lista = acquisisci();	// la lista
	int risposta = -1;							// per interazione con utente

	/* leggi ripetutamente cosa vuole fare l'utente */
	while(risposta !=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("1->Inserimento di un parallelogramma in testa alla lista.\n");
		printf("2->Cancellazione dell'ultimo parallelogramma della lista.\n");
		printf("3->Visualizzazione della lista di parallelogrammi.\n");
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
