#include <stdio.h>

void cancellaCella(char str[], int i){
	while(str[i]!='\0'){
		str[i]=str[i+1];
		i++;
	}
}

void cancellaDueNumericiUguali(char str[])
{
	int i = 0;
	int uguale=0;
	
	while (str[i]!='\0'){
		if (str[i]>='0' && str[i]<='9'){
			uguale=1;
			while (str[i]==str[i+1]){
				i++;
				uguale++;
			}
			if (uguale==2){
				for (int j=0; j<2; j++){
					cancellaCella(str, i-1); 
				}
			} 
			else {
				i++;
			}
		} 
		else {
			i++;
		}
	}
}

void testCancellaDueNumericiUguali()
{
	// non avevo voglia di inventarmi i test.
	
	/*stringa vuota*/
	char stringa1[]="";
	cancellaDueNumericiUguali(stringa1);
	printf("\n\nTest CancellaDueNumeriUguali(\"\"): Atteso = \"\", Calcolato = \"%s\" \n",stringa1);
	/*stringa due numeri uguali all'inizio*/
	char stringa2[]="22a";
	cancellaDueNumericiUguali(stringa2);
	printf("Test CancellaDueNumeriUguali(\"22a\"): Atteso = \"a\", Calcolato = \"%s\" \n",stringa2);
	/*stringa due numeri uguali alla fine*/
	char stringa3[]="a22";
	cancellaDueNumericiUguali(stringa3);
	printf("Test CancellaDueNumeriUguali(\"a22\"): Atteso = \"a\", Calcolato = \"%s\" \n",stringa3);
	/*stringa due numeri uguali al centro*/
	char stringa4[]="a22a";
	cancellaDueNumericiUguali(stringa4);
	printf("Test CancellaDueNumeriUguali(\"a22a\"): Atteso = \"aa\", Calcolato = \"%s\" \n",stringa4);
	/*stringa tre numeri uguali*/
	char stringa5[]="222";
	cancellaDueNumericiUguali(stringa5);
	printf("Test CancellaDueNumeriUguali(\"222\"): Atteso = \"222\", Calcolato = \"%s\" \n",stringa5);
	/*stringa 3 numeri uguali e due numeri uguali*/
	char stringa6[]="22233";
	cancellaDueNumericiUguali(stringa6);
	printf("Test CancellaDueNumeriUguali(\"22233\"): Atteso = \"222\", Calcolato = \"%s\" \n",stringa6);
	/*stringa solo caratteri diversi da numeri */
	char stringa7[]="abc!";
	cancellaDueNumericiUguali(stringa7);
	printf("Test CancellaDueNumeriUguali(\"abc!\"): Atteso = \"abc!\", Calcolato = \"%s\" \n",stringa7);
	/*stringa casuale */
	char stringa8[]="22cde555ee12a13367bb5";
	cancellaDueNumericiUguali(stringa8);
	printf("Test CancellaDueNumeriUguali(\"22cde555ee12a13367bb5\"): Atteso = \"cde555ee12a167bb5\", Calcolato = \"%s\" \n",stringa8);
}

int main(int argc, char **argv)
{
	printf("Questa applicazione rimuove sequenze di esattamente due caratteri numerici uguali consecutivi.\n");
	
	char stringa[50];
	printf("Immetti la tua stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	cancellaDueNumericiUguali(stringa);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testCancellaDueNumericiUguali();
	
	return 0;
}
