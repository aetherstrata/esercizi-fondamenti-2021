#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione si cerca una sequenza di esattamente due caratteri "interessanti";
 * questo richiede di distinguere il caso in cui il contatore i è 0 da quello in cui il contatore è >0
 * perchè nel primo caso non si può accedere all'elemento con indice i-1 */
 
/*funzione che riceve una stringa e la modifica rimuovendo ogni sequenza di esattamente due caratteri numerici consecutivi*/
void nienteNumeriDueCifre(char *stringa) {
    int i, j;  //contatori
    i=0;
    /*continuo fino alla fine della stringa*/
    while(stringa[i]!='\0') {
        /*se l'indice Ã¨ diverso da 0, ho due caratteri consecutivi numerici e il carattere precedente ed il successivo alla coppia non sono numerici, elimino i due caratteri consecutivi numerici*/
        if(i!=0 && (stringa[i]>='0' && stringa[i]<='9') && (stringa[i+1]>='0' && stringa[i+1]<='9')
        && (!(stringa[i+2]>='0' && stringa[i+2]<='9')) && (!(stringa[i-1]>='0' && stringa[i-1]<='9'))) {
            for(j=i; stringa[j]!='\0'; j++)
                stringa[j]=stringa[j+2]; //elimino i caratteri copiando tutta la stringa due indici indietro
        }
        else { /*se l'indice Ã¨ uguale a 0, ho due caratteri consecutivi numerici e il carattere precedente ed il successivo alla coppia non sono numerici, elimino i due caratteri consecutivi numerici*/
            if (i==0 && (stringa[i]>='0' && stringa[i]<='9') && (stringa[i+1]>='0' && stringa[i+1]<='9') && (!(stringa[i+2]>='0' && stringa[i+2]<='9'))) {
                for(j=i; stringa[j]!='\0'; j++)
                    stringa[j]=stringa[j+2]; //elimino i caratteri copiando tutta la stringa due indici indietro
            }
            else
                i++; //se non ho due caratteri numerici consecutivi seguiti e preceduti da caratteri non numerici, vado al prossimo elemento

        }
    }
}

/*TEST*/
void testNienteNumeriDueCifre() {
    /*stringa nulla*/
    char stringa1[]="";
    nienteNumeriDueCifre(stringa1);
    printf("Test nienteNumeriDueCifre(\"\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa1);
    /*stringa senza caratterici numerici*/
    char stringa2[]="abcd";
    nienteNumeriDueCifre(stringa2);
    printf("Test nienteNumeriDueCifre(\"abcd\"): Atteso=\"abcd\", Calcolato=\"%s\" \n", stringa2);
    /*stringa con un solo carattere numerico*/
    char stringa3[]="1";
    nienteNumeriDueCifre(stringa3);
    printf("Test nienteNumeriDueCifre(\"1\"): Atteso=\"1\", Calcolato=\"%s\" \n", stringa3);
    /*stringa con due caratteri numerici*/
    char stringa4[]="12";
    nienteNumeriDueCifre(stringa4);
    printf("Test nienteNumeriDueCifre(\"12\"): Atteso=\"\", Calcolato=\"%s\" \n", stringa4);
    /*stringa con tre caratteri numerici*/
    char stringa5[]="123";
    nienteNumeriDueCifre(stringa5);
    printf("Test nienteNumeriDueCifre(\"123\"): Atteso=\"123\", Calcolato=\"%s\" \n", stringa5);
    /*stringa con due caratteri numerici all'inizio*/
    char stringa6[]="12abc";
    nienteNumeriDueCifre(stringa6);
    printf("Test nienteNumeriDueCifre(\"12abc\"): Atteso=\"abc\", Calcolato=\"%s\" \n", stringa6);
    /*stringa con due caratteri numerici alla fine*/
    char stringa7[]="abc12";
    nienteNumeriDueCifre(stringa7);
    printf("Test nienteNumeriDueCifre(\"abc12\"): Atteso=\"abc\", Calcolato=\"%s\" \n", stringa7);
    /*stringa generale*/
    char stringa8[]="12ab123fg67xyh2iu09";
    nienteNumeriDueCifre(stringa8);
    printf("Test nienteNumeriDueCifre(\"12ab123fg67xyh2iu09\"): Atteso=\"ab123fgxyh2iu\", Calcolato=\"%s\" \n", stringa8);

}

/*FUNZIONE PRINCIPALE*/
int main() {
    /*Input*/
    char stringa[50];
    printf("Benvenuto utente!\n");
    printf("Questo programma modifica una stringa rimuovendo ogni sequenza di esattamente due caratteri numerici consecutivi.\n");
    printf("Inserisci la stringa:\n");
    fgets(stringa, 50, stdin);

    /*rimuovo '\n'*/
    stringa[strlen(stringa)-1]='\0';

    /*Invocazione funzione di modifica*/
    nienteNumeriDueCifre(stringa);
    /*Stampa stringa modificata*/
    printf("La nuova stringa %c '%s'\n", 138, stringa);

    /*Invocazione funzione test*/
    testNienteNumeriDueCifre();
}
