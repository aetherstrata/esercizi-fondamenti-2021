#include <stdio.h>
#include <string.h>

int AlmenoUnaMaiuscola(char* string, int len)
{
	int risultato;
	if(len==0){
		risultato=0;
	} else {
		risultato = (string[0]>='A' && string[0]<='Z') || AlmenoUnaMaiuscola(string+1,strlen(string)-1);
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	char stringa[50];
	printf("Immetti una stringa:\n");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0'; //sostituisce l'ultimo carattere con NULL
	printf("Hai inserito: %s\n", stringa);
	
	if(AlmenoUnaMaiuscola(stringa, strlen(stringa))){
		printf("Esiste almeno una maiuscola nella stringa!\n");
		
	} else {
		printf("NON Esiste almeno una maiuscola nella stringa!\n");
	}
	
	return 0;
}
