#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* Get the number of input lines, returning the value */
int getNinputlines();

/* Convert a string formatted input line into hexadecimal digits, stored in a 
 * character array format for arguments: out = in */
void processline(char *out, char *in);

#endif
