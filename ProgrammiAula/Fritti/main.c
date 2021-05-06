#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _FRITTO {
	char nome[30];
	float prezzo;
	char tipo;
} Fritto;

typedef struct _NODO {
	Fritto f;
	struct _NODO* next;
} Nodo;

// Stampa un fritto
void stampaFritto(Fritto* f){
	printf("Fritto: %s\n", f->nome);
	printf("Prezzo: %.2f", f->prezzo);
	if(f->tipo == 's'){
		printf("Surgelato: Si\n\n");
	} else {
		printf("Surgelato: No\n\n");
	}
}

void stampaMenu(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n");
	} else {
		printf("Ecco la lista dei fritti nel menu: \n");
		while(head!=NULL){
			stampaFritto(&head->f);
			head=head->next;
		}
		printf("Fine del menu!\n");
	}
}

void leggiDati(Fritto* f)
{
	printf("Come si chiama il fritto?");
	fgets(f->nome, 30, stdin);
	f->nome[strlen(f->nome)-1]='\0';
	printf("Quanto costa?");
	scanf("%f", &f->prezzo);
	printf("Surgelato?");
	scanf("%c", &f->tipo);
}

void inserimentoInCoda(Nodo** headPointer)
{
	Nodo* nuovo = malloc(sizeof(Nodo));
	leggiDati(&nuovo->f);
	nuovo->next=NULL;
	
	if(*headPointer==NULL){
		*headPointer = nuovo;
	} else {
		Nodo* corrente = *headPointer;
		while(corrente->next!=NULL){
			corrente=corrente->next;
		}
		corrente->next = nuovo;
	}
}

int precede(Fritto* f1`, Fritto* f2){
	return (f1->tipo == 'f' && f1->tipo == 's') ||
			(f1->tipo==f2->tipo && f1->prezzo<f2->prezzo)
}

void ordina(Nodo* head){
	Nodo* inizio = head;
	Nodo* minimo;
	Nodo* nodo;
	
	if(head==NULL){
		printf("La lista è vuota!\n")
	} else{
		for(inizio=head; inizio->next!=NULL; inizio=inizio->next){
			minimo=inizio;
			for(nodo=inizio->next; nodo!=NULL ; nodo=nodo->next){
				if(precede(&nodo->f, &minimo->f)){
					minimo=nodo;
				}
			}
			temp = minimo->f;
			minimo->f=inizio
		}
	}
}

int main(int argc, char **argv)
{
	Nodo* head = NULL;
	
	printf("Che operazione vuoi fare?\n");
	
	int risposta=-1;
	while(risposta!=0){
		printf("1 -> ");
		printf("2 -> ");
		printf("3 -> ");
		printf("0 -> ");
		scanf("%d%*c");
	}
	
	return 0;
}
