#include <stdio.h>

void cancellaCella(char str[], int index)
{
	for(int i=index; str[i]!='\0'; i++){
		str[i]=str[i+1];
	}
}

void viaPuntiEccessivi(char str[])
{
	int i=0;
	while(str[i]!='\0'){
		if(str[i-2]!='.' && str[i-1]=='.' && str[i]=='.' && str[i+1]!='.'){
			cancellaCella(str, i);
		} else {
			i++;
		}
	}
	
}

void testViaPuntiEccessivi()
{
	/* stringa vuota */
	char stringa1[]="";
	viaPuntiEccessivi(stringa1);
	printf("Test viaPuntuEccessivi(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	/* stringa con due punti all'inizio */
	char stringa2[]="..ciao";
	viaPuntiEccessivi(stringa2);
	printf("Test viaPuntuEccessivi(\"..ciao\"): Atteso = \".ciao\", Calcolato = \"%s\" \n", stringa2);
	/* stringa con due punti alla fine */
	char stringa3[]="ciao..";
	viaPuntiEccessivi(stringa3);
	printf("Test viaPuntuEccessivi(\"ciao..\"): Atteso = \"ciao.\", Calcolato = \"%s\" \n", stringa3);
	/* stringa con solo due punti */
	char stringa4[]="..";
	viaPuntiEccessivi(stringa4);
	printf("Test viaPuntuEccessivi(\"..\"): Atteso = \".\", Calcolato = \"%s\" \n", stringa4);
	/* stringa con sequenze di piu di due punti */
	char stringa5[]=".....hera55....69!!...";
	viaPuntiEccessivi(stringa5);
	printf("Test viaPuntuEccessivi(\".....hera55....69!!...\"): Atteso = \".....hera55....69!!...\", Calcolato = \"%s\" \n", stringa5);
	/* stringa con un solo punto */
	char stringa6[]=".";
	viaPuntiEccessivi(stringa6);
	printf("Test viaPuntuEccessivi(\".\"): Atteso = \".\", Calcolato = \"%s\" \n", stringa6);
	/* stringa con varie sequenze di due punti */
	char stringa7[]="..v4..3e..&$..";
	viaPuntiEccessivi(stringa7);
	printf("Test viaPuntuEccessivi(\"..v4..3e..&$..\"): Atteso = \".va.3e.&$.\", Calcolato = \"%s\" \n", stringa7);
}

int main(int argc, char **argv)
{
	char stringa[50];
	
	printf("Questo programma rimpiazza ogni sequenza di due punti consecutivi in una stringa con uno solo.\n");
	printf("Inserisci la tua stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n')
		i++;
	stringa[i]='\0';
	
	viaPuntiEccessivi(stringa);
	printf("La stringa modificata %c: %s\n", 138, stringa);
	
	testViaPuntiEccessivi();
	
	return 0;
}
