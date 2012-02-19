/**
 * @file randseed.c
 *
 * @brief Seed of the random number generator implementation
 */

/* System includes */
#include <stdlib.h> /* random */
#include <time.h>   /* time */

/* Local includes */
#include <randseed.h>


/* Seeds the random number generator from '/dev/random' */
void
seed_random(void)
{
  srand(time(NULL));
}

