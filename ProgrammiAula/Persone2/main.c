#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATA {
	int g;
	int m;
	int a;
} Data;

typedef struct PERSONA{
	char nome[20];
	char cognome[20];
	Data data;
} Persona;

typedef struct NODO {
	Persona p;
	struct NODO* next;
} Nodo;

Persona creaPersona(){
	Persona nuovo;
	printf("Qual %c il nome di questa persona? ", 138);
	fgets(nuovo.nome, 20, stdin);
	nuovo.nome[strlen(nuovo.nome)-1]='\0';
	printf("Qual %c il cognome di questa persona? ", 138);
	fgets(nuovo.cognome, 20, stdin);
	nuovo.cognome[strlen(nuovo.cognome)-1]='\0';
	printf("Inserisci la data di nascita di %s %s\n", nuovo.nome, nuovo.cognome);
	printf("Giorno: ");
	scanf("%d", &nuovo.data.g);
	printf("Mese: ");
	scanf("%d", &nuovo.data.m);
	printf("Anno: ");
	scanf("%d", &nuovo.data.a);
	return nuovo;
}

void stampaPersona(Persona* p){
	printf("Nome: %s\n",p->nome);
	printf("Cognome: %s\n",p->cognome);
	printf("Data: %d/%d/%d\n", p->data.g, p->data.m, p->data.a);
	printf("/****************/\n");
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n\n");
	} else {
		printf("Inizio della lista\n");
		printf("/****************/\n");
		while(head!=NULL){
			stampaPersona(&head->p);
			head=head->next;
		}
		printf("Fine della lista!\n\n");
	}
}

Nodo* inserimentoCoda(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->p=creaPersona();
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
	printf("Inserimento effettuato!\n\n");
	return head;
}

Nodo* eliminazioneTesta(Nodo* head){
	if(head==NULL){
		printf("Nulla da eliminare!\n\n");
	} else {
		Nodo* dealloca = head;
		head=head->next;
		free(dealloca);
		printf("Cancellazione effettuata!\n\n");
	}
	return head;
}

void salvaSuFile(Nodo* head){
	if(head==NULL){
		printf("Nulla da salvare!\n\n");
	} else {
		FILE* fp = fopen("persone.dat","wb");
		if(fp==NULL){
			printf("Errore di scrittura!\n\n");
		} else {
			while(head!=NULL){
				fwrite(&head->p, sizeof(Persona), 1, fp);
				head=head->next;
			}
			fclose(fp);
			printf("File salvato!\n\n");
		}
	}
}

Nodo* leggiDaFile(){
	FILE* fp = fopen("persone.dat","rb");
	Nodo* head;
	if(fp==NULL){
		printf("Errore di lettura!\n\n");
		head=NULL;
	} else {
		Persona persona;
		head = malloc(sizeof(Nodo));
		int letto = fread(&persona, sizeof(Persona), 1, fp);
		if(letto==0){
			printf("File vuoto!\n\n");
		} else {
			head->p=persona;
			Nodo* nodo;
			nodo=head;
			while(fread(&persona, sizeof(Persona), 1, fp)>0){
				nodo->next=malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->p=persona;
			}
			nodo->next=NULL;
			printf("Lettura completata!\n\n");
		}
		fclose(fp);
	}
	return head;
}

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di persone.\n\n");
	
	Nodo* lista = leggiDaFile();
	int scelta;
	do {
		printf("Quale operazione voui fare?\n\n");
		printf("1- Inserimento\n");
		printf("2- Eliminazione\n");
		printf("3- Visualizzazione\n");
		printf("0- Termina programma\n\n");
		printf("Inerisci la scelta: ");
		scanf("%d%*c",&scelta);
		printf("\n");
		if(scelta==1){
			lista = inserimentoCoda(lista);
		} else if(scelta==2){
			lista = eliminazioneTesta(lista);
		} else if(scelta==3){
			stampaLista(lista);
		} else if(scelta!=0){
			printf("Scelta non valida!\n\n");
		}
	} while(scelta!=0);
	salvaSuFile(lista);
	return 0;
}
