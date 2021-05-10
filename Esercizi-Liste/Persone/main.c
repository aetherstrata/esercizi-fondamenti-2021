#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _DATA {
	int g;
	int m;
	int a;
} Data;

typedef struct _PERSONA {
	char nome[20];
	char cognome[20];
	Data data;
} Persona;

typedef struct _NODO {
	Persona p;
	struct _NODO* next;
} Nodo;

/* * * * * * * */
/* * STAMPA * */
/* * * * * * */

void stampaPersona(Persona* p)
{
	printf("Nome: %s %s\n", p->nome, p->cognome);
	printf("Data di nascita: %d/%d/%d\n\n", p->data.g, p->data.m, p->data.a);
}

void stampaLista(Nodo* head)
{
	if(head==NULL){
		printf("La lista %c vuota! Nulla da visualizzare!\n\n", 138);
	} else {
		while(head!=NULL){
			stampaPersona(&head->p);
			head=head->next;
		}
	}
}

/* * * * * * * * * */
/* * INSERIMENTO * */
/* * * * * * * * * */

Data creaData()
{
	Data nuovaData;
	
	printf("Qual %c la data di nascita di questa persona?\n", 138);
	printf("Giorno: ");
	scanf("%d", &nuovaData.g);
	printf("Mese: ");
	scanf("%d", &nuovaData.m);
	printf("Anno: ");
	scanf("%d", &nuovaData.a);
	
	return nuovaData;
}

Persona creaPersona()
{
	Persona nuovaPersona;
	
	printf("Qual %c il nome di questa persona? ", 138);
	fgets(nuovaPersona.nome, 20, stdin);
	nuovaPersona.nome[strlen(nuovaPersona.nome)-1]='\0';
	
	printf("Qual %c il cognome di questa persona? ", 138);
	fgets(nuovaPersona.cognome, 20, stdin);
	nuovaPersona.cognome[strlen(nuovaPersona.cognome)-1]='\0';
	
	nuovaPersona.data = creaData();
	
	return nuovaPersona;
}

Nodo* inserisciPersona(Nodo* head)
{
	if(head==NULL){
		head = malloc(sizeof(Nodo));
		head->p=creaPersona();
		head->next=NULL;
	} else {
		Nodo* nodo = head;
		while(nodo->next!=NULL){
			nodo=nodo->next;
		}
		nodo->next=malloc(sizeof(Nodo));
		nodo=nodo->next;
		nodo->p=creaPersona();
		nodo->next=NULL;
	}
	
	printf("Inserimento completato!\n\n");
	
	return head;
}

/* * * * * * * * * * */
/* * ELIMINAZIONE * */
/* * * * * * * * * */

Nodo* cancellaPersona(Nodo* head)
{
	if(head==NULL){
		printf("La lista %c vuota! Nulla da cancellare!\n\n", 138);
	} else {
		Nodo* dealloca = head;
		head=head->next;
		free(dealloca);
	}
	
	printf("Cancellazione completata!\n\n");
	
	return head;
}

/* * * * * * */
/* * MAIN * */
/* * * * * */

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di persone.\n\n");
	
	Nodo* lista = NULL;
	
	int choice=-1;
	while(choice!=0){
		printf("Che operazione vuoi fare?\n");
		printf("1- Visualizza la lista di persone.\n");
		printf("2- Inserisci una persona in coda alla lista.\n");
		printf("3- Elimina la prima persona della lista.\n");
		printf("0- Termina programma.\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d%*c",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				stampaLista(lista);
			break;
			
			case 2:
				lista = inserisciPersona(lista);
			break;
			
			case 3:
				lista = cancellaPersona(lista);
			break;
			
			case 0:
				printf("Arrivederci!\n");
			break;
			
			default:
				printf("Scelta non valida!\n\n");
		}
	}
	return 0;
}
