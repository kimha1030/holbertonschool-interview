#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * *insert_node - inserts a number inyo a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	/*
	 * The data of the new node is number and it
	 * points to NULL
	*/
	new->n = number;
	new->next = NULL;
	/*
	 * In case there are no nodes, the head node
	 * would be the new node
	*/
	if (*head == NULL)
		*head = new;
	/*
	* The loop ends when the next node is null and if the value of
	* the next node is less than the value of the new node, then the
	* the new node is join in the linked list in the right order.
	*/
	while (current->next != NULL)
	{
		if (current->next->n < new->n)
			current = current->next;
		else
		{
			break;
		}
	}
	new->next = current->next;
	current->next = new;
	return (new);
}
