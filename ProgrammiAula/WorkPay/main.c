#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Declare structures */
typedef struct _PERSON {
	char name[50];
	float rate;
	float hours;
	float weeklyPay;
} Person;

typedef struct _NODE {
	Person p;
	struct _NODE* next;
} Node;

/* Calculate pay (considering 40h = max worktime) */
void calculatePay(Person* p)
{
	float pay;
	if(p->hours<40){
		pay = p->rate*p->hours;
	} else {
		pay = p->rate*40 + (p->hours - 40)*1.5*p->rate; // The rest of the hours get 150% pay
	}
	p->weeklyPay = pay;
}

void flushStream(){
	int c;
	while ( (c = getchar()) != EOF && c != '\n'); 
}

void populatePerson(Person* p)
{
	printf("What is the name? ");
	flushStream();
	fgets(p->name, 50, stdin);
	p->name[strcspn(p->name, "\n")] = '\0';
	
	printf("How many hours do they work weekly? ");
	scanf("%f", &p->hours);
	
	printf("What is their hourly rate? ");
	scanf("%f", &p->rate);
	
	printf("\n");
	
	calculatePay(p);
}

void insertPerson(Node** headPointer)
{
	Node* newPerson = malloc(sizeof(Node));
	populatePerson(&newPerson->p);
	
	if(*headPointer == NULL){
		*headPointer = newPerson;
	} else {
		Node* previousNode = *headPointer;
		while(previousNode->next!=NULL)
			previousNode=previousNode->next;
		previousNode->next=newPerson;
	}
	newPerson->next=NULL;
	
	printf("%s has been added to the list!\n", newPerson->p.name);
	printf("Their weekly pay is %.2f.\n\n", newPerson->p.weeklyPay);
}

void printPerson(Person* p, int idx)
{
	printf(" - #%d Person\n", idx);
	printf("Name: %s\n", p->name);
	printf("Rate: %.2f\n", p->rate);
	printf("Weekly hours: %.2f\n", p->hours);
	printf("Weekly pay: %.2f\n\n", p->weeklyPay);
}

void printList(Node* head)
{
	if(head==NULL){
		printf("The list is empty!\n\n");
	} else {
		int i=0;
		while(head!=NULL){
			i++;
			printPerson(&head->p, i);
			head=head->next;
		}
		printf("End of the list!\n\n");
	}
}

float inputPayLimit()
{
	float limit;
	printf("Persons which get paid more than this number will be removed from the list: ");
	scanf("%f", &limit);
	return limit;
}

//TODO: fix me
void deleteFromList(Node** headPointer)
{
	float limit = inputPayLimit();
	
	Node* prevNode;
	Node* node;
	int num=0;
	
	if(*headPointer!=NULL){
		if ((*headPointer)->p.weeklyPay>=limit) {
			node = *headPointer;
			*headPointer = (*headPointer)->next;
			printf("%s has been deleted!\n", node->p.name);
			free(node);
			num++;
		}
		node = (*headPointer)->next;
		prevNode = *headPointer;
			
		while(node!=NULL){
			if(node->p.weeklyPay>=limit){
				prevNode->next=node->next;
				printf("%s has been deleted!\n", node->p.name);
				free(node);
				num++;
			} else {
				prevNode = node;
				node = node->next;
			}
		}
		if(num==0)
			printf("Nothing has been deleted!\n\n");
		else
			printf("%d persons have been deleted from the list!\n\n", num);
	}
}


Node* initializeListFromFile()
{
	Node* head = NULL; //initialize list
	FILE* fp = fopen("list.dat", "rb");
	if(fp==NULL){
		printf("Cannot read from file!\n\n");
	} else {
		int num = 0;
		Person person;
		num = fread(&person, sizeof(Person), 1, fp);
		
		if(num == 0){
			printf("The file is empty!\n");
		} else {
			head = malloc(sizeof(Node));
			head->p = person;
			
			Node* node=head;
			while(fread(&person, sizeof(Person), 1, fp)>0){
				node->next = malloc(sizeof(Node));
				node=node->next;
				node->p=person;
			}
			node->next=NULL;
			printf("The file was read successfully!\n");
		}
	}
	return head;
}

void saveToFile(Node* list)
{
	FILE* fp = fopen("list.dat", "wb");
	if(fp==NULL){
		printf("failed to save to file!\n");
	} else {
		while(list!=NULL){
			fwrite(&list->p, sizeof(Person), 1, fp);
			list = list->next;
		}
		fclose(fp);
		printf("Save complete!\n");
	}
}

int main(int argc, char **argv)
{
	Node* list = initializeListFromFile(); //Initialize list from file
	
	printf("!! This program calcutates the right pay for each person you input. !!\n\n");
	
	int choice = -1;
	while(choice!=0){
		printf("1 -> Input a person to check its corresponding weekly pay.\n");
		printf("2 -> Visualize all persons in the list.\n");
		printf("3 -> Remove persons by weekly pay.\n");
		printf("0 -> Exit program.\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch (choice){
			case 1:
				insertPerson(&list);
			break;
			
			case 2:
				printList(list);
			break;
			
			case 3:
				deleteFromList(&list);
			break;
			
			case 0:
				saveToFile(list);
			break;
			
			default:
				printf("Invalid selection!\n\n");
		}
	}
	return 0;
}