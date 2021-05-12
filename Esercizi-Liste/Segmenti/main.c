#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* * * * * * * * */
/* * STRUTTURE * */
/* * * * * * * * */

typedef struct PUNTO {
	float x;
	float y;
} Punto;

typedef struct SEGM {
	Punto a;
	Punto b;
} Segm;

typedef struct NODO {
	Segm s;
	struct NODO* next;
} Nodo;

/* * * * * * * * * * * * * * */
/* * FUNZIONI GEOMETRICHE * */
/* * * * * * * * * * * * * */

float lunghezza(Segm* s){
	return sqrt(pow(s->a.x-s->b.x,2)+pow(s->a.y-s->b.y,2));
}

float coefficiente(Segm* s){
	return (s->b.y-s->a.y)/(s->b.x-s->a.x);
}

int paralleli(Segm* s1, Segm* s2){
	return coefficiente(s1)==coefficiente(s2);
}

int perpendicolari(Segm* s1, Segm* s2){
	return coefficiente(s1)==-1/coefficiente(s2);
}

/* * * * * * * * * * * */
/* * VISUALIZZAZIONE * */
/* * * * * * * * * * * */

void stampaPunto(Punto* p){
	printf("(%.2f,%.2f)\n",p->x,p->y);
}

void stampaSegmento(Segm* s){
	printf("Estremo A: ");
	stampaPunto(&s->a);
	printf("Estremo B: ");
	stampaPunto(&s->b);
	printf("Lunghezza: %.2f\n\n", lunghezza(s));
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da visualizzare!\n\n");
	} else {
		printf("/******************/\n\n");
		while(head!=NULL){
			stampaSegmento(&head->s);
			head=head->next;
		}
		printf("/******************/\n\n");
	}
}

/* * * * * * * * */
/* * CONFRONTO * */
/* * * * * * * * */

void primiPerpendicolari(Nodo* head){
	if(head->next==NULL){
		printf("La lista deve contenere almeno due segmenti!\n\n");
	} else {
		if(perpendicolari(&head->s,&head->next->s)){
			printf("I primi due segmenti sono perpendicolari!\n\n");
		} else {
			printf("I primi due segmenti NON sono perpendicolari!\n\n");
		}
	}
}

Segm* selezionaNodo(Nodo* head){
	Segm* segmento=NULL;
	char scelta;
	
	while(head!=NULL){
		stampaSegmento(&head->s);
		printf("Vuoi selezionare questo segmento? (Y/N) ");
		scanf("%c%*c",&scelta);
		printf("\n/*******************/\n");
		
		if(scelta=='Y'||scelta=='y'){
			segmento=&head->s;
			break;
		}
		
		head=head->next;
	}
	
	return segmento;
}

void verificaParalleli(Nodo* head){
	if(head->next==NULL){
		printf("La lista deve contenere almeno due segmenti!\n\n");
	} else {
		Segm *s1=NULL;
		Segm *s2=NULL;
		
		while(s1==NULL){
			s1 = selezionaNodo(head);
		}
		while(s2==NULL){
			s2 = selezionaNodo(head);
		}
		if(paralleli(s1,s2)){
			printf("I segmenti selezionati sono paralleli!\n\n");
		} else {
			printf("I segmenti selezionati NON sono paralleli!\n\n");
		}
	}
}

/* * * * * * * * * */
/* * INSERIMENTO * */
/* * * * * * * * * */

Segm creaSegmento(){
	Segm nuovo;
	printf("Inserisci le coordinate del primo estreml del segmento.\n");
	printf("x: ");
	scanf("%f", &nuovo.a.x);
	printf("y: ");
	scanf("%f", &nuovo.a.y);
	do {
		printf("Inserisci le coordinate del secondo estremo del segmento.\n");
		printf("x: ");
		scanf("%f", &nuovo.b.x);
		printf("y: ");
		scanf("%f", &nuovo.a.y);
		if(nuovo.b.x==nuovo.a.x && nuovo.b.y==nuovo.a.y){
			printf("Almeno una coordinata deve essere diversa da quella del primo estremo!\n");
		}
	} while (nuovo.b.x==nuovo.a.x && nuovo.b.y==nuovo.a.y);
	return nuovo;
}

Nodo* inserisciSegmento(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->s=creaSegmento();
	nuovo->next=head;
	return nuovo;
}

/* * * * * * * * * * */
/* * CANCELLAZIONE * */
/* * * * * * * * * * */

Nodo* cancellaSegmento(Nodo* head){
	if(head==NULL){
		printf("Nulla da cancellare!\n\n");
	} else {
		Nodo* dealloca = head;
		head=head->next;
		free(dealloca);
	}
	return head;
}

/* * * * * * * * * * * * * * */
/* * * GESTIONE DEI FILE * * */
/* * * * * * * * * * * * * * */

Nodo* leggiFile(){
	FILE* fp = fopen("segmenti.dat","rb");
	Nodo* head = malloc(sizeof(Nodo));
	if(fp==NULL){
		printf("Erroe di lettura!\n\n");
		head=NULL;
	} else {
		Segm segmento;
		int letto = fread(&segmento, sizeof(Segm), 1, fp);
		
		if(letto){
			head->s=segmento;
			Nodo* nodo=head;
			
			while(fread(&segmento, sizeof(Segm), 1, fp)>0){
				nodo->next=malloc(sizeof(Nodo));
				nodo=nodo->next;
				nodo->s=segmento;
			}
			nodo->next=NULL;
			
			fclose(fp);
			printf("Lettura completata!\n\n");
		} else {
			printf("Niente da leggere!\n\n");
		}
	}
	return head;
}

void salvaFile(Nodo* head){
	if(head==NULL){
		printf("Nulla da salvare!\n\n");
	} else {
		FILE* fp = fopen("segmenti.dat","wb");
		if(fp==NULL){
			printf("Errore di scrittura!\n\n");
		} else {
			while(head!=NULL){
				fwrite(&head->s, sizeof(Segm), 1, fp);
				head=head->next;
			}
			fclose(fp);
			printf("Scrittura completata!\n\n");
		}
	}
}

/* * * * * * * * */
/* * * MAIN * * */
/* * * * * * * */
   
int main(int argc, char **argv)
{
	Nodo* lista = leggiFile();
	
	int risposta = -1;

	while(risposta != 0) {
		
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserimento\n");
		printf("2 -> Cancellazione\n");
		printf("3 -> Visualizzazaione\n");
		printf("4 -> Verifica se due segmenti sono paralleli\n");
		printf("5 -> Verifica se i primi due segmenti sono perpendicolari\n");
		printf("0 -> Termina il programma\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d%*c", &risposta);
		printf("\n");
		
		if(risposta == 1)
		{
			lista = inserisciSegmento(lista);
		}
		else if(risposta == 2)
		{
			lista = cancellaSegmento(lista);
		}
		else if(risposta == 3)
		{
			stampaLista(lista);
		}
		else if(risposta == 4)
		{
			verificaParalleli(lista);
		}
		else if(risposta == 5)
		{
			primiPerpendicolari(lista);
		}
		else if(risposta != 0)
		{
			printf("Selezione non valida!\n");
		}
	}
	
	salvaFile(lista);
	
	return 0;
}
