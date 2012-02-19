/**
 * @file rsakey.c
 *
 * @brief RSA key structure implementation
 */

/* Project includes */
#include <stdint.h>
#include <findkeys.h>

/* Local includes */
#include <rsakey.h>


/* Initialize RSA key */
void
rsakey_init(rsakey_t *rsakey,
            uint16_t msglen)
{
  uint32_t d = 0, e = 0, n = 0;

  find_keys(&d, &e, &n);
  rsakey->d = d;
  rsakey->e = e;
  rsakey->n = n;

  rsakey->msglen = msglen;
}

