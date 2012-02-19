/**
 * @file findprime.c
 *
 * @brief Prime number finder implementation
 */

/* System includes */
#include <stdint.h>
#include <math.h>   /* sqrt and ceil */
#include <stdlib.h> /* rand */

/* Local includes */
#include <findprime.h>
#include <randseed.h>


/* Randomly finds a prime number between lower and upper using wheel
 * factorization to test for primality. */
uint32_t
find_prime(uint32_t lower,
           uint32_t upper)
{
  /* A bunch of arrays that we will use to test primality */
  uint32_t test[] = { 2, 3, 5, 7 };
  uint32_t divisors[] = {
      1,  11,  13,  17,  19,  23,  29,  31,  37,  41,
     43,  47,  53,  59,  61,  67,  71,  73,  79,  83,
     89,  97, 101, 103, 107, 109, 113, 121, 127, 131,
    137, 139, 143, 149, 151, 157, 163, 167, 169, 173,
    179, 181, 187, 191, 193, 197, 199, 209
  };
  uint32_t num_divisors = 48, num_test = 4;
  uint32_t new_prime = 0, test_product = 2 * 3 * 5 * 7;
  uint32_t root = 0, multiple = 0, counter = 0;
  uint32_t current_prime =  0;

  seed_random();

  /* Now we generate a random number in the specified range and do
   * wheel factorization to verify primality until we find a prime */
  /* Subtract because we are going to add 2 */
  do {
    new_prime = rand() % (upper - lower) + lower - 2;
  } while (new_prime % 2 == 0);

  while (!current_prime) {
    /* Test the next odd number */
    new_prime += 2;

    /* Handle the passed the top problem and the overflow the integer
     * problem */
    if (new_prime > upper) {
      new_prime -= lower;
    }
    if (new_prime < lower) {
      new_prime += lower;
    }
    current_prime = new_prime;

    /* Test it with the test divisors first, skipping 2 */
    for (counter = 1; counter < num_test && current_prime; ++counter) {
      if (current_prime % test[counter] == 0) {
        current_prime = 0;
      }
    }

    if (current_prime) {
      root = ceil(sqrt(current_prime));

      /* We stop testing divisors when we have passed the square
       * root */
      /* Skip 1 when we start testing */
      for (counter = 1, multiple = 0;
           current_prime && divisors[counter] + multiple <= root;
           ++counter) {
        if (current_prime % (divisors[counter] + multiple) == 0) {
          current_prime = 0;
        }

        /* Increase the multiple when we need to */
        if (counter == num_divisors) {
          counter = 0;
          multiple += test_product;
        }
      }
    } /* if (current_prime...) */
  } /* while (!current_prime...) */

  return current_prime;
}

