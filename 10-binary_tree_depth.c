#include "binary_trees.h"

/**
 * binary_tree_depth -  a function that measures
 * the depth of a node in a binary tree
 *
 * @tree: pointer to binary tree
 *
 * Return: size of depth or zero
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int left_depth, right_depth, depth;

	if (tree == NULL)
		return (0);

	left_depth = binary_tree_depth(tree->left);
	right_depth = binary_tree_depth(tree->right);

	if (left_depth > right_depth)
	{
		depth = (left_depth + 1);
	}

	depth = (right_depth + 1);

	return (depth);
}
