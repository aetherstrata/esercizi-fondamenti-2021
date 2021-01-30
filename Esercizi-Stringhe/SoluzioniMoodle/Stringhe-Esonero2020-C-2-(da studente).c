#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trovano due caratteri "interessanti", si verifica
 * se il terzo carattere è interessante, nel qual caso la sequenza è lunga più di due ed i 
 * caratteri interessanti vengono superati con un ciclo, oppure se è lunga esattamente due, 
 * nel qual caso i caratteri interessanti vengono cancellati */
 
/* Funzione che riceve come parametri una stringa, restituisce una stringa dalla quale sono stati eliminati tutti i numeri che si presentano
 * esattamente due volte consecutivamente */
void nienteNumeriDueCifre(char *stringa) {
    /* Ciclo che elimina esclusivamente due caratteri numerici che si presentano consecutivamente */
    int i = 0;
    if(!(stringa[i] == '\0')) { // se la stringa non è vuota allora viene analizzata
        while(i < strlen(stringa) - 1) { // analizzo gli elementi fino al penultimo carattere prima del carattere '\0'
        /* Ci sono due caratteri nuemrici consecutivi? */
            if((stringa[i] >= '0' && stringa[i] <= '9') && (stringa[i + 1] >= '0' && stringa[i + 1] <= '9')) {
                /* Questi due numeri sono seguiti da altri numeri? */
                if(stringa[i + 2] >= '0' && stringa[i + 2] <= '9') {
                    i = i + 2; // allora non devo canellarli, quindi posso passare al terzo elemento
                    /* Ci sono altri numeri dopo il terzo numero */
                    while(stringa[i] >= '0' && stringa[i] <= '9')
                        i++; // vado avanti finchè il carattere con indice i non è un numero
                }
                /* Ci sono solo due numeri? */
                else {
                    /* Ciclo per eliminare il primo numero */
                    for(int j = i; stringa[j] != '\0'; j++)
                        stringa[j] = stringa[j + 1];
                    /* Ciclo per eliminare il secondo numero */
                    for(int j = i; stringa[j] != '\0'; j++)
                        stringa[j] = stringa[j + 1];
                    /* La stringa è vuota? */
                }
            }
            /* I due caratteri presi in considerazione nell'if non sono tutti e due numeri? */
            else
                i++;
        }
    }
}

/* Funzione test */
void testNienteNumeriDueCifre() {
    /* Stringa vuota */
    char stringa0[] = "";
    nienteNumeriDueCifre(stringa0);
    printf("TestNienteNumeriDueCifre: (); Atteso: (); Calcolato: (%s);\n", stringa0);
    /* Stringa con solo due numeri */
    char stringa1[] = "12";
    nienteNumeriDueCifre(stringa1);
    printf("TestNienteNumeriDueCifre: (12); Atteso: (); Calcolato: (%s);\n", stringa1);
     /* Stringa senza caratteri numerici */
    char stringa2[] = "abcdef";
    nienteNumeriDueCifre(stringa2);
    printf("TestNienteNumeriDueCifre: (abcdef); Atteso: (abcdef); Calcolato: (%s);\n", stringa2);
    /* Stringa con solo caratteri numerici */
    char stringa3[] = "12345";
    nienteNumeriDueCifre(stringa3);
    printf("TestNienteNumeriDueCifre: (12345); Atteso: (12345); Calcolato: (%s);\n", stringa3);
    /* Stringa con due numeri all'inizio, e caratteri non numerici dopo */
    char stringa4[] = "12abcd";
    nienteNumeriDueCifre(stringa4);
    printf("TestNienteNumeriDueCifre: (12abcd); Atteso: (abcd); Calcolato: (%s);\n", stringa4);
    /* Stringa con caratteri non numerici all'inizio, e due caratteri numerici alla fine */
    char stringa5[] = "abcd12";
    nienteNumeriDueCifre(stringa5);
    printf("TestNienteNumeriDueCifre: (abcd12); Atteso: (abcd); Calcolato: (%s);\n", stringa5);
    /* Stringa con coppie di caratteri numerici intervallate da caratteri non numerici */
    char stringa6[] = "12a12a12a12a";
    nienteNumeriDueCifre(stringa6);
    printf("TestNienteNumeriDueCifre: (12a12a12a12a); Atteso: (aaaa); Calcolato: (%s);\n", stringa6);
    /* Stringa con triple di tre numeri intervallate da caratteri non numerici */
    char stringa7[] = "123a123a123a123a123";
    nienteNumeriDueCifre(stringa7);
    printf("TestNienteNumeriDueCifre: (123a123a123a123a123); Atteso: (123a123a123a123a123); Calcolato: (%s);\n", stringa7);
    /* Stringa casuale */
    char stringa8[] = "abc12def3abc4d1w23de678  21waql9p0";
    nienteNumeriDueCifre(stringa8);
    printf("TestNienteNumeriDueCifre: (abc12def3abc4d1w23de678  21waql9p0); Atteso: (abcdef3abc4d1wde678  waqp0); Calcolato: (%s);\n", stringa8);
}

int main() {
	printf("Inserisci una stringa: ");
    char stringa[50];
    fgets(stringa, 50, stdin);
    stringa[strlen(stringa) - 1] = '\0'; // elimino il carattere newline
    nienteNumeriDueCifre(stringa);
    printf("Stringa modificata: %s\n", stringa);
    testNienteNumeriDueCifre();
}
