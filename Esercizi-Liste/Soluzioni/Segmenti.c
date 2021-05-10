#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* un punto del piano */
struct Punto{
    float x;
    float y;
};

typedef struct Punto PUNTO;

/* un segmento del piano */
struct Segmento{
    struct Punto estremo1;
    struct Punto estremo2;
};

typedef struct Segmento SEG;

/* lista di segmenti */
struct Nodo{
    struct Segmento seg;
    struct Nodo* next;
};

typedef struct Nodo* NODO;

/**********************************************
 ****************** LUNGHEZZA *****************
 **********************************************/

/* funzione che calcola la distanza fra due punti */
float distanza(PUNTO p1, PUNTO p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

/* funzione che calcola la lunghezza di un segmento */
float lunghezza(SEG s) {
	return distanza(s.estremo1, s.estremo2);
}

/**********************************************
 ******************** STAMPE ******************
 **********************************************/

/* funzione che stampa un punto */
 void stampaPunto(PUNTO p){
    printf("(%.2f,%.2f)",p.x,p.y);
 }

/* per stampare un segmento */
void stampaSegmento(SEG s) {
	printf("Il segmento ha estremi ");
	stampaPunto(s.estremo1);
	printf(" e ");
	stampaPunto(s.estremo2);
	printf(" e lunghezza %.2f\n", lunghezza(s));
}

/* per stampare una lista di segmenti */
void stampa(NODO lista) {
	/* vai avanti fino a che ci sono segmenti */
	if(lista==NULL)
		printf("La lista %c vuota\n\n", 138);
	else {
		printf("*********************\n");
		printf("Ecco la lista di segmenti\n");
		printf("*********************\n\n");
		while(lista!= NULL) {
			stampaSegmento(lista->seg);
			lista = lista->next;
		}
		printf("\n*********************\n\n");
	}
}

/**********************************************
 ************ INSERIMENTO IN TESTA ************
 **********************************************/

/* inserimento di un segmento in lista con lettura */
SEG leggiSegmento() {
	SEG s;		// da inserire
	do{
		printf("Caro utente, qual %c la coordinata x del primo estremo del segmento? ", 138);
		scanf("%f", &s.estremo1.x);
		printf("Caro utente, qual %c la coordinata y del primo estremo del segmento? ", 138);
		scanf("%f", &s.estremo1.y);
		printf("Caro utente, qual %c la coordinata x del secondo estremo del segmento? ", 138);
		scanf("%f", &s.estremo2.x);
		printf("Caro utente, qual %c la coordinata y del secondo estremo del segmento? ", 138);
		scanf("%f", &s.estremo2.y);
		printf("\n");
		if(s.estremo1.x==s.estremo2.x && s.estremo1.y==s.estremo2.y)
			printf("Gli estremi coincidono! Riprova!\n\n");
	}
	while(s.estremo1.x==s.estremo2.x && s.estremo1.y==s.estremo2.y);
	return s;
}

NODO inserimento(NODO lista) {
	/* alloca memoria per il nuovo nodo */
	NODO testa = malloc(sizeof(struct Nodo));
	/* riempi il suo campo dati */
	testa->seg = leggiSegmento();

	/* collega il nuovo nodo al successivo, che potrebbe essere NULL se la lista era vuota*/
	testa->next = lista;
	printf("Inserito!\n\n");

	/* il nuovo nodo diventa la testa della lista */
	return testa;
}

/**********************************************
 ************ CANCELLAZIONE IN TESTA ************
 **********************************************/

/* cancellazione del primo segmento della lista */
NODO cancellaNodo(NODO head) {
	NODO primoNodo;											// il nuovo primo nodo della lista

	/* lista vuota? */
	if(head==NULL) {
		primoNodo = NULL;
		/* stampa messaggio e termina */
		printf("Niente da cancellare!\n\n");
	}
	else {
		/* il secondo nodo diventa il primo; eventualmente questo � NULL */
		primoNodo = head->next;
		/* viene deallocata la memoria del primo nodo */
		free(head);
		/* stampa messaggio e termina */
		printf("Segmento cancellato!\n\n");
	}

	/* restituisci l'indirizzo del nuovo primo elemento */
	return primoNodo;
}

/**********************************************
 ****************** PENDENZE ******************
 **********************************************/

/* funzione che dato un segmento ne restituisce la pendenza come valore positivo */
float slope(SEG s) {
	// pre: s non � verticale
	return (s.estremo1.y - s.estremo2.y) / (s.estremo1.x - s.estremo2.x);
}

/* verifica segmenti paralleli */
int parallel(SEG s1, SEG s2) {
	int p;			// valore da restituire
	/* il caso in cui almeno uno dei due sia verticale va gestito diversamente */
	if(s1.estremo1.x == s1.estremo2.x && s2.estremo1.x == s2.estremo2.x)		// entrambi verticali
		p =1;
	else
		if(s1.estremo1.x == s1.estremo2.x || s2.estremo1.x == s2.estremo2.x)		// uno verticale
			p=0;
		else 		// nessuno verticale
			p = (slope(s1) == slope(s2));
	return p;
}

/* verifica segmenti perpendicolari */
int orthogonal(SEG s1, SEG s2) {
	int p;			// valore da restituire
	/* il caso in cui almeno uno dei due sia verticale va gestito diversamente */
	/* entrambi verticali */
	if(s1.estremo1.x == s1.estremo2.x && s2.estremo1.x == s2.estremo2.x)
		p =0;
	else
		/* s1 verticale ed s2 orizzontale */
		if(s1.estremo1.x == s1.estremo2.x && s2.estremo1.y == s2.estremo2.y)
			p=1;
		else
			/* s1 orizzontale ed s2 verticale */
			if(s1.estremo1.y == s1.estremo2.y && s2.estremo1.x == s2.estremo2.x)
				p=1;
			else 		// nessuno verticale
				p = (slope(s1)*slope(s2) == -1);
	return p;
}

/* funzione che verifica se due segmenti della lista sono perpendicolari */
void paralleli(NODO head) {
	SEG s1, s2;				// segmenti
	if(head== NULL || head->next==NULL)
		printf("Non ci sono abbastanza segmenti per la verifica\n\n");
	else {
		int trovati = 0;							// numero segmenti individuati
		int risposta;								// per interazione con utente

		while(trovati<1 && head!=NULL) {				// ricerca del primo segmento
			printf("Ecco un segmento della lista:\n");
			stampaSegmento(head->seg);
			printf("E' questo il segmento che ti interessa? (1=SI, 0=NO)\n");
			scanf("%d", &risposta);
			if(risposta){			// trovato
				trovati++;
				s1 = head->seg;
			}
			head = head->next;
		}

		while(trovati<2 && head!=NULL) {				// ricerca del secondo segmento
			printf("Ecco un segmento della lista:\n");
			stampaSegmento(head->seg);
			printf("E' questo il segmento che ti interessa? (1=SI, 0=NO)\n");
			scanf("%d", &risposta);
			if(risposta){			// trovato
				trovati++;
				s2 = head->seg;
			}
			head = head->next;
		}

		/* verifica finale */
		if(trovati<2)
			printf("Non hai inserito abbastanza segmenti!\n\n");
		else
			if(parallel(s1,s2))
				printf("I segmenti sono paralleli!\n\n");
			else
				printf("I segmenti NON sono paralleli!\n\n");
	}
}

/* funzione che verifica se i primi due segmenti della lista sono perpendicolari */
void perpendicolari(NODO head) {
	SEG s1, s2;				// segmenti
	if(head== NULL || head->next==NULL)
		printf("Non ci sono abbastanza segmenti per la verifica\n\n");
	else {
		s1 = head->seg;							// primo segmento
		s2 = head->next->seg;				// secondo segmento
		/* verifica la perpendicolarit� */
		if(orthogonal(s1,s2))
			printf("Sono perpendicolari!\n\n");
		else
			printf("Non sono perpendicolari!\n\n");
	}
}

/**********************************************
 **************** GESTIONE FILE ****************
 **********************************************/

 /**** funzione per l'acquisizione di una lista su file DI TESTO *****/
 struct Nodo* acquisizione() {
   struct Nodo* head = NULL;
 	/* apri il file */
 	FILE* fp = fopen("segmenti.txt", "r");
 	/* file non aperto */
 	if(fp==NULL)
 		printf("Apertura file non riuscita!\n\n");
 	/* file aperto */
 	else {
 		SEG s;
 		if(fscanf(fp,"%f %f %f %f", &s.estremo1.x, &s.estremo1.y, &s.estremo2.x, &s.estremo2.y)==EOF)
 			printf("Il file non contiene segmenti!\n\n");
 		else {
 			/* primo segmento */
 			head = malloc(sizeof(struct Nodo));
 			head->seg = s;
 			struct Nodo* nodo=head;
 			/* segmenti successivi */
 			while(fscanf(fp,"%f %f %f %f", &s.estremo1.x, &s.estremo1.y, &s.estremo2.x, &s.estremo2.y)!=EOF) {
 				nodo->next = malloc(sizeof(struct Nodo));
 				nodo=nodo->next;
 				nodo->seg = s;
 			}
 			/* per l'ultimo nodo della lista */
 			nodo->next =NULL;
 			printf("Segmenti recuperati!\n\n");
 		}

 		fclose(fp);
 	}

 	return head;
 }

 /* funzione per il salvataggio di una lista su file TESTUALE */
 void salvataggio(struct Nodo* lista) {
 	FILE* fp = fopen("segmenti.txt", "w");	// per la scrittura di un file testuale
   /* file non aperto */
 	if(fp==NULL)
 		printf("Salvataggio non riuscito!\n");
 	/* file aperto */
 	else {
 		/* salva un segmento alla volta */
 		while(lista!=NULL) {
 			fprintf(fp, "%f %f %f %f\n", lista->seg.estremo1.x,  lista->seg.estremo1.y,
               lista->seg.estremo2.y,  lista->seg.estremo2.y);
 			lista = lista->next;
 		}
 		fclose(fp);
 		printf("Salvataggio riuscito!\n");
 	}
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
		printf("1 -> Inserisci un segmento in testa alla lista\n");
		printf("2 -> Cancella il primo segmento della lista\n");
		printf("3 -> Visualizza la lista di segmenti\n");
		printf("4 -> Verifica se due segmenti a scelta sono paralleli\n");
		printf("5 -> Verifica se i primi due segmenti sono perpendicolari\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1) {
			lista = inserimento(lista);
		}
		else if(risposta==2) {
			lista = cancellaNodo(lista);
		}
		else if(risposta==3) {
			stampa(lista);
		}
		else if(risposta==4) {
			paralleli(lista);
		}
		else if(risposta==5) {
			perpendicolari(lista);
		}
		else if(risposta==0) {
			printf("Adios!\n\n");
		}
		else printf("Selezione non valida!\n\n");
	}
	salvataggio(lista);
}
