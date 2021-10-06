#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/

typedef struct FRITTO{
	char nome[30];
	char surgelato;
	float prezzo;
} Fritto;

typedef struct NODO{
	Fritto f;
	struct NODO* next;
} Nodo;

/*******************************************/
/*********** FUNZIONI GEOMETRICHE **********/
/*******************************************/


/*****************************/
/*********** STAMPE **********/
/*****************************/

void stampaFritto(Fritto* f){
	printf("Nome: %s\n", f->nome);
	printf("Surgelato: %c\n", f->surgelato);
	printf("Prezzo: %.2f\n", f->prezzo);
	printf("|**************************|\n");
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n\n");
	} else {
		printf("|**************************|\n");
		while(head!=NULL){
			stampaFritto(&head->f);
			head=head->next;
		}
		printf("\n");
	}
}

/**********************************************
 **************** INSERIMENTO *****************
 **********************************************/

Fritto creaFritto(){
	Fritto nuovo;
	printf("Nome del fritto: ");
	fgets(nuovo.nome, 30, stdin);
	nuovo.nome[strlen(nuovo.nome)-1]='\0';
	printf("Congelato: (S/N) ");
	scanf("%c",&nuovo.surgelato);
	printf("Prezzo: (Euro) ");
	scanf("%f", &nuovo.prezzo);
	return nuovo;
}

Nodo* inserisciFritto(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->f=creaFritto();
	nuovo->next=NULL;
	if(head==NULL){
		head=nuovo;
	} else {
		Nodo* nodo = head;
		while(nodo->next!=NULL){
			nodo=nodo->next;
		}
		nodo->next=nuovo;
	}
	printf("Inserimento completato!\n\n");
	return head;
}

/**********************************************
 ********* ORDINAMENTO ************************
 **********************************************/

int condizione(Fritto* n1, Fritto* n2){
	return ((n1->surgelato=='S' && n2->surgelato=='N') ||
			(n1->prezzo>n2->prezzo));
}

void ordinaLista(Nodo* head){
	if(head==NULL){
		printf("Lista vuota!\n\n");
	} else if(head->next==NULL){
		printf("La listan non richiede ordinamento!\n\n");
	} else {
		Nodo *i, *y;
		for(i=head;i->next!=NULL;i=i->next){
			for(y=i;y!=NULL;y=y->next){
				if(condizione(&i->f,&y->f)){
					Fritto temp = y->f;
					y->f = i->f;
					i->f = temp;
				}
			}
		}
	}
}

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* inizializza la lista */
	Nodo* lista = NULL;

	int risposta = -1;			// per interazione con utente

	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserisci un fritto\n");
		printf("2 -> Ordina la lista\n");
		printf("3 -> Visualizza la lista di triangoli\n");
		printf("0 -> Termina il programma\n\n");
		scanf("%d%*c", &risposta);
		printf("\n");
		/* gestisci le operazioni dell'utente */
		if(risposta==1)
			lista = inserisciFritto(lista);
		else if(risposta==2)
			ordinaLista(lista);
		else if(risposta==3)
			stampaLista(lista);
		else if(risposta==0)
			printf("Finito!\n\n");
		else printf("Selezione non valida!\n\n");
	}
}