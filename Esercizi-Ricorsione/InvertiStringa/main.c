#include <stdio.h>
#include <string.h>

void cambiaCaratteri(char* string, int i, int len){
	if(len>i){
		char temp = string[i];
		string[i]=string[len];
		string[len]=temp;
		cambiaCaratteri(string, i+1, len-1);
	}
}

int main(int argc, char **argv)
{
	char stringa[50];
	printf("Inserisci una stringa da invertire: ");
	fgets(stringa, 50, stdin);
	stringa[strlen(stringa)-1]='\0';
	cambiaCaratteri(stringa, 0, strlen(stringa)-1);
	printf("%s\n",stringa);
	return 0;
}
