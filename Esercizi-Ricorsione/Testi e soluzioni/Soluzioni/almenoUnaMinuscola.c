#include <stdio.h>
#include <string.h>


/* funzione che verifica se la stringa parametro contiene almeno 
 * un carattere alfabetico minuscolo: REALIZZAZIONE 3 */
int minuscola(char *st1){
   int  esisteMinuscola; 		// il valore da restituire
   
   if (strlen(st1)==0) 
		/* non ci sono caratteri da verificare */
     esisteMinuscola=0;
   else 
		/* verifica il primo carattere e ricorri sul resto della stringa */
         esisteMinuscola= (st1[0]>='a' && st1[0]<='z') || minuscola(st1+1);

   return esisteMinuscola;
}

/* funzione principale */   
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa "); 
	printf("e determina se contiene almeno un carattere alfabetico minuscolo.\n"); 
	char stringa[50];
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	/* invoca la funzione minuscola e stampo il risultato */
	if(minuscola(stringa))
		printf("La stringa contiene un carattere alfabetico minuscolo!\n\n");
	else
		printf("La stringa non contiene un carattere alfabetico minuscolo!\n\n");
}
