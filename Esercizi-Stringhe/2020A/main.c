#include <stdio.h>

void cancellaCella(char str[], int i){
	while(str[i]!='\0'){
		str[i]=str[i+1];
		i++;
	}
}

void viaParoleDaDue(char str[])
{
	int i=0;
	int preAlfabetico=0;
	while (str[i]!='\0'){
		if ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
			while ((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
				i++;
				preAlfabetico++;
			}
			
			if (preAlfabetico==2){
				for (int j=0; j<2; j++){
					cancellaCella(str, i-2); 
				}
			}
			preAlfabetico=0;
		} else {
			i++;
		}
	}
}

void testViaParoleDaDue()
{
	// non avevo voglia di inventarmi i test.
	
    /*stringa vuota*/
    char stringa1[]="";
    viaParoleDaDue(stringa1);
    printf("Test viaParoleDaDue(\"\"): Atteso=\"\", calcolato=\"%s\" \n", stringa1);
    /*stringa senza caratteri alfabetici doppi*/
    char stringa2[]="abc56fghi";
    viaParoleDaDue(stringa2);
    printf("Test viaParoleDaDue(\"abc56fghi\"): Atteso=\"abc56fghi\", calcolato=\"%s\" \n", stringa2);
    /*stringa con solo due caratteri alfabetici*/
    char stringa3[]="ab";
    viaParoleDaDue(stringa3);
    printf("Test viaParoleDaDue(\"ab\"): Atteso=\"\", calcolato=\"%s\" \n", stringa3);
    /*stringa con solo una sequenza di due caratteri alfabetici all'inizio*/
    char stringa4[]="ab56tryu";
    viaParoleDaDue(stringa4);
    printf("Test viaParoleDaDue(\"ab56tryu\"): Atteso=\"56tryu\", calcolato=\"%s\" \n", stringa4);
    /*stringa con solo una sequenza di due caratteri alfabetici alla fine*/
    char stringa5[]="abcd56tr";
    viaParoleDaDue(stringa5);
    printf("Test viaParoleDaDue(\"abcd56tr\"): Atteso=\"abcd56\", calcolato=\"%s\" \n", stringa5);
    /*stringa con solo una sequenza di due caratteri alfabetici al centro*/
    char stringa6[]="abcd56ef89ghi";
    viaParoleDaDue(stringa6);
    printf("Test viaParoleDaDue(\"abcd56ef89ghi\"): Atteso=\"abcd5689ghi\", calcolato=\"%s\" \n", stringa6);
    /*stringa normale*/
    char stringa7[]="ab12cde56ee78a67bb";
    viaParoleDaDue(stringa7);
    printf("Test viaParoleDaDue(\"ab12cde56ee78a67bb\"): Atteso=\"12cde5678a67\", calcolato=\"%s\" \n", stringa7);
}

int main(int argc, char **argv)
{
	printf("Questa applicazione rimuove sequenze di esattamente due caratteri alfabetici consecutivi.\n");
	
	char stringa[50];
	printf("Immetti la tua stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	viaParoleDaDue(stringa);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testViaParoleDaDue();
	
	return 0;
}
