#include "binary_trees.h"

/**
 * binary_sibling - a function that finds the sibling of a node
 *
 * @node: node to tree
 * Return: pointer to sibling node
 */

binary_tree_t *binary_sibling(binary_tree_t *node)
{
        if (node == NULL)
                return (NULL);
        if (node->parent == NULL)
                return (NULL);
        if (node->parent->left == NULL || node->parent->right == NULL)
                return (NULL);
        if (node->parent->left != node)
                return (node->parent->left);
        return (node->parent->right);
}

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	node = node->parent;
	return (binary_sibling(node));
}
