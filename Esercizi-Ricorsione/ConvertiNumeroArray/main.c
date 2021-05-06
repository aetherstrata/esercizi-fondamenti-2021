#include <stdio.h>

int ContaCifre(int n)
{
	int cifre;
	
	if(n/10==0){
		cifre=1;
	} else {
		cifre = 1+ContaCifre(n/10);
	}
	
	return cifre;
}

void ConvertiNumeroStringa(int* array, int len, int n)
{
	if(len==0){
		array[0]=n;
	} else {
		array[len]=n%10;
		ConvertiNumeroStringa(array, len-1, n/10);
	}
}

int main(int argc, char **argv)
{
	int n;
	printf("Inserisci un numero: \n");
	scanf("%d", &n);
	
	int len = ContaCifre(n);
	
	int array[len];
	
	ConvertiNumeroStringa(array, len-1, n);
	
	return 0;
}
