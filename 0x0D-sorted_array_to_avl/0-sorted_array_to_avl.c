#include "binary_trees.h"

avl_t *new_node(int value)
{
	avl_t *new = malloc(sizeof(avl_t));
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}

avl_t *array_to_tree(int *array, int start, int end)
{
	avl_t *root = NULL;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = new_node(array[mid]);
	if (root == NULL)
		return (NULL);
	root->left = array_to_tree(array, start, mid - 1);
	if (root->left != NULL)
		root->left->parent = root;
	root->right = array_to_tree(array, mid + 1, end);
	if (root->right != NULL)
		root->right->parent = root;
	return (root);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int n = (size * sizeof(int)) / sizeof(array[0]);

	avl_t *root = array_to_tree(array, 0, n - 1);

	return (root);
}

