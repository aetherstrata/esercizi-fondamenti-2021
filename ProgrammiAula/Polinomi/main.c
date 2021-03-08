#include <stdio.h>

float potenza(float base, int exp)
{
	float risultato;
	
	if (exp==0){
		risultato = 1;
	} else {
		risultato = base * potenza(base, exp-1);
	}
	
	return risultato;
}

float polinomio(float coefficienti[], int grado, int x)
{
	float risultato;
	
	if (grado == 0){
		risultato = coefficienti[0];
	} else {
		risultato = potenza(coefficienti[grado], grado) * x + polinomio(coefficienti, grado-1, x);
	}
	
	return risultato;
}

int main(int argc, char **argv)
{
	int grado;
	
	printf("Questo programma legge i coefficienti di un polinomio in una variabile e calcola il valore del polinomio per un certo valore della variabile.\n");
	printf("Dio che grado %c il polinomio? ", 138);
	scanf("%d", &grado);
	
	float coefficienti[grado];
	
	for(int i=0; i<grado; i++){
		printf("Quanto vale il coefficiente di grado %d? ", i);
		scanf("%f", &coefficienti[i]);
	}
	
	int variabile;
	
	printf("Quale valore vuoi dare alla variabile? ");
	scanf("%d", &variabile);
	
	printf("Il polinomio vale: %f", polinomio(coefficienti, grado, variabile));
	
	return 0;
}
