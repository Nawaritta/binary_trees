#include "binary_trees.h"

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
	l = binary_tree_size(tree);
	return (l & (l + 1)) == 0;
}
