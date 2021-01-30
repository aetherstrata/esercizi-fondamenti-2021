#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", un ciclo
 * interno permette di contare quanti caratteri interessanti consecutivi ci sono; parallelamente
 * viene incrementato il contatore principale, per superare la sequenza di caratteri interessanti 
 * Se questa era lunga due, viene quindi cancellata */
 
/*funzione che modifica la stringa eliminando ogni sequenza di esattamente due caratteri uguali consecutivi*/
void cancellaDueNumeriUguali(char *stringa) {
	int i = 0;  //contatore
	int conteggio;  //per contare i numeri uguali
	int j;
	while(stringa[i]!='\0') {
		if(!(stringa[i]>='0' && stringa[i]<='9')) {
			i++;
		}
		else {
			conteggio=1;
			/*fintanto che il numero attuale è uguale al succesivo*/
			while(stringa[i]==stringa[i+1]) {
				conteggio++;  //incrementa conteggio
				i++;
			}
			/*se conteggio = 2 cancella*/
			if(conteggio == 2) {
				j=i;
				while(stringa[j]!='\0') {
					stringa[j]=stringa[j+1];
					j++;
				}
				j=i-1;
				while(stringa[j]!='\0') {
					stringa[j]=stringa[j+1];
					j++;
				}
			}
			/*altrimenti vai avanti */
			else {
				i++;
			}
		}
	}
}

void testCancellaDueNumeriUguali(char *stringa) {
	/*stringa vuota*/
	char stringa1[]="";
	cancellaDueNumeriUguali(stringa1);
	printf("\n\nTest CancellaDueNumeriUguali(\"\"): Atteso = \"\", Calcolato = \"%s\" \n",stringa1);
	/*stringa due numeri uguali all'inizio*/
	char stringa2[]="22a";
	cancellaDueNumeriUguali(stringa2);
	printf("Test CancellaDueNumeriUguali(\"22a\"): Atteso = \"a\", Calcolato = \"%s\" \n",stringa2);
	/*stringa due numeri uguali alla fine*/
	char stringa3[]="a22";
	cancellaDueNumeriUguali(stringa3);
	printf("Test CancellaDueNumeriUguali(\"a22\"): Atteso = \"a\", Calcolato = \"%s\" \n",stringa3);
	/*stringa due numeri uguali al centro*/
	char stringa4[]="a22a";
	cancellaDueNumeriUguali(stringa4);
	printf("Test CancellaDueNumeriUguali(\"a22a\"): Atteso = \"aa\", Calcolato = \"%s\" \n",stringa4);
	/*stringa tre numeri uguali*/
	char stringa5[]="222";
	cancellaDueNumeriUguali(stringa5);
	printf("Test CancellaDueNumeriUguali(\"222\"): Atteso = \"222\", Calcolato = \"%s\" \n",stringa5);
	/*stringa 3 numeri uguali e due numeri uguali*/
	char stringa6[]="22233";
	cancellaDueNumeriUguali(stringa6);
	printf("Test CancellaDueNumeriUguali(\"22233\"): Atteso = \"222\", Calcolato = \"%s\" \n",stringa6);
	/*stringa solo caratteri diversi da numeri */
	char stringa7[]="abc!";
	cancellaDueNumeriUguali(stringa7);
	printf("Test CancellaDueNumeriUguali(\"abc!\"): Atteso = \"abc!\", Calcolato = \"%s\" \n",stringa7);
	/*stringa casuale */
	char stringa8[]="22cde555ee12a13367bb5";
	cancellaDueNumeriUguali(stringa8);
	printf("Test CancellaDueNumeriUguali(\"22cde555ee12a13367bb5\"): Atteso = \"cde555ee12a167bb5\", Calcolato = \"%s\" \n",stringa8);

}

/*funzione main*/
int main() {
	/*input*/
	char stringa[50];
	printf("Caro utente sono un programma che modifica la stringa rimuovendo ogni sequenza di esattamente due caratteri numerici uguali consecutivi.\n\n");
	printf("Inserisca tale stringa:  ");
	fgets(stringa,50,stdin);
	/*elimina carattere new line*/
	stringa[strlen(stringa)-1]='\0';
	cancellaDueNumeriUguali(stringa);
	/*output*/
	printf("\n\nLa stringa modificata %c:  %s",138,stringa);

	testCancellaDueNumeriUguali(stringa);
}
