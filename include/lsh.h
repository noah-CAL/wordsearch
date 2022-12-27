#ifndef LSH_H
#define LSH_H

uint8_t compute_hamming_distance(char *a, char *b);

int32_t max_bounded_hamming_distance(char *a, char *b, int32_t k);

#endif