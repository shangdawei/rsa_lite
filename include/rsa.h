/**
 * @file rsa.h
 *
 * @brief RSA encryption/decryption routines declaration
 */

#ifndef RSA_H
#define RSA_H

/* Project includes */
#include <rsakey.h>

/* System includes */
#include <stdint.h>


/**
 * @typedef Encrypted data type
 *
 * @brief RSA encrypted data type declaration
 */
typedef uint32_t rsa_enc_t;


/* Public interface */
/**
 * @brief Encrypts a message with RSA using the public key
 *
 * @param *cypher_msg Where the encrypted message will be stored
 * @param **plain     Plain text message
 * @param plain_len   Length of the plain message
 * @param e           Public key
 * @param n           Key length
 */
void rsa_encrypt_public(rsa_enc_t **cypher_msg,
                        const char *plain,
                        unsigned int plain_len,
                        uint32_t e,
                        uint32_t n);

/**
 * @brief Decrypts  a message with RSA using the private key
 *
 * @param **plain     Where the encrypted string will be stored
 * @param *cypher_msg Encrypted message
 * @param plain_len   Length of the plain message
 * @param d           Private key
 * @param n           Key length
 */
void rsa_decrypt_private(char **plain,
                         const rsa_enc_t *cypher_msg,
                         unsigned int plain_len,
                         uint32_t d,
                         uint32_t n);

/**
 * @brief RSA encryption
 *
 * @param **cypher_msg Where the encrypted string will be stored
 * @param *plain       Plain message
 * @param e            Public key
 * @param n            Key lenght (modulus)
 *
 * @return Public and private keys struture
 */
rsakey_t rsa_encrypt(rsa_enc_t **cypher_msg,
                     const char *plain);

/**
 * @brief RSA decryption
 *
 * @param **plain     Where the decrypted string will be stored
 * @param *cypher_msg Encrypted  message
 * @param rsakey      Key used to decrypt
 */
void rsa_decrypt(char **plain,
                 const rsa_enc_t *cypher_msg,
                 const rsakey_t rsakey);


#endif /* ! RSA_H */

