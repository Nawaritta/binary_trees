#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if(!node || node->right || node->left || !node->parent)
		return (0);
	return (1);
}
