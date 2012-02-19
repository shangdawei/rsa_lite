/**
 * @file exponentiation.c
 *
 * @brief Exponentiation implementation
 */

/* System includes */
#include <stdint.h>

/* Local includes */
#include <exponentiation.h>


uint32_t
exponentiate(uint32_t p,
             uint32_t q,
             uint32_t m)
{
  uint32_t square = 0, result = 0;

  /* m must be less that 65536 or else we may get an overflow
   * situation */
  if (m > 65536) {
    return 0;
  }

  /* Do the first step */
  square = p % m;
  if (q & 0x1) {
    result = square;
  }
  q = q >> 1;

  /* Continue until there are no more 1's left in q */
  while (q != 0) {
    /* Square the previous term and evaluate the mod */
    square = (square * square) % m;

    /* Update the result */
    if (q & 0x1) {
      if (result == 0) {
        result = square;
      } else {
        result = (result * square) % m;
      }
    }

    /* Bitshift the exponent */
    q = q >> 1;
  }

  return result;
}

