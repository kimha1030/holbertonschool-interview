#include "search.h"

/**
 * *check_value - function that checks the value of nodes.
 * @list: pointer to the head of the skip list to search
 * @ult_value: pointer to the last node
 * @value: value to search
 * Return: pointer where value is located
 */

skiplist_t *check_value(skiplist_t *list, skiplist_t *ult_value, int value)
{
	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->index == ult_value->index)
		{
			break;
		} else if (list->n == value)
		{
			return (list);
		}
		list = list->next;
	}
	return (NULL);
}

/**
 * *linear_skip - function that searches for value in sorted skip list of ints.
 * @list: pointer to the head of the skip list to search
 * @value: value to search
 * Return: pointer on the first node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ult_value;

	if (list == NULL)
		return (NULL);
	while (list)
	{
		int val = list->express->n;

		printf("Value checked at index [%lu] = [%d]\n", list->express->index, val);
		if (val >= value)
		{
			ult_value = list->express;
			size_t uvi = ult_value->index;

			printf("Value found between indexes [%lu] and [%lu]\n", list->index, uvi);
			skiplist_t *chk_val = check_value(list, ult_value, value);

			return (chk_val);
		}
		list = list->express;
		if (!list->express)
		{
			ult_value = list;
			while (ult_value->next)
			{
				ult_value = ult_value->next;
			}
			size_t uvi = ult_value->index;

			printf("Value found between indexes [%lu] and [%lu]\n", list->index, uvi);
			skiplist_t *chk_val = check_value(list, ult_value, value);

			return (chk_val);
		}
	}
	return (NULL);
}
