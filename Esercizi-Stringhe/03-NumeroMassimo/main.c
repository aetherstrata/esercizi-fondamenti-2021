#include <stdio.h>

int numeroMassimo(char str[])
{
	int massimo=-1;
	int valore=-1;
	
	for(int i=0; str[i]!='\0'; i++){
		if (str[i]>='0' && str[i]<='9'){
			if(valore==-1){
				valore=str[i]-'0';
			} 
			else {
				valore=valore*10+str[i]-'0';
			}
			if(valore>massimo)
				massimo=valore;
		} 
		else {
			valore=-1;
		}
	}
	
	return massimo;
}

void testNumeroMassimo()
{
	/* stringa con soli caratteri numerici */ 
	char stringa1[] = "12345"; 
	printf("Test numeroMassimo(\"12345\"): Atteso = 12345, Calcolato = %d \n", numeroMassimo(stringa1));
	/* stringa con soli caratteri alfabetici */ 
	char stringa2[] = "asdasd"; 
	printf("Test numeroMassimo(\"asdasd\"): Atteso = -1, Calcolato = %d \n", numeroMassimo(stringa2));
	/* stringa con massimo numerico all'inizio */ 
	char stringa3[] = "1234po45"; 
	printf("Test numeroMassimo(\"1234po45\"): Atteso = 1234, Calcolato = %d \n", numeroMassimo(stringa3));
	/* stringa con massimo numerico alla fine */ 
	char stringa4[] = "12gh345"; 
	printf("Test numeroMassimo(\"12gh345\"): Atteso = 345, Calcolato = %d \n", numeroMassimo(stringa4));
	/* stringa vuota */ 
	char stringa5[] = ""; 
	printf("Test numeroMassimo(\"\"): Atteso = -1, Calcolato = %d \n", numeroMassimo(stringa5));
}

int main(int argc, char **argv)
{
	printf("Questo programma restituisce il numero massimo contenuto nella stringa fornita.\n");
	printf("Immetti la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	printf("Il massimo numeico della stringa vale %d\n", numeroMassimo(stringa));
	
	testNumeroMassimo();
	
	return 0;
}
