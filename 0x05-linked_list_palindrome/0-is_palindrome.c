#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * len_list - returns the number of elements in list.
 * @head: pointer to head of linked list
 * Return: length of single linked list (i)
 */
int len_list(listint_t **head)
{
	int i = 0;
	listint_t *aux;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

/**
 * list_reverse - Reverse the list
 * @head: pointer to head of linked list
 * Return: nothing
 */
void list_reverse(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *tmp = *head;
	listint_t *aux = NULL;

	while (tmp != NULL)
	{
		aux = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = aux;
	}
	*head = prev;
}

/**
 * is_palindrome - checks if the linked list is a palindrome
 * @head: pointer to head of linked list
 * Return: 1 if list is palindrome or 0 if it is not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *new_head = *head;
	listint_t *tmp;
	listint_t *aux = *head;
	int length_list, middle, x = 0, num = 1;

	if (head == NULL)
		return (1);
	length_list = len_list(head);
	middle = length_list / 2;
	while (x < middle)
	{
		new_head = new_head->next;
		x++;
	}
	if (length_list % 2 != 0)
		new_head = new_head->next;
	list_reverse(&new_head);
	tmp = new_head;
	aux = *head;
	while (tmp != NULL)
	{
		if (tmp->n != aux->n)
			num = 0;
		tmp = tmp->next;
		aux = aux->next;
	}
	return (num);
}
