#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if there is a cycle in list
 * @list: pointer to list
 * Return: if there is cycle 1, otherwise, 0
 */
int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	first = list, second = list;
	if (list == NULL)
		return (0);
	while (second != NULL && first != NULL && second->next != NULL)
	{
		second = second->next->next;
		first = first->next;
		if (second == first)
			return (1);
	}
	return (0);
}
