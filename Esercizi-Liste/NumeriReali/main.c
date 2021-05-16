#include <stdio.h>
#include <stdlib.h>

typedef struct NUM{
	int i;
	int d;
} Num;

typedef struct NODO{
	Num n;
	struct NODO* next;
} Nodo;

void stampaNumero(Num* n){
	printf("%d,%d\n",n->i,n->d);
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n\n");
	} else {
		printf("Ecco la lista di numeri reali:\n");
		while(head!=NULL){
			stampaNumero(&head->n);
			head=head->next;
		}
		printf("\nFine della lista!\n\n");
	}
}

Num creaNumero(){
	Num n;
	printf("Inserisci la parte intera del numero: ");
	scanf("%d", &n.i);
	printf("Inserisci la parte decimale del numero: ");
	scanf("%d", &n.d);
	return n;
}

Nodo* inserisciTesta(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->n=creaNumero();
	nuovo->next=head;
	return nuovo;
}

Nodo* inserisciCoda(Nodo* head){
	if(head==NULL){
		head = inserisciTesta(head);
	} else {
		Nodo* nuovo = malloc(sizeof(Nodo));
		nuovo->n=creaNumero();
		nuovo->next=NULL;
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
	Nodo* lista = NULL;
	int scelta;
	printf("Questo programma gestisce una lista di nunmeri reali.\n\n");
	
	do {
		printf("Quale operazione vuoi fare?\n\n");
		printf("1- Inserisci un numero in testa alla lista.\n");
		printf("2- Inserisci un numero in coda alla lista.\n");
		printf("3- Visualizza la lista.\n");
		printf("0- Termina programma.\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d", &scelta);
		printf("\n");
		if(scelta==1){
			lista = inserisciTesta(lista);
		} else if(scelta==2){
			lista = inserisciCoda(lista);
		} else if(scelta==3){
			stampaLista(lista);
		} else if(scelta!=0){
			printf("Scelta non valida!\n\n");
		}
	} while(scelta!=0);
	
	return 0;
}
