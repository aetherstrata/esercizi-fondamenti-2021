#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica 
 * la modifica trasformando ciascun carattere non alfabetico in un asterisco */
void asteriscoNonAlfabetico(char *stringa) {
	
	/* scandisci ogni carattere della stringa */
	for(int i=0; stringa[i] != '\0'; i++) {
		/* se il carattere corrente non è alfabetico, trasformalo */
		if(!((stringa[i]>='A' && stringa[i]<='Z') || (stringa[i]>='a' && stringa[i]<='z')))
			stringa[i] = '*';
	}
}

/* funzione di test per asteriscoNonAlfabetico */
void testAsteriscoNonAlfabetico() {
	
	/* stringa senza caratteri alfabetici */
	char stringa1[] = "12345=)(67";
	asteriscoNonAlfabetico(stringa1);
	printf("Test asteriscoNonAlfabetico(\"12345=)(67\"): Atteso = \"**********\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con soli caratteri alfabetici */
	char stringa2[] = "aAbBcdDe";
	asteriscoNonAlfabetico(stringa2);
	printf("Test asteriscoNonAlfabetico(\"aAbBcdDe\"): Atteso = \"aAbBcdDe\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con un solo non alfabetico in prima posizione */
	char stringa3[] = "8abc";
	asteriscoNonAlfabetico(stringa3);
	printf("Test asteriscoNonAlfabetico(\"8abc\"): Atteso = \"*abc\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con un solo non alfabetico in ultima posizione */
	char stringa4[] = "abc8";
	asteriscoNonAlfabetico(stringa4);
	printf("Test asteriscoNonAlfabetico(\"abc8\"): Atteso = \"abc*\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con un solo alfabetico in prima posizione */
	char stringa5[] = "a67)£";
	asteriscoNonAlfabetico(stringa5);
	printf("Test asteriscoNonAlfabetico(\"a67)£\"): Atteso = \"a****\", Calcolato = \"%s\" \n", stringa5);

	/* stringa con un sola alfabetico in ultima posizione */
	char stringa6[] = "67)£a";
	asteriscoNonAlfabetico(stringa6);
	printf("Test asteriscoNonAlfabetico(\"67)£a\"): Atteso = \"****a\", Calcolato = \"%s\" \n", stringa6);

	/* stringa con un solo non alfabetico in posizione centrale */
	char stringa7[] = "cd3fg";
	asteriscoNonAlfabetico(stringa7);
	printf("Test asteriscoNonAlfabetico(\"cd3fg\"): Atteso = \"cd*fg\", Calcolato = \"%s\" \n", stringa7);	

	/* stringa vuota */
	char stringa8[] = "";
	asteriscoNonAlfabetico(stringa8);
	printf("Test asteriscoNonAlfabetico(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa8);	

	/* stringa con diversi non alfabetici */
	char stringa9[] = "a3b4c(d=e?p";
	asteriscoNonAlfabetico(stringa9);
	printf("Test asteriscoNonAlfabetico(\"a3b4c(d=e?p\"): Atteso = \"a*b*c*d*e*p\", Calcolato = \"%s\" \n", stringa9);	
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica "); 
	printf("trasformando ciascun carattere non alfabetico in un asterisco.\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione asteriscoNonAlfabetico */
	asteriscoNonAlfabetico(stringa);
	
	/* output */
	printf("Ecco la stringa trasformata: %s\n\n", stringa);
	
	/* fai partire il test */
	testAsteriscoNonAlfabetico();
}