#include <stdio.h>

int doppiaStringa(char str[]){
	int conto=0;
	while(str[conto]!='\0'){
		conto++;
	}
	
	if (conto%2!=0) //Una stringa con numero elementi dispari non può essere una ripetizione
		return 0;
	
	for(int i=0;i<conto/2;i++){
		if(str[i]!=str[i+conto/2])
			return 0;
	}
	
	return 1;
}

void testDoppiaStringa(){
	
	char str1[]="";
	printf("Test doppiaStringa(\"\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(str1));
	
	char str2[]="abcba";
	printf("Test doppiaStringa(\"abcba\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(str2));
	
	char str3[]="abacaba";
	printf("Test doppiaStringa(\"abcaba\"): Atteso = 0, Calcolato = %d \n", doppiaStringa(str3));
	
	char str4[]="popipopi";
	printf("Test doppiaStringa(\"popipopi\"): Atteso = 1, Calcolato = %d \n", doppiaStringa(str4));
}

int main(int argc, char **argv)
{
	printf("Questo programa controlla che una stringa sia composta da due ripetizioni di una sottostringa\n");
	
	char stringa[50];
	printf("Immetti la stringa da verificare:\n");
	fgets(stringa, 50, stdin);
	
	int i=0;
	while(stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	if(doppiaStringa(stringa))
		printf("Questa stringa %c composta da due ripetizioni di una sottostringa!\n", 138);
	else
		printf("Questa stringa NON %c composta da due ripetizioni di una sottostringa!\n", 138);
	
	testDoppiaStringa();
	
	return 0;
}
