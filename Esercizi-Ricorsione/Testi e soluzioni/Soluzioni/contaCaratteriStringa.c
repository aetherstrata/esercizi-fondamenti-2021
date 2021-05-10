#include <stdio.h>
#include <string.h>

/* funzione che conta quante volte il carattere parametro compare nella 
 * stringa parametro a partire dall'indice parametro */
 int contaDaIndice(char *s, char c, int indice){
    int cont;		// il valore da restituire
	
	if (indice == strlen(s))
		/* l'indice è fuori dalla stringa */
		cont = 0;		
	else 
		/* confronta il carattere con indice parametro e ricorri sul resto della stringa */
		cont = (s[indice]==c) + contaDaIndice(s, c, indice+1);

	return cont;
}    
    
/* funzione che restituisce la lunghezza di una stringa: REALIZZAZIONE 2 */
int contaOccorrenze(char *s, char c) {
	 return contaDaIndice(s,c,0);
}


/* funzione principale */   
int main(){
	/* input */
	printf("Ciao, sono un programma che legge una stringa ed un carattere "); 
	printf("e determina il numero di occorrenze del carattere nella stringa.\n"); 
	char stringa[50];
	char carattere;
	
	printf("Introduci una bella stringa: ");
	fgets(stringa, 50, stdin);
	
	/* rimuovi \n */
	stringa[strlen(stringa)-1]='\0';
	
	printf("Introduci una bel carattere: ");
	carattere = fgetc(stdin);
	
	/* invoca la funzione contaOccorrenze e stampa il risultato */
	printf("La stringa contiene %d occorrenze del carattere!\n\n", contaOccorrenze(stringa, carattere));
}
