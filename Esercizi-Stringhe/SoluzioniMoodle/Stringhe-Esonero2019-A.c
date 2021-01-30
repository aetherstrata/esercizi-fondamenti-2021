#include <stdio.h>
#include <string.h>

/* la funzione riceve come parametro una stringa e la modifica così che ogni sequenza di almeno 
 * due caratteri consecutivi uguali venga trasformata in una sequenza di esattamente 
 * due caratteri consecutivi uguali */
void alPiuDueConsecutivi(char* stringa)
{
	/* se ci sono massimo due caratteri non devi fare niente */
	if(strlen(stringa)>2) { 
		/*scorri tutta la stringa, il primo carattere che potresti cancellare è il terzo */
		int i=2;
		while(stringa[i]!='\0') 
			/* cancella se il carattere corrente è uguale ai due precedenti */
			if(stringa[i]==stringa[i-2] && stringa[i]==stringa[i-1])
				for(int j=i; stringa[j]!='\0'; j++)
					stringa[j]=stringa[j+1];
			/* altrimenti vai avanti */
			else
				i++;
	}
}

/* funzione di test per alPiuDueConsecutivi */
void testAlPiuDueConsecutivi()
{
	/*stringa vuota*/
	char stringa1[]="";
	alPiuDueConsecutivi(stringa1);
	printf("Test alPiuDueConsecutivi(\"\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa1);

	/*tre caratteri uguali all'inizio*/
	char stringa2[]="aaa12345";
	alPiuDueConsecutivi(stringa2);
	printf("Test alPiuDueConsecutivi(\"aaa12345\"): Atteso=\"aa12345\", Calcolato=\"%s\" \n", stringa2);

	/*tre caratteri uguali alla fine*/
	char stringa3[]="12345aaa";
	alPiuDueConsecutivi(stringa3);
	printf("Test alPiuDueConsecutivi(\"12345aaa\"): Atteso=\"12345aa\", Calcolato=\"%s\" \n", stringa3);

	/*tre caratteri uguali al centro*/
	char stringa4[]="12aaa34";
	alPiuDueConsecutivi(stringa4);
	printf("Test alPiuDueConsecutivi(\"12aaa34\"): Atteso=\"12aa34\", Calcolato=\"%s\" \n", stringa4);

	/*solo uguali */
	char stringa5[]="aaaaaa";
	alPiuDueConsecutivi(stringa5);
	printf("Test alPiuDueConsecutivi(\"aaaaaa\"): Atteso=\"aa\", Calcolato=\"%s\" \n", stringa5);

	/* tutti diversi */
	char stringa6[]="12345";
	alPiuDueConsecutivi(stringa6);
	printf("Test alPiuDueConsecutivi(\"12345\"): Atteso=\"12345\", Calcolato=\"%s\" \n", stringa6);

	/*stringa normale, con diverse occorrenze di almeno tre caratteri uguali consecutivi */
	char stringa7[]="1aaa12aaaaa12aaa1";
	alPiuDueConsecutivi(stringa7);
	printf("Test alPiuDueConsecutivi(\"1aaa12aaaaa12aaa1\"): Atteso=\"1aa12aa12aa1\", Calcolato=\"%s\" \n", stringa7);
}

/*funzione principale*/
int main(int argc, char **argv)
{
	/*INPUT*/
	char stringa[50];
	printf("Benvenuto, questo programma modifica una stringa in modo che ogni sequenza di almeno ");
	printf("due caratteri consecutivi uguali venga trasformata in una sequenza di esattamente due ");
	printf("caratteri consecutivi uguali.\n");

	printf("Inserisci la stringa: ");
	fgets(stringa,50,stdin);
	/* rimuovo il carattere \n */
	stringa[strlen(stringa)-1]='\0';

	/* modifica la stringa e stampa il risultato */
	alPiuDueConsecutivi(stringa);
	printf("\nEcco la tua stringa modificata: \"%s\"\n\n", stringa);

	/* testa la funzione */
	testAlPiuDueConsecutivi();
}

