#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _NUMERO {
	int num;
	int den;
} Numero;

typedef struct _RETTA {
	int verticale;
	Numero m;
	Numero q;
} Retta;

typedef struct _NODO {
	Retta r;
	struct _NODO* next;
} Nodo;

/* * * STAMPA * * */

void stampaFrazione(Numero* n)
{
	printf("%d/%d\n",n->num,n->den);
}

void stampaRetta(Retta* r)
{
	char v;
	if(r->verticale)
		v='Y';
	else
		v='N';
	
	printf("verticale: %c\n", v);
	
	if(r->verticale){
		printf("intersezione: ");
		stampaFrazione(&r->q);
	} else {
		printf("coefficiente: ");
		stampaFrazione(&r->m);
		printf("intercetta: ");
		stampaFrazione(&r->q);
	}
	printf("/---------------/\n");
}

void stampaLista(Nodo* head)
{
	if(head==NULL){
		printf("La lista %c vuota.\n\n", 138);
	} else {
		printf("Ecco la lista delle rette nel piano:\n\n");
		while(head!=NULL){
			stampaRetta(&head->r);
			head=head->next;
		}
	}
}

/* * * ELIMINA * * */

Nodo* cancellaNodo(Nodo* head)
{
	if(head==NULL){
		printf("Nulla da cancellare!\n\n");
	} else {
		Nodo* dealloca = head;
		head=head->next;
		free(dealloca);
	}
	
	return head;
}

/* * INSERIMENTO * */

Retta creaRetta()
{
	Retta retta;
	char v='\0';
	
	printf("Inserisci la nuova retta:\n");
	printf("La retta %c verticale?\n(Y/N) ", 138);
	scanf("%c",&v);
	
	if(v=='Y'||v=='y') {
		retta.verticale=1;
		retta.m.num=0;
		retta.m.den=0;
	} else
		retta.verticale=0;
	
	if(retta.verticale){
		printf("In che punto interseziona l'asse delle x?\n");
		printf("Numeratore: ");
		scanf("%d", &retta.q.num);
		printf("Denominatore: ");
		scanf("%d", &retta.q.den);
	} else {
		printf("Quanto vale il suo coefficiente angolare?\n");
		printf("Numeratore: ");
		scanf("%d", &retta.m.num);
		printf("Denominatore: ");
		scanf("%d", &retta.m.den);
		printf("Quanto vale l'intercetta?\n");
		printf("Numeratore: ");
		scanf("%d", &retta.q.num);
		printf("Denominatore: ");
		scanf("%d", &retta.q.den);
	}
	
	return retta;
}

int precede(Retta* r1, Retta* r2)
{
	int risultato;
	
	if(r2->verticale)
		risultato = 1;
	else if(r1->verticale)
		risultato = 0;
	else {
		float m1 = (float)r1->m.num/r1->m.den;
		float m2 = (float)r2->m.num/r2->m.den;
		
		risultato = m1<m2;
	}
	
	return risultato;
}

void ordinaLista(Nodo* head)
{
	Nodo* i;
	Nodo* y;
	for(i=head;i->next!=NULL;i=i->next){
		for(y=i;y!=NULL;y=y->next){
			if(!precede(&i->r,&y->r)){
				Retta temp = y->r;
				y->r = i->r;
				i->r = temp;
			} 
		}
	}
}

Nodo* inserisciNodo(Nodo* head)
{
	Nodo* nuovo = malloc(sizeof(Nodo));
	
	nuovo->r=creaRetta();
	nuovo->next=head;

	ordinaLista(nuovo);
	
	return nuovo;
}

/* * LETTURA DA FILE * */

Nodo* leggiDaFile()
{
	FILE* fp = fopen("rette.dat","rb");
	Nodo* head;
	
	if(fp==NULL){
		printf("Impossibile aprire il file!\n\n");
		head=NULL;
	} else {
		Retta retta;
		int letto = fread(&retta, sizeof(Retta), 1, fp);
		
		if(letto){
			head = malloc(sizeof(Nodo));
			head->r=retta;
			
			Nodo* nodo=head;
			while(fread(&retta, sizeof(Retta), 1, fp)>0){
				nodo->next = malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->r=retta;
			}
			nodo->next=NULL;
			printf("File letto con successo!\n\n");
		} else {
			printf("Il file %c vuoto!\n\n", 138);
		}
	}
	return head;
}

/* * SALVATAGGIO SU FILE * */

void salvaSuFile(Nodo* head)
{
	FILE* fp = fopen("rette.dat","wb");
	
	if(fp==NULL){
		printf("Salvataggio fallito!\n\n");
	} else {
		while(head!=NULL){
			fwrite(&head->r, sizeof(Retta), 1, fp);
			head=head->next;
		}
		fclose(fp);
		printf("Salvataggio effettuato\n\n");
	}
}

/* * * MAIN * * */

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di rette nel piano.\n\n");
	
	Nodo* lista = leggiDaFile();
	
	int choice=-1;
	
	while(choice!=0){
		printf("Cosa vuoi fare?\n");
		printf("1- Inserisci una nuova retta.\n");
		printf("2- Cancella la retta in cima alla lista.\n");
		printf("3- Visualizza la lista di cerchi.\n");
		printf("Inserisci la scelta: ");
		scanf("%d%*c", &choice);
		
		switch (choice)
		{
			case 1:
				lista = inserisciNodo(lista);
			break;
			
			case 2:
				lista = cancellaNodo(lista);
			break;
			
			case 3:
				stampaLista(lista);
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
