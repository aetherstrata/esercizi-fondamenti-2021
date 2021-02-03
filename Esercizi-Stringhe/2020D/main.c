#include <stdio.h>

void cancellaCella(char str[], int i){
	while(str[i]!='\0'){
		str[i]=str[i+1];
		i++;
	}
}

void cancellaDueMinuscoliUguali(char str[])
{
	int i = 0;
	int j = 0;
	
	while (str[i]!='\0'){
		if (str[i]>='a' && str[i]<='z' && str[i]==str[i+1]){
			j=i+2;
			while (str[i]==str[j])
				j++;
			if(j==i+2){
				for(int k=0; k<2; k++){
					cancellaCella(str, i); 
				}
			} else {
				i=j;
			}
		} 
		else {
			i++;
		}
	}
}

void testCancellaDueMinuscoliUguali(){
	/*stringa vuota*/
	char stringa1[]="";
	cancellaDueMinuscoliUguali(stringa1);
	printf("Test cancellaDueMinuscoliUguali(''): Atteso = '' , Calcolato = '%s' \n", stringa1);

	/*stringa con una sola coppia di caratteri uguali al centro*/
	char stringa2[]="12aa34bbbb";
	cancellaDueMinuscoliUguali(stringa2);
	printf("Test cancellaDueMinuscoliUguali('12aa34bbbb'): Atteso = '1234bbbb' , Calcolato = '%s' \n", stringa2);

	/*stringa con due coppie di caratteri uguali*/
	char stringa3[]="7aa123bbb44ds4tgghr12k";
	cancellaDueMinuscoliUguali(stringa3);
	printf("Test cancellaDueMinuscoliUguali('7aa123bbb44ds4tgghr12k'): Atteso = '7123bbb44ds4thr12k' , Calcolato = '%s' \n", stringa3);

	/*stringa con una coppia di caratteri uguali all'inizio*/
	char stringa4[]="aa34bbbb";
	cancellaDueMinuscoliUguali(stringa4);
	printf("Test cancellaDueMinuscoliUguali('aa34bbbb'): Atteso = '34bbbb' , Calcolato = '%s' \n", stringa4);

	/*stringa con una coppia di caratteri uguali alla fine*/
	char stringa5[]="aaa12bb";
	cancellaDueMinuscoliUguali(stringa5);
	printf("Test cancellaDueMinuscoliUguali('aaa12bb'): Atteso = 'aaa12' , Calcolato = '%s' \n", stringa5);

	/*stringa con tre coppie di caratteri uguali*/
	char stringa6[]="aabbcc";
	cancellaDueMinuscoliUguali(stringa6);
	printf("Test cancellaDueMinuscoliUguali('aabbcc'): Atteso = '' , Calcolato = '%s' \n", stringa6);
}

int main(int argc, char **argv)
{
	printf("Questa applicazione rimuove sequenze di esattamente due caratteri minuscoli uguali consecutivi.\n");
	
	char stringa[50];
	printf("Immetti la tua stringa:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	cancellaDueMinuscoliUguali(stringa);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testCancellaDueMinuscoliUguali();
	
	return 0;
}
