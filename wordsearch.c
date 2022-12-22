#include <omp.h>
#include <stdio.h>
#include <string.h>
#include "wordsearch.h"

#define DICTNAME "dictionary.txt"

bool word_in_list(char *word) {
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