/**
 * @file inverse.h
 *
 * @brief Finds the modular inverse of a number using the extended
 *        Euclidean algorithm
 *
 * @details An implementation of the extended euclidean algorithm
 *          Finds solutions to diophantine equations of the form:
 *          ax + by = gcd(a, b)
 */

#ifndef INVERSE_H
#define INVERSE_H

/* System includes */
#include <stdint.h>


/**
 * @brief Extended Euclidean algorithm for finding the modular inverse
 *        of a number
 *
 * @details Algorithm:
 *
 *   do {
 *     quotient <- Divide oldx * number +
 *                        oldy * mod by x * number +
 *                        y * mod
 *     newx <- Subtract x * quotient from oldx
 *     newy <- Subtract y * quotient from oldy
 *     oldx <- x
 *     oldy <- y
 *     x <- newx
 *     y <- newy
 *   } while ( x * number + y * mod != 1)
 *
 * @param number The number that we want inverse of
 * @param mod    The base to find the inverse
 *
 * @return The inverse, or zero if isn't one
 */
uint32_t inverse(uint32_t number,
                 uint32_t mod);


#endif /* ! INVERSE_H */

