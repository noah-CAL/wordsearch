#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "include/lsh.h"
#include "include/wordsearch.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (!min((a), (b)))

/** Computes the Hamming Distance between word A and B. In this context, Hamming Distance
 * is defined as the number of characters between A and B which are different. */
uint8_t compute_hamming_distance(char *a, char *b) {
    uint8_t len_a = strlen(a);
    uint8_t len_b = strlen(b);
    uint8_t minlen = min(len_a, len_b);
    if (minlen == 0) {
        return 0;
    }
    uint8_t ham_dist = 0;
    for (int i = 0; i < minlen; i += 1) {
        if (a[i] != b[i]) {
            ham_dist += 1;
        }
    }
    return ham_dist + max(len_a, len_b) - minlen;
}