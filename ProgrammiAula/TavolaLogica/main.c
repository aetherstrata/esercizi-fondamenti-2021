#include <stdio.h>

int main()
{
	int a, b, c;
	printf("|a|b|c|e|\n");
	a=0; b=0; c=0;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=0; b=0; c=1;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=0; b=1; c=0;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=0; b=1; c=1;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=1; b=0; c=0;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=1; b=0; c=1;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=1; b=1; c=0;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	a=1; b=1; c=1;
	printf("|%d|%d|%d|%d|\n", a, b, c, (a || b) || (!a || c) && (b && c));
	
	printf("\n\n");
	printf("|a|b|e|\n");
	a=0; b=0;
	printf("|%d|%d|%d|\n", a, b, ((a && b) || (a && !b)) || ((a && b) || (!a && b)));
	a=1; b=1;
	printf("|%d|%d|%d|\n", a, b, ((a && b) || (a && !b)) || ((a && b) || (!a && b)));
	a=0; b=1;
	printf("|%d|%d|%d|\n", a, b, ((a && b) || (a && !b)) || ((a && b) || (!a && b)));
	a=1; b=0;
	printf("|%d|%d|%d|\n", a, b, ((a && b) || (a && !b)) || ((a && b) || (!a && b)));
	
	return 0;
}
