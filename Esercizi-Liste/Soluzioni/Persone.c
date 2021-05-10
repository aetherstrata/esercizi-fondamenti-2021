#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 /* struttura per rappresentare una data */
typedef struct Data {
	int giorno;
	int mese;
	int anno;
} DATA;

/* struttura per rappresentare una persona */
typedef struct Persona {
	char nome[20];
	char cognome[20];
	DATA dataDiNascita;
} PERSONA;

/* struttura per rappresentare un nodo della lista */
typedef struct nodo {
	PERSONA persona;
	struct nodo* next;
} NODO;

/* visualizzazione data di nascita */
void visualizzaData(DATA* data){
    printf("DATA DI NASCITA: %d/%d/%d\n", data->giorno, data->mese, data->anno);
}

/* visualizzazione persona */
void visualizzaPersona(PERSONA* persona){
    printf("\nNOME: %s\n", persona->nome);
    printf("COGNOME: %s\n", persona->cognome);
    visualizzaData(&(persona->dataDiNascita));
}

/* visualizzazione lista */
void visualizza(NODO* lista) {
	if(lista==NULL)
		printf("Lista vuota!\n\n");
	else {
		printf("Ecco la lista!\n");
		while(lista!=NULL) {
			visualizzaPersona(&(lista->persona));
			lista = lista->next;
		}
	}
}

/* INPUT data */
void immettiData(DATA* data) {
	/* leggi giorno, mese e anno */
	printf("Inserisci il giorno: ");
	scanf("%d", &(data->giorno));
	printf("Inserisci il mese: ");
	scanf("%d", &(data->mese));
	printf("Inserisci l'anno: ");
	scanf("%d%*c", &(data->anno));
}

/* INPUT persona */
void ottieniDatiPersona(PERSONA* p) {
	/* ottieni i dati della persona */
	printf("Introduci il nome della persona: ");
	fgets(p->nome, 20, stdin);
	(p->nome)[strlen(p->nome)-1]='\0';

	printf("Introduci il cognome della persona: ");
	fgets(p->cognome, 20, stdin);
	(p->cognome)[strlen(p->cognome)-1]='\0';

	printf("Introduci la data di nascita della persona...\n");
    immettiData(&(p->dataDiNascita));
}

/* inserimento in coda */
NODO* inserisciCoda(NODO* head) {
	NODO* nuovoNodo;										// il nuovo nodo della lista
	nuovoNodo = malloc(sizeof(NODO));		 		// allocazione nuovo nodo nell'heap

	/* riempi i campi del nuovo nodo */
	ottieniDatiPersona(&(nuovoNodo->persona));
	nuovoNodo->next = NULL;

	/* collega il nodo al precedente */
	if(head == NULL) 		// lista vuota?
		head = nuovoNodo;		// il nuovo nodo diventa il primo
	else{							// lista non vuota, cerca l'ultimo nodo
		NODO* nodoCorrente = head;
		while(nodoCorrente->next != NULL)
			nodoCorrente = nodoCorrente->next;

		/* ora nodoCorrente � l'indirizzo dell'ultimo nodo della lista */
		nodoCorrente->next = nuovoNodo;
	}

	printf("Inserimento effettuato!\n\n");
	return head;	// nota che se la lista non � vuota � gi� tutto a posto
}

/* cancellazione in testa */
NODO* cancellaTesta(NODO* head) {
	NODO* primoNodo;											// il nuovo primo nodo della lista

	/* lista vuota? */
	if(head==NULL) {
		primoNodo = NULL;
		printf("Niente da cancellare!\n");
	}
	else {
		/* il secondo nodo diventa il primo; eventualmente questo � NULL */
		primoNodo = head->next;
		/* viene deallocata la memoria del primo nodo */
		free(head);
		printf("Cancellazione effettuata!\n");
	}

	/* restituisci l'indirizzo del nuovo primo elemento */
	return primoNodo;
}

/**********************************************
 **************** GESTIONE FILE ****************
 **********************************************/

/* funzione per l'acquisizione di una lista su file */
NODO* acquisizione() {
	FILE* fp = fopen("persone.txt", "r");				// per la lettura di un file
	NODO* head = NULL;										// testa della lista
	NODO* current;												// nodo corrente
	NODO* previous;											// nodo precedente

	PERSONA p;													// persona
	int letto;													// lettura OK o no

	/* se non hai aperto il file non devi fare niente */
	if(fp!=NULL) {
		/* leggi il primo nodo della lista */
		if(fscanf(fp,"%s%s%d%d%d",&p.nome,&p.cognome,&p.dataDiNascita.giorno,
										&p.dataDiNascita.mese,&p.dataDiNascita.anno)!=EOF) {		// almeno una persona presente nel file
			/* memorizza nell'heap il primo nodo della lista */
			head = malloc(sizeof(NODO)) ;
			head->persona = p;

			/* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
			previous = head;
			/* adesso leggi tutti gli altri nodi */
			while(fscanf(fp,"%s%s%d%d%d",&p.nome,&p.cognome,&p.dataDiNascita.giorno,
											&p.dataDiNascita.mese,&p.dataDiNascita.anno)!=EOF){
				/* leggi un nuovo nodo */
				current = malloc(sizeof(NODO)) ;
				current->persona = p;

				/* collega il nuovo nodo al precedente */
				previous->next = current;

				/* il nuovo nodo diventa il precedente */
				previous = current;
			}
			/* sistema ultimo nodo */
			previous -> next = NULL;
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

/* funzione per il salvataggio di una persona su file */
void salvaPersona(PERSONA* p, FILE* fp) {
	fprintf(fp, "%s %s %d %d %d", p->nome, p->cognome, p->dataDiNascita.giorno,
	                     p->dataDiNascita.mese, p->dataDiNascita.anno);
}

/* funzione per il salvataggio di una lista su file */
void salvataggio(NODO* lista) {
	FILE* fp = fopen("persone.txt", "w");					// per la scrittura di un file
  if(fp!=NULL) {
    while(lista!= NULL) {												// procedi fino a che hai nodi
			salvaPersona(&(lista->persona),fp);
			if(lista->next!=NULL)
				fprintf(fp,"\n");													// di separazione
  		lista = lista->next;												// passa al prossimo nodo
  	}
    fclose(fp);
    printf("Salvataggio eseguito!\n\n");
  }
  else
    printf("Salvataggio non riuscito!\n\n");
}

/* FUNZIONE PRINCIPALE */
int main() {

	int numero=-1;	 		// per la scelta dell'utente

	/* lista di persone, inizialmente recuperata da file */
	NODO* lista = acquisizione();

	/* ciclo di interazione con l'utente */
	while(numero!=0) {
		printf("\nCiao utente! Puoi svolgere le seguenti operazioni:\n");
		printf("Introduci 1 -> Immetti una persona\n");
		printf("Introduci 2 -> Cancella una persona\n");
		printf("Introduci 3 -> Visualizza la lista\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &numero);

		/* immetti una persona */
		if(numero==1)
			lista = inserisciCoda(lista);

		/* cancella una persona */
		else  if(numero==2)
			lista = cancellaTesta(lista);

		/* visualizza tutta la lista */
		else  if(numero==3)
			visualizza(lista);

		/* numero sbagliato? */
		else  if(numero!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n");
		/* fine programma */
		else {
			printf("Adios!\n");
		}
	}
	/* salva dati su un file */
	salvataggio(lista);
}
