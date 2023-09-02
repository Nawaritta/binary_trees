#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to value
 *         or NULL if tree is NULL or if nothing is found,
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	if (!tree)
		return (NULL);

	tmp = (bst_t *)tree;

	while (tmp)
	{
		if (value > tmp->n)
			tmp = tmp->right;
		else if (value < tmp->n)
			tmp = tmp->left;
		else
			return (tmp);
	}
	return (NULL);
}
