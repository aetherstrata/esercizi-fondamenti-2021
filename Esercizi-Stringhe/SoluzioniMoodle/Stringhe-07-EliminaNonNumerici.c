#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica 
 * eliminando tutti i caratteri non numerici */
void eliminaNonNumerici(char *stringa) {
	int i, j;					// contatori
	
	i=0;
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* il carattere attuale non è numerico? */
		if(!(stringa[i]>='0' && stringa[i]<='9')) {
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

/* funzione di test per eliminaNonNumerici */
void testEliminaNonNumerici() {
	/* stringa senza caratteri numerici */
	char stringa1[] = "a&/,.&bc";
	eliminaNonNumerici(stringa1);
	printf("Test eliminaNonNumerici(\"a&/,.&bc\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con soli caratteri numerici */
	char stringa2[] = "8473985";
	eliminaNonNumerici(stringa2);
	printf("Test eliminaNonNumerici(\"8473985\"): Atteso = \"8473985\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con un solo carattere non numerico in prima posizione */
	char stringa3[] = "a123";
	eliminaNonNumerici(stringa3);
	printf("Test eliminaNonNumerici(\"a123\"): Atteso = \"123\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con un solo carattere non numerico in ultima posizione */
	char stringa4[] = "123a";
	eliminaNonNumerici(stringa4);
	printf("Test eliminaNonNumerici(\"123a\"): Atteso = \"123\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con un solo carattere numerico in prima posizione */
	char stringa5[] = "1abc";
	eliminaNonNumerici(stringa5);
	printf("Test eliminaNonNumerici(\"1abc\"): Atteso = \"1\", Calcolato = \"%s\" \n", stringa5);	

	/* stringa con un solo carattere numerico in ultima posizione */
	char stringa6[] = "abc1";
	eliminaNonNumerici(stringa6);
	printf("Test eliminaNonNumerici(\"abc1\"): Atteso = \"1\", Calcolato = \"%s\" \n", stringa6);	

	/* stringa vuota */
	char stringa7[] = "";
	eliminaNonNumerici(stringa7);
	printf("Test eliminaNonNumerici(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa7);	

	/* stringa con diversi caratteri numerici e diversi caratteri non numerici */
	char stringa8[] = "ab56hj?#fg3";
	eliminaNonNumerici(stringa8);
	printf("Test eliminaNonNumerici(\"ab56hj?#fg3\"): Atteso = \"563\", Calcolato = \"%s\" \n", stringa8);	
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica "); 
	printf("eliminando tutti i caratteri non numerici\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione eliminaNonNumerici */
	eliminaNonNumerici(stringa);
	
	/* output */
	printf("Ecco la stringa di soli caratteri numerici: %s\n", stringa);

	/* fai partire il test */
	testEliminaNonNumerici();
}