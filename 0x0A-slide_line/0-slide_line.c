#include "slide_line.h"

/**
 * slide_line - Function that merges an array of integers
 * @line: Array of integers.
 * @size: Number of elements in array.
 * @direction: Direction that indicates how to move the
 * elements of the array.
 * Return: 1 in success, and 0 in failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (size <= 0 || ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT)))
		return (0);
	if (direction == SLIDE_LEFT)
		left(line, size);
	else if (direction == SLIDE_RIGHT)
		right(line, size);
	else
		return (0);
	return (1);
}

/**
 * left - function that slides an array of integers to left
 * @line: pointer to array of integers.
 * @size: number of elements in array.
 * Return: 1 in success, and 0 in failure.
 */
void left(int *line, size_t size)
{
	size_t i, k, p, q = 0;
	int aux[32];

	for (k = 0; k < size; k++)
		aux[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (line[p] != 0)
			aux[q++] = line[p];
	}
	for (i = 0; i < size; i++)
	{
		if (aux[i] == aux[i + 1])
		{
			aux[i] += aux[i + 1];
			aux[i + 1] = 0;
		}
	}
	q = 0;
	for (k = 0; k < size; k++)
		line[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (aux[p] != 0)
		{
			line[q++] = aux[p];
		}
	}
}


/**
 * right - function that slides an array of integers to right
 * @line: pointer an array of integers.
 * @size: number of elements in array.
 * Return: 1 in success, and 0 in failure.
 */
void right(int *line, size_t size)
{
	size_t q = 0, j;
	int aux[32], p, i, k;

	for (j = 0; j < size; j++){
		aux[j] = 0;
	}
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (line[p] != 0)
			aux[q--] = line[p];
	}
	for (i = size - 1; i >= 0; i--){
		if (aux[i] == aux[i-1])
		{
			aux[i] += aux[i-1];
			aux[i-1] = 0;
		}
	}
	for (k = size - 1; k >= 0; k--)
		line[k] = 0;
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (aux[p] != 0)
			line[q--] = aux[p];
	}
}
