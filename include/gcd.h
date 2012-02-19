/**
 * @file gcd.h
 *
 * @brief Euclidean algorithm for greatest common divisor (GCD)
 *        declaration
 */

#ifndef GCD_H
#define GCD_H

/* System includes */
#include <stdint.h>


/**
 * @brief Finds the GCD of a and b using the Euclidean algorithm
 *
 * @param a Factor
 * @oaram b Factor
 *
 * @return GCD of @e a and @e b
 */
uint32_t gcd(uint32_t a, uint32_t b);


#endif /* ! GDC_H */

