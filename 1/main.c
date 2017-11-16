#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* external function declarations */
#include "functions.h"

/* maximum input line length */
#define MAXLINELENGTH (2000)


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
	int n;
	if (! (n = getNinputlines()) ) {
		printf("Invalid number of input lines entered. Exiting.\n");
		return EXIT_FAILURE;
	}

	/* buffer to store the string formatted line */
	char *linebuf = malloc(MAXLINELENGTH + 1);
	
	/* create a structure for each line, holding line
	 * and metadata including length of the line */
	struct lines {
		char *hexline;
		unsigned int linelen;
	} line[n];
	
	for(int i = 0; i < n; i++) {
		printf("Input line %d: ", i + 1);
		scanf("%s", linebuf);
		line[i].hexline = malloc(strlen(linebuf)/2);
		line[i].linelen = processline(line[i].hexline, linebuf);
	}
	
	/* tidy up */
	for(int i = 0; i < n; i++)
		free(line[i].hexline);
	free(linebuf);
	return 0;
}
