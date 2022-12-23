#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordsearch.h"

/** Returns the filename of the dictionary DICT_NUM according to the file name
 * form r"dict_\d+\.txt if it is present in the current directory
*/
char *get_filename(int dict_num) {
    size_t size = sizeof("dict_.txt") + \
            sizeof(char) * (floor(dict_num / 10) + 1);
    char *buf = malloc(size);
    char *format = "dict_%d.txt";
    int code = snprintf(buf, size, format, dict_num);
    if (code == -1) {
        printf("snprintf failed with dictionary #%d", dict_num);
        return NULL;
    }
    return buf;
}

/** Determines the number of wordlists of the form r"dict_\d+\.txt" present
 * in the current directory.
*/
int get_num_wordlists() {
    int fcount = 0;
    while (true) {
        char *filename = get_filename(fcount);
        if (filename == NULL) {
            return fcount;
        }
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            return fcount;
        }
        fclose(fp);
        fcount += 1;
    }
    return 0;
}

/** Determines the number of wordlists of the form r"dict_\d+\.txt" present
 * in the current directory and returns an array of FILEs.
*/
FILE **get_wordlists() {
    int filecount = get_num_wordlists();
    FILE **lists = calloc(filecount, sizeof(FILE *));
    for (int i = 0; i < filecount; i += 1) {
        FILE *fp = fopen(get_filename(i), "r");
        lists[i] = fp;
    }
    return lists;
}

/** Returns TRUE if WORD is present in the WORDLIST. */
bool word_in_sublist(FILE *wordlist, char *word) {
    char *lineptr;
    ssize_t nread;
    do {
        lineptr = NULL;
        size_t n = 0;
        nread = getline(&lineptr, &n, wordlist); 
        if (lineptr[nread-1] == '\n') {
            lineptr[nread-1] = '\0';
        }
        if (n >= 3 && lineptr[nread-2] == '\r') {
            lineptr[nread-2] = '\0';
        }
    } while (nread != -1 && strcmp(word, lineptr) != 0);
    bool found = strcmp(word, lineptr) == 0;
    free(lineptr);
    return found;

}

/** Returns TRUE if WORD is present in the many dictionaries in the current directory 
 * of the form dict_i.txt
*/
bool word_in_dict(char *word) {
    // FILE **lists = get_wordlists();  // don't need this?
    int num_lists = get_num_wordlists();
    // TODO: parallelize and optimize
    bool found = false;
    for (int i = 0; i < num_lists; i += 1) {
        FILE *wordlist = fopen(get_filename(i), "r");
        found = word_in_sublist(wordlist, word);
        fclose(wordlist);
        if (found) {
            return true;
        }
    }
    return false;
}
