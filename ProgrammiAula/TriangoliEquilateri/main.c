#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* * * * * * * * * * */
/* * * STRUTTURE * * */
/* * * * * * * * * * */

typedef struct _punto {
	float x;
	float y;
} Punto;

typedef struct _triangolo {
	Punto vertice;
	float lato;
} Triangolo;

typedef struct _nodo {
	Triangolo t;
	struct _nodo* next;
} Nodo;

/* * * * * * * * * * */
/* * * GEOMETRIA * * */
/* * * * * * * * * * */

float perimetro(Triangolo* t){
	return 3*t->lato;
}

Punto inBassoSinistra(Triangolo* t){
	Punto p;
	p.x = t->vertice.x - (t->lato)/2;
	p.y = t->vertice.y - ((t->lato)/2*sqrt(3));
	return p;
}

Punto inBassoDestra(Triangolo* t){
	Punto p;
	p.x = t->vertice.x + (t->lato)/2;
	p.y = t->vertice.y - ((t->lato)/2*sqrt(3));
	return p;
}

/* * * * * * * * * * * */
/* * FUNZIONE STAMPA * */
/* * * * * * * * * * * */

void stampaPunto(Punto* p){
	printf("(%.2f,%.2f)", p->x, p->y);
}

void stampaTriangolo(Triangolo* t)
{
	Punto p1, p2;
	p1 = inBassoSinistra(t);
	p1 = inBassoDestra(t);
	
	printf("Triangolo con perimentro %.2f e vertici: ", perimetro(t));
	stampaPunto(&t->vertice);
	stampaPunto(&p1);
	stampaPunto(&p2);
}

void stampaLista(Nodo* head)
{
	if(head==NULL){
		printf("Nessun elemento!");
	} else {
		printf("Lista dei triangoli contenuti della lista: \n");
		while(head!=NULL){
			stampaTriangolo(&head->t);
			head=head->next;
		}
		printf("Fine della lista!");
	}
}

void leggiTriangolo(Triangolo* t)
{
	printf("Quanto %c lunga la base?\n", 138);
	printf("lato: ");
	scanf("%f", &t->lato);
	printf("Quali sono le coordinate del vertice in alto?\n");
	printf("x: ");
	scanf("%f",&t->vertice.x);
	printf("y: ");
	scanf("%f",&t->vertice.y);
}

Nodo* inserisci(Nodo* head)
{
	Nodo* nuovoNodo = malloc(sizeof(Nodo));
	leggiTriangolo(&nuovoNodo->t);
	
	// Caso inserimento in testa
	if(head==NULL || (nuovoNodo->t.lato < head->t.lato)){
		nuovoNodo->next=head;
		head = nuovoNodo;
	}
	//Caso generale
	else {
		Nodo* precedente = head;
		Nodo* successivo = head->next;
		
		while(successivo!=NULL && successivo->t.lato < nuovoNodo->t.lato){
			precedente = precedente->next;
			successivo = successivo->next;
		}
		
		precedente->next = nuovoNodo;
		nuovoNodo->next = successivo;
	}
	
	printf("Inserimento effettuato!\n");
	return head;
}

Nodo* cancella(Nodo* head){
	float p;
	printf("Qual %c il perimetro del triangolo da cancellare? ", 138);
	scanf("%f", &p);
	
	if(head!=NULL){
		printf("Nulla da cancellare!\n");
	} else {
		// Caso cancellazione in testa
		if(perimetro(&head->t) == p){
			Nodo* dealloca = head;
			head = head->next;
			free(dealloca);
			printf("Cancellazione effettuata!\n");
		} 
		// Caso generale
		else {
			Nodo* precedente = head;
			Nodo* successivo = head->next;
			
			while(successivo!=NULL && perimetro(&successivo->t)!=p){
				precedente = precedente->next;
				successivo = successivo->next;
			}
			
			if(successivo == NULL){
				printf("Nessun triangolo ha il perimentro immesso!\n");
			} else {
				precedente->next = successivo->next;
				free(successivo);
				printf("Cancellazione effettuata!\n");
			}
		}
	}
}

Nodo* acquisizione()
{
	FILE* fp = fopen("Monstata.dat", "rb");
	Nodo* head = NULL;
	
	if(fp==NULL){
		printf("Lettura non riuscita!\n");
	} else {
		int letto = 0;
		Triangolo triangolo;
		letto = fread(&triangolo, sizeof(Triangolo), 1, fp);
		
		if(letto == 0){
			printf("Il file non contiene triangoli!\n");
		} else {
			head = malloc(sizeof(Nodo));
			head->t = triangolo;
			
			Nodo* nodo=head;
			while(fread(&triangolo, sizeof(Triangolo), 1, fp)>0){
				nodo->next = malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->t=triangolo;
			}
			nodo->next=NULL;
			printf("File letto con successo!\n");
		}
		fclose(fp);
	}
	return head;
}

void salvataggio(Nodo* lista)
{
	FILE* fp = fopen("monstrata.dat", "wb");
	if(fp==NULL){
		printf("Salvataggio non riuscito!\n");
	} else {
		while(lista!=NULL){
			fwrite(&lista->t, sizeof(Triangolo), 1, fp);
			lista = lista->next;
		}
		fclose(fp);
		printf("Salvataggio Effettuato!\n");
	}
}

int main(int argc, char **argv)
{
	Nodo* lista = acquisizione();
	
	int scelta = -1;
	while(scelta!=0){
		printf("Che operazione vuoi eseguire?\n");
		printf("1 -> \n");
		printf("2 -> \n");
		printf("3 -> \n");
		printf("0 -> Termina programma.\n");
		
		scanf("%d",&scelta);
		
		if(scelta==1){
			stampaLista(lista);
		} else if(scelta==2){
			lista = inserisci(lista);
		} else if(scelta==3){
			lista = cancella(lista);
		}
	}
	return 0;
}
