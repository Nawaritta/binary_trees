#include "binary_trees.h"

/**
 * binary_tree_preorder_next - returns the next node to visit in
 *                            pre-order traversal
 * @node: a pointer to the current node
 * Return: a pointer to the next node to visit,
 *        or NULL if the traversal is complete
 *
 */
binary_tree_t *binary_tree_preorder_next(const binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->left != NULL)
		return (node->left);

	if (node->right != NULL)
		return (node->right);

	while (node->parent != NULL)
	{
		if (node == node->parent->left && node->parent->right != NULL)
			return (node->parent->right);
		node = node->parent;
	}
	return (NULL);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 if not or if tree is NULL.
 *
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *sub;

	if (tree == NULL)
		return (0);
	while (tree != NULL)
	{
		if (tree->left)
		{
			sub = tree->left;
			while (sub)
			{
				if (sub->n > tree->n)
					return (0);
				sub = binary_tree_preorder_next(sub);
				if (tree->parent)
					if (sub == tree->parent->right)
						break;
				if (sub == tree->right)
					break;
			}
		}
		if (tree->right)
		{
			sub = tree->right;
			while (sub)
			{
				if (sub->n < tree->n)
					return (0);
				sub = binary_tree_preorder_next(sub);
			}
		}
		tree = binary_tree_preorder_next(tree);
	}
	return (1);
}
