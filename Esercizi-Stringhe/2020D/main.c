#include <stdio.h>

void viaParoleDaDue(char str[])
{
	int preAlfabetico;
	int i=0;
	int j=0;
	while (str[i]!='\0'){
		if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
			if (preAlfabetico==1){
				if (!(str[i+1]>='A' && str[i+1]<='Z') && !(str[i+1]>='a' && str[i+1]<='z')) {
					j=i;
					while (str[j]!='\0'){
						str[j-1]=str[j+1];
						str[j]=str[j+2];
						j++;
					}
				}
				preAlfabetico=0;
			} else if (!(str[i-1]>='A' && str[i-1]<='Z') && !(str[i-1]>='a' && str[i-1]<='z')){
				preAlfabetico=1;
				i++;
			} else {
				i++;
			}
		} else {
			i++;
		}
	}
}

void testViaParoleDaDue()
{
	char stringa1[] = ""; 
	viaParoleDaDue(stringa1); 
	printf("Test viaParoleDaDue(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);
	
	char stringa2[] = "popipopi"; 
	viaParoleDaDue(stringa2); 
	printf("Test viaParoleDaDue(\"popipopi\"): Atteso = \"popipopi\", Calcolato = \"%s\" \n", stringa2);
	
	char stringa3[] = "po45i3sa!"; 
	viaParoleDaDue(stringa3); 
	printf("Test viaParoleDaDue(\"po45i3sa!\"): Atteso = \"45i3!\", Calcolato = \"%s\" \n", stringa3);
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
