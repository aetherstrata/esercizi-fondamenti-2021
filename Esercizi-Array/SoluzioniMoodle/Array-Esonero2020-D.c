#include <stdio.h>
/* Data una sequenza di interi, verificare se per ogni tripla di elementi consecutivi
   la somma del primo e del secondo elemento della tripla sia uguale alla differenza
   tra il terzo e il secondo elemento della tripla  */
/*
 * SPECIFICA DEL PROBLEMA
 * INPUT : Una sequenza di interi e la sua dimensione.
 * PRE-CONDIZIONE : dimensione>=0
 * OUTPUT: Un intero verifica
 * POST-CONDIZIONE: verifica e' 1 se nella sequenza in ogni tripla di elementi la somma del primo e del
                    secondo elemento e' uguale alla differenza tra il terzo e il secondo
                    elemento, 0 altrimenti.
 *
 * TIPO DI PROBLEMA : Verifica universale.
 */

#include <stdio.h>

int verificaSuccessione(int array[],int lunghezza)
{
    int verifica=1;
    int i=0;

    while(i<lunghezza-2 && verifica)
        if (array[i]+array[i+1]!=array[i+2]-array[i+1])
            verifica=0;
        else
            i++;
    return verifica;
}

int main(int argc, char **argv)
{
	int dimensione;
    printf("Questo programma verifica se in una sequenza di interi, per ogni tripla,\n");
    printf("la somma dei primi due elementi %c uguale alla differenza del terzo per il primo.\n",138);
    printf("\nInserisci la dimensione dell'array: ");
    scanf("%d",&dimensione);
    int vettore[dimensione];

    printf("\nAdesso inseriamo gli elementi.\n");

    printf("-----------------------------\n");
    for(int i=0;i<dimensione;i++){
        printf("Elemento [%d] = ",i+1);
        scanf("%d", &vettore[i]);
    }

    printf("\n-----------------------------\n");
    if(verificaSuccessione(vettore,dimensione)){
        printf("\nNella sequenza, in ogni tripla, la somma dei primi due elementi\n");
        printf("%c uguale alla differenza tra il terzo e il secondo.\n\n",138);
    }
    else{
        printf("\nNella sequenza c'%c almeno una tripla in cui la somma dei primi due elementi\n",138);
        printf("non %c uguale alla differenza tra il terzo e il secondo.\n\n",138);
    }
}
