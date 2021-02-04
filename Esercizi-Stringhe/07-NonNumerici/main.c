#include <stdio.h>

void eliminaCella(char str[], int i)
{
	while(str[i]!='\0'){
		str[i]=str[i+1];
		i++;
	}
}

void eliminaNonNumerici(char str[])
{
	int i=0;
	while (str[i]!='\0'){
		if (!(str[i]>='0' && str[i]<='9')){
			eliminaCella(str, i);
		} 
		else {
			i++;
		}
	}
}

void testEliminaNonNumerici()
{
	/* stringa senza caratteri numerici */ 
	char stringa1[] = "ashgdj,;.)(mfndkf"; 
	eliminaNonNumerici(stringa1); 
	printf("Test eliminaNonNumerici(\"ashgdj,;.)(mfndkf\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	/* stringa vuota */ 
	char stringa2[] = ""; 
	eliminaNonNumerici(stringa2); 
	printf("Test eliminaNonNumerici(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa2);
	/* stringa con solo caratteri numerici */ 
	char stringa3[] = "3478921"; 
	eliminaNonNumerici(stringa3); 
	printf("Test eliminaNonNumerici(\"3478921\"): Atteso = \"3478921\", Calcolato = \"%s\" \n", stringa3);
	/* stringa con caratteri numerici alla fine */ 
	char stringa4[] = "fgsky34721"; 
	eliminaNonNumerici(stringa4); 
	printf("Test eliminaNonNumerici(\"fgsky34721\"): Atteso = \"34721\", Calcolato = \"%s\" \n", stringa4);
	/* stringa con caratteri numerici all'inizio */ 
	char stringa5[] = "347va88xei"; 
	eliminaNonNumerici(stringa5); 
	printf("Test eliminaNonNumerici(\"347va88xei\"): Atteso = \"34788\", Calcolato = \"%s\" \n", stringa5);
}

int main(int argc, char **argv)
{
	printf("Questo programma elimina tutti i caratteri non numerici di una stringa.\n");
	printf("Inserisci la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	eliminaNonNumerici(stringa);
	printf("La stringa modificata %c %s\n\n", 138, stringa);
	
	testEliminaNonNumerici();
	
	return 0;
}
