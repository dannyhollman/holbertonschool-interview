#include "lists.h"

/**
 * insert_node - adds node to sorted linked list
 * @head: pointer to pointer of first node
 * @number: value of new node
 * Return: address of new node or NULL if fail
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *temp = *head;
	listint_t *last;

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = number;
		*head = new;
		return (new);
	}

	while (temp != NULL)
	{
		if (temp->n >= number)
		{
			last->next = new;
			new->next = temp;
			new->n = number;
			break;
		}
		last = temp;
		temp = temp->next;
	}
	return (new);
}
