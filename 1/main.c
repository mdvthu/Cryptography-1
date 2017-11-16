#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* external function declarations */
#include "functions.h"

/* maximum input line length */
#define MAXLINELENGTH 1000


/* Convert a string formatted input line into hexadecimal digits, stored in a 
 * character array format for arguments: out = in */
size_t processline(char *out, char *in)
{
	char *out_pos = out;
	char *in_pos = in;

	while(*in_pos != '\0') {
		if(sscanf(in, "%2hhx", out_pos) != 2) {
			in_pos++;
			break;
		}
		in_pos += 2;
		out_pos++;
	}

	return out_pos - out;
}

int main()
{
	/* prompt the user for the number of input lines */
	int n = getNinputlines();

	/* declare a generic counter variable */
	int i;

	/* buffer to store the string formatted line */
	char *linebuf = malloc(MAXLINELENGTH + 1);

	/* create a structure for each line, holding line
	 * and metadata including length of the line */
	struct lines {
		char *hexline;
		unsigned int linelen;
	} line[n];

	for(i = 0; i < n; i++) {
		printf("Input line %d: ", i + 1);
		scanf("%s", linebuf);
	}
	printf("\n");

	/* tidy up */
	free(linebuf);

	return 0;
}
