#include <stdio.h>
#include <gmp.h>

/* a basic example of GNU Multiple Precision aka "Bignum" library */

int main()
{
	/* declare and initialize a new big int */
	mpz_t i;
	mpz_init(i);
	/* set the big int to a BIG number (base 36 */
	mpz_set_str(i, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", 36);
	/* print the value */
	gmp_printf("i is %Zd\n", i);
	/* create a really really big number: raise i to the power of 1024 */
	mpz_pow_ui(i, i, 1024);
	gmp_printf("i^1024 is %Zd\n", i);
	/* tidy up */
	mpz_clear(i);

	return 0;
}
