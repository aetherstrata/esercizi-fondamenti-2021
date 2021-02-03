#include <stdio.h>

void cancellaCella(char str[], int i){
	while(str[i]!='\0'){
		str[i]=str[i+1];
		i++;
	}
}

void nienteNumeriDueCifre(char str[])
{
	int i=0;
	int preNumerico=0;
	while (str[i]!='\0'){
		if (str[i]>='0' && str[i]<='9'){
			while (str[i]>='0' && str[i]<='9'){
				i++;
				preNumerico++;
			}
			
			if (preNumerico==2){
				for(int j=0; j<2; j++){
					cancellaCella(str, i-2); 
				}
			}
			preNumerico=0;
		} else {
			i++;
		}
	}
}

void testNienteNumeriDueCifre()
{
	// non avevo voglia di inventarmi i test.
	
    /*stringa nulla*/
    char stringa1[]="";
    nienteNumeriDueCifre(stringa1);
    printf("Test nienteNumeriDueCifre(\"\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa1);
    /*stringa senza caratterici numerici*/
    char stringa2[]="abcd";
    nienteNumeriDueCifre(stringa2);
    printf("Test nienteNumeriDueCifre(\"abcd\"): Atteso=\"abcd\", Calcolato=\"%s\" \n", stringa2);
    /*stringa con un solo carattere numerico*/
    char stringa3[]="1";
    nienteNumeriDueCifre(stringa3);
    printf("Test nienteNumeriDueCifre(\"1\"): Atteso=\"1\", Calcolato=\"%s\" \n", stringa3);
    /*stringa con due caratteri numerici*/
    char stringa4[]="12";
    nienteNumeriDueCifre(stringa4);
    printf("Test nienteNumeriDueCifre(\"12\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa4);
    /*stringa con tre caratteri numerici*/
    char stringa5[]="123";
    nienteNumeriDueCifre(stringa5);
    printf("Test nienteNumeriDueCifre(\"123\"): Atteso=\"123\", Calcolato=\"%s\" \n", stringa5);
    /*stringa con due caratteri numerici all'inizio*/
    char stringa6[]="12abc";
    nienteNumeriDueCifre(stringa6);
    printf("Test nienteNumeriDueCifre(\"12abc\"): Atteso=\"abc\", Calcolato=\"%s\" \n", stringa6);
    /*stringa con due caratteri numerici alla fine*/
    char stringa7[]="abc12";
    nienteNumeriDueCifre(stringa7);
    printf("Test nienteNumeriDueCifre(\"abc12\"): Atteso=\"abc\", Calcolato=\"%s\" \n", stringa7);
    /*stringa generale*/
    char stringa8[]="12ab123fg67xyh2iu09";
    nienteNumeriDueCifre(stringa8);
    printf("Test nienteNumeriDueCifre(\"12ab123fg67xyh2iu09\"): Atteso=\"ab123fgxyh2iu\", Calcolato=\"%s\" \n", stringa8);
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
