#ifndef SUBSTRING_H
#define SUBSTRING_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int check_substring(char const *s, char const **words, int nb_words, int word_len, int *used, int start);

#endif
