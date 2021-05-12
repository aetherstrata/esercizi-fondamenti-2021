#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* STRUTTURE */

typedef struct PUNTO {
	float x;
	float y;
} Punto;

typedef struct CERCHIO {
	Punto centro;
	float r;
} Cerchio;

typedef struct NODO {
	Cerchio c;
	struct NODO* next;
} Nodo;

/* * * STAMPA * * */

void stampaPunto(Punto* p)
{
	printf("(%.2f,%.2f)\n", p->x, p->y);
}

void stampaCerchio(Cerchio* c)
{
	printf("Centro: ");
	stampaPunto(&c->centro);
	printf("Raggio: %.2f\n\n", c->r);
}

void stampaLista(Nodo* head)
{
	if(head==NULL){
		printf("La lista %c vuota!\n\n", 138);
	} else {
		while(head!=NULL){
			stampaCerchio(&head->c);
			head=head->next;
		}
	}
}

/* INSERIMENTO */

Cerchio creaCerchio()
{
	Cerchio c;
	printf("Inserisci il raggio del cerchio: ");
	scanf("%f", &c.r);
	printf("Inserisci le coordinate del cerchio:\n");
	printf("x: ");
	scanf("%f", &c.centro.x);
	printf("y: ");
	scanf("%f", &c.centro.y);
	return c;
}

Nodo* inserisciNodo(Nodo* head)
{
	Nodo* nuovo = malloc(sizeof(Nodo));
	
	nuovo->c = creaCerchio();
	nuovo->next=head;
	
	return nuovo;
}

/* * ELIMINAZIONE * */

int uguale(Cerchio* c1, Cerchio* c2)
{
	return (c1->r==c2->r && c1->centro.x==c2->centro.x && c1->centro.y==c2->centro.y);
}

Nodo* cancellaCerchio(Nodo* head)
{
	Cerchio cancella = creaCerchio();
	
	Nodo* nodoCorrente;
	Nodo* nodoPrec;
	
	if(head!=NULL) {

		/* cancellazione del primo nodo della lista */
		if(uguale(&head->c, &cancella)) {
			nodoCorrente = head;
			head = head->next;
			free(nodoCorrente);
			printf("Ho cancellato il primo elemento della lista!\n");
		}
		
		/* cancellazione di un nodo della lista che non è il primo */
		nodoCorrente = head->next;
		nodoPrec = head;
		
		while(nodoCorrente!=NULL) {
			if(uguale(&nodoCorrente->c, &cancella)){
				
				nodoPrec->next = nodoCorrente->next;
				free(nodoCorrente);
				nodoCorrente=nodoPrec->next;
				
			}
			else {
				nodoPrec = nodoCorrente;
				nodoCorrente = nodoCorrente->next;
			}
		}
	}
	
	return head;
}

/* FUNZIONI GEOMETRICHE */

float distanzaCentro(Cerchio* c1, Cerchio* c2)
{
	return sqrt(pow(c1->centro.x-c2->centro.x,2)+pow(c1->centro.y-c2->centro.y,2));
}

void isInscritto(Nodo* head)
{
	if(head->next==NULL){
		printf("Servono almeno due elementi da comparare.");
	} else {
		float d = distanzaCentro(&head->c,&head->next->c);
		
		if(head->c.r+d<=head->next->c.r)
			printf("Il primo cerchio %c contenuto completamente nel secondo.\n\n", 138);
		else
			printf("Il primo cerchio NON %c contenuto completamente nel secondo.\n\n", 138);
	}
}

/* LEGGI DA FILE */

Nodo* leggiFile()
{
	FILE* fp = fopen("osu.dat","rb");
	Nodo* head;
	
	if(fp==NULL){
		printf("Impossibile aprire il file!\n\n");
		head=NULL;
	} else {		
		Cerchio cerchio;
		int letto = fread(&cerchio, sizeof(Cerchio), 1, fp);
		
		if(letto==0){
			printf("Il file %c vuoto!\n\n", 138);
		} else {
			head=malloc(sizeof(Nodo));
			head->c=cerchio;
			
			Nodo* nodo=head;
			
			while(fread(&cerchio, sizeof(Cerchio), 1, fp)>0){
				nodo->next = malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->c=cerchio;
			}
			nodo->next=NULL;
			printf("File letto con successo!\n\n");
		}
		fclose(fp);
	}
	
	return head;
}

/* SALVA SU FILE */

void salvaSuFile(Nodo* head)
{
	FILE* fp = fopen("osu.dat","wb");
	
	if(fp==NULL){
		printf("Salvataggio fallito!\n\n");
	} else {
		while(head!=NULL){
			fwrite(&head->c, sizeof(Cerchio), 1, fp);
			head=head->next;
		}
		fclose(fp);
		printf("Salvataggio effettuato\n\n");
	}
}

/* * * MAIN * * */

int main(int argc, char **argv)
{
	printf("Questo programma gestisce una lista di punti nel piano.\n\n");
	
	Nodo* lista = leggiFile();
	
	int choice=-1;
	
	while(choice!=0){
		printf("Cosa vuoi fare?\n");
		printf("1- Inserisci un nuovo cerchio.\n");
		printf("2- Cancella un cerchio.\n");
		printf("3- Visualizza la lista di cerchi.\n");
		printf("4- Verifica se il primo cerchio %c totalmente inscritto nel secondo.\n\n", 138);
		printf("Inserisci la scelta: ");
		scanf("%d%*c", &choice);
		
		switch (choice)
		{
			case 1:
				lista = inserisciNodo(lista);
			break;
			
			case 2:
				lista = cancellaCerchio(lista);
			break;
			
			case 3:
				stampaLista(lista);
			break;
			
			case 4:
				isInscritto(lista);
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
