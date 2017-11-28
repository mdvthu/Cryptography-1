#include <stdio.h>

/* getNinputlines() */
/* Get the number of input lines, returning the value */
int getNinputlines() 
{
#ifdef DEBUG
	printf("DEBUG: Call to getNinputlines()\n");
#endif
	int n;
	printf("Enter number of input lines: ");
	/* continue to get input until a valid integer is entered */
	while (scanf("%d", &n) != 1 || n <= 0)
		printf("Invalid number of input lines entered. Please enter a positive integer: ");
#ifdef DEBUG
	printf("User entered %d input lines\n", n);
#endif
	return n;
}

/* processline() */
/* Convert a string formatted input line into hexadecimal digits, stored in a 
 * character array format for arguments: out = in */
void processline(char *out, char *in)
{
	/* copy the initial pointers to keep track of positions */
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

#ifdef DEBUG
	printf("DEBUG: Call to processlines(char *out, char *in): Hex formatted line length appears as %zd\n", out_pos - out);
#endif
}


