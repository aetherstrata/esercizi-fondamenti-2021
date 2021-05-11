#include <stdio.h>
#include <stdlib.h>

typedef struct _INTERVALLO {
	int a;
	int b;
} Intervallo;

typedef struct _NODO {
	Intervallo i;
	struct _NODO* next;
} Nodo;

/* * * * * * * * * * * * * * */
/* * FUNZIONI GEOMETRICHE * */
/* * * * * * * * * * * * * */

int maxA(Nodo* head)
{
	int max=0;
	
	while(head!=NULL){
		if(head->i.a>max){
			max=head->i.a;
		}
		head=head->next;
	}
	
	return max;
}

int minB(Nodo* head)
{
	int min=head->i.b;
	
	while(head!=NULL){
		if(head->i.b<min){
			min=head->i.b;
		}
		head=head->next;
	}
	
	return min;
}

/* * * * * * * * * */
/* * ORDINAMENTO * */
/* * * * * * * * * */

void ordinaLista(Nodo* head)
{
	Nodo* i;
	Nodo* y;
	
	//Bubble sort
	for(i=head;i->next!=NULL;i=i->next){
		for(y=i;y!=NULL;y=y->next){
			if(i->i.a>y->i.a){
				Intervallo temp1 = i->i;
				i->i=y->i;
				y->i=temp1;
			}
			if(i->i.a==y->i.a && i->i.b>y->i.b){
				Intervallo temp2 = i->i;
				i->i=y->i;
				y->i=temp2;
			}
		}
	}
}

/* * * * * * * */
/* * STAMPA * */
/* * * * * * */

void stampaIntervallo(Intervallo* i)
{
	for(int inizio=0; inizio<i->a; inizio++){
		printf(" ");
	}
	for(int fine=0; fine<(i->b-i->a); fine++){
		printf("-");
	}
	printf("\n");
}

void stampaLista(Nodo* head)
{
	if(head==NULL){
		printf("'Nulla da visualizzare!");
	} else {
		while(head!=NULL){
			stampaIntervallo(&head->i);
			head=head->next;
		}
	}
	printf("\n");
}

void stampaIntersezione(Nodo* head)
{
	if(minB(head)<=maxA(head)){
		printf("Intersezione impossibile!\n\n");
	} else {
		Intervallo intersezione;
		intersezione.a=maxA(head);
		intersezione.b=minB(head);
		stampaIntervallo(&intersezione);
	}
	printf("\n");
}

/* * * * * * * * * */
/* * INSERIMENTO * */
/* * * * * * * * * */

Intervallo creaIntervallo()
{
	Intervallo nuovoIntervallo;
	nuovoIntervallo.a=-1;
	nuovoIntervallo.b=-1;
	
	while(nuovoIntervallo.a<0){
		printf("Qual %c il primo membro dell'intervallo? ", 138);
		scanf("%d", &nuovoIntervallo.a);
		if(nuovoIntervallo.a<0){
			printf("Il primo membro deve essere maggiore di zero!\n");
		}
	}
	
	while(nuovoIntervallo.b<=nuovoIntervallo.a){
		printf("Qual %c il secondo membro dell'intervallo? ", 138);
		scanf("%d", &nuovoIntervallo.b);
		if(nuovoIntervallo.b<=nuovoIntervallo.a){
			printf("Il secondo membro deve essere maggiore del primo!\n");
		}
	}
	printf("\n");
	
	return nuovoIntervallo;
}

Nodo* inserisciIntervallo(Nodo* head)
{
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->i = creaIntervallo();
	nuovo->next=head;
	return nuovo;
}

/* * * * * * * * * * */
/* * ELIMINAZIONE * */
/* * * * * * * * * */

Nodo* cancellaIntervallo(Nodo* head)
{
	if(head==NULL){
		printf("Nulla da cancellare!\n\n");
	} else {
		if(head->next==NULL){
			free(head);
			head=NULL;
		} else {
			Nodo* curr = head->next;
			Nodo* prev = head;
			while(curr->next!=NULL){
				prev = curr;
				curr = curr->next;
			}
			
			free(curr);
			prev->next=NULL;
		}
		printf("Cacellazione effettuata!\n\n");
	}
	
	return head;
}

/* * * * * * * */
/* * LETTURA * */
/* * * * * * * */

Nodo* leggiDaFile()
{
	FILE* fp = fopen("intervalli.dat","rb");
	Nodo* head;
	
	if(fp==NULL){
		printf("Errore di lettura!\n\n");
		head=NULL;
	} else {
		Intervallo intervallo;
		int letto = fread(&intervallo, sizeof(Intervallo), 1, fp);
		
		if(letto){
			head = malloc(sizeof(Nodo));
			head->i = intervallo;
			
			Nodo* nodo=head;
			while(fread(&intervallo, sizeof(Intervallo), 1, fp)>0){
				nodo->next = malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->i=intervallo;
			}
			nodo->next=NULL;
			printf("File letto con successo!\n\n");
		} else {
			printf("Il file %c vuoto!\n\n", 138);
		}
	}
	return head;
}

/* * * * * * * * */
/* * SCRITTURA * */
/* * * * * * * * */

void salvaSuFile(Nodo* head)
{
	if(head==NULL){
		printf("Nulla da salvare!\n\n");
	} else {
		FILE* fp = fopen("intervalli.dat","wb");
		if(fp==NULL){
			printf("Scrittura fallita!\n\n");
		} else {
			while(head!=NULL){
				fwrite(&head->i, sizeof(Intervallo), 1, fp);
				head=head->next;
			}
			fclose(fp);
			printf("Scrittura completata!\n\n");
		}
	}
}

/* * * * * * */
/* * MAIN * */
/* * * * * */

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di intervalli nel piano.\n\n");
	
	Nodo* lista = leggiDaFile();
	
	int choice=-1;
	while(choice!=0){
		printf("Che operazione vuoi fare?\n");
		printf("1- Inserisci un nuovo intervallo in testa alla lista.\n");
		printf("2- Elimina l'intervallo in coda alla lista.\n");
		printf("3- Visualizza tutti gli intervalli della lista.\n");
		printf("4- Ordina gli intervalli.\n");
		printf("5- Stampa l'intersezione di tutti gli intervalli.\n");
		printf("0- Termina programma.\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d%*c",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				lista = inserisciIntervallo(lista);
			break;
			
			case 2:
				lista = cancellaIntervallo(lista);
			break;
			
			case 3:
				stampaLista(lista);
			break;
			
			case 4:
				ordinaLista(lista);
			break;
			
			case 5:
				stampaIntersezione(lista);
			break;
			
			case 0:
				salvaSuFile(lista);
			break;
			
			default:
				printf("Scelta non valida!\n\n");
		}
	}
	return 0;
}
