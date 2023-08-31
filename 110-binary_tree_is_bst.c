#include "binary_trees.h"

/**
 * subtree_trav_next - returns the next node to visit in
 *                            pre-order traversal
 * @node: a pointer to the current node
 * @subroot: a pointer to the root node of the subtree
 * Return: a pointer to the next node to visit,
 *         or NULL if the traversal is complete
 */
binary_tree_t *subtree_trav_next(const binary_tree_t *node,
				 const binary_tree_t *subroot)
{
	binary_tree_t *tmp;

	if (node == NULL || subroot == NULL)
		return (NULL);

	if (node->left != NULL)
		return (node->left);

	if (node->right != NULL)
		return (node->right);

	while (node->parent != NULL)
	{
		if (node == node->parent->left && node->parent->right != NULL)
		{
			tmp = node->parent->right;
			while (tmp)
			{
				if (tmp == subroot)
					return (node->parent->right);
				tmp = tmp->parent;
			}
			return (NULL);
		}
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
	const binary_tree_t *sub, *root;

	if (tree == NULL)
		return (0);
	root = tree;
	while (tree != NULL)
	{
		if (tree->left)
		{
			sub = tree->left;
			while (sub)
			{
				if (sub->n >= tree->n)
					return (0);
				sub = subtree_trav_next(sub, tree->left);
			}
		}
		if (tree->right)
		{
			sub = tree->right;
			while (sub)
			{
				if (sub->n <= tree->n)
					return (0);
				sub = subtree_trav_next(sub, tree->right);
			}
		}
		tree = subtree_trav_next(tree, root);
	}
	return (1);
}
