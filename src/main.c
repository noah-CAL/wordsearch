#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/time.h"
#include "include/wordsearch.h"

#define OPSTRING "eath"  // command line options arguments
#define SEARCH_MODES enum SEARCH_MODES { EXACT, APPROXIMATE }
#define USAGE_STR "Usage: %s [-" OPSTRING "] word...\n"
#define PRINT_USAGE_DETAILS() (fprintf(stderr, USAGE_STR, argv[0]))
#define PRINT_OPT_ARGS() (\
                printf("Arguments:\n" \
                "-e  Exact Match (default)\n" \
                "-a  Approximate Match\n" \
                "-t  Time the search algorithms\n" \
                "-h  List command arguments\n"))

int main(int argc, char **argv) {
    if (get_num_wordlists() == 0) {
        printf("Zero wordlists found in " ROOT " ...did you run 'make build'?\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 1) {
        PRINT_USAGE_DETAILS();
        PRINT_OPT_ARGS();
        exit(EXIT_FAILURE);
    }
    bool time = false;
    SEARCH_MODES search_mode = EXACT;
    int opt = getopt(argc, argv, OPSTRING);
    for (; opt != -1; opt = getopt(argc, argv, OPSTRING)) {
        switch(opt) {
            case 'e': search_mode = EXACT; break;
            case 'a': search_mode = APPROXIMATE; break;
            case 't': time = true; break;
            case 'h':
                PRINT_OPT_ARGS();
                exit(EXIT_SUCCESS);
            default:
                PRINT_USAGE_DETAILS();
                exit(EXIT_FAILURE);
        }
    }
    if (optind == argc) {
        PRINT_USAGE_DETAILS();
        printf("Please specify a word to search.\n");
        exit(EXIT_FAILURE);
    }
    if (search_mode == EXACT) {
        char *word = argv[optind];
        printf("Searching dictionaries for %s (exact match)...\n", word);
        printf("%s %s in dictionary.\n", word,
                word_in_dict_optimized(word) ? "found" : "is not");
        if (time) {
            time_search_algorithms(word);
        }
    }
    else if (search_mode == APPROXIMATE) {
        printf("Approximate searching not yet implemented. ");
        exit(EXIT_SUCCESS);
    }
    return 0;
}
