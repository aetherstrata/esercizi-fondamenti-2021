#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica 
 * eliminando le ripetizioni di caratteri alfabetici maiuscoli */
void nienteDoppieMaiuscole(char *stringa) {
	int i, j;					// contatori
	
	i=0;
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* il carattere corrente è alfabetico maiuscolo ed uguale al successivo? */
		if((stringa[i]>='A' && stringa[i]<='Z') && (stringa[i]==stringa[i+1])) {
			/* copia tutti i caratteri da i+1 una posizione indietro */ 
			j=i;
			while(stringa[j] != '\0') {
				stringa[j] = stringa[j+1];
				j++;
			} 
		}
		else 
			i++;		// passa al prossimo carattere
	}
}

/* funzione di test per nienteDoppieMaiuscole */
void testNienteDoppieMaiuscole() {
	/* stringa senza doppieMaiuscole */
	char stringa1[] = "AbBCc";
	nienteDoppieMaiuscole(stringa1);
	printf("Test nienteDoppieMaiuscole(\"AbBCc\"): Atteso = \"AbBCc\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con tutti i caratteri uguali e maiuscoli */
	char stringa2[] = "AAAAA";
	nienteDoppieMaiuscole(stringa2);
	printf("Test nienteDoppieMaiuscole(\"AAAAA\"): Atteso = \"A\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con una sola doppia maiuscola in prima posizione */
	char stringa3[] = "AAbB";
	nienteDoppieMaiuscole(stringa3);
	printf("Test nienteDoppieMaiuscole(\"AAbB\"): Atteso = \"AbB\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con una sola doppia maiuscola in ultima posizione */
	char stringa4[] = "aABB";
	nienteDoppieMaiuscole(stringa4);
	printf("Test nienteDoppieMaiuscole(\"aABB\"): Atteso = \"aAB\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con una sola doppia maiuscola in posizione centrale */
	char stringa5[] = "aAAa";
	nienteDoppieMaiuscole(stringa5);
	printf("Test nienteDoppieMaiuscole(\"aAAa\"): Atteso = \"aAa\", Calcolato = \"%s\" \n", stringa5);	

	/* stringa vuota */
	char stringa6[] = "";
	nienteDoppieMaiuscole(stringa6);
	printf("Test nienteDoppieMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa6);	

	/* stringa con diverse doppie maiuscole */
	char stringa7[] = "aAAbBBBB5CCAA2AA";
	nienteDoppieMaiuscole(stringa7);
	printf("Test nienteDoppieMaiuscole(\"aAAbBBBB5CCAA2AA\"): Atteso = \"aAbB5CA2A\", Calcolato = \"%s\" \n", stringa7);	
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica "); 
	printf("eliminando le ripetizioni di caratteri alfabetici maiuscoli\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione nienteDoppieMaiuscole */
	nienteDoppieMaiuscole(stringa);
	
	/* output */
	printf("Ecco la stringa senza le ripetizioni richieste: %s", stringa);
	
	/* fai partire il test */
	testNienteDoppieMaiuscole();
}