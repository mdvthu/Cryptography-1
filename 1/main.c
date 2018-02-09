#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* external function declarations */
#include "functions.h"

/* Define a new macro for the preprocessor */
/* maximum input line length */
#define MAXLINELENGTH (2000)

int main()
{
	/* prompt the user for the number of input lines */
	int n = getNinputlines(); 

	/* buffer to store the string formatted line */
	char *linebuf = malloc(MAXLINELENGTH + 1);
	
	/* create a structure for each line, holding line
	 * and metadata including length of the line */
	struct lines {
		char *hexline;
		size_t linelen;
	} line[n];
	
	/* collect and process each line */
	for(int i = 0; i < n; i++) {
		printf("Input line %d: ", i + 1);
		/* load the input into the line buffer */
		scanf("%s", linebuf);
		/* allocate memory to hold the processed line */
		line[i].hexline = malloc(strlen(linebuf)/2);
		/* process the line, storing the return value in the struct */
		line[i].linelen = processline(line[i].hexline, linebuf);
	}
	
	for(int i=0; i < line[0].linelen; i++)
		printf("%d: %2x ", i, line[0].hexline[i]);

	/* tidy up */
	for(int i = 0; i < n; i++)
		free(line[i].hexline);
	free(linebuf);

	return EXIT_SUCCESS;
}
