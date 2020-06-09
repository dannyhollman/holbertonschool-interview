#include "lists.h"

/**
 * check_cycle - checks for cycle in linked list
 * @list: list to check for cycle
 * Return: 1 if true, 0 if false
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}

	return (0);
}
