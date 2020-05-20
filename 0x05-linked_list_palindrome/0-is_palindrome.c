#include "lists.h"
#include <stdio.h>

/**
 * list_length - finds length of linked list
 * @head: pointer to head of list
 * Return: length of list
 */
int list_length(listint_t *head)
{
	listint_t *temp = head;
	int length = 0;

	while (temp != NULL)
	{
		length += 1;
		temp = temp->next;
	}
	return (length - 1);
}
/**
 * is_palindrome - determines if linked list is palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	int *array, length, index = 0, i, j;
	listint_t *temp = *head;

	length = list_length(*head);
	array = malloc(length * sizeof(int));
	
	if (length == 0)
		return (1);

	while (temp != NULL)
	{
		array[index] = temp->n;
		index++;
		temp = temp->next;
	}
	
	i = 0;
	j = length;
	while (i < j)
	{
		if (array[i] != array[j])
			return (0);
		i++;
		j--;
	}

	return (1);
}
