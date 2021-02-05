#include <stdio.h>

void cancellaCella(char str[], int index)
{
	for(int i=index; str[i]!='\0'; i++){
		str[i]=str[i+1];
	}
}

int isMinuscolo(char c)
{
	if(c>='a'&& c<='z'){
		return 1;
	} else {
		return 0;
	}
}

void dueMinuscolePerVolta(char str[])
{
	int i=0;
	while(str[i]!='\0'){
		if(isMinuscolo(str[i-1]) && isMinuscolo(str[i]) && isMinuscolo(str[i+1])){
			cancellaCella(str, i+1);
		} else {
			i++;
		}
	}
}

void testDueMinuscolePerVolta()
{
	/* stringa vuota */ 
	char stringa1[] = ""; 
	dueMinuscolePerVolta(stringa1); 
	printf("Test dueMinuscolePerVolta(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	/* stringa con sole minuscole */ 
	char stringa2[] = "abcdef"; 
	dueMinuscolePerVolta(stringa2); 
	printf("Test dueMinuscolePerVolta(\"abcdef\"): Atteso = \"ab\", Calcolato = \"%s\" \n", stringa2);
	/* stringa senza minuscole */ 
	char stringa3[] = "ABC123"; 
	dueMinuscolePerVolta(stringa3); 
	printf("Test dueMinuscolePerVolta(\"ABC123\"): Atteso = \"ABC123\", Calcolato = \"%s\" \n", stringa3);
	/* stringa mista */ 
	char stringa4[] = "abcdeFGHImeme666!!uuwwuu"; 
	dueMinuscolePerVolta(stringa4); 
	printf("Test dueMinuscolePerVolta(\"abcdeFGHImeme666!!uuwwuu\"): Atteso = \"abFGHIme666!!uu\", Calcolato = \"%s\" \n", stringa4);
	
}

int main(int argc, char **argv)
{
	char stringa[50];
	
	printf("Questo programma riduce sequenze di caratteri minuscoli consecutivi in sequenze di massimo due caratteri minuscoli.\n");
	printf("Inserisci la stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while(stringa[i]!='\0'){
		i++;
	}
	stringa[i]='\0';
	
	dueMinuscolePerVolta(stringa);
	printf("La stringa modificata %c: %s", 138, stringa);
	
	testDueMinuscolePerVolta();
	
	return 0;
}
