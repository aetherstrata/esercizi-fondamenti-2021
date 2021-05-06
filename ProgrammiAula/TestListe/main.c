#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int numero;
	struct Nodo* next;
};

void visualizzaLista(struct Nodo* lista){
	if(lista==NULL){
		printf("La lista %c vuota.", 138);
	} else {
		printf("Ecco gli interi della lista: ");
		while (lista!=NULL){
			printf("%d ", lista->numero);
			lista = lista->next;
		}
	}
}

struct Nodo* inserisciInTesta(struct Nodo* head){
	struct Nodo* nuovo = malloc(sizeof(struct Nodo));
	printf("Che intero vuoi memorizzare? ");
	scanf("%d", &nuovo->numero);
	nuovo->next = head;
	return nuovo;
}

void inserisciInTesta2(struct Nodo** puntaHead){
	struct Nodo* nuovo = malloc(sizeof(struct Nodo));
	
	printf("Che intero vuoi memorizzare? ");
	scanf("%d", &nuovo->numero);
	
	nuovo->next = *puntaHead;
	*puntaHead = nuovo;
}

int main(int argc, char **argv)
{
	struct Nodo* head = NULL;
	int scelta=-1;
	while (scelta!=0){
		printf("Che cosa vuoi fare? \n");
		printf("1- Visualizza la lista. \n");
		printf("2- Inserisci un elemento in testa. \n");
		printf("3- Inserisci un elemento in testa (Metodo 2). \n");
		printf("0- Termina programma. \n");
		scanf("%d", &scelta);
		
		if (scelta=1){
			visualizzaLista(head);
		} else if (scelta=2){
			head = inserisciInTesta(head);
		} else if (scelta=3){
			inserisciInTesta2(&head);
		} else if (scelta!=0){
			printf("Selezione non valida!\n");
		}
	}
}
