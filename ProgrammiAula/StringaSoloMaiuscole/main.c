#include <stdio.h>
#include <strings.h>

void maiuscole(char* str)
{
	while(*str != '\0'){
		if(*str >= 'a' && *str <= 'z'){
			*str = *str + ('A'-'a');
		}
		str++;
	}

}

int main(int argc, char **argv)
{
	char stringa[50];
	
	printf("Introduci una stringa: ");
	fgets(stringa, 50, stdin);
	
	stringa[strlen(stringa)-1]='\0';
	
	printf("Stringa inserita: %s \n", stringa);
	
	maiuscole(stringa);
	printf("Stringa modificata: %s \n", stringa);
	
	return 0;
}
