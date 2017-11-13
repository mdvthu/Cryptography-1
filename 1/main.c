#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINELENGTH 1000

/* Convert a string formatted input line 
 * into hexadecimal digits, stored in a 
 * character array
 * format for arguments: out = in */
void processline(char *out, char *in)
{

}

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

int main()
{
	int n = getNinputlines();



	return 0;
}
