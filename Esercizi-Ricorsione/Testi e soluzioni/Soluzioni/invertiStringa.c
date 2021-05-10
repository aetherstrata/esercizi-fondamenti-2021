#include <stdio.h>
#include <string.h>

/* funzione che inverte una stringa fra gli indici parametro */
void aux(char *st1, int i,int j){
    char app;		// carattere di appoggio

    if (i<j) {
		/* ci sono caratteri da invertire: scambia quelli con indici i e j */
        app = st1[i];
        st1[i]=st1[j];
        st1[j]=app;   
        aux(st1,i+1,j-1);
    }  
	/* Il caso base è "non fare niente" quando non ci sono più caratteri da invertire */
}

/* funzione che inverte una stringa: REALIZZAZIONE 2 */
void inverti(char *st1){
     aux(st1,0,strlen(st1)-1); 
}

/* funzione principale */
int main(){

	/* INPUT */
	char stringa[50];
    printf("Ciao, io inverto stringhe. Dammene una please.\n");
    fgets(stringa,50,stdin);
	
	/* fine stringa al posto del carattere di ritorno a capo */
	stringa[strlen(stringa)-1]='\0';

	/* inverti la stringa */
	inverti(stringa);

	/* OUTPUT */
	printf("Ecco la stringa inversa: %s \n", stringa);

}



