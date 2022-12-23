#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <stdbool.h>

/** Returns TRUE if WORD is in the dictionary. FALSE otherwise. */
bool word_in_dict_unoptimized(char *word);

/** Returns TRUE if WORD is in the dictionary. FALSE otherwise. 
 * Uses OpenMP to speed up processing. */
bool word_in_dict_optimized(char *word);

/** Returns the number of wordlists of the form r"dict_\d+\.txt" present
 * in the current directory.
*/
int get_num_wordlists();

#endif