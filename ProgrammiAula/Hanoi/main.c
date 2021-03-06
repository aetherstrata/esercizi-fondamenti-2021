#include <stdio.h>

void hanoi(int n, int sorg, int app, int dest);

/* programma per il risolvere il problema della torre di Hanoi */
int main()
{
	int dischi;
	printf("Io risolvo il problema della torre di Hanoi. Quanti dischi?\n");
	scanf("%d", &dischi);
	printf("Ecco la soluzione\n\n");
	hanoi(dischi,1,2,3);
	printf("Finito!\n");
}

/* funzione per il movimento di un disco */
void muoviUnDisco(int sorg, int dest) {
	printf("Muovo un disco dalla pila %d alla pila %d\n", sorg, dest);
}

/* funzione per la soluzione del problema della torre di Hanoi  */
void hanoi(int n, int sorg, int app, int dest) {
	if(n==1)
		/* caso base */
		muoviUnDisco(sorg,dest);
	else {
		/* passo ricorsivo: 1) sposta gli n-1 dischi piccoli su app; 2) sposta il discone su dest;
		 * 3) sposta gli n-1 dischi piccoli su dest */
		hanoi(n-1,sorg, dest, app);
		muoviUnDisco(sorg,dest);
		hanoi(n-1,app, sorg, dest);
	}
}