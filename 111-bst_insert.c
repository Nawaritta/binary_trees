#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp, *new;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	new = malloc(sizeof(bst_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->right = NULL;
	new->left = NULL;
	while (1)
	{
		if (tmp->n > value)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
				break;
		} else if (tmp->n < value)
		{
			if (tmp->right)
				tmp = tmp->right;
			else
				break;
		} else
		{
			free(new);
			return (NULL); }
	}
	new->parent = tmp;
	if (value > tmp->n)
		tmp->right = new;
	else
		tmp->left = new;
	return (new);
}
