#include <stdio.h>
#include <string.h>

/* verifica se un carattere è minuscolo */
int minuscolo(char c) {
	int res = 0;
	if(c >= 'a' && c <= 'z')
		res = 1;
	return res;
}

/* la funzione riceve come parametro una stringa e la modifica così che ogni sequenza di almeno 
 * due caratteri alfabetici minuscoli venga trasformata in una sequenza di esattamente due 
 * caratteri alfabetici minuscoli*/
void dueMinuscolePerVolta(char* stringa)
{
	/* se ci sono massimo due caratteri non devi fare niente */
	if(strlen(stringa)>2) {
	/*scorri tutta la stringa, il primo carattere che potresti cancellare è il terzo */
	int i=2;
	while(stringa[i]!='\0') 
		/* cancella se il carattere corrente e due precedenti sono minuscoli */
		if(minuscolo(stringa[i-2]) && minuscolo(stringa[i-1]) && minuscolo(stringa[i]))
			for(int j=i; stringa[j]!='\0'; j++)
				stringa[j]=stringa[j+1];
		/* altrimenti vai avanti */
		else
			i++;
	}
}

/* funzione di test per dueMinuscolePerVolta */
void testDueMinuscolePerVolta()
{
	/*stringa vuota*/
	char stringa1[]="";
	dueMinuscolePerVolta(stringa1);
	printf("Test dueMinuscolePerVolta(\"\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa1);

	/*tre caratteri minuscoli all'inizio*/
	char stringa2[]="abc11111";
	dueMinuscolePerVolta(stringa2);
	printf("Test dueMinuscolePerVolta(\"abc11111\"): Atteso=\"ab11111\", Calcolato=\"%s\" \n", stringa2);

	/*tre caratteri minuscoli alla fine*/
	char stringa3[]="11111abc";
	dueMinuscolePerVolta(stringa3);
	printf("Test dueMinuscolePerVolta(\"11111abc\"): Atteso=\"11111ab\", Calcolato=\"%s\" \n", stringa3);

	/*tre caratteri minuscoli al centro*/
	char stringa4[]="11abc11";
	dueMinuscolePerVolta(stringa4);
	printf("Test dueMinuscolePerVolta(\"11abc11\"): Atteso=\"11ab11\", Calcolato=\"%s\" \n", stringa4);

	/*solo minuscole*/
	char stringa5[]="abcdef";
	dueMinuscolePerVolta(stringa5);
	printf("Test dueMinuscolePerVolta(\"abcdef\"): Atteso=\"ab\", Calcolato=\"%s\" \n", stringa5);

	/*nessuna minuscola*/
	char stringa6[]="111111";
	dueMinuscolePerVolta(stringa6);
	printf("Test dueMinuscolePerVolta(\"111111\"): Atteso=\"111111\", Calcolato=\"%s\" \n", stringa6);

	/*stringa normale, con diverse occorrenze di almeno tre minuscole consecutive*/
	char stringa7[]="1abc11abcdef11abcde1";
	dueMinuscolePerVolta(stringa7);
	printf("Test dueMinuscolePerVolta(\"1abc11abcdef11abcde1\"): Atteso=\"1ab11ab11ab1\", Calcolato=\"%s\" \n", stringa7);
}

/*funzione principale*/
int main(int argc, char **argv)
{
	/*INPUT*/
	char stringa[50];
	printf("Benvenuto, questo programma modifica una stringa in modo che ogni sequenza di almeno ");
	printf("due caratteri alfabetici minuscoli venga trasformata in una sequenza di esattamente due ");
	printf("caratteri alfabetici minuscoli.\n");

	printf("Inserisci la stringa: ");
	fgets(stringa,50,stdin);
	/* rimuovo il carattere \n */
	stringa[strlen(stringa)-1]='\0';

	/* modifica la stringa e stampa il risultato */
	dueMinuscolePerVolta(stringa);
	printf("\nEcco la tua stringa modificata: \"%s\"\n\n", stringa);

	/* testa la funzione */
	testDueMinuscolePerVolta();
}

