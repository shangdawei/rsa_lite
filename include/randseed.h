/**
 * @file randseed.h
 *
 * @brief Seed of the random number generator declaration
 */

#ifndef RANDSEED_H
#define RANDSEED_H


/**
 * @brief Seeds the random number generator from '/dev/random'
 *
 * @return 0 if everything is ok, 1 if '/dev/random' couldn't be open
 *         or 2 if there is some reading error in '/dev/random/'
 *
 * @todo Find a better implementation
 */
void seed_random(void);


#endif /* ! RANDSEED_H */

