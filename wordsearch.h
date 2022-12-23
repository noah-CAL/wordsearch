#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <stdbool.h>

/** Returns TRUE if WORD is in the dictionary. FALSE otherwise. */
bool word_in_dict_unoptimized(char *word);

/** Returns TRUE if WORD is in the dictionary. FALSE otherwise. 
 * Uses OpenMP to speed up processing. */
bool word_in_dict_optimized(char *word);

#endif