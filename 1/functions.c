#include <stdio.h>

/* Get the number of input lines, returning the value */
int getNinputlines() 
{
	int n;
	printf("Enter number of input lines: ");
	scanf("%d", &n);
#ifdef DEBUG
	printf("DEBUG: Call to getNinputlines(): User entered %d input lines\n", n);
#endif
	return n;
}


