/**
 * @file gcd.c
 *
 * @brief Euclidean algorithm for GCD implementation
 */

/* System includes */
#include <stdint.h>

/* Local includes */
#include <gcd.h>


/* Computes the GCD of a and b */
uint32_t
gcd(uint32_t a,
    uint32_t b)
{
  uint32_t r = a, old_r = 0;

  if (b > a) {
    a = b;
    b = r;
    
  }

  while (r != 0) {
    old_r = r;
    r = a % b;
    a = b;
    b = r;
  }

  return old_r;
}

