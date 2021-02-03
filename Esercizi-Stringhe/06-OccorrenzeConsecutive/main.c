#include <stdio.h>

void occorrenzeConsecutive(char str[])
{
	int i=0;
	int c;
	int massimo;
	char carattere;
	
	while(str[i]!='\0'){
		if (str[i]==str[i-1])
			c++;
		else
			c=1;
		
		if (c>massimo){
			carattere=str[i];
			massimo=c;
		}
		
		i++;
	}
	
	printf("Il carattere con il maggior numero di occorrenze consecutive %c '%c' che ha %d occorrenze consecutive!", 138, carattere, massimo);
}

void testOccorrenzeConsecutive()
{
	printf("\n");
	
	//Una sola ripetizione
	char stringa1[] = "aaaaa"; 
	printf("Test occorrenze(\"aaaaa\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive è 'a' che ha 5 occorrenze consecutive\", Calcolato = \""); 
	occorrenzeConsecutive(stringa1); 
	printf("\"\n\n");
	
	//Ripetizione più lunga a inizio stringa
	char stringa2[] = "aaabbaa"; 
	printf("Test occorrenze(\"aabbaaa\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive è 'a' che ha 3 occorrenze consecutive\", Calcolato = \""); 
	occorrenzeConsecutive(stringa2); 
	printf("\"\n\n");
	
	//Ripetizione più lunga a fine stringa
	char stringa3[] = "56665ysdii344!!!!"; 
	printf("Test occorrenze(\"56665ysdii344!!!!\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive è '!' che ha 4 occorrenze consecutive\", Calcolato = \""); 
	occorrenzeConsecutive(stringa3); 
	printf("\"\n\n");
	
	//Ripetizione in mezzo alla stringa
	char stringa4[] = "55ddsayyyy88"; 
	printf("Test occorrenze(\"55ddsayyyy88\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive è 'y' che ha 4 occorrenze consecutive\", Calcolato = \""); 
	occorrenzeConsecutive(stringa4); 
	printf("\"\n\n");
	
	//Ripetizione = 1
	char stringa5[] = "kikyo51"; 
	printf("Test occorrenze(\"55ddsayyyy88\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive è 'k' che ha 1 occorrenze consecutive\", Calcolato = \""); 
	occorrenzeConsecutive(stringa5); 
	printf("\"\n\n");
}

int main(int argc, char **argv)
{
	printf("Questo programma restituisce il valore con più ricorrenze consecutive nella stringa.\n");
	printf("Inserisci la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	int i = 0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	occorrenzeConsecutive(stringa);
	
	printf("\n");
	
	testOccorrenzeConsecutive();
	
	return 0;
}
