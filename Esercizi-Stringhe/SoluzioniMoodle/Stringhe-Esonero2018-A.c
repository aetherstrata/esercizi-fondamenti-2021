#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e la modifica
 * separando tutte le parole con un singolo spazio */
void soloParole(char *stringa) {
	int i, j;					// contatori
	i = 0;

	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* se il carattere attuale è alfabetico, vai avanti */
		if((stringa[i]>='a' && stringa[i]<='z')|| (stringa[i]>='A' && stringa[i]<='Z'))
			i++;
		else {		// carattere attuale non alfabetico
			/* sostituisci il carattere attuale con uno spazio solo se il prossimo
			 * è alfabetico e quello corrente non ha indice 0; altrimenti cancellalo */
			if(i!=0 && ((stringa[i+1]>='a' && stringa[i+1]<='z')|| (stringa[i+1]>='A' && stringa[i]<='Z'))) {
				/* sostituisci il carattere con uno spazio e poi vai avanti */
				stringa[i] = ' ';
				i++;
			}
			else {
				/* cancellalo */
				for(j=i;	stringa[j] != '\0'; j++)
					stringa[j] = stringa[j+1];
			}
		}
	}
}

/* Funzione che riceve come parametro una stringa e la modifica
 * separando tutte le parole con un singolo spazio; soluzione alternativa */
void soloParole2(char *stringa) {
	int i;								// per scorrere la  stringa
	int j = 0;						// per scorrere le posizioni nella stringa modificata

	
	/* vai avanti fino alla fine della stringa */
	for(i=0; stringa[i] != '\0'; i++) {
		/* se il carattere attuale è alfabetico, copialo nella stringa modificata */
		if((stringa[i]>='a' && stringa[i]<='z')|| (stringa[i]>='A' && stringa[i]<='Z')) {
			stringa[j] = stringa[i];
			j++;
		}
		else {		// carattere attuale non alfabetico
			/* se il prossimo carattere è alfabetico e già hai inserito caratteri nella stringa modificata, 
			 * allora inserisci uno spazio nella stringa modificata */
			if(j!=0 && ((stringa[i+1]>='a' && stringa[i+1]<='z')|| (stringa[i+1]>='A' && stringa[i]<='Z'))) {
				stringa[j] = ' ';
				j++;
			}
		}
	}
	
	/* è necessario delimitare la fine della stringa modificata */
	stringa[j] = '\0';
}

/* funzione di test */
void testSoloParole() {

	/* stringa vuota */
	char stringa1[] = "";
	soloParole(stringa1);
	printf("Test soloParole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con sole caratteri alfabetici */
	char stringa2[] = "djskfhdjkhg";
	soloParole(stringa2);
	printf("Test soloParole(\"djskfhdjkhg\"): Atteso = \"djskfhdjkhg\", Calcolato = \"%s\" \n", stringa2);

	/* stringa senza caratteri alfabetici */
	char stringa3[] = "0£,  .34";
	soloParole(stringa3);
	printf("Test soloParole(\"0£,.34\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con un solo carattere alfabetico all'inizio */
	char stringa4[] = "a678()0";
	soloParole(stringa4);
	printf("Test soloParole(\"a678()0\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con un solo carattere alfabetico alla fine */
	char stringa5[] = "678/0a";
	soloParole(stringa5);
	printf("Test soloParole(\"678/0a\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa5);


	/* stringa con un solo carattere non alfabetico all'inizio */
	char stringa6[] = "6abcde";
	soloParole(stringa6);
	printf("Test soloParole(\"6abcde\"): Atteso = \"abcde\", Calcolato = \"%s\" \n", stringa6);

	/* stringa con un solo carattere non alfabetico alla fine */
	char stringa7[] = "abcde6";
	soloParole(stringa7);
	printf("Test soloParole(\"abcde6\"): Atteso = \"abcde\", Calcolato = \"%s\" \n", stringa7);

	/* stringa con una sola parola centrale*/
	char stringa8[] = "123abcd 45";
	soloParole(stringa8);
	printf("Test soloParole(\"123abcd 45\"): Atteso = \"abcd\", Calcolato = \"%s\" \n", stringa8);

	/* stringa con tante parole */
	char stringa9[] = " abc 5def ?? ghi))";
	soloParole(stringa9);
	printf("Test soloParole(\" abc 5def ?? ghi))\"): Atteso = \"abc def ghi\", Calcolato = \"%s\" \n", stringa9);

}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e la modifica ");
	printf("evidenziando le sole parole\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);

	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';

	/* invoca la funzione soloParole */
	soloParole(stringa);

	/* output */
	printf("Ecco la stringa di sole parole: \"%s\"\n\n", stringa);

	testSoloParole();
}