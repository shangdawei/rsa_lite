/**
 * @file rsa.c
 *
 * @brief RSA encryption/decryption routines implementation
 */

/* System includes */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Project includes */
#include <rsakey.h>
#include <exponentiation.h>

/* Local includes */
#include <rsa.h>


/* Encrypt using public key */
void
rsa_encrypt_public(rsa_enc_t **cypher_msg,
                   const char *plain,
                   unsigned int plain_len,
                   uint32_t e,
                   uint32_t n)
{
  int i;
  uint32_t data;
  uint32_t cyphertext;
  rsa_enc_t *tmp;

  tmp = *cypher_msg;
  for (i = 0; i < plain_len; i++) {
    data = plain[i];

    /* C_i = M^e (mod n) */
    cyphertext = exponentiate(data, e, n);
    tmp[i] = cyphertext;
  }

  /* *cypher_msg = tmp; */

  return;
}


/* Decrypt using private key */
void
rsa_decrypt_private(char **plain,
                    const rsa_enc_t *cypher_msg,
                    unsigned int plain_len,
                    uint32_t d,
                    uint32_t n)
{
  int i;
  uint32_t data;
  uint32_t decrypted;
  char *tmp;

  tmp = *plain;
  for (i = 0; i < plain_len; i++) {
    data = cypher_msg[i];

    /* M_i = C^d (mod n) */
    decrypted = exponentiate(data, d, n);
    tmp[i] = decrypted;
  }

  /* *plain = tmp; */

  return;
}


/* RSA encrypt string */
rsakey_t
rsa_encrypt(rsa_enc_t **cypher_msg,
            const char *plain)
{
  rsakey_t rsakey;

  rsakey_init(&rsakey, strlen(plain));
  rsa_encrypt_public(cypher_msg, plain, strlen(plain),
                     rsakey.e, rsakey.n);

  return rsakey;
}


/* RSA decrypt string */
void
rsa_decrypt(char **plain,
            const rsa_enc_t *cypher_msg,
            rsakey_t rsakey)
{
  rsa_decrypt_private(plain,
                      cypher_msg,
                      *cypher_msg,
                      rsakey.d,
                      rsakey.n);
  return;
}

