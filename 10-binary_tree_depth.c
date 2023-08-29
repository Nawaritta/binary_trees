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
	size_t depth;

       	depth = 0;

	if (tree == NULL)
		return 0;

	while (tree->parent != NULL)
	{
		depth++;

		tree = tree->parent;
	}
	return depth;
}
