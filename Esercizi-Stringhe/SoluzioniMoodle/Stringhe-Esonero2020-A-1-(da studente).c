#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", un ciclo
 * interno permette di contare quanti caratteri interessanti consecutivi ci sono; parallelamente
 * viene incrementato il contatore principale, per superare la sequenza di caratteri interessanti 
 * Se questa era lunga due, viene quindi cancellata */

/* funzione che cancella un carattere copiando tutti i caratteri nella posizione precedente */
void shift(char *stringa, int i){
    while(stringa[i]!='\0'){
        stringa[i]=stringa[i+1];
        i++;
    }
}

/* funzione per cancellare le sequenze di due caratteri alfabetici da una stringa */
void viaParoleDaDue(char *stringa){
    int i=0;
    int c=0;//contatore per le lettere alfabetiche

    /* ciclo che viene esegiuito fino alla fine della stringa */
    while(stringa[i]!='\0'){
        /* se trovo un carattere alfabetico */
        if((stringa[i]>='a' && stringa[i]<='z') || (stringa[i]>='A' && stringa[i]<='Z')) {
            /* conto quanti caratteri alfabetici trovo, scorrendo anche il contatore principale */
            while((stringa[i]>='a' && stringa[i]<='z') || (stringa[i]>='A' && stringa[i]<='Z')){
                i++;
                c++;
            }

            /* e ho trovato solo 2 caratteri alfabetici, li cancello */
             if(c==2){
                for(int j=0; j<2; j++){
                    shift(stringa,i-2); //cancello i caratteri
                }
             }
            c=0; //resetto il contatore
        }
        else
            i++;
    }
}

void testViaParoleDaDue (){
    /*stringa vuota*/
    char stringa1[]="";
    viaParoleDaDue(stringa1);
    printf("Test viaParoleDaDue(\"\"): Atteso=\"\", calcolato=\"%s\" \n", stringa1);
    /*stringa senza caratteri alfabetici doppi*/
    char stringa2[]="abc56fghi";
    viaParoleDaDue(stringa2);
    printf("Test viaParoleDaDue(\"abc56fghi\"): Atteso=\"abc56fghi\", calcolato=\"%s\" \n", stringa2);
    /*stringa con solo due caratteri alfabetici*/
    char stringa3[]="ab";
    viaParoleDaDue(stringa3);
    printf("Test viaParoleDaDue(\"ab\"): Atteso=\"\", calcolato=\"%s\" \n", stringa3);
    /*stringa con solo una sequenza di due caratteri alfabetici all'inizio*/
    char stringa4[]="ab56tryu";
    viaParoleDaDue(stringa4);
    printf("Test viaParoleDaDue(\"ab56tryu\"): Atteso=\"56tryu\", calcolato=\"%s\" \n", stringa4);
    /*stringa con solo una sequenza di due caratteri alfabetici alla fine*/
    char stringa5[]="abcd56tr";
    viaParoleDaDue(stringa5);
    printf("Test viaParoleDaDue(\"abcd56tr\"): Atteso=\"abcd56\", calcolato=\"%s\" \n", stringa5);
    /*stringa con solo una sequenza di due caratteri alfabetici al centro*/
    char stringa6[]="abcd56ef89ghi";
    viaParoleDaDue(stringa6);
    printf("Test viaParoleDaDue(\"abcd56ef89ghi\"): Atteso=\"abcd5689ghi\", calcolato=\"%s\" \n", stringa6);
    /*stringa normale*/
    char stringa7[]="ab12cde56ee78a67bb";
    viaParoleDaDue(stringa7);
    printf("Test viaParoleDaDue(\"ab12cde56ee78a67bb\"): Atteso=\"12cde5678a67\", calcolato=\"%s\" \n", stringa7);

}

int main(){
    /*input*/
    char stringa[50];
    printf("Ciao utente inserisci una stringa e io la modifico eliminando tutte le sequenze di due carratteri alfabetici consecutivi: ");
    fgets(stringa,50,stdin);
    stringa[strlen(stringa)-1]='\0';
    /*outpu*/
    viaParoleDaDue(stringa);
    printf("Ecco la tua stringa modificata: %s\n", stringa);
    testViaParoleDaDue();
}
