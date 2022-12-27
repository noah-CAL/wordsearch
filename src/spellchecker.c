#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/spellchecker.h"
#include "include/wordsearch.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (!min((a), (b)))

/** Computes the Hamming Distance between words A and B. In this context, Hamming Distance
 * is defined as the number of characters between A and B which are different. */
uint8_t compute_hamming_distance(char *a, char *b) {
    /* Precompute lengths to avoid MACRO double-computation. */
    uint8_t len_a = strlen(a);
    uint8_t len_b = strlen(b);
    uint8_t ham_dist = abs(len_a - len_b);
    for (int i = 0; i < min(len_a, len_b); i += 1) {
        if (a[i] != b[i]) {
            ham_dist += 1;
        }
    }
    return ham_dist;
}

/** Returns the Hamming Distance between words A and B. Short-circuits and returns
 * -1 if the (Hamming_Distance > K) to save time when comparing words. Set K=INT_MAX
 * to compute the regular hamming distance.
 */
int32_t max_bounded_hamming_distance(char *a, char *b, int32_t k) {
    /* Precompute lengths to avoid MACRO double-computation. */
    uint8_t len_a = strlen(a);
    uint8_t len_b = strlen(b);
    uint8_t ham_dist = abs(len_a - len_b);
    if (ham_dist > k) {
        return -1;
    }
    for (int i = 0; i < min(len_a, len_b); i += 1) {
        if (a[i] != b[i]) {
            ham_dist += 1;
            if (ham_dist > k) {
                return -1;
            }
        }
    }
    return ham_dist;
}