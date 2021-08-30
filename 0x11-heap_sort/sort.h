#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void heap(int *array, size_t size, int b, int i);
void swap(int *b, int *i);
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif
