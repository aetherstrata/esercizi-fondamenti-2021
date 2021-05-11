#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struttura del tipo Punto
typedef struct Punto {
	float x;
	float y;
} Point;

// Struttura del tipo Parallelogramma
typedef struct VettoreParallelogramma {
	Point bs;
	Point ad;
	float b;
} VectorSet;

typedef struct Nodo {
	VectorSet v;
	struct Nodo* next;
} Node;

/* * * * * * * * * * * * * * * * * */
/* *Funzioni geometriche * * * * * */
/* * * * * * * * * * * * * * * * * */

float Altezza(VectorSet* para) 
{
	float h = para->ad.y - para->bs.y;
	return h;
}

float LatoObliquo(VectorSet* para)
{
	float lato = sqrt( pow((para->ad.x-para->bs.x-para->b),2) + pow(Altezza(para),2) );
	return lato;
}

float Perimetro(VectorSet* para)
{
	int perimetro = LatoObliquo(para)*2 + para->b*2;
	return perimetro;
}

float Area(VectorSet* para)
{
	float area = para->b * Altezza(para);
	return area;
}

int isRettangolo (VectorSet* para)
{
	int result = 0;
	
	if ((para->ad.x-para->b) == para->bs.x)
		result = 1;
	
	return result;
}

/* * * * * * * * * * * * * * * */
/* * * FUNZIONI DI STAMPA * * */
/* * * * * * * * * * * * * * */

void stampaPunto(Point p)
{
	printf("(%.2f , %.2f)\n", p.x, p.y);
}

void stampaVettoreParallelogramma(VectorSet* para)
{
	printf("Il vertice bs ha coordinate: ");
	stampaPunto(para->bs);
	printf("Il vertice ad ha coordinate: ");
	stampaPunto(para->ad);
	printf("La lunghezza della base vale %.2f\n", para->b);
	printf("Il perimetro del parallelogramma vale %.2f\n", Perimetro(para));
	printf("L'area del parallelogramma vale %.2f\n", Area(para));
	if (isRettangolo(para))
		printf("Questo parallelogramma %c rettangolo!\n\n", 138);
	else 
		printf("Questo parallelogramma NON %c rettangolo!\n\n", 138);
}

void stampaLista(Node* head){
	if(head==NULL){
		printf("Nessun parallelogramma nell'array!\n");
	} else {
		printf("Ecco la lista di parallelogrammi: \n\n");
		for(int i=1; head!=NULL; i++){
			printf("Parallelogramma #%d: \n", i);
			stampaVettoreParallelogramma(&head->v);
			head=head->next;
		}
		printf("/---------------------/\n\n");
	}
}

/* * * * * * * * * * * * * * */
/* * * GESTIONE DEI FILE * * */
/* * * * * * * * * * * * * * */

Node* LeggiFile()
{
	FILE* fp = fopen("datiVettori.dat", "rb");
	Node* head;
	
	if(fp==NULL){
		printf("Lettura fallita!\n");\
		head=NULL;
	} else {
		VectorSet para;
		int letto = fread(&para, sizeof(VectorSet), 1, fp);
		
		if(letto){
			head = malloc(sizeof(Node));
			head->v=para;
			
			Node* nodo=head;
			while(fread(&para, sizeof(VectorSet), 1, fp)>0){
				nodo->next = malloc(sizeof(Node));
				nodo=nodo->next;
				nodo->v=para;
			}
			nodo->next=NULL;
			fclose(fp);
		} else {
			printf("Nulla da leggere!\n\n");
		}
	}
	return head;
}

void SalvaSuFile(Node* head)
{
	FILE* fp = fopen("datiVettori.dat", "wb");
	if(fp==NULL){
		printf("Scrittura fallita!\n");
	} else {
		if(head==NULL){
			printf("Nulla da salvare!\n\n");
		} else {
			while(head!=NULL){
				fwrite(&head->v, sizeof(VectorSet), 1, fp);
				head=head->next;
			}
			fclose(fp);
			printf("Salvataggio completato!\n\n");
			printf("/---------------------/\n\n");
		}
	}
}

/* * * * * * * * * */
/* * INSERIMENTO * */
/* * * * * * * * * */

VectorSet creaVettore()
{
	VectorSet para;
	/* Vertice BS */
	printf("Quali sono le coordinate del vertice BS?\n");
	printf("X: ");
	scanf("%f", &para.bs.x);
	printf("Y: ");
	scanf("%f", &para.bs.y);
	
	/* Vertice AD */
	printf("Quali sono le coordinate del vertice AD?\n");
	do {
		printf("X: ");
		scanf("%f", &para.ad.x); 
		if (para.ad.x<=para.bs.x)
			printf("Questo valore deve essere maggiore di %.2f!\n", para.bs.x);
	} while (para.ad.x<=para.bs.x);
	do {
		printf("Y: ");
		scanf("%f", &para.ad.y); 
		if (para.ad.y<=para.bs.y)
			printf("Questo valore deve essere maggiore di %.2f!\n", para.bs.y);
	} while (para.ad.y<=para.bs.y);

	/* Lunghezza base */
	do {
		printf("Qual %c la lunghezza della base? ", 138);
		scanf("%f", &para.b); 
		if (para.b<=0 || para.b>=(para.ad.x-para.bs.x))
			printf("Questo valore deve essere minore di %.2f e maggiore di 0\n", para.ad.x-para.bs.x);
	} while (para.b<=0 || para.b>=(para.ad.x-para.bs.x));
	
	return para;
}

Node* inserisciParallelogramma(Node* head)
{
	Node* nuovo = malloc(sizeof(Node));
	nuovo->v=creaVettore();
	nuovo->next=head;
	return nuovo;
}

/* * * * * * * * * * */
/* * CANCELLAZIONE * */
/* * * * * * * * * * */

Node* cancellaParallelogramma(Node* head)
{
	if(head==NULL){
		printf("Nulla da cancellare!\n\n");
	} else {
		if(head->next==NULL){
			free(head);
			head=NULL;
		} else {
			Node* nodo;
			while(nodo->next!=NULL)
				nodo=nodo->next;
			free(nodo->next);
			nodo->next=NULL;
		}
		printf("Cancellazione effettuata!\n\n");
	}
	return head;
}

/* * * * * * * * * * */
/* * FUNZIONE MAIN * */
/* * * * * * * * * * */

int main(int argc, char **argv)
{
	Node* lista = LeggiFile();
	
	int risposta = 0;
	do {
		printf("Quale operazione vuoi fare?\n\n");
		printf("1 -> Inserisci un nuovo vettore parallelogramma.\n");
		printf("2 -> Cancella l'ultimo parallelogramma della lista.\n");
		printf("3 -> Visualizza l'elenco dei parallelogrammi.\n");
		printf("0 -> Termina esecuzione.\n\n");
		printf("Risposta: ");
		scanf("%d", &risposta);
		printf("\n");
		
		if(risposta==1){
			lista = inserisciParallelogramma(lista);
		} else if (risposta==2){
			lista = cancellaParallelogramma(lista);
		} else if (risposta==3){
			stampaLista(lista);
		} else if (risposta!=0){
			printf("Selezione non valida!\n");
		}
	}
	while (risposta != 0);
	
	SalvaSuFile(lista);
	
	return 0;
}
