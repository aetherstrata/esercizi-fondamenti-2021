#include <stdio.h>

void nienteNumeriDueCifre(char str[])
{
	int preNumerico;
	int i=0;
	int j=0;
	while (str[i]!='\0'){
		if(str[i]>='0' && str[i]<='9'){
			if (preNumerico==1){
				if (!(str[i+1]>='0' && str[i+1]<='9')) {
					j=i;
					while (str[j]!='\0'){
						str[j-1]=str[j+1];
						str[j]=str[j+2];
						j++;
					}
				}
				preNumerico=0;
			} else if (!(str[i-1]>='0' && str[i-1]<='9')){
				preNumerico=1;
				i++;
			} else {
				i++;
			}
		} else {
			i++;
		}
	}
}

void testNienteNumeriDueCifre()
{
	char stringa1[] = ""; 
	nienteNumeriDueCifre(stringa1); 
	printf("Test nienteNumeriDueCifre(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	
	char stringa2[] = "popipopi"; 
	nienteNumeriDueCifre(stringa2); 
	printf("Test nienteNumeriDueCifre(\"popipopi\"): Atteso = \"popipopi\", Calcolato = \"%s\" \n", stringa2);
	
	char stringa3[] = "po45i3sa!"; 
	nienteNumeriDueCifre(stringa3); 
	printf("Test nienteNumeriDueCifre(\"po45i3sa!\"): Atteso = \"45i3!\", Calcolato = \"%s\" \n", stringa3);
}

int main(int argc, char **argv)
{
	printf("Questa applicazione rimuove sequenze di esattamente due caratteri numerici consecutivi.\n");
	
	char stringa[50];
	printf("Immetti la tua stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	nienteNumeriDueCifre(stringa);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testNienteNumeriDueCifre();
	
	return 0;
}
