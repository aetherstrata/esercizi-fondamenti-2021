#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica 
 * la modifica trasformando tutte le lettere minuscole (non accentate) 
 * dell'alfabeto inglese nelle corrispondenti lettere maiuscole */
void rendiMaiuscole(char *stringa) {
	
	/* scandisci ogni carattere della stringa */
	for(int i=0; i<strlen(stringa); i++) {
		/* se il carattere corrente è alfabetico minuscolo, trasformalo */
		if(stringa[i]>='a' && stringa[i]<='z') 
			stringa[i] = stringa[i] + 'A' - 'a';
	}
}

/* funzione di test per rendiMaiuscole */
void testRendiMaiuscole() {
	/* stringa senza minuscole */
	char stringa1[] = "ABCDE123";
	rendiMaiuscole(stringa1);
	printf("Test rendiMaiuscole(\"ABCDE123\"): Atteso = \"ABCDE123\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con tutti i caratteri minuscoli */
	char stringa2[] = "abcde";
	rendiMaiuscole(stringa2);
	printf("Test rendiMaiuscole(\"abcde\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con una sola minuscola in prima posizione */
	char stringa3[] = "aBCDE";
	rendiMaiuscole(stringa3);
	printf("Test rendiMaiuscole(\"aBCDE\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con una sola minuscola in ultima posizione */
	char stringa4[] = "ABCDe";
	rendiMaiuscole(stringa4);
	printf("Test rendiMaiuscole(\"ABCDe\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con una sola non minuscola in prima posizione */
	char stringa5[] = "Abcde";
	rendiMaiuscole(stringa5);
	printf("Test rendiMaiuscole(\"Abcde\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa5);

	/* stringa con una sola minuscola in ultima posizione */
	char stringa6[] = "abcdE";
	rendiMaiuscole(stringa6);
	printf("Test rendiMaiuscole(\"abcdE\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa6);

	/* stringa con una sola minuscola in posizione centrale */
	char stringa7[] = "ABcDE";
	rendiMaiuscole(stringa7);
	printf("Test rendiMaiuscole(\"ABcDE\"): Atteso = \"ABCDE\", Calcolato = \"%s\" \n", stringa7);	

	/* stringa vuota */
	char stringa8[] = "";
	rendiMaiuscole(stringa8);
	printf("Test rendiMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa8);	

	/* stringa con diverse minuscole */
	char stringa9[] = "a437bfCGfk)=";
	rendiMaiuscole(stringa9);
	printf("Test rendiMaiuscole(\"a437bfCGfk)=\"): Atteso = \"A437BFCGFK)=\", Calcolato = \"%s\" \n", stringa9);	
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica "); 
	printf("trasformando tutte le lettere minuscole nelle corrispondenti lettere maiuscole\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione rendiMaiuscole */
	rendiMaiuscole(stringa);
	
	/* output */
	printf("Ecco la stringa trasformata: %s\n\n", stringa);
	
	/* fai partire il test */
	testRendiMaiuscole();
}