/**
 * @file exponentiation.h
 *
 * @brief Exponentiation definition using the square and multiply
 *        algorithm for fast exponentation
 *
 * @details Uses the square and multiply algorithm for fast
 *          exponentation
 *
 *  This works but is quite inefficient:
 *
 *  1. This could take advantage of fermat's little theorem to speed
 *     the exponentiation, expecially for the case of RSA decryption.
 *
 *  2. The squares in the algorithm will begin to repeat. Rather than
 *     simply calculating them over and over, some form of
 *     array/vector/list should be used to lookup the repeating
 *     values.
 */

#ifndef EXPONENTIATION_H
#define EXPONENTIATION_H

/* System includes */
#include <stdint.h>


/**
 * @brief Evaluate p^q (mod m) quickly
 *
 * @details Algorithm:
 *
 *  1. Write q in binary form:
 *     q = (an)2^n + (a(n-1))2^(n-1) + ... + * (a2)2^2 + (a1)2^1
 *
 *  2. Compute p^1, p^2, p^4, ..., p^(2^n) (mod m) by squaring the
 *     previous term in the sequence
 *
 *  3. Multiply together all a^(2^i) such that (ai) = 1 to get the
 *     result
 *
 * @param p Base
 * @param q Exponent
 * @param m Modulus of the congrunence
 *
 * @pre m < 65535
 *
 * @return The result of evaluate p^q (mod m), or 0 otherwise
 */
uint32_t exponentiate(uint32_t p,
                      uint32_t q,
                      uint32_t m);


#endif /* ! EXPONENTIATION_H */

