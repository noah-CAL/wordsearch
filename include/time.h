#ifndef TIME_H
#define TIME_H

#include <stdbool.h>

double time_function(bool (*search_func)(char *), char *word);

void time_search_algorithms(char *word);

#endif