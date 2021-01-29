#include <stdio.h>

//Calcola il GCD tra due numer interi
int Mcd(int a, int b)
{
	//pre: a,b > 0
	int risultato;
	
	if (a<b)
		risultato = a;
	else
		risultato = b;
	
	while (a%risultato !=0 || b%risultato !=0)
		risultato--;
	
	return risultato;
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
