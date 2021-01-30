#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", si verifica
 * se il successivo è pure lui interessante e quello dopo no. Se la verifica ha successo si cancella,
 * altrimenti si superano tutti i caratteri interessanti con un ciclo. Questa seconda operazione
 * è necessaria per evitare di cancellare gli ultimi due caratteri di una sequenza lunga più di due */

/* funzione che riceve come prametro una stringa e la modifica rimuovendo ogni sequenza
 * di esattamente due caratteri alfabetici consecutivi */
void viaParoleDaDue(char *stringa) {
    int i, j;           //contatori
    i = 0;
    /* vai avanti fino alla fine della stringa */
    while(stringa[i]!='\0') {
        /* se il carattere non è alfabetico vai avanti */
        if(!((stringa[i]>='a' && stringa[i]<='z')||(stringa[i]>='A' && stringa[i]<='Z')))
            i++;
        else {      //il carattere corrente è alfabetico
            /* hai esattamente due caratteri alfabetici consecutivi? */
            if(((stringa[i+1]>='a' && stringa[i+1]<='z')||(stringa[i+1]>='A' && stringa[i+1]<='Z')) && (!((stringa[i+2]>='a' && stringa[i+2]<='z')||(stringa[i+2]>='A' && stringa[i+2]<='Z')))) {
                /* devi cancellare i due caratteri alfabetici */
                for(j=i; stringa[j]|='\0'; j++)
                    stringa[j] = stringa[j+2];
            }
            else {      //hai più di due caratteri alfabetici consecutivi
                while(((stringa[i]>='a' && stringa[i]<='z')||(stringa[i]>='A' && stringa[i]<='Z')))
                    i++;            //passa al prossimo elemento
            }
        }
    }
}

/* funzione di test per viaParoleDaDue */
void testViaParoleDaDue() {

    /* stringa vuota */
    char stringa1[] = "";
    viaParoleDaDue(stringa1);
    printf("test viaParoleDaDue(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

    /* stringa senza sequenze di esattamente due caratteri alfabetici */
    char stringa2[] = "12abc34fgh";
    viaParoleDaDue(stringa2);
    printf("test viaParoleDaDue(\"12abc34fgh\"): Atteso = \"12abc34fgh\", Calcolato = \"%s\" \n", stringa2);

    /* stringa di esattamente due caratteri alfabetici */
    char stringa3[] = "ab";
    viaParoleDaDue(stringa3);
    printf("test viaParoleDaDue(\"ab\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa3);

    /* stringa con una sola sequenza di esattamente due caratteri alfabetici all'inizio */
    char stringa4[] = "ab123abc";
    viaParoleDaDue(stringa4);
    printf("test viaParoleDaDue(\"ab123abc\"): Atteso = \"123abc\", Calcolato = \"%s\" \n", stringa4);

    /* stringa con una sola sequenza di esattamente due caratteri alfabetici alla fine */
    char stringa5[] = "abc123ab";
    viaParoleDaDue(stringa5);
    printf("test viaParoleDaDue(\"abc123ab\"): Atteso = \"abc123\", Calcolato = \"%s\" \n", stringa5);

    /* stringa con una sola sequenza di esattamente due caratteri alfabetici al centro */
    char stringa6[] = "123ab4abc";
    viaParoleDaDue(stringa6);
    printf("test viaParoleDaDue(\"123ab4abc\"): Atteso = \"1234abc\", Calcolato = \"%s\" \n", stringa6);

    /* stringa normale con più sequenze di esattamente due caratteri alfabetci */
    char stringa7[] = "abc4ab45de6g;ju";
    viaParoleDaDue(stringa7);
    printf("test viaParoleDaDue(\"abc4ab45de6g;ju\"): Atteso = \"abc4456g;\", Calcolato = \"%s\" \n", stringa7);
}

/* funzione principale */
int main(int argc, char **argv)
{
	/* input */
    printf("Ciao utente, sono un programma che legge una stringa e la modifica rimuovendo\n");
    printf("ogni sequenza di esattamente due caratteri alfabetici consecutivi\n\n");
    char stringa[50];
    printf("Introduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';

    /* invoca la funzione viaParoleDaDue */
    viaParoleDaDue(stringa);

    /* output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);

    /* fai partire il test */
    testViaParoleDaDue();
}
