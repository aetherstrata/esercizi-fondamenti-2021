#include <stdio.h>
#include <string.h>

/* funzione che verifica se la stringa parametro è palindroma fra gli indici parametro */
int aux(char *s, int inf, int sup){
    int res; 		// il risultato da restituire
	
    if (inf>=sup) 
		/* sei rimasto con un carattere singolo o meno */
        res = 1; 
    else 
		/* hai ancora coppie di caratteri da verificare */
        res = (s[inf]==s[sup]) && aux(s,inf+1,sup-1);

  return res; 
}

/* funzione che verifica se la stringa parametro è palindroma: REALIZZAZIONE 2 */
int palindroma(char *s){
    return aux(s,0,strlen(s)-1);
}

/* funzione principale */
int main() {
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina se %c palindroma.\n",138); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione palindroma e stampo il risultato */
	if(palindroma(stringa))
		printf("La stringa %c palindroma!\n\n", 138);
	else
		printf("La stringa non %c palindroma!\n\n", 138);
}
