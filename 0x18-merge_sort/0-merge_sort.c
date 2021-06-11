#include "sort.h"

/**
* merge - Function that merges left and right arrays
* @array: pointer
* @leftArray: pointer to left array
* @rightArray: pointer to right array
* @size: size array
* return: void
*/

void merge(int *array, int *leftArray, int *rightArray, size_t size)
{
	int sizeLeft, sizeRight;
	int k = 0, j = 0, i = 0;

	sizeLeft = size / 2;
	sizeRight = size - sizeLeft;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(leftArray, sizeLeft);
	printf("[right]: ");
	print_array(rightArray, sizeRight);
	while (i < sizeLeft && j < sizeRight)
	{
		if (leftArray[i] < rightArray[j])
			array[k++] = leftArray[i++];
		else
			array[k++] = rightArray[j++];
	}
	while (j < sizeRight)
		array[k++] = rightArray[j++];
	while (i < sizeLeft)
		array[k++] = leftArray[i++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
* merge_sort - Function that sorts an array of integers in
* ascending order using the Merge Sort algorithm
* @array: pointer to array
* @size: size array
* return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t l, sm, mid = 0;
	int leftArray[100];
	int rightArray[100];

	if (array == NULL)
		return;
	if (size < 2)
		return;
	mid = size / 2;
	for (l = 0; l < mid; l++)
		leftArray[l] = array[l];
	for (l = mid; l < size; l++)
		rightArray[l - mid] = array[l];
	merge_sort(leftArray, mid);
	sm = size - mid;
	merge_sort(rightArray, sm);
	merge(array, leftArray, rightArray, size);
}
