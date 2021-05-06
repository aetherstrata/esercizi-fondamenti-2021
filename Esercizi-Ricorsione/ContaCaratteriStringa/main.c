#include <stdio.h>
#include <string.h>

int ContaCaratteriStringa(char* string, int len, char c)
{
	int conto;
	if(len==0){
		conto=0;
	} else {
		if(string[0]==c){
			conto=1+ContaCaratteriStringa(string+1, len-1, c);
		} else {
			conto=ContaCaratteriStringa(string+1, len-1, c);
		}
	}
	return conto;
}

int main(int argc, char **argv)
{
	char stringa[50];
	char carattere;
	
	printf("Inserisci una stringa:\n");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';
	printf("Inserisci il carattere da contare: ");
	scanf("%c",&carattere);
	
	int conto = ContaCaratteriStringa(stringa, strlen(stringa), carattere);
	
	printf("Il carattere %c viene ripetuto %d volte nella stringa.\n", carattere, conto);
	
	return 0;
}
