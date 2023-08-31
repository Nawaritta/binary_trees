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

/**
 * current_level - function to traverse the current level
 * @tree: node
 * @level: int level
 * @func: function to pass
 */
void current_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		current_level(tree->left, level - 1, func);
		current_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - binary tree level order
 * @tree: tree node
 * @func: function to pass
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h, i = 1;

	h = binary_tree_height(tree);
	while (i <= h + 1)
	{
		current_level(tree, i, func);
		i++;
	}
}
