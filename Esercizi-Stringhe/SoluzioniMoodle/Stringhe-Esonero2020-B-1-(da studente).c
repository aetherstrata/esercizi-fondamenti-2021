#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", un ciclo
 * interno permette di contare quanti caratteri interessanti consecutivi ci sono. Se sono due
 * questi vengono cancellati, altrimenti la sequenza di caratteri interessanti viene superata
 * con un opportuno incremento del contatore principale */ 
 
/*funzione che riceve in input una stringa e la modifica togliendo
 * le sequenze di esattamente due caratteri numerici consecutivi uguali*/
void cancellaDueNumericiUguali(char *stringa){
    int conteggio;
    /*cotrollo tutta la stringa*/
    int i=0;
    while(stringa[i]!='\0'){
        if(stringa[i]>='0' && stringa[i]<='9'){             //se il carattere è numerico

			/* conta quanti caratteri uguali trovi */
            conteggio=0;
            for(int j=i; stringa[j]==stringa[i]; j++)       
                conteggio++;

            /*se ne ho trovati esattamente 2 uguali li cancello*/
            if(conteggio==2)
                for(int k=i; k<strlen(stringa)-1; k++)      
                    stringa[k]=stringa[k+2];

            /*altrimenti vado avanti, superando la sequenza di caratteri uguali */
            else
                i=i+conteggio;
        }
        else                                                //se il carattere non Ã¨ numerico controllo quello successivo
            i++;
    }
}


/*funzione di test*/
void testCancellaDueNumericiUguali(){
    /*stringa vuota*/
    char stringa1[]="";
    cancellaDueNumericiUguali(stringa1);
    printf("test cancellaDueNumericiUguali(\"\")\n atteso:\"\",  effettivo:\"%s\"\n\n", stringa1);

    /*stringa con solo non numerici*/
    char stringa2[]="abcd";
    cancellaDueNumericiUguali(stringa2);
    printf("test cancellaDueNumericiUguali(\"abcd\")\n atteso:\"abcd\",  effettivo:\"%s\"\n\n", stringa2);

    /*stringa con una sola coppia di numerici uguali, all'inizio*/
    char stringa3[]="22abcd";
    cancellaDueNumericiUguali(stringa3);
    printf("test cancellaDueNumericiUguali(\"22abcd\")\n atteso:\"abcd\",  effettivo:\"%s\"\n\n", stringa3);

    /*stringa con una sola coppia di numerici uguali, alla fine*/
    char stringa4[]="abcd33";
    cancellaDueNumericiUguali(stringa4);
    printf("test cancellaDueNumericiUguali(\"abcd33\")\n atteso:\"abcd\",  effettivo:\"%s\"\n\n", stringa4);

    /*stringa con una tripla di numerici consecutivi uguali*/
    char stringa5[]="abc444de";
    cancellaDueNumericiUguali(stringa5);
    printf("test cancellaDueNumericiUguali(\"abc444de\")\n atteso:\"abcde\",  effettivo:\"%s\"\n\n", stringa5);

    /*utilizzo normale della funzione*/
    char stringa6[]="12ab33c2d444422";
    cancellaDueNumericiUguali(stringa6);
    printf("test cancellaDueNumericiUguali(\"12ab33c2d444422\")\n atteso:\"12abc2d4444\",  effettivo:\"%s\"\n\n", stringa6);
}

/*funzione main*/
int main(){
    char stringa[50];
    /*input*/
    printf("caro utente inserire una stringa di massimo 50 caratteri:  ");
    fgets(stringa, 50, stdin);
    /*tolgo il carattere '\n'*/
    stringa[strlen(stringa)-1]='\0';

    /*invoco la funzione cancellaDueNumericiUguali*/
    cancellaDueNumericiUguali(stringa);
    /*output*/
    printf("la stringa inserita senza le sequenze di esattamente due caratteri numerici consecutivi uguali %c: %s\n\n", 138, stringa);

    /*richiamo la funzione di test*/
    testCancellaDueNumericiUguali();
}

