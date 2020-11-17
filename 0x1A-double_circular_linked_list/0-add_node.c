#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * add_node_end - Adds a node to end of circular doubly linked list
 * @list: Double pointer to head of list
 * @str: Value of new node
 * Return: Pointer to new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new, *end;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	end = (*list)->prev;

	end->next = new;
	new->prev = end;

	new->next = *list;
	(*list)->prev = new;

	return (new);
}
/**
 * add_node_begin - Adds a node to beginning of circular doubly linked list
 * @list: Double pointer to head of list
 * @str: Value of new node
 * Return: Pointer to new node, or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *end;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}
	end = (*list)->prev;
	new->next = *list;
	new->prev = end;

	end->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
