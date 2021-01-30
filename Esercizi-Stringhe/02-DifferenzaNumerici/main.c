#include <stdio.h>
#include <stdlib.h>

int differenzaNumerici(char str[]){
	int conto=0;
	int massimo=-1;
	int i=0;
	while (str[i]!='\0'){
		if (str[i]>='0' && str[i]<='9')
			conto++;
		i++;
	}
	
	if (conto==0)
		return massimo;
	
	int numeroCorrente=0;
	int numeroVecchio=-1;
	int differenza=0;
	int j=0;
	
	while (str[j]!='\0'){
		if (str[j]>='0' && str[j]<='9'){
			numeroCorrente=str[j]-'0';
			if (numeroVecchio!=-1){
				if (numeroCorrente>numeroVecchio)
					differenza=numeroCorrente-numeroVecchio;
				else
					differenza=numeroVecchio-numeroCorrente;
				if (differenza>massimo)
					massimo=differenza;
			}
			numeroVecchio=numeroCorrente;
		}		
		j++;
	}
	
	return massimo;
}

int main(int argc, char **argv)
{
	printf("Questo programma calcola la differenza massima tra due elementi numerici della stringa.\n");
	printf("Immetti la tua stringa:\n");
	
	char stringa[50];
	fgets(stringa, 50, stdin);
	
	int i=0;
	while (stringa[i]!='\n'){
		i++;
	}
	stringa[i]='\0';
	
	if(differenzaNumerici(stringa)==-1)
		printf("Non ci sono interi da confrontare in questa stringa.");
	else
		printf("La differenza massima tra due interi %c %d\n", 138, differenzaNumerici(stringa));
	
	return 0;
}
