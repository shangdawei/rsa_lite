/**
 * @file inverse.c
 *
 * @brief Finds the modular inverse of a number using the extended
 *        Euclidean algorithm
 */

/* Project includes */
#include <stdint.h>
#include <gcd.h>

/* Local includes */
#include <inverse.h>


/* Extended Euclidean algorithm for finding the modular inverse of a
 * number */
uint32_t
inverse(uint32_t number,
        uint32_t mod)
{
  long int quotient = 0;
  long int x = 0, y = 1;
  long int oldx = 1, oldy = 0;
  long int newx = 0, newy = 0;

  if (gcd(number, mod) != 1) {
    return 0;
  }

  /* Algorithm */
  while ((x * number) + (y * mod) != 1) {
    quotient =
      ((oldx * number) + (oldy * mod)) /
      ((x * number) + (y * mod));

    newx = oldx - (x * quotient);
    newy = oldy - (y * quotient);

    oldx = x;
    oldy = y;

    x = newx;
    y = newy;
  }

  if (x < 0) {
    x += mod;
  }

  return x;
}
