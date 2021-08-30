#include "sort.h"

/**
 * heap - Function that convert an array in heap
 * @array: Array of ints
 * @size: Number of elements in array
 * @b: Heap size
 * @i: Position in array
 */
void heap(int *array, size_t size, int b, int i)
{
	int l = (i * 2) + 1;
	int r = (i * 2) + 2;
	int maximum = i;

	if (l < b && array[l] > array[maximum])
		maximum = l;
	if (r < b && array[r] > array[maximum])
		maximum = r;
	if (maximum != i)
	{
		swap(&array[i], &array[maximum]);
		print_array(array, size);
		heap(array, size, b, maximum);
	}
}

/**
 * swap - Function that swap two ints
 * @b: Int for swap
 * @i: Int for swap
 */
void swap(int *b, int *i)
{
	int temp = *b;
	*b = *i;
	*i = temp;
}


/**
 * heap_sort - Function that sorts an array of integers
 * in ascending order using the heap sort algorithm
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i, middle, end;

	if (array == NULL || size < 2)
		return;
	middle = (size / 2)-1;
	end = size - 1;

	for (i = middle; i >= 0; i--)
		heap(array, size, size, i);

	for (i = end; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heap(array, size, i, 0);
	}
}
