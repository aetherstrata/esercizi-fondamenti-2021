#include <stdio.h>

void cancellaCella(char str[], int index)
{
	for(int i=index; str[i]!='\0'; i++){
		str[i]=str[i+1];
	}
}

void alPiuDueConsecutivi(char str[])
{
	int i=0;
	while (str[i]!='\0'){
		if (str[i-1]==str[i] && str[i+1]==str[i]){
			cancellaCella(str, i+1);
		}
		else {
			i++;
		}
	}
}

void testAlPiuDueConsecutivi()
{
	/* stringa vuota */ 
	char stringa1[] = ""; 
	alPiuDueConsecutivi(stringa1); 
	printf("Test alPiuDueConsecutivi(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	/* stringa senza ripetizioni */
	char stringa2[] = "ciao"; 
	alPiuDueConsecutivi(stringa2); 
	printf("Test alPiuDueConsecutivi(\"ciao\"): Atteso = \"ciao\", Calcolato = \"%s\" \n", stringa2);
	/* stringa con ripetizione all'inizio */
	char stringa3[] = "cccciao"; 
	alPiuDueConsecutivi(stringa3); 
	printf("Test alPiuDueConsecutivi(\"cccciao\"): Atteso = \"cciao\", Calcolato = \"%s\" \n", stringa3);
	/* stringa con ripetizione alla fine */
	char stringa4[] = "ciaooooo"; 
	alPiuDueConsecutivi(stringa4); 
	printf("Test alPiuDueConsecutivi(\"ciaooooo\"): Atteso = \"ciaoo\", Calcolato = \"%s\" \n", stringa4);
	/* stringa con varie ripetizioni */
	char stringa5[] = "ccccciiiiiaaaaaaooooo!!!!!!!"; 
	alPiuDueConsecutivi(stringa5); 
	printf("Test alPiuDueConsecutivi(\"ccccciiiiiaaaaaaooooo!!!!!!!\"): Atteso = \"cciiaaoo!!\", Calcolato = \"%s\" \n", stringa5);
}

int main(int argc, char **argv)
{
	char stringa[50];
	
	printf("Questo programma rimuove sequenze di caratteri consecutivi pi%c lunghe di due caratteri.\n", 163);
	printf("Inserisci la stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while(stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	alPiuDueConsecutivi(stringa);
	printf("La stringa modificata %c: %s\n\n", 138, stringa);
	
	testAlPiuDueConsecutivi();
	
	return 0;
}
