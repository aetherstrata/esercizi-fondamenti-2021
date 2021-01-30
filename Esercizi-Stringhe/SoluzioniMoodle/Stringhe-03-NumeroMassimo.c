#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa. La funzione 
 * restituisce il massimo numero contenuto nella stringa o -1 se 
 * la stringa non contiene nessun carattere numerico. */
int numeroMassimo(char *stringa) {
	int i;								// per scandire la stringa
	int numeroAttuale;			// il numero attuale
	int numeroMassimo;			// il numero massimo 
	
	/* inizializzazioni */
	numeroAttuale = -1;
	numeroMassimo = -1;
	i = 0;			// prima posizione da guardare
	/* vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0') {
		/* il carattere attuale è numerico? */
		if(stringa[i]>='0' && stringa[i]<='9') {
			
			/* primo carattere numerico? */
			if(numeroAttuale==-1)
				numeroAttuale = stringa[i]-'0';
			else	// se non è il primo devi aggiornare quello precedente
				numeroAttuale = numeroAttuale * 10 + (stringa[i]-'0');
			
			/* controlla se hai un nuovo massimo */
			if(numeroAttuale>numeroMassimo)
				numeroMassimo = numeroAttuale; 
		}
		else // non stiamo guardando un carattere numerico
			numeroAttuale = -1;
		i++;		// passa al prossimo carattere
	}
	return numeroMassimo;
}


/* funzione di test per numeroMassimo */
void testNumeroMassimo() {
	
	/* stringa vuota */
	char stringa1[] = "";
	printf("Test numeroMassimo(\"\"): Atteso = -1, Calcolato = %d \n", 	numeroMassimo(stringa1));

	/* stringa senza caratteri numerici */
	char stringa2[] = "act?-£";
	printf("Test numeroMassimo(\"act?-£\"): Atteso = -1, Calcolato = %d \n", 	numeroMassimo(stringa2));

	/* stringa con un solo carattere numerico in prima posizione */
	char stringa3[] = "2ab£c)=";
	printf("Test numeroMassimo(\"2ab£c)=\"): Atteso = 2, Calcolato = %d \n", numeroMassimo(stringa3));

	/* stringa con un solo carattere numerico in ultima posizione */
	char stringa4[] = "ab£c)=3";
	printf("Test numeroMassimo(\"ab£c)=3\"): Atteso = 3, Calcolato = %d \n", numeroMassimo(stringa4));

	/* stringa con soli caratteri numerici */
	char stringa5[] = "12345";
	printf("Test numeroMassimo(\"12345\"): Atteso = 12345, Calcolato = %d \n", numeroMassimo(stringa5));

	/* stringa con una sequenza di caratteri numerici */
	char stringa6[] = "ab123cd";
	printf("Test numeroMassimo(\"ab123cd(\"): Atteso = 123, Calcolato = %d \n", numeroMassimo(stringa6));

	/* stringa con più di una sequenza di caratteri numerici */
	char stringa7[] = "sh123dfv89(";
	printf("Test numeroMassimo(\"sh123dfv89(\"): Atteso = 123, Calcolato = %d \n", numeroMassimo(stringa7));
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina il massimo numero contenuto nella stringa.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione numeroMassimo */
	int numero = numeroMassimo(stringa);
	
	/* output */
	if(numero==-1)
		printf("La stringa non contiene caratteri numerici!\n\n");
	else
		printf("Il massimo numero nella stringa %c %d.\n\n", 138, numero);
		
	/* fai partire il test */
	testNumeroMassimo();
}