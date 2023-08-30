#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 *
 * @tree: tree node
 *
 * Return: 1 if is full otherwise return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if ((tree->right) && (tree->left))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
