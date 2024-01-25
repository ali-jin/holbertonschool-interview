#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 2
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int merge_line_left(int *line, size_t size);
int merge_line_right(int *line, size_t size);

#endif
