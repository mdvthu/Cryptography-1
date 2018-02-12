#include <stdio.h>
#include <assert.h>
#include <gmp.h>
#include <sys/random.h>

int main()
{
	/* MP variable declarations */
	mpz_t l_lim, rand_i, b, exp, result;
	gmp_randstate_t s;

	/* lower limit of random prime suggested in the course is 2^1024 */
	mpz_init(l_lim);
	mpz_ui_pow_ui(l_lim, 2, 1024);
#ifdef DEBUG
	gmp_printf("2^1024: %Zd\n", l_lim);
#endif

	while(1) {
		/* cryptographically secure random seed
		 * reseeding is required for each iteration */
		unsigned long seed;
		getrandom(&seed, sizeof(seed), 0);
#ifdef DEBUG
		printf("Random seed: %lu\n", seed);
#endif
		/* select a random number between 0 and 2^1024 */
		mpz_init(rand_i);
		gmp_randinit_mt(s);
		gmp_randseed_ui(s, seed);
		mp_bitcnt_t maxbits = 1024;
		mpz_urandomb(rand_i, s, maxbits);

		/* add the base to the random element */
		mpz_add(rand_i, rand_i, l_lim);

		/* calculate: 2^(random - 1) % random */
		mpz_inits(exp, result, NULL);
		mpz_init_set_ui(b, 2);
		mpz_sub_ui(exp, rand_i, 1);
		mpz_powm(result, b, exp, rand_i);

		/* test: 2^(p-1) == 1 mod p */
		if (mpz_cmp_ui(result, 1) == 0) {
			gmp_printf("Large Fermat-probable prime: %Zd\n", rand_i);
			break;
		}

#ifdef DEBUG
		gmp_printf("Random: %Zd\n", rand_i);
#endif
	}

	/* check the number using the GMP library number theory test */
	assert(mpz_probab_prime_p(rand_i, 50) > 0);

	/* tidy up */
	gmp_randclear(s);
	mpz_clears(b, exp, rand_i, l_lim, result, NULL);

	return 0;
}
