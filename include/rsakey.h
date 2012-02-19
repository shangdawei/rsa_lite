/**
 * @file rsakey.h
 *
 * @brief RSA key structure declaration
 */

#ifndef RSAKEY_H
#define RSAKEY_H

/* System includes */
#include <stdint.h>


/**
 * @typedef key_t
 *
 * @brief RSA key
 */
typedef struct rsakey_s {
  uint32_t d;      /**< Public key */
  uint32_t e;      /**< Private key */
  uint32_t n;      /**< Key length */
  uint16_t msglen; /**< Message length */
} rsakey_t;


/**
 * @brief Initialize a RSA key
 *
 * @param *rsakey Key to initialize
 * @param *msglen Lenght of the plain message to encrypt
 */
void rsakey_init(rsakey_t *rsakey, uint16_t msglen);


#endif /* ! RSAKEY_H */

