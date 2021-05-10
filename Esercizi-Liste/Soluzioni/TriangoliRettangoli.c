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

struct TriangoloRettangolo {
	struct Punto as;
	struct Punto bd;
};

struct Nodo {
	struct TriangoloRettangolo tr;
	struct Nodo* next;
};

typedef struct TriangoloRettangolo TR;
typedef struct Nodo* NODO;

/*****************************/
/*** FUNZIONI GEOMETRICHE ****/
/*****************************/

/* calcolo dell'area di un triangolo */
float area(TR t) {
	return (t.as.y-t.bd.y)*(t.bd.x-t.as.x)/2;
}

/*****************************/
/*********** STAMPE **********/
/*****************************/

/* per la stampa di un punto */
void stampaPunto(struct Punto p) {
	printf("(%.2f,%.2f)", p.x, p.y);
}

/* per la stampa di un triangolo */
void stampaTriangolo(TR t) {
	struct Punto p;
	
	/* stampa le coordinate dei vertici */
	printf("Stampo un triangolo!\n");
	printf("Il vertice in alto a sinistra ha coordinate ");
	stampaPunto(t.as);
	printf("\n");
	printf("Il vertice in basso a destra ha coordinate ");
	stampaPunto(t.bd);
	printf("\n");
	p.x = t.as.x;
	p.y = t.bd.y;
	printf("Il vertice in basso a sinistra ha coordinate ");
	stampaPunto(p);
	printf("\n\n");
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
			stampaTriangolo(lista->tr);
			lista = lista->next;
		}
		printf("*****************\n");
	}
}

/**************************************/
/********* INSERIMENTO ORDINATO *******/
/**************************************/

/* funzione che legge un triangolo */
void leggiTriangolo(TR* t) {
	
	/* leggi le coordinate dei vertici del parallelogramma */
	printf("Qual %c la coordinata x del vertice in alto a sinistra? ", 138);		// x(as)
	scanf("%f", &(t->as.x));
	printf("Qual %c la coordinata y del vertice in alto a sinistra? ", 138);		// y(as)
	scanf("%f", &(t->as.y));

	do {
		printf("Qual %c la coordinata x del vertice in basso a destra? ", 138);		// x(bd)
		scanf("%f", &(t->bd.x));
		if(t->bd.x<= t->as.x)
			printf("Questo valore deve essere maggiore di %.2f!\n", t->as.x);
	}
	while(t->bd.x<= t->as.x);

	do {
		printf("Qual %c la coordinata y del vertice in basso a destra? ", 138);		// y(bd)
		scanf("%f", &(t->bd.y));
		if(t->bd.y>= t->as.y)
			printf("Questo valore deve essere minore di %.2f!\n", t->as.y);
	}
	while(t->bd.y>= t->as.y);
}

/* funzione per l'inserimento di un triangolo in una lista ordinata per area creascente */
NODO inserimentoOrdine(NODO head) {
	int trovato = 0;	 			// booleano: per sapere quando ho trovato dove inserire il nodo
    NODO precedente; 			// nodo prima di quello da inserire

	/* input del nuovo nodo */
    NODO nuovo; 					// quello da inserire 
	nuovo = malloc(sizeof(struct Nodo));
	leggiTriangolo(&(nuovo->tr));
	
	/* lista vuota? */
	if(head == NULL) {
		nuovo->next = NULL;
		head = nuovo;
	}
	else {
		/* il nuovo nodo diventa il primo? */
		if(area(nuovo->tr)<=area(head->tr)) {
			nuovo->next = head;
			head = nuovo;
		}
		else {
			/* scorro la lista finchè non trovo dove inserire */
			precedente = head;		// sei sempre dopo il nodo fittizio
			while(precedente->next!=NULL && !trovato){

				/* hai trovato il punto giusto se quello nuovo precede il successivo */
				if(area(nuovo->tr)<=area(precedente->next->tr))
					trovato=1;
				else
					precedente=precedente->next;
			}

			/* alla fine del ciclo, precedente è un riferimento al nodo precedente a quello
			 * da inserire */
			nuovo->next=precedente->next;
			precedente->next=nuovo;
		}
	}

	printf("\nTriangolo inserito!\n\n");
	return head;
}	

/*****************************/
/***** INSERIMENTO IN TESTA ***/
/*****************************/

/* funzione per l'inserimento in testa di un triangolo */
NODO inserimentoTesta(NODO lista) {
	/* alloca memoria per il nuovo nodo */
	NODO testa = malloc(sizeof(struct Nodo));
	/* riempi il suo campo dati */
	leggiTriangolo(&(testa->tr));
	
	/* collega il nuovo nodo al successivo, che potrebbe essere NULL se la lista era vuota*/
	testa->next = lista;
	printf("\nTriangolo inserito!\n\n");
	
	/* il nuovo nodo diventa la testa della lista */
	return testa;
}

/*****************************/
/********* ORDINAMENTO *******/
/*****************************/

/* funzione che ordina gli elementi di una lista; implementa selection sort */
void ordinamento(NODO head) {
	NODO primo;				// primo nodo parte non ordinata
	NODO minimo;			// minimo corrente
	NODO nodo;				// nodo corrente
	TR temp;					// variabile ausiliaria
	
	/* il primo nodo non ordinato è il primo nodo della lista */
	primo = head;					
	/* prosegui fino a che il primo nodo da ordinare è NULL */
	while(primo!=NULL) {
		/* inizializza il minimo a primo */
		minimo = primo;
		/* guarda tutti i nodi a partire dal successivo a primo e prosegui fino a 
		 * che non li hai visti tutti */
		for(nodo = primo->next; nodo!=NULL; nodo = nodo -> next) 
			/* minore del minimo ? */
			if(area(nodo->tr) < area(minimo->tr)) 
				minimo = nodo;

		/* adesso scambia i campi dati del minimo e del primo elemento non ordinato */
		temp = primo->tr;
		primo->tr = minimo->tr;
		minimo->tr = temp;
		
		/* fai scorrere il primo elemento non ordinato */
		primo = primo->next;
	}
	printf("Lista ordinata!\n\n");
}

/*****************************/
/************* MAIN ***********/
/*****************************/

/* funzione principale */
int main() {
	NODO lista = NULL;				// la lista, inizialmente vuota
	int risposta = -1;					// per interazione con utente

	/* leggi ripetutamente cosa vuole fare l'utente */
	while(risposta !=0) {
		printf("Che operazione vuoi svolgere?\n");
		printf("1->Inserimento di un triangolo in testa alla lista.\n");
		printf("2->Inserimento ordinato di un triangolo nella lista (funziona ");
		printf("solo se la lista %c ordinata)\n", 138);
		printf("3->Ordinamento della lista.\n");
		printf("4->Visualizzazione della lista.\n");
		printf("0->Termina l'esecuzione.\n");
		scanf("%d", &risposta);
		/* inserimento */
		if(risposta==1) {
			lista = inserimentoTesta(lista);
		}
		/* cancellazione */
		else if(risposta==2) {
			lista = inserimentoOrdine(lista);
		}
		/* ordinamento */
		else if(risposta==3) {
			ordinamento(lista);
		}
		/* visualizzazione */
		else if(risposta==4) {
			stampa(lista);
		}
		else if(risposta!=0)
			printf("Selezione non valida!\n\n");
	}

	printf("Alla prossima!\n");
}
