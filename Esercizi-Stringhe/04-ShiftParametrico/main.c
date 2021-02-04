#include <stdio.h>
#include <string.h>

void shiftParametrico(char str[], int n)
{
	int len = strlen(str);
	int k = len;
	
	// Congruenza lineare per gestire i casi in cui il parametro è più grande di len
	if (len!=0 && n>len){
		for (int i=0; n>len; i++){
			n-=len;
		}
	}
	
	// Non fare niente se la stringa è vuota (spreco di tempo)
	if (len!=0){
		for (int j=0; j<n; j++){
			while (k>=0){
				str[k+n]=str[k];
				k--;
			}
		
		str[j]=str[j+len];
		}
		str[len]='\0';
	}
}

void testShiftParametrico()
{
	/* shift con parametro 0 */ 
	char stringa1[] = "abcdef"; 
	shiftParametrico(stringa1, 0);
	printf("Test shiftParametrico(\"abcdef\", 0): Atteso = \"abcdef\", Calcolato = \"%s\" \n", stringa1);
	
	/* shift con parametro 1 */ 
	char stringa2[] = "abcdef"; 
	shiftParametrico(stringa2, 1);
	printf("Test shiftParametrico(\"abcdef\", 1): Atteso = \"fabcde\", Calcolato = \"%s\" \n", stringa2);
	
	/* shift con parametro uguale alla lunghezza di s */ 
	char stringa3[] = "abcdef"; 
	shiftParametrico(stringa3, 6);
	printf("Test shiftParametrico(\"abcdef\", 6): Atteso = \"abcdef\", Calcolato = \"%s\" \n", stringa3);
	
	/* stringa vuota */ 
	char stringa4[] = ""; 
	shiftParametrico(stringa4, 4);
	printf("Test shiftParametrico(\"\", 4): Atteso = \"\", Calcolato = \"%s\" \n", stringa4);
	
	/* stringa con meno caratteri del parametro */ 
	char stringa5[] = "abc"; 
	shiftParametrico(stringa5, 5);
	printf("Test shiftParametrico(\"abc\", 5): Atteso = \"bca\", Calcolato = \"%s\" \n", stringa5);
	
	/* stringa di un carattere */ 
	char stringa6[] = "a"; 
	shiftParametrico(stringa6, 3);
	printf("Test shiftParametrico(\"a\", 3): Atteso = \"a\", Calcolato = \"%s\" \n", stringa6);
}

int main(int argc, char **argv)
{
	printf("Questo programma sposta la stringa di x posizioni verso destra\n");
	printf("Inserisci la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	int i = 0;
	while(stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	int pos = 0;
	printf("Di quanti indici vuoi spostare la tua stringa?\n");
	scanf("%d", &pos);
	
	shiftParametrico(stringa, pos);
	printf("La stringa modificata %c \"%s\"\n\n", 138, stringa);
	
	testShiftParametrico();
	
	return 0;
}
