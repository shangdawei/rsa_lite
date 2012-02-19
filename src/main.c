/**
 * @file main.c
 *
 * @brief RSA test (only ASCII characters)
 *
 * @fixme Memory issues; some 'Segmentation fault', etc.
 */

/* System includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Project includes */
#include <rsa.h>


/* Show usage */
void show_usage(FILE *fp, const char *arg0);


/* Main entry */
int main(int argc, char *argv[])
{
  char *input;
  char *output;
  rsa_enc_t *enc_str;
  rsakey_t rsakey;

  /* Check arguments */
  if (argc < 2) {
    show_usage(stdout, argv[0]);
    return 1;
  }

  /* Allocate memory */
  input    = (char *) malloc(sizeof(char) * (strlen(argv[1]) + 1));
  output   = (char *) malloc(sizeof(char) * (strlen(argv[1]) + 1));
  enc_str  = (rsa_enc_t *) malloc(sizeof(rsa_enc_t) *
                                 (strlen(argv[1]) + 1));
  if (input == NULL || output == NULL || enc_str == NULL) {
    fprintf(stderr, "%s: No enough memory\n", argv[0]);
    return 1;
  }

  /* Get the argument */
  strncpy(input, argv[1], (strlen(argv[1]) + 1));

  /* We encrypt... */
  rsakey = rsa_encrypt(&enc_str, input);

  /* ... and then we decrypt */
  rsa_decrypt(&output, enc_str, rsakey);

  /* *******************************************************/
  /* at this point, 'output' should be the same as 'input' */
  /* *******************************************************/

  /* Find public and private keys */
  fprintf(stderr, "Public key = %u, private key = %u, length = %u\n",
          rsakey.e, rsakey.d, rsakey.n);


  /* Check */
  fprintf(stdout, "After RSA encryption/decryption:\n %s\n", output);
  if (strcmp(input, output) == 0) {
    fprintf(stdout, "\n%s: Decrypted data MATCH input. OK!\n", argv[0]);
  } else {
    fprintf(stderr, "\n%s: Decrypted data does NOT match input\n", argv[0]);
  }

  /* Free heap memory */
  free(input);
  /*free(output);*/ /* <-- I CANNOT FREE MEMORY WITHOUT A MAP DUMP! */
  /*free(enc_str);*/

  return 0;
}


/* Show usage on screen */
void
show_usage(FILE *fp, const char *arg0)
{
  fprintf(fp, "Usage: %s <string>\n\n", arg0);
}

