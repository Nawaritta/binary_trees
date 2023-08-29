#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t height, h_right = 0, h_left = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		h_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		h_right = binary_tree_height(tree->right) + 1;
	height = (h_left > h_right) ? h_left : h_right;

	return (height);
}
