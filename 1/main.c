#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINELENGTH 1000

/* convert a string formatted input line 
 * into hexadecimal digits, stored in a 
 * character array
 * format for arguments: out = in */
void processline(char *out, char *in)
{
}

/* return the number of input lines */
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

int main()
{
	/* number of input lines */
	int n = getNinputlines();

	return 0;
}
