/**
 * @file findkeys.h
 *
 * @brief Finds valid keys for the RSA scheme
 */

#ifndef FINDKEYS_H
#define FINDKEYS_H

/* System includes */
#include <stdint.h>


/**
 * @brief Finds keys for the RSA cryptosystem
 *
 * @param *e Public key
 * @param *d Private key
 * @param *n Key length
 */
void find_keys(uint32_t *e,
               uint32_t *d,
               uint32_t *n);


#endif /* FINDKEYS_H */

