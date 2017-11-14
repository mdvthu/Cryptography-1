#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* external function declarations */
#include "functions.h"

/* maximum input line length */
#define MAXLINELENGTH 1000


/* Convert a string formatted input line 
 * into hexadecimal digits, stored in a 
 * character array
 * format for arguments: out = in */
void processline(char *out, char *in)
{

}

int main()
{
	/* prompt the user for the number of input lines */
	int n = getNinputlines();

	/* declare a generic counter variable */
	int i;

	/* buffer to store the string formatted line */
	char *linebuf = malloc(MAXLINELENGTH + 1);

	for(i = 0; i < n; i++) {
		printf("Enter input line %d\n", i);
	}

	/* tidy up */
	free(linebuf);

	return 0;
}
