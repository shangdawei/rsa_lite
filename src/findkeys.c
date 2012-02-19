/**
 * @file findkeys.c
 *
 * @brief Finds valid keys for the RSA scheme
 */

/* System includes */
#include <stdint.h>
#include <stdlib.h>  /* random */

/* Project includes */
#include <findprime.h>
#include <gcd.h>
#include <inverse.h>
#include <randseed.h>

/* Local includes */
#include <findkeys.h>


/* Finds keys for the RSA cryptosystem */
void
find_keys(uint32_t *e,
          uint32_t *d,
          uint32_t *n)
{
  uint32_t p = 0, q = 0, phi = 0;

  /* Seed the random number generator and get p, q */
  seed_random();

  /* Get p, q; length = 8, 8 bits so p*q = n is at least 15 bits so
   * n < 2^16 (overflow) */
  p = find_prime(128, 255);
  /* Weird stuff happens when p == q */
  do {
    q = find_prime(128, 255);
  } while (q == p);

  /* n = p * q; phi = (p - 1) * (q - 1) */
  *n = p * q;
  phi = (p - 1) * (q - 1);

  /* Choose e such that gcd(e, phi) == 1 and choose e < n so we don't
   * overflow */
  do {
    *e = 0;
    do {
      *e = rand() % *n;
    }
    while (*e % 2 == 0);
  }
  while (gcd(*e, phi) != 1);

  /* find d, the inverse of e (mod phi) */
  *d = inverse(*e, phi);

  return;
}

