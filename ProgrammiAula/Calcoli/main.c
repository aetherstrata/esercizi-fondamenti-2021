#include <stdio.h>

int main(){
float r;     //un valore reale 
int f;        // un valore intero
int bl;      // un valore booleano

/*espressioni sugli int */
f = 6 + 2 + 1;
printf("6 + 2 + 1 = ");
printf("%d\n", f);

f = 2 * 3 + 4;
printf("2 * 3 + 4 = ");
printf("%d\n", f);

f = 4 + 2 * 3;
printf("4 + 2 * 3 = ");
printf("%d\n", f);

f = 6- 2-1;
printf("6- 2-1 = ");
printf("%d\n", f);

/*espressione con int e float */
f = 1/2 + 1/2;
printf("1/2 + 1/2 = ");
printf("%d\n", f);

r = 1/2 + 1/2;
printf("1/2 + 1/2 = ");
printf("%f\n", r);

r = 1.0/2 + 1/2.0;
printf("1.0/2 + 1/2.0 = ");
printf("%f\n", r);

r = 1.0/2 + 1/2;
printf("1.0/2 + 1/2 = ");
printf("%f\n", r);

/*espressione sui booleani */
bl = !1 && 0;
printf("!1 && 0 = ");
printf("%d\n",bl);

bl = !(1 && 0);
printf("!(1 && 0) = ");
printf("%d\n",bl);

bl = (1 && 0) || ! (1 && 0);
printf("(1 && 0) || ! (1 && 0) = ");
printf("%d\n",bl);

bl = (f>=0) && (f<=10);
printf("(f>=0) && (f<=10) = ");
printf("%d\n",bl);
}