#ifndef SLIDE_H
#define SLIDE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction);
void left(int *line, size_t size);
void right(int *line, size_t size);

#endif
