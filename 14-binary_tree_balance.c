#include "binary_trees.h"


/**
 * binary_tree_height2 - another implementation for the height function
 * because for some reason that i am too sleepy to care about the previous
 * implementation doesn't work
 *
 * @tree: tree node
 * Return: height int
 *
 */

size_t binary_tree_height2(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 1, right = 1;

		if (tree->right)
			right +=  binary_tree_height2(tree->right);
		if (tree->left)
			left +=  binary_tree_height2(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * binary_tree_balance - a function that measures
 * the balance factor of a binary tree
 *
 * @tree: tree node
 *
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);

	return (left_height - right_height);
}
