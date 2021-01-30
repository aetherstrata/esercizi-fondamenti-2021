#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione un ciclo interno permette di contare quanti caratteri 
 * interessanti consecutivi ci sono. Se sono due questi vengono cancellati, altrimenti la 
 * sequenza di caratteri interessanti viene superata con un opportuno incremento del 
 * contatore principale */ 

/* funzione che riceve come parametro una stringa
 * e rimuove dall astringa ogni sequenza di esattamente due
 * caratteri alfabetici minuscoli uguali consecutivi
 */
void cancellaDueMinuscoliUguali(char stringa[]){
	int len=strlen(stringa);
	int cont=1;				//contaotre delle lettere uguali
	int i=0, j=0, k=0;		//contatori
	while(stringa[i]!='\0'){
		cont=1;
		/*verifico che l'elemento sia un carattere alfabetico minuscolo*/
		if(stringa[i]<='z' && stringa[i]>='a'){
			/*conto quanti caratteri alfabetici uguali lo seguono*/
			j=i+1;
			while(stringa[j]==stringa[i]){
				cont++;
				j++;
			}
			/*se sono esattamente due li rimuovo*/
			if(cont==2){
				k=i+2;
				while(k<len+1){
					stringa[k-2]=stringa[k];
					k++;
				}
			}
		}
		/*se sono più di due lettere vado al carattere successivo all'ultima*/
		if(cont>2){
			i=i+(cont);
		}else if(cont<2){
			i++;
		}
	}
}

/*funzione di test*/
void testCancellaDueMinuscoliUguali(){
	/*stringa vuota*/
	char stringa1[]="";
	cancellaDueMinuscoliUguali(stringa1);
	printf("Test cancellaDueMinuscoliUguali(''): Atteso = '' , Calcolato = '%s' \n", stringa1);

	/*stringa con una sola coppia di caratteri uguali al centro*/
	char stringa2[]="12aa34bbbb";
	cancellaDueMinuscoliUguali(stringa2);
	printf("Test cancellaDueMinuscoliUguali('12aa34bbbb'): Atteso = '1234bbbb' , Calcolato = '%s' \n", stringa2);

	/*stringa con due coppie di caratteri uguali*/
	char stringa3[]="7aa123bbb44ds4tgghr12k";
	cancellaDueMinuscoliUguali(stringa3);
	printf("Test cancellaDueMinuscoliUguali('7aa123bbb44ds4tgghr12k'): Atteso = '7123bbb44ds4thr12k' , Calcolato = '%s' \n", stringa3);

	/*stringa con una coppia di caratteri uguali all'inizio*/
	char stringa4[]="aa34bbbb";
	cancellaDueMinuscoliUguali(stringa4);
	printf("Test cancellaDueMinuscoliUguali('aa34bbbb'): Atteso = '34bbbb' , Calcolato = '%s' \n", stringa4);

	/*stringa con una coppia di caratteri uguali alla fine*/
	char stringa5[]="aaa12bb";
	cancellaDueMinuscoliUguali(stringa5);
	printf("Test cancellaDueMinuscoliUguali('aaa12bb'): Atteso = 'aaa12' , Calcolato = '%s' \n", stringa5);

	/*stringa con tre coppie di caratteri uguali*/
	char stringa6[]="aabbcc";
	cancellaDueMinuscoliUguali(stringa6);
	printf("Test cancellaDueMinuscoliUguali('aabbcc'): Atteso = '' , Calcolato = '%s' \n", stringa6);
}

/*funzione principale*/
int main(int argc, char **argv)
{
	printf("Questo programma rimuove dall astringa ogni sequenza di esattamente due caratteri alfabetici minuscoli uguali consecutivi\n");
	/*INPUT*/
	char stringa[50];
	printf("Inserisci la tua stringa\n");
	fgets(stringa,50,stdin);
	/*rimozione del \n*/
	stringa[strlen(stringa)-1]='\0';
	/*richiamo della funzione*/
	cancellaDueMinuscoliUguali(stringa);
	/*OUTPUT*/
	printf("La stringa modificata %c %s\n",138, stringa);
	testCancellaDueMinuscoliUguali();
}
