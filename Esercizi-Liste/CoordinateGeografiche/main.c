#include <stdio.h>
#include <stdlib.h>

typedef struct COORD
{
	float lon;
	float lat;
} Coord;

typedef struct NODO
{
	Coord c;
	struct NODO* next;
} Nodo;

void stampaCoordinata(Coord* c){
	printf("Longitudine: %.6f ; Latitudine: %.6f\n", c->lon, c->lat);
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n\n");
	} else {
		printf("Ecco la lista di coordinate:\n\n");
		while(head!=NULL){
			stampaCoordinata(&head->c);
			head=head->next;
		}
	}
}

Nodo* cancellaCoordinata(Nodo* head){
	if(head==NULL){
		printf("Nulla da cancellare!\n\n");
	} else {
		Nodo* dealloca=head;
		head=head->next;
		free(dealloca);
	}
	return head;
}

Coord creaCoordinata(){
	Coord nuovo;
	printf("Inserisci la nuova coordinata.\n");
	printf("Longitudine: ");
	scanf("%f", &nuovo.lon);
	printf("Latitudine: ");
	scanf("%f", &nuovo.lat);
	printf("\n");
	return nuovo;
}

Nodo* inserisciCoordinata(Nodo* head){
	Nodo* nuovo=malloc(sizeof(Nodo));
	nuovo->c=creaCoordinata();
	nuovo->next=NULL;
	if(head==NULL){
		head=nuovo;
	} else {
		Nodo* nodo=head;
		while(nodo->next!=NULL){
			nodo=nodo->next;
		}
		nodo->next=nuovo;
	}
	
	return head;
}

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di coordintate geografiche.\n\n");

	Nodo* lista = NULL;
	int choice;

	do{
		printf("Quale operazione vuoi eseguire?\n\n");
		printf("1- Inserisci una nuova coordinata.\n");
		printf("2- Cancella la prima coordinata.\n");
		printf("3- Visualizza l'elenco di coordinate.\n");
		printf("0- Termina il programma.\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d",&choice);
		printf("\n");
		if(choice==1){
			lista = inserisciCoordinata(lista);
		} else if(choice==2){
			lista = cancellaCoordinata(lista);
		} else if(choice==3){
			stampaLista(lista);
		} else if(choice!=0){
			printf("Scelta non valida!\n\n");
		}
	}
	while(choice!=0);

	return 0;
}
