#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa. La funzione 
 * stampa un messaggio che indica quale carattere ha il maggior 
 * numero di occorrenze consecutive nella stringa e quante sono 
 * tali occorrenze. */
void numeroOccorrenze(char *stringa) {
// pre: stringa non vuota

	int i;								// per scandire la stringa
	char carattereAttuale;		// carattere sotto esame
	int occorrenzeAttuali;		// numero di occorrenze attuali
	char carattereMassimo;	// carattere a massimo numero occorrenze
	int occorrenzeMassime;	// massimo numero di occorrenze
	
	/* inizializzazioni */
	carattereAttuale = stringa[0];
	carattereMassimo = stringa[0];
	occorrenzeAttuali = 1;
	occorrenzeMassime = 1;
	i = 1;			// prima posizione da guardare
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* stai continuando una sequenza? */
		if(stringa[i]==carattereAttuale) {
			/* aumenta le occorrenze attuali ed eventualmente 
			 * anche i dati sul massimo */
			occorrenzeAttuali++;
			if(occorrenzeAttuali>occorrenzeMassime) {
				carattereMassimo = carattereAttuale;
				occorrenzeMassime = occorrenzeAttuali;
			}
		}
		else { // nuovo carattere
			carattereAttuale = stringa[i];
			occorrenzeAttuali = 1;
		}
		i++;		// passa al prossimo carattere
	}

	/* output */
	printf("Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c '%c' che ha %d occorrenze consecutive.", 138, 
	carattereMassimo, occorrenzeMassime);
}

/* funzione di test per numeroOccorrenze */
void testNumeroOccorrenze() {
	
	/* stringa con sole ripetizioni dello stesso carattere */
	char stringa1[] = "aaaaa";
	printf("Test numeroOccorrenze(\"aaaaa\"): Atteso = \"Il carattere con il maggior");
	printf(" numero di occorrenze consecutive %c 'a' che ha 5 occorrenze consecutive\"", 138);
	printf(", Calcolato = \"");
	numeroOccorrenze(stringa1);
	printf("\"\n\n");

	/* stringa in cui la ripetizione massima è iniziale */
	char stringa2[] = "aaabcdde";
	printf("Test numeroOccorrenze(\"aaabcdde\"): Atteso = \"Il carattere con il maggior");
	printf(" numero di occorrenze consecutive %c 'a' che ha 3 occorrenze consecutive\"", 138);
	printf(", Calcolato = \"");
	numeroOccorrenze(stringa2);
	printf("\"\n\n");
	
	/* stringa in cui la ripetizione massima è finale */
	char stringa3[] = "aabcddeee";
	printf("Test numeroOccorrenze(\"aabcddeee\"): Atteso = \"Il carattere con il maggior");
	printf(" numero di occorrenze consecutive %c 'e' che ha 3 occorrenze consecutive\"", 138);
	printf(", Calcolato = \"");
	numeroOccorrenze(stringa3);
	printf("\"\n\n");
	
	/* stringa in cui la ripetizione massima è lunga 1 */
	char stringa4[] = "abcdef";
	printf("Test numeroOccorrenze(\"aabcddeee\"): Atteso = \"Il carattere con il maggior");
	printf(" numero di occorrenze consecutive %c 'a' che ha 1 occorrenze consecutive\"", 138);
	printf(", Calcolato = \"");
	numeroOccorrenze(stringa4);
	printf("\"\n\n");

	/* stringa con diverse ripetizioni lunghe */
	char stringa5[] = "abbbbbccdddeeeef";
	printf("Test numeroOccorrenze(\"abbbbccdddeeeef\"): Atteso = \"Il carattere con il maggior");
	printf(" numero di occorrenze consecutive %c 'b' che ha 5 occorrenze consecutive\"", 138);
	printf(", Calcolato = \"");
	numeroOccorrenze(stringa5);
	printf("\"\n\n");
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina il carattere che ha il massimo numero di ");
	printf("occorrenze consecutive e quante sono tali occorrenze.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione numeroOccorrenze */
	numeroOccorrenze(stringa);
	printf("\n\n");
	
	/* fai partire il test */
	testNumeroOccorrenze();
}