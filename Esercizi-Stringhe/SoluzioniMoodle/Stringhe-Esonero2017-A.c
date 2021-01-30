#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica 
 * eliminando tutti i caratteri non alfabetici */
void soloAlfabetici(char *stringa) {
	int i, j;					// contatori
	
	i=0;
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* il carattere attuale non è alfabetico? */
		if(!((stringa[i]>='a' && stringa[i]<='z')||
		   (stringa[i]>='A' && stringa[i]<='Z'))) {
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

/* funzione di test per soloAlfabetici */
void testSoloAlfabetici() {
	/* stringa senza caratteri alfabetici */
	char stringa1[] = "0&/,.&34";
	soloAlfabetici(stringa1);
	printf("Test soloAlfabetici(\"0&/,.&34\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con soli caratteri alfabetici */
	char stringa2[] = "abcdeABCDE";
	soloAlfabetici(stringa2);
	printf("Test soloAlfabetici(\"abcdeABCDE\"): Atteso = \"abcdeABCDE\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con un solo carattere non alfabetico in prima posizione */
	char stringa3[] = "1abc";
	soloAlfabetici(stringa3);
	printf("Test soloAlfabetici(\"1abc\"): Atteso = \"abc\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con un solo carattere non alfabetico in ultima posizione */
	char stringa4[] = "abc1";
	soloAlfabetici(stringa4);
	printf("Test soloAlfabetici(\"abc1\"): Atteso = \"abc\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con un solo carattere alfabetico in prima posizione */
	char stringa5[] = "a123";
	soloAlfabetici(stringa5);
	printf("Test soloAlfabetici(\"a123\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa5);	

	/* stringa con un solo carattere alfabetico in ultima posizione */
	char stringa6[] = "123a";
	soloAlfabetici(stringa6);
	printf("Test soloAlfabetici(\"123a\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa6);	

	/* stringa vuota */
	char stringa7[] = "";
	soloAlfabetici(stringa7);
	printf("Test soloAlfabetici(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa7);	

	/* stringa con diversi caratteri alfabetici e diversi caratteri non alfabetici */
	char stringa8[] = "ab56hj?#fg3";
	soloAlfabetici(stringa8);
	printf("Test soloAlfabetici(\"ab56hj?#fg3\"): Atteso = \"abhjfg\", Calcolato = \"%s\" \n", stringa8);	
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica "); 
	printf("eliminando tutti i caratteri non alfabetici\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione soloAlfabetici */
	soloAlfabetici(stringa);
	
	/* output */
	printf("Ecco la stringa di soli caratteri alfabetici: %s\n", stringa);

	/* fai partire il test */
	testSoloAlfabetici();
}