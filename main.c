#include <stdio.h>
#include "wordsearch.h"

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Please specify a word to search.\n");
        return 1;
    }
    char *word = argv[1];
    printf("Searching for %s in dictionary...\n", word);
    if (word_in_dict(word)) {
        printf("%s found in dictionary!\n", word);
    } else {
        printf("%s is not in dictionary\n", word);
    }
    return 0;
}