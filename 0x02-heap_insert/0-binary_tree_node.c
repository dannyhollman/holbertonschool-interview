#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node
 * @value: value of new node
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->n = value;

	if (parent == NULL)
		return (new);

	if (parent->left == NULL)
	{
		parent->left = new;
		new->parent = parent;
		return (new);
	}

	if (parent->right == NULL)
	{
		parent->right = new;
		new->parent = parent;
		return (new);
	}

	return (NULL);
}
