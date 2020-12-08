#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

/**
 * left_height - Height of left tree
 * @node: Input node
 * Return: Height of left tree starting from node
 */
int left_height(const binary_tree_t *node)
{
	int height = 0;
	const binary_tree_t *temp = node;

	while (temp->left)
	{
		temp = temp->left;
		height++;
	}
	return (height);
}
/**
 * right_height - Height of right tree
 * @node: Input node
 * Return: Height of right tree starting from node
 */
int right_height(const binary_tree_t *node)
{
	int height = 0;
	const binary_tree_t *temp = node;

	while (temp->right)
	{
		temp = temp->right;
		height++;
	}
	return (height);
}
/**
 * traverse - Traverse tree recursively
 * @node: Current node in tree
 * @low: Lowest value in tree
 * @high: Highest value in tree
 * Return: 0 if AVL, 1 otherwise
 */
int traverse(const binary_tree_t *node, int low, int high)
{
	int left, right;

	if (!node)
		return (0);

	if (node->n < low || node->n > high)
		return (1);
	right = right_height(node);
	left = left_height(node);
	if (right - left > 1)
	{
		return (1);
	}
	else
	{
		return (traverse(node->left, low, node->n - 1) ||
				traverse(node->right, node->n + 1, high));
	}
}
/**
 * binary_tree_is_avl - Check if tree is AVL tree
 * @tree: Input tree
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (!traverse(tree, INT_MIN, INT_MAX));
}
