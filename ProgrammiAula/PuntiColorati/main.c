#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _POINT {
	float x;
	float y;
	char colour[20];
} Point;

typedef struct _NODE {
	Point p;
	struct _NODE* next;
} Node;

float distance(Point p1, Point p2){
	return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

void printPoint(Point p)
{
	printf("x: %.2f\n", p.x);
	printf("y: %.2f\n", p.y);
	printf("colour: %s\n", p.colour);
}

void printList(Node* head)
{
	if(head==NULL){
		printf("Nothing to list!\n\n");
	} else {
		printf("This is the list of all stored points:\n\n");
		while(head!=NULL){
			printPoint(head->p);
			head=head->next;
		}
		printf("End of the list!\n\n");
	}
}

void printLeastDistant(Node* head)
{
	if(head==NULL){
		printf("Nothing to list!\n\n");
	} else {
		Node* node=head->next;
		Node* prevNode=head;
		
		float min = distance(prevNode->p,node->p);
		Point p1, p2;
		while(prevNode!=NULL){
			while(node->next!=NULL){
				if (distance(prevNode->p,node->p)<min) {
					min = distance(prevNode->p,node->p);
					p1 = prevNode->p;
					p2 = node->p;
				}
				node=node->next;
			}
			prevNode=prevNode->next;
		}
		printf("The least distant points are:\n");
		printPoint(p1);
		printPoint(p2);
	}
}

void printByColour(Node* head)
{
	if(head==NULL){
		printf("Nothing to list!\n\n");
	} else {
		char choice[20];
		printf("What colour are the points you want to print?\n");
		printf("colour: ");
		fgets(choice, 20, stdin);
		while(head!=NULL){
			if(head->p.colour == choice){
				printPoint(head->p);
			}
		}
	}
}

Node* insert(Node* head)
{
	Node* newNode = malloc(sizeof(Node));
	printf("Quali sono le coordinate del nuovo punto?\n");
	printf("x: ");
	scanf("%f", &newNode->p.x);
	printf("y: ");
	scanf("%f%*c", &newNode->p.y);
	
	printf("Qual %c il colore del nuovo punto?\n", 138);
	fgets(newNode->p.colour, 20, stdin);
	printf("\n");
	
	newNode->next=head;
	head=newNode;
	
	return head;
}

Node* deleteOnX(Node* head)
{
	Node* node;
	if(head==NULL){
		printf("Nothing to list!\n\n");
	} else {
		if(head->p.y==0){
			node=head;
			head=head->next;
			free(node);
		}
		
		node=head->next;
		Node* prevNode=head;
		
		while(node!=NULL){
			if(node->p.y==0){
				prevNode->next=node->next;
				free(node);
			} else {
				prevNode=node;
				node=node->next;
			}
			node=node->next;
		}
		printf("All points with y=0 have been deleted!\n\n");
	}
	
	return head;
}

int main(int argc, char **argv)
{
	Node* list = NULL;
	
	printf("Questo programma permette di fare alcune operazioni su una serie di punti introdotti dall'utente.\n\n");
	
	int choice=-1;
	while (choice!=0){
		printf("1- List all stored points.\n");
		printf("2- Insert a new point into the list.\n");
		printf("3- Delete all points with y=0.\n");
		printf("4- Print the two points which are the least distant.\n");
		printf("5- Print all the points which have the specified colour.\n\n");
		printf("Your choice: ");
		scanf("%d%*c", &choice);
		
		switch (choice)
		{
			case 1:
				printList(list);
			break;
			
			case 2:
				list = insert(list);
			break;
			
			case 3:
				list = deleteOnX(list);
			break;
			
			case 4:
				printLeastDistant(list);
			break;
			
			case 5:
				printByColour(list);
			break;
			
			default:
			printf("Invalid choice!\n\n");
		}
	}
	
	return 0;
}
