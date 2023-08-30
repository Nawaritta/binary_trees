#include "binary_trees.h"
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		if (tree->left->n > tree->n)
			return (0);

		binary_tree_is_bst(tree->left);
	}
	if (tree->right)
	{
		if(tree->right->n < tree->n)
		return (0);
		binary_tree_is_bst(tree->right);
	}


	return (1);
}
