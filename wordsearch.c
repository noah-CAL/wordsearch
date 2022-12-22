#include <omp.h>
#include <stdio.h>
#include <string.h>
#include "wordsearch.h"

#define DICTNAME "dictionary.txt"

bool word_in_list(char *word) {
    FILE **lists = get_wordlists();
    int num_lists = 0;
    for (int i = 0; lists[i] != NULL; i += 1) {
        num_lists += 1;
    }
    # TODO: parallelize and optimize
    FILE *wordlist = fopen("dictionary.txt", "r");
    char *lineptr = NULL;
    ssize_t nread;
    do {
        size_t n = 0;
        nread = getline(&lineptr, &n, wordlist); 
        if (lineptr[nread-1] == '\n') {
            lineptr[nread-1] = '\0';
        }
    } while (nread != -1 && strcmp(word, lineptr) != 0);
    fclose(wordlist);
    if (strcmp(word, lineptr) == 0) {
        printf("%s found in dictionary!\n", word);
        return true;
    }
    printf("%s is not in dictionary\n", word);
    return false;
}

/** Determines the number of wordlists of the form r"dict_\d+\.txt" present
 * in the current directory and returns an array of FILEs.
*/
FILE **get_wordlists() {
    FILE **lists = calloc(sizeof(FILE *));
    int i = 0;
    do {
        char *strp = "dict_%d.txt";
        int ret_code = asprintf(&strp, i);
        if (ret_code == -1) {
            printf("MALLOC FAILED HERE WAAAA"); // todo: handle the malloc error
            break;
        }
        FILE *f = fopen(strp, "r");
        if (f == NULL) {
            break;  // reached the end of the dictionaries.
        }
        lists[i] = f;
        i += 1;
        realloc(lists, sizeof(FILE *) * (i + 1));
    } while (true);
    return lists;
}