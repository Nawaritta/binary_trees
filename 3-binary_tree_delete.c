#include "binary_trees.h"

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left = NULL, *right = NULL;

	if(tree == NULL)
		return;
	if(tree->left)
		left = tree->left;
	if(tree->right)
		right = tree->right;
	binary_tree_delete(left);
	binary_tree_delete(right);
	free(tree);

}
