#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", si verifica
 * se il successivo è pure lui interessante e quello dopo no. Se la verifica ha successo si cancella,
 * altrimenti si superano tutti i caratteri interessanti con un ciclo. Questa seconda operazione
 * è necessaria per evitare di cancellare gli ultimi due caratteri di una sequenza lunga più di due */

/* Funzione che riceve come parametro un carattere e restituisce 1 se il carattere
 * è numerico, 0 altrimenti */
int numerico(char c)
{
	int numero; //variabile di verifica
	numero = 0; //all'inizio consideriamo il carattere come non-numerico

	if(c>='0'&&c<='9') /* Il carattere è numerico? */
		numero = 1;

	return numero;
}

/* Funzione che riceve come parametro una stringa e la modifica rimuovendo ogni
 * sequenza di esattamente due caratteri numerici uguali consecutivi */
void cancellaDueNumericiUguali(char *stringa)
{
	int i; //variabile contatore per scorrere lungo la stringa
	i = 0;
	int fine; //variabile che stabilisce la fine del ciclo
	fine = strlen(stringa) - 2; //così arriviamo fino al terzultimo carattere (penultimo se escludiamo '\0' come carattere)

	while(i<=fine)
	{
		if(numerico(stringa[i])&&stringa[i]==stringa[i+1]) /* Il carattere attuale è numerico ed è uguale al carattere successivo? */
		{
			if(stringa[i]!=stringa[i+2]) //se abbiamo esattamente due caratteri uguali consecutivi, allora li cancelliamo
				for(int j=i; stringa[j]!='\0'; j++) //ciclo for per cancellare i due caratteri numerici identici
				{
					stringa[j+1]=stringa[j+2];
					stringa[j]=stringa[j+1];
				}	
			else //sennò andiamo avanti fino al carattere successivo diverso
				while(stringa[i]==stringa[i+1])
					i++;
		}
		else //sennò andiamo avanti
			i++;
	}
}

/* Funzione di test */
void testCancellaDueNumericiUguali()
{
	/* stringa vuota */
	char stringa1[] = "";
	cancellaDueNumericiUguali(stringa1);
	printf("Test cancellaDueNumericiUguali(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* stringa senza due caratteri numerici uguali */
	char stringa2[] = "12345";
	cancellaDueNumericiUguali(stringa2);
	printf("Test cancellaDueNumericiUguali(\"12345\"): Atteso = \"12345\", Calcolato = \"%s\" \n", stringa2);

	/* stringa con due caratteri numerici uguali solo all'inizio */
	char stringa3[] = "112345";
	cancellaDueNumericiUguali(stringa3);
	printf("Test cancellaDueNumericiUguali(\"112345\"): Atteso = \"2345\", Calcolato = \"%s\" \n", stringa3);

	/* stringa con due caratteri numerici uguali solo in mezzo */
	char stringa4[] = "123345";
	cancellaDueNumericiUguali(stringa4);
	printf("Test cancellaDueNumericiUguali(\"123345\"): Atteso = \"1245\", Calcolato = \"%s\" \n", stringa4);

	/* stringa con due caratteri numerici uguali solo alla fine */
	char stringa5[] = "123455";
	cancellaDueNumericiUguali(stringa5);
	printf("Test cancellaDueNumericiUguali(\"123455\"): Atteso = \"1234\", Calcolato = \"%s\" \n", stringa5);

	/* stringa con solo due caratteri numerici uguali*/
	char stringa6[] = "00";
	cancellaDueNumericiUguali(stringa6);
	printf("Test cancellaDueNumericiUguali(\"00\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa6);

	/* stringa con più di due caratteri numerici uguali*/
	char stringa7[] = "0000";
	cancellaDueNumericiUguali(stringa7);
	printf("Test cancellaDueNumericiUguali(\"0000\"): Atteso = \"0000\", Calcolato = \"%s\" \n", stringa7);

	/* stringa con sequenze di caratteri numerici uguali ma di lunghezze diverse */
	char stringa8[] = "1a22b333c4444d55555";
	cancellaDueNumericiUguali(stringa8);
	printf("Test cancellaDueNumericiUguali(\"1a22b333c4444d55555\"): Atteso = \"1ab333c4444d55555\", Calcolato = \"%s\" \n", stringa8);

	/* stringa normale */
	char stringa9[] = "003a6666b114c7777d225";
	cancellaDueNumericiUguali(stringa9);
	printf("Test cancellaDueNumericiUguali(\"003a6666b114c7777d225\"): Atteso = \"3a6666b4c7777d5\", Calcolato = \"%s\" \n", stringa9);
}

/* Funzione principale */
int main(int argc, char **argv)
{
	printf("Ciao utente! Sono un programma che legge una stringa e la modifica rimuovendo\n");
	printf("ogni sequenza di esattamente due caratteri numerici uguali consecutivi.\n\n");

	char stringa[50];

	/* INPUT */
	printf("Inserisci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimozione '\n' */
	stringa[strlen(stringa)-1]='\0';

	/* Invocazione funzione che modifica la stringa */
	cancellaDueNumericiUguali(stringa);

	/* OUTPUT */
	printf("Stringa modificata: %s\n\n", stringa);

	/* Invocazione funzione di test */
	testCancellaDueNumericiUguali();

	return 0;
}
