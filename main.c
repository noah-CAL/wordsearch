#include <omp.h>
#include <stdio.h>
#include "wordsearch.h"

/** Returns the time elapsed for the program to search the dictionaries for WORD
 * with different search algorithms.
*/
double time_function(bool (*search_func)(char *), char *word) {
    double start = omp_get_wtime();
    search_func(word);
    return omp_get_wtime() - start;
}

void time_search_algorithms(char *word) {
    printf("Timing the algorithms...\n");
    printf("Search (unoptimized): %f seconds\n", time_function(word_in_dict_unoptimized, word));
    printf("Search (optimized): %f seconds\n", time_function(word_in_dict_optimized, word));
    // Print speedup?
    // printf("Speedup: %fx", )
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Please specify a word to search.\n");
        return 1;
    }
    char *word = argv[1];
    printf("Searching for %s in dictionary...\n", word);
    if (word_in_dict_optimized(word)) {
        printf("%s found in dictionary!\n", word);
    } else {
        printf("%s is not in dictionary\n", word);
    }
    time_search_algorithms(word);
    return 0;
}
