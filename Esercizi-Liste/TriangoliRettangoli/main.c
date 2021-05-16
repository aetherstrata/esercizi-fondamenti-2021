#include <stdio.h>
#include <stdlib.h>

typedef struct PUNTO{
	float x;
	float y;
} Punto;

typedef struct TRIANGOLO{
	Punto as;
	Punto bd;
} Triangolo;

typedef struct NODO{
	Triangolo t;
	struct NODO* next;
} Nodo;

float area(Triangolo* t){
	float h = t->as.y-t->bd.y;
	float b = t->bd.x-t->as.x;
	return b*h/2;
}

void stampaTriangolo(Triangolo* t){
	printf("AS (%.2f, %.2f)\n",t->as.x,t->as.y);
	printf("BD (%.2f, %.2f)\n",t->bd.x,t->bd.y);
	printf("Area: %.2f\n\n", area(t));
}

void stampaLista(Nodo* head){
	if(head==NULL){
		printf("Nulla da stampare!\n\n");
	} else {
		printf("Ecco la lista di triangoli!\n\n");
		while(head!=NULL){
			stampaTriangolo(&head->t);
			head=head->next;
		}
		printf("Fine della lista!\n\n");
	}
}

void ordinaLista(Nodo* head){
	for(Nodo*i=head; i->next!=NULL; i=i->next){
		for(Nodo*y=i; y!=NULL; y=y->next){
			if(area(&i->t)>area(&y->t)){
				Triangolo temp = y->t;
				y->t=i->t;
				i->t=temp;
			}
		}
	}
	printf("Lista ordinata!\n\n");
}

Triangolo creaTriangolo(){
	Triangolo nuovo;
	printf("Inserisci le coordinate di AS\n");
	printf("x: ");
	scanf("%f", &nuovo.as.x);
	printf("y: ");
	scanf("%f", &nuovo.as.y);
	printf("Inserisci le coordinate di BD\n");
	do{
		printf("x: ");
		scanf("%f", &nuovo.bd.x);
		if(nuovo.bd.x<=nuovo.as.x){
			printf("Questo valore deve essere maggiore di %.2f\n", nuovo.as.x);
		}
	} while(nuovo.bd.x<=nuovo.as.x);
	do{
		printf("y: ");
		scanf("%f", &nuovo.bd.y);
		if(nuovo.bd.y>=nuovo.as.y){
			printf("Questo valore deve essere minore di %.2f\n", nuovo.as.y);
		}
	} while(nuovo.bd.y>=nuovo.as.y);
	return nuovo;
}

Nodo* inserisciTriangolo(Nodo* head){
	Nodo* nuovo = malloc(sizeof(Nodo));
	nuovo->t=creaTriangolo();
	nuovo->next=head;
	ordinaLista(nuovo);
	printf("Triangolo inserito!\n\n");
	return nuovo;
}

int main(int argc, char **argv)
{
	Nodo* lista = NULL;
	int scelta;
	printf("Questo programma gestisce una lista di triangoli rettangoli.\n\n");
	
	do {
		printf("Quale operazione vuoi fare?\n\n");
		printf("1- Inserisci un triangolo nella lista.\n");
		printf("2- Visualizza la lista.\n");
		printf("0- Termina programma.\n\n");
		printf("Inserisci la scelta: ");
		scanf("%d", &scelta);
		printf("\n");
		if(scelta==1){
			lista = inserisciTriangolo(lista);
		} else if(scelta==2){
			stampaLista(lista);
		} else if(scelta!=0){
			printf("Scelta non valida!\n\n");
		}
	} while(scelta!=0);
	
	return 0;
}
