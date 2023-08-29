#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hight = 0;
	if(tree == NULL)
		return (hight);

	hight = 1;
