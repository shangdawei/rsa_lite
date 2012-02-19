/**
 * @file findprime.h
 *
 * @brief Prime number finder declaration
 *
 * @details Find prime using wheel factorization to generate a prime
 *          in a certain range.
 */

#ifndef FINDPRIME_H
#define FINDPRIME_H

/* System includes */
#include <stdint.h>


/**
 * @brief Randomly finds a prime number between lower and upper using
 *        wheel factorization to test for primality
 *
 * @details This could be much faster with advanced primality tests
 *          and expecially with probabilistic primality testing, which
 *          any serious RSA implementation should use. The lower bound
 *          is included, the upper bound is excluded.
 *
 * @param lower Lower boundary
 * @param upper Upper boundary
 *
 * @return Prime number
 *
 * @note
 *  (http://www.utm.edu/research/primes/glossary/WheelFactorization.html
 */
uint32_t find_prime(uint32_t lower,
                    uint32_t upper);


#endif /* ! FINDPRIME_H */

