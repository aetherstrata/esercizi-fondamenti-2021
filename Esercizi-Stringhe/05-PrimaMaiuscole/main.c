#include <stdio.h>

void primaMaiuscole(char str[])
{
	int i = 0;
	int k = 0;
	char scambio;
	while (str[i]!='\0'){
		if (str[i]<='z' && str[i]>='a'){
			k=i;
			scambio=str[i];
			while (str[k]!='\0'){
				if (str[k]<='Z' && str[k]>='A'){
					str[i]=str[k];
					str[k]=scambio;
					break;
				}
				k++;
			}
		}
		i++;
	}
}

void testPrimaMaiuscole()
{
	/* stringa con un solo carattere maiuscolo in ultima posizione */ 
	char stringa1[] = "abC"; 
	primaMaiuscole(stringa1); 
	printf("Test primaMaiuscole(\"abC\"): Atteso = \"Cba\", Calcolato = \"%s\" \n", stringa1);
	
	/* stringa con un più caratteri maiuscoli in ultima posizione */ 
	char stringa2[] = "abCSD"; 
	primaMaiuscole(stringa2); 
	printf("Test primaMaiuscole(\"abCSD\"): Atteso = \"CSDba\", Calcolato = \"%s\" \n", stringa2);
	
	/* stringa con un solo carattere maiuscolo in mezzo alla stringa */ 
	char stringa3[] = "abCsa"; 
	primaMaiuscole(stringa3); 
	printf("Test primaMaiuscole(\"abCsa\"): Atteso = \"Cbasa\", Calcolato = \"%s\" \n", stringa3);
	
	/* stringa con caratteri maiuscoli in varie posizioni */ 
	char stringa4[] = "abCsDa"; 
	primaMaiuscole(stringa4); 
	printf("Test primaMaiuscole(\"abCsDa\"): Atteso = \"CDasba\", Calcolato = \"%s\" \n", stringa4);
}

int main(int argc, char **argv)
{
	printf("Questo programma ordina le stringhe in modo da mettere le maiuscole prima delle minuscole.\n");
	printf("Inserisci la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	int i = 0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	primaMaiuscole(stringa);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testPrimaMaiuscole();
	
	return 0;
}
