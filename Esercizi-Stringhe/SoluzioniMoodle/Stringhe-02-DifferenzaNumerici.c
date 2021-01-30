#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e restituisce la massima differenza 
 * (in valore assoluto) fra due caratteri numerici che appartengono alla stringa e fra i 
 * quali non ci sono altri caratteri numerici, oppure -1 se la stringa non contiene 
 * due caratteri numerici. */
int differenzaCaratteriNumerici(char *stringa) {
	int i;									// per scandire la stringa
	int ultimoNumero;				// ultimo numero letto
	int numeroCorrente;			// numero corrente
	int differenzaAttuale;			// la differenza attuale 
	int differenzaMassima;			// la differenza massima 
	
	/* inizializzazioni */
	differenzaMassima = -1;
	ultimoNumero = -1;
	i = 0;			// prima posizione da guardare
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* il carattere attuale è numerico? altrimenti non devi fare niente */
		if(stringa[i]>='0' && stringa[i]<='9') {
			/* prendi il numero corrente */
			numeroCorrente = stringa[i]-'0';
				
			/* hai già trovato caratteri numerici? */
			if(ultimoNumero!=-1) {
				
				/* calcola la differenza fra i due numeri */
				if(numeroCorrente>ultimoNumero)
					differenzaAttuale = numeroCorrente - ultimoNumero;
				else
					differenzaAttuale = ultimoNumero -  numeroCorrente;
				
				/* nuovo massimo? */
				if(differenzaAttuale>differenzaMassima)
					differenzaMassima = differenzaAttuale;
			}
	
			/* aggiorna l'ultimo numero */
			ultimoNumero = numeroCorrente;
		}
		i++;		// passa al prossimo carattere
	}
	return differenzaMassima;
}

/* funzione di test per differenzaCaratteriNumerici */
void testDifferenzaCaratteriNumerici() {
	
	/* stringa vuota */
	char stringa1[] = "";
	printf("Test differenzaCaratteriNumerici(\"\"): Atteso = -1, Calcolato = %d \n", 	differenzaCaratteriNumerici(stringa1));

	/* stringa senza caratteri numerici */
	char stringa2[] = "act?-£";
	printf("Test differenzaCaratteriNumerici(\"act?-£\"): Atteso = -1, Calcolato = %d \n", 	differenzaCaratteriNumerici(stringa2));

	/* stringa con un solo carattere numerico */
	char stringa3[] = "ab£c2)=";
	printf("Test differenzaCaratteriNumerici(\"ab£c2)=\"): Atteso = -1, Calcolato = %d \n", differenzaCaratteriNumerici(stringa3));

	/* stringa con due caratteri numerici di cui uno è il primo */
	char stringa4[] = "1abc7dep";
	printf("Test differenzaCaratteriNumerici(\"1abc7dep\"): Atteso = 6, Calcolato = %d \n", differenzaCaratteriNumerici(stringa4));

	/* stringa con due caratteri numerici di cui uno è l'ultimo */
	char stringa5[] = "acd3efg6";
	printf("Test differenzaCaratteriNumerici(\"acd3efg6\"): Atteso = 3, Calcolato = %d \n", differenzaCaratteriNumerici(stringa5));

	/* stringa con due soli caratteri, entrambi numerici */
	char stringa6[] = "12";
	printf("Test differenzaCaratteriNumerici(\"12\"): Atteso = 1, Calcolato = %d \n", differenzaCaratteriNumerici(stringa6));

	/* istanza normale */
	char stringa7[] = "a12b7c3da9bcd2";
	printf("Test differenzaCaratteriNumerici(\"a12b7c3da9bcd2\"): Atteso = 7, Calcolato = %d \n", differenzaCaratteriNumerici(stringa7));
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa e determina la massima "); 
	printf("differenza fra due caratteri numerici nella stringa fra i quali "); 
	printf("non compaiono altri caratteri numerici.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione differenzaCaratteriNumerici */
	int differenza = differenzaCaratteriNumerici(stringa);
	
	/* output */
	if(differenza==-1)
		printf("La stringa non contiene due caratteri numerici!\n\n");
	else
		printf("La massima differenza fra due caratteri numerici %c %d.\n\n", 138, differenza);
		
	/* fai partire il test */
	testDifferenzaCaratteriNumerici();
}