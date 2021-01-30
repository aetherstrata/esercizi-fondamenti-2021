#include <stdio.h>
#include <string.h>

/* Funzione che riceve come parametro una stringa e riordina i 
 * caratteri della stringa così che tutti i caratteri alfabetici maiuscoli 
 * compaiono prima di tutti i caratteri alfabetici minuscoli. */
void primaMaiuscole(char *stringa) {
	int i = 0;							// scorri da sinistra
	int j = strlen(stringa)-1;		// scorri da destra
	
	/* vai avanti fino a che gli indici non si incontrano */
	while(i<j) {
		
		/* il carattere con indice i sta bene dove sta? */
		if(!(stringa[i]>='a' && stringa[i]<='z'))
			i++;
		else {
			/* il carattere con indice j sta bene dove sta? */
			if(!(stringa[j]>='A' && stringa[j]<='Z')) 
				j--;
			else {
			/* il carattere con indice i è minuscolo e quello con indice
			 * j è maiuscolo: scambiali */
				char temp = stringa[i];
				stringa[i] = stringa[j];
				stringa[j] = temp;
			}
		}
	}
}

/* funzione di test per primaMaiuscole */
void testPrimaMaiuscole() {
	
	/* stringa vuota */
	char stringa1[] = "";
	primaMaiuscole(stringa1);
	printf("Test primaMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* stringa con un solo carattere minuscolo */
	char stringa2[] = "a";
	primaMaiuscole(stringa2);
	printf("Test primaMaiuscole(\"a\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con un solo carattere maiuscolo */
	char stringa3[] = "A";
	primaMaiuscole(stringa3);
	printf("Test primaMaiuscole(\"A\"): Atteso = \"A\", Calcolato = \"%s\" \n", stringa3);

	/* stringa in cui la sola minuscola fuori posto è in prima posizione */
	char stringa4[] = "aBCdef";
	primaMaiuscole(stringa4);
	printf("Test primaMaiuscole(\"aBCdef\"): Atteso = \"BCadef\", Calcolato = \"%s\" \n", stringa4);

	/* stringa in cui la sola maiuscola fuori posto è in ultima posizione */
	char stringa5[] = "ABdefC";
	primaMaiuscole(stringa5);
	printf("Test primaMaiuscole(\"ABdefC\"): Atteso = \"ABCefd\", Calcolato = \"%s\" \n", stringa5);

	/* stringa con diversi caratteri fuori posto */
	char stringa6[] = "aAbBcCdD";
	primaMaiuscole(stringa6);
	printf("Test primaMaiuscole(\"aAbBcCdD\"): Atteso = \"DACBcbda\", Calcolato = \"%s\" \n", stringa6);
}

/* funzione principale */
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e riordina i caratteri così che i caratteri alfabetici maiuscoli ");
	printf("compaiono prima dei caratteri alfabetici minuscoli.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* riordina i caratteri */
	primaMaiuscole(stringa);
	
	/* output */
	printf("Ecco la stringa trasformata: %s\n\n", stringa);
	
	/* fai partire il test */
	testPrimaMaiuscole();
}