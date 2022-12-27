#include <omp.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "include/wordsearch.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))

/** Returns the time elapsed for the program to search the dictionaries for WORD
 * with different search algorithms.
*/
double time_function(bool (*search_func)(char *), char *word) {
    double start = omp_get_wtime();
    search_func(word);
    return omp_get_wtime() - start;
}

void print_thread_details() {
    int num_lists = get_num_wordlists();
    int max_threads = omp_get_max_threads();
    int num_threads = min(num_lists, max_threads);
    printf("num_lists: %d  max_threads: %d\n", num_lists, max_threads);
    printf("Running search with %d threads\n...\n", num_threads);
}

/** Script to run the two exact search algorithms and print to STDOUT. */
void time_search_algorithms(char *word) {
    printf("\nTiming the algorithms against %d dictionaries...\n", get_num_wordlists());
    print_thread_details();
    double unoptimized = time_function(word_in_dict_unoptimized, word);
    double optimized = time_function(word_in_dict_optimized, word);
    printf("Search (unoptimized): %f seconds\n", unoptimized);
    printf("Search (optimized): %f seconds\n", optimized);
    printf("Speedup: %.2fx\n", unoptimized / optimized);
}