#include <stdio.h>

int main()
{
	/*
	 * 10>5
	 * 10.0 < 5.0 
	 * 10 > 10
	 * 10 >= 10
	 * 10.0 >= 5.0
	 * 10 == 5
	 * 10 == 10
	 * 10 != 5
	 * 10 != 10
	 */
	 
	printf("10>5: valore atteso = 1 valore reale = %d \n",10>5);
	printf("10.0<5.0: valore atteso = 0 valore reale = %d \n",10.0 < 5.0);
	printf("10>10: valore atteso = 0 valore reale = %d \n",10>10);
	printf("10>=10: valore atteso = 1 valore reale = %d \n",10>=10);
	printf("10.0 >= 5.0: valore atteso = 1 valore reale = %d \n",10.0 >= 5.0);
	printf("10 == 5: valore atteso = 0 valore reale = %d \n",10 == 5);
	printf("10 == 10: valore atteso = 1 valore reale = %d \n",10 == 10);
	printf("10 != 5: valore atteso = 1 valore reale = %d \n",10 != 5);
	printf("10 != 10: valore atteso = 0 valore reale = %d \n",10 != 10);
	
	return 0;
}
