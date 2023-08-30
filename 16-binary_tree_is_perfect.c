#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree
 *
 * Return: size int or 0 if null
 */

size_t binary_size(const binary_tree_t *tree)
{
		if (tree == NULL)
				return (0);
		return (binary_size(tree->right) + 1 + binary_size(tree->left));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree node
 *
 * Return: 1 if perfect otherwise zero
 *
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l;

	if (tree == NULL)
		return (0);
	l = binary_size(tree);
	return (l & (l + 1)) == 0;
}
