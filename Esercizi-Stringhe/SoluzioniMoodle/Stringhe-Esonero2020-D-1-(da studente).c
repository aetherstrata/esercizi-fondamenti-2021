#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trovano due caratteri "interessanti", un ciclo
 * interno permette di superare tutti i caratteri interessanti consecutivi. Se alla fine di
 * questo ciclo sei a due distanza da dove sei partito, allora la sequenza di caratteri interessanti 
 * è lunga due e viene cancellata, altrimenti il contatore principale viene aggiornato */ 
 
/*Funzione che cancella l'elemento della stringa parametro all'indice
 * index e il suo successivo*/
void cancellaConSucc(char str[], int index) {
	int volte;		//ho rimosso per 0 volte
	int j;			//contatore

	/*devo implementare un algoritmo di cancellazione per due volte sullo stesso indice*/
	for(volte=0; volte<2; volte++) {
		j=index;
		while(str[j]!='\0') {
			str[j]=str[j+1];
			j++;
		}
	}
}


/* Funzione che modifica la stringa parametro cancellando ogni sequenza di esattamente
 * due carattere alfabetici minuscoli */
void cancellaDueMinUguali(char str[]) {
	//pre: nessuna
	int i=0;			//var contatore
	int j=0;				//var per verifica di quanti minuscoli consecutivi ho

	/*accedo a tutti gli elementi della stringa  */
	while(str[i]!='\0') {

		/*verifico se il successivo dell'elemento corrente è
		 * uguale all'elemento corrente ed è minuscolo*/
		if(str[i]!=str[i+1] || !(str[i]>='a' && str[i]<='z'))
			/*se diverso o se il carattere considerato non è un alfabetico
			 * minuscolo, passo al prossimo elemento*/
			i++;
		else {
			/*se uguali e minuscoli, verifico se ho altri elementi consecutivi
			 * uguali o se ne ho esattamente due*/
			 /*inizializzo j a i+2, ovvero all'elemento due posizioni successibùvo
			  * l'elemento corrente*/
			j=i+2;
			/*vado avanti finchè non ne incontro uno diverso*/
			while(str[i]==str[j])
				j++;
			/*se j=i+2, non è stato eseguito il corpo del while e allora il secondo elemento dopo
			 * l'elemento corrente non gli è uguale; ho esattamente due uguali*/
			if(j==i+2)
				cancellaConSucc(str, i);		//elimino l'elemento corrente e il suo successivo
			else
				/*allora ho più di due minuscoli uguali, non elimino e vado a
				 * considerare la stringa dall'indice dopo la sequenza di uguali*/
				 i=j;

		}
	}
}

/*Funzione di test per cancellaDueMinUguali*/
void testCancellaDueMinUguali() {
	/*stringa vuota*/
	char test1[]="";
	cancellaDueMinUguali(test1);
	printf("Test cancellaDueMinUguali(\"\"): atteso:\"\", calcolato:\"%s\";\n", test1);

	/*stringa con un solo carattere*/
	char test2[]="a";
	cancellaDueMinUguali(test2);
	printf("Test cancellaDueMinUguali(\"a\"): atteso:\"a\", calcolato:\"%s\";\n", test2);

	/*stringa con esattamente due caratteri minuscoli*/
	char test3[]="aa";
	cancellaDueMinUguali(test3);
	printf("Test cancellaDueMinUguali(\"aa\"): atteso:\"\", calcolato:\"%s\";\n", test3);

	/*str con esattamente due minuscoli all'inizio*/
	char test4[]="aa123";
	cancellaDueMinUguali(test4);
	printf("Test cancellaDueMinUguali(\"aa123\"): atteso:\"123\", calcolato:\"%s\";\n", test4);

	/*str con esattamente due minuscoli alla fine*/
	char test5[]="123eraa";
	cancellaDueMinUguali(test5);
	printf("Test cancellaDueMinUguali(\"123eraa\"): atteso:\"123er\", calcolato:\"%s\";\n", test5);

	/*str con esattamente due minuscoli in mezzo*/
	char test6[]="asdffg";
	cancellaDueMinUguali(test6);
	printf("Test cancellaDueMinUguali(\"asdffg\"): atteso:\"asdg\", calcolato:\"%s\";\n", test6);

	/*str con ripetizioni di pìù di due minuscoli*/
	char test7[]="+eeeeee5";
	cancellaDueMinUguali(test7);
	printf("Test cancellaDueMinUguali(\"\"): atteso:\"+eeeeee5\", calcolato:\"%s\";\n", test7);

	/*str senza eliminazioni*/
	char test8[]="afde54";
	cancellaDueMinUguali(test8);
	printf("Test cancellaDueMinUguali(\"afde54\"): atteso:\"afde54\", calcolato:\"%s\";\n", test8);

	/*istanza normale*/
	char test9[]="asdffghhhjjk";
	cancellaDueMinUguali(test9);
	printf("Test cancellaDueMinUguali(\"asdffghhhjjk\"): atteso:\"asdghhhk\", calcolato:\"%s\";\n", test9);


}

int main(int argc, char **argv)
{
	char stringa[50];

	/*Input*/
	printf("Ciao utente, sono un programma che data una stringa rimuove ogni sequenza di esattamente due minuscoli consecutivi.\n"
	"Inserisci una stringa: ");
	fgets(stringa, 50, stdin);
	/*Elimino lo \n se presente*/
	if(stringa[strlen(stringa)-1]=='\n')
		stringa[strlen(stringa)-1]='\0';

	/*Output*/
	cancellaDueMinUguali(stringa);
	printf("La tua nuova stringa %c %s.\n", 138, stringa);

	/*Test*/
	testCancellaDueMinUguali();
}
