#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e verifica se 
 * la stringa consiste di due sottostringhe uguali. */
int doppiaStringa(char *stringa) {
	int doppia = 1;						// valore da restituire		
	int lun = strlen(stringa);			// lunghezza stringa
	int i = 0;								// contatore
	
	/* se lunghezza è dispari sicuramente no */
	if(lun%2 != 0)
		doppia = 0;
	
	else {
		/* vai avanti fino a che non hai visto la prima metà */
		while(doppia && i<lun/2)
			/* confronta la posizione i con la posizione n/2 + i */
			if(stringa[i]!=stringa[lun/2 +i])
				doppia = 0;
			else
				i++;
	}
	return doppia;
}

/* funzione di test per doppiaStringa */
void testDoppiaStringa() {
	
	/* stringa vuota */
	char stringa1[] = "";
	printf("Test doppiaStringa(\"\"): Atteso = 1, Calcolato = %d \n", 	doppiaStringa(stringa1));

	/* stringa con un solo carattere */
	char stringa2[] = "a";
	printf("Test doppiaStringa(\"a\"): Atteso = 0, Calcolato = %d \n", 	doppiaStringa(stringa2));

	/* stringa con due soli caratteri uguali */
	char stringa3[] = "aa";
	printf("Test doppiaStringa(\"aa\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(stringa3));

	/* stringa in cui l'unico problema è sul primo carattere */
	char stringa4[] = "obcdabcd";
	printf("Test doppiaStringa(\"obcdabcd\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa4));

	/* stringa in cui l'unico problema è sull'ultimo carattere */
	char stringa5[] = "abcdabcp";
	printf("Test doppiaStringa(\"abcdabcp\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa5));

	/* stringa in cui l'unico problema è su un carattere centrale */
	char stringa6[] = "abedabcd";
	printf("Test doppiaStringa(\"abedabcd\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa6));

	/* istanza positiva normale */
	char stringa7[] = "abcdabcd";
	printf("Test doppiaStringa(\"abcdabcd\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(stringa7));

	/* istanza negativa normale */
	char stringa8[] = "abcd1234";
	printf("Test doppiaStringa(\"abcd1234\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(stringa8));
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e verifica "); 
	printf("se la stringa consiste di due sottostringhe uguali.\n");
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* verifica la proprietà */
	if(doppiaStringa(stringa))
		printf("La stringa consiste di due sottostringhe uguali!\n\n");
	else
		printf("La stringa non consiste di due sottostringhe uguali!\n\n");
	
	/* fai partire il test */
	testDoppiaStringa();
}