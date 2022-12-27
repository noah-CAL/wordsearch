#include <omp.h>
#include <stdio.h>
#include "include/wordsearch.h"

/** Returns the time elapsed for the program to search the dictionaries for WORD
 * with different search algorithms.
*/
double time_function(bool (*search_func)(char *), char *word) {
    double start = omp_get_wtime();
    search_func(word);
    return omp_get_wtime() - start;
}

void time_search_algorithms(char *word) {
    printf("Timing the algorithms against %d dictionaries...\n", get_num_wordlists());
    double unoptimized = time_function(word_in_dict_unoptimized, word);
    double optimized = time_function(word_in_dict_optimized, word);
    printf("Search (unoptimized): %f seconds\n", unoptimized);
    printf("Search (optimized): %f seconds\n", optimized);
    printf("Speedup: %.2fx\n", unoptimized / optimized);
}

int main(int argc, char **argv) {
    if (get_num_wordlists() == 0) {
        printf("Zero wordlists found in " ROOT " ...did you run 'make build'?\n");
        return -1;
    }
    if (argc <= 1) {
        printf("Please specify a word to search.\n");
        return 1;
    }
    char *word = argv[1];
    printf("Searching for %s in dictionary...\n", word);
    if (word_in_dict_unoptimized(word)) {
        printf("%s found in dictionary!\n", word);
    } else {
        printf("%s is not in dictionary\n", word);
    }
    time_search_algorithms(word);
    return 0;
}
