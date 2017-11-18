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


