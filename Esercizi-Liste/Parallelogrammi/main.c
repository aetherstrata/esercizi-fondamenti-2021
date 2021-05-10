#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struttura del tipo Punto
typedef struct Punto {
	float x;
	float y;
} Point;

// Struttura del tipo Parallelogramma
typedef struct VettoreParallelogramma {
	Point bs;
	Point ad;
	float b;
} VectorSet;

/* * * * * * * * * * * * * * * * * */
/* *Funzioni geometriche * * * * * */
/* * * * * * * * * * * * * * * * * */

float Altezza(VectorSet para) 
{
	float h = para.ad.y - para.bs.y;
	return h;
}

float LatoObliquo(VectorSet para)
{
	float lato = sqrt( pow((para.ad.x-para.bs.x-para.b),2) + pow(Altezza(para),2) );
	return lato;
}

float Perimetro(VectorSet para)
{
	int perimetro = LatoObliquo(para)*2 + para.b*2;
	return perimetro;
}

float Area(VectorSet para)
{
	float area = para.b * Altezza(para);
	return area;
}

int isRettangolo (VectorSet para)
{
	int result = 0;
	
	if ((para.ad.x-para.b) == para.bs.x)
		result = 1;
	
	return result;
}

/* * * * * * * * * * * * * * * */
/* * * FUNZIONI DI STAMPA * * */
/* * * * * * * * * * * * * * */

void stampaPunto(Point p)
{
	printf("(%.2f , %.2f)\n", p.x, p.y);
}

void stampaVettoreParallelogramma(VectorSet para)
{
	printf("Il vertice bs ha coordinate: ");
	stampaPunto(para.bs);
	printf("Il vertice ad ha coordinate: ");
	stampaPunto(para.ad);
	printf("La lunghezza della base vale %.2f\n", para.b);
	printf("Il perimetro del parallelogramma vale %.2f\n", Perimetro(para));
	printf("L'area del parallelogramma vale %.2f\n", Area(para));
	if (isRettangolo(para))
		printf("Questo parallelogramma %c rettangolo!\n\n", 138);
	else 
		printf("Questo parallelogramma NON %c rettangolo!\n\n", 138);
}

void stampaLista(VectorSet* array, int l){
	if(l==0){
		printf("Nessun parallelogramma nell'array!\n");
	} else {
		printf("Ecco la lista di parallelogrammi: \n\n");
		for(int i=0; i<l; i++){
			printf("Parallelogramma #%d: \n", i);
			stampaVettoreParallelogramma(array[i]);
		}
		printf("/---------------------/\n\n");
	}
}

/* * * * * * * * * * * * * * */
/* * * GESTIONE DEI FILE * * */
/* * * * * * * * * * * * * * */

int LeggiFile(VectorSet* array)
{
	int l = 0;
	FILE* fp = fopen("datiVettori.dat", "rb");
	
	if(fp==NULL){
		printf("Lettura fallita!\n");
	} else {
		VectorSet para;
		while(fread(&para, sizeof(VectorSet), 1, fp)>0){
			array[l]=para;
			l++;
		}
		fclose(fp);
	}
	return l;
}

void SalvaSuFile(VectorSet* array, int l)
{
	FILE* fp = fopen("datiVettori.dat", "wb");
	if(fp==NULL){
		printf("Scrittura fallita!\n");
	} else {
		fwrite(array, sizeof(VectorSet), l, fp);
		fclose(fp);
		printf("Salvataggio completato!\n\n");
		printf("/---------------------/\n\n");
	}
}

/* * * * * * * * * */
/* * INSERIMENTO * */
/* * * * * * * * * */

void leggiVettori(VectorSet* para)
{
	/* Vertice BS */
	printf("Quali sono le coordinate del vertice BS?\n");
	printf("X: ");
	scanf("%f", &para->bs.x);
	printf("Y: ");
	scanf("%f", &para->bs.y);
	
	/* Vertice AD */
	printf("Quali sono le coordinate del vertice AD?\n");
	do {
	printf("X: ");
	scanf("%f", &para->ad.x); 
	if (para->ad.x<=para->bs.x)
		printf("Questo valore deve essere maggiore di %.2f!\n", para->bs.x);
	} while (para->ad.x<=para->bs.x);
	do {
	printf("Y: ");
	scanf("%f", &para->ad.y); 
	if (para->ad.y<=para->bs.y)
		printf("Questo valore deve essere maggiore di %.2f!\n", para->bs.y);
	} while (para->ad.y<=para->bs.y);

	/* Lunghezza base */
	do {
	printf("Qual %c la lunghezza della base? ", 138);
	scanf("%f", &para->b); 
	if (para->b<=0 || para->b>=(para->ad.x-para->bs.x))
		printf("Questo valore deve essere minore di %.2f e maggiore di 0\n", para->ad.x-para->bs.x);
	} while (para->b<=0 || para->b>=(para->ad.x-para->bs.x));
}

int inserisciParallelogramma(VectorSet* array, int l)
{
	if (l==10)
		printf("Array completo!\n");
	else {
		leggiVettori(array+l);
		l++;
		printf("\n");
		printf("Parallelogramma inserito nell'array!\n\n");
		printf("/---------------------/\n\n");
	}
	return l;
}

/* * * * * * * * * * */
/* * CANCELLAZIONE * */
/* * * * * * * * * * */

void cancellaCella(VectorSet* array, int idx, int l){
	for(int i=idx; i<l; i++){
		array[i]=array[i+1];
		i++;
	}
}

int cancellaParallelogramma(VectorSet* array, int l, float soglia)
{
	int i=0;
	while(i<l){
		if(Area(array[i])>soglia){
			cancellaCella(array, i, l);
			l--;
		} else {
			i++;
		}
	}
	return l;
}

int cancellaSoglia(VectorSet* array, int l)
{
	float limite;
	
	printf("Qual %c l'area limite? ", 138);
	scanf("%f", &limite);
	
	l = cancellaParallelogramma(array, l , limite);
	
	printf("Tutti i parallelogrammi con area maggiore di %.2f sono stati cancellati!\n\n", limite);
	printf("/---------------------/\n\n");
	
	return l;
}

/* * * * * * * * * * */
/* * FUNZIONE MAIN * */
/* * * * * * * * * * */

int main(int argc, char **argv)
{
	VectorSet array[10];
	int l=0;
	l = LeggiFile(array);
	
	int risposta = 0;
	do{
		printf("Quale operazione vuoi fare?\n\n");
		printf("1 -> Inserisci un nuovo vettore parallelogramma.\n");
		printf("2 -> Cancella tutti i parallelogrammi con area maggiore di un valore.\n");
		printf("3 -> Visualizza l'elenco dei parallelogrammi.\n");
		printf("0 -> Termina esecuzione.\n\n");
		printf("Risposta: ");
		scanf("%d", &risposta);
		printf("\n");
		
		if(risposta==1){
			l = inserisciParallelogramma(array, l);
		} else if (risposta==2){
			l = cancellaSoglia(array, l);
		} else if (risposta==3){
			stampaLista(array, l);
		} else if (risposta!=0){
			printf("Selezione non valida!\n");
		}
	}
	while (risposta != 0);
	
	SalvaSuFile(array, l);
	
	return 0;
}
