#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _VERTICE
{
	float x;
	float y;
} Vertice;

typedef struct _ROMBO
{
	Vertice a;
	Vertice b;
	float d;
} Rombo;

typedef struct _NODO
{
	Rombo r;
	struct _NODO* next;
} Nodo;

/* * * * * * * * * * * * * * * * * */
/* *Funzioni geometriche * * * * * */
/* * * * * * * * * * * * * * * * * */

float DiagonaleVerticale(Rombo* r)
{
	return r->a.y - r->b.y;
}

float LatoObliquo(Rombo* r)
{
	float c1 = DiagonaleVerticale(r) / 2;
	float c2 = r->d / 2;
	return sqrt(pow(c1, 2) + pow(c2, 2));
}

float Perimetro(Rombo* r)
{
	return LatoObliquo(r) * 4;
}

float Area(Rombo* r)
{
	return r->d * DiagonaleVerticale(r) / 2;
}

int isQuadrato(Rombo* r)
{
	return r->d == DiagonaleVerticale(r);
}

/* * * * * * * * * */
/* * * STAMPA * * */
/* * * * * * * * */

void stampaPunto(Vertice* p)
{
	printf("(%.2f, %.2f)\n", p->x, p->y);
}

void stampaRombo(Rombo* r)
{
	printf("Vertice A: ");
	stampaPunto(&r->a);
	printf("Vertice B: ");
	stampaPunto(&r->b);
	printf("Diagonale: %.2f\n", r->d);
	printf("Perimetro: %.2f\n", Perimetro(r));
	printf("Area: %.2f\n", Area(r));
	printf("Quadrato: ");
	if(isQuadrato(r))
		printf("SI\n\n");
	else
		printf("NO\n\n");
}

void stampaLista(Nodo* head)
{
	if(head == NULL)
	{
		printf("Nulla da visualizzare!\n\n");
	}
	else
	{
		printf("/*****************/\n\n");
		while(head!=NULL){
			stampaRombo(&head->r);
			head = head->next;
		}
		printf("/*****************/\n\n");
	}
}

Rombo creaRombo()
{
	Rombo nuovoRombo;

	printf("Quali sono le coordinate del vertice A?\n");
	printf("X: ");
	scanf("%f", &nuovoRombo.a.x);
	printf("Y: ");
	scanf("%f", &nuovoRombo.a.y);

	printf("Quali sono le coordinate del vertice B?\n");
	nuovoRombo.b.x = nuovoRombo.a.x;
	do
	{
		printf("Y: ");
		scanf("%f", &nuovoRombo.b.y);
		if(nuovoRombo.b.y >= nuovoRombo.a.y) printf("Questo valore deve essere minore di %.2f!\n", nuovoRombo.a.y);
	}
	while(nuovoRombo.b.y >= nuovoRombo.a.y);

	/* Lunghezza diagonale */
	do
	{
		printf("Qual %c la lunghezza della diagonale? ", 138);
		scanf("%f", &nuovoRombo.d);
		if(nuovoRombo.d <= 0) printf("Questo valore deve essere maggiore di 0\n");
	}
	while(nuovoRombo.d <= 0);

	return nuovoRombo;
}

Nodo* inserisciRombo(Nodo* head)
{
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->r = creaRombo();
	nuovo->next = head;
	return nuovo;
}

Nodo* cancellaRombo(Nodo* head)
{
	if(head == NULL)
	{
		printf("Niente da cancellare!\n\n");
	}
	else
	{
		if(head->next == NULL)
		{
			Nodo* dealloca = head;
			free(dealloca);
			head=NULL;
		}
		else
		{
			Nodo* nodo = head;
			while(nodo->next != NULL)
			{
				nodo = nodo->next;
			}
			free(nodo->next);
			nodo->next = NULL;
		}
		printf("Cancellazione effettuata!\n\n");
	}
	return head;
}

/* * * * * * * * * * * * */
/* * GESTIONE DEI FILE * */
/* * * * * * * * * * * * */

Nodo* leggiFile()
{
	FILE* fp = fopen("rombi.dat", "rb");
	Nodo* head;

	if(fp == NULL)
	{
		printf("Errore di lettura!\n\n");
		head = NULL;
	}
	else
	{
		Rombo rombo;
		int letto = fread(&rombo, sizeof(Rombo), 1, fp);

		if(letto)
		{
			head = malloc(sizeof(Nodo));
			head->r = rombo;

			Nodo* nodo = head;
			while(fread(&rombo, sizeof(Rombo), 1, fp) > 0)
			{
				nodo->next = malloc(sizeof(Nodo));
				nodo = nodo->next;
				nodo->r = rombo;
			}
			nodo->next = NULL;
		}
		else
		{
			printf("File vuoto!\n\n");
		}
		fclose(fp);
		printf("Lettura completata!\n\n");
	}

	return head;
}

void salvaSuFile(Nodo* head)
{
	if(head == NULL)
	{
		printf("Nulla da salvare!\n\n");
	}
	else
	{
		FILE* fp = fopen("rombi.dat", "wb");

		if(fp == NULL)
		{
			printf("Salvataggio fallito!\n\n");
		}
		else
		{
			while(head != NULL)
			{
				fwrite(&head->r, sizeof(Rombo), 1, fp);
				head = head->next;
			}
			fclose(fp);
			printf("Salvataggio effettuato\n\n");
		}
	}
}

int main(int argc, char** argv)
{
	printf("Questo programma gestisce una lista di rombi.\n\n");

	Nodo* lista = leggiFile();

	int risposta = -1;
	while(risposta != 0)
	{
		printf("Quale operazione vuoi fare?\n\n");
		printf("1 -> Inserisci un nuovo rombo.\n");
		printf("2 -> Cancella l'ultimo rombo della lista.\n");
		printf("3 -> Visualizza l'elenco dei rombi.\n");
		printf("0 -> Termina esecuzione.\n\n");
		printf("Risposta: ");
		scanf("%d", &risposta);
		printf("\n");

		if(risposta == 1)
		{
			lista = inserisciRombo(lista);
		}
		else if(risposta == 2)
		{
			lista = cancellaRombo(lista);
		}
		else if(risposta == 3)
		{
			stampaLista(lista);
		}
		else if(risposta != 0)
		{
			printf("Selezione non valida!\n");
		}
	}

	printf("Inizio salvataggio...\n");
	salvaSuFile(lista);

	return 0;
}
