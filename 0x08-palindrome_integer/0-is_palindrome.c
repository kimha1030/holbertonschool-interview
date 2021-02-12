#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - Function that checks if a num is palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char num[50];
	int i = 0, j, count, half;

	while (n)
	{
		num[i] = n % 10;
		n = n / 10;
	}
	num[i] = '\0';
	count = i;
	half = count / 2;
	for (j = 0; j < half; j++)
	{
		if (num[j] != num[(count - 1) -j])
			return (0);
	}
	return (1);
}
