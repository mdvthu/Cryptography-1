#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* external function declarations */
#include "functions.h"

/* maximum input line length */
#define MAXLINELENGTH (2000)

/* plan:
 * 1) enter number of input lines
 * 2) process each input line into hex lines, line by line, storing data into a structure
 * 3) line by line, N ^ N+1, crib drag " a ", " in ", " the " etc
 * 4) store sucessful matches, look for key
 */

/* to do:
 * 1) doxygen documentation 
 * 2) lint and other source code analysers 
 */

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
		/* calculate the line length from the input string length */
		line[i].linelen = strlen(linebuf) / 2;
		/* process the line, storing the return value in the struct */
		processline(line[i].hexline, linebuf);
	}

	for(int i = 0; i < line[0].linelen; i++) {
#ifdef DEBUG
		printf("DEBUG: Printing line 0, hex %d\n", i);
#endif
		printf("%2X ", line[0].hexline[0]);
	}
	
	printf("\n");


	/* tidy up */
	for(int i = 0; i < n; i++)
		free(line[i].hexline);
	free(linebuf);

	return EXIT_SUCCESS;
}
