#include <stdio.h>

void cancellaCella(char str[], int index)
{
	for(int i=index; str[i]!='\0'; i++){
		str[i]=str[i+1];
	}
}

void soloUnaMaiuscola(char str[])
{
	int i=0;
	while(str[i]!='\0'){
		if (str[i-2]!='A' && str[i-1]=='A' && str[i]=='A' && str[i+1]!='A'){
			cancellaCella(str, i);
		} else {
			i++;
		}
	}
}

void testSoloUnaMaiuscola()
{
	/* stringa vuota */ 
	char stringa1[] = ""; 
	soloUnaMaiuscola(stringa1); 
	printf("Test soloUnaMaiuscola(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	/* stringa con sole minuscole */ 
	char stringa2[] = "abcdef"; 
	soloUnaMaiuscola(stringa2); 
	printf("Test soloUnaMaiuscola(\"abcdef\"): Atteso = \"abcdef\", Calcolato = \"%s\" \n", stringa2);
	/* stringa con due A all'inizio */ 
	char stringa3[] = "AABCdd"; 
	soloUnaMaiuscola(stringa3); 
	printf("Test soloUnaMaiuscola(\"AABCdd\"): Atteso = \"ABCdd\", Calcolato = \"%s\" \n", stringa3);
	/* stringa con due A alla fine */ 
	char stringa4[] = "frtGGokAA"; 
	soloUnaMaiuscola(stringa4); 
	printf("Test soloUnaMaiuscola(\"frtGGokAA\"): Atteso = \"frtGGokA\", Calcolato = \"%s\" \n", stringa4);
	/* stringa con più di due A */ 
	char stringa5[] = "frtAAAAAaaAGGok"; 
	soloUnaMaiuscola(stringa5); 
	printf("Test soloUnaMaiuscola(\"frtAAAAAaaAGGok\"): Atteso = \"frtAAAAAaaAGGok\", Calcolato = \"%s\" \n", stringa5);
}

int main(int argc, char **argv)
{
	char stringa[50];
	
	printf("Questo programma sostituisce esattamente due A maiuscole in una stringa in una A maiuscola.\n");
	printf("Inserisci la string:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	soloUnaMaiuscola(stringa);
	printf("La stringa modificata %c: %s",138, stringa);
	
	testSoloUnaMaiuscola();
	
	return 0;
}