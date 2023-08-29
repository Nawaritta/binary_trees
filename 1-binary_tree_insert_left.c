#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child = malloc(sizeof(binary_tree_t));

	if(left_child == NULL)
		return (NULL);


	if(parent->left)
	{
		parent->left->parent = left_child;
		left_child->left = parent->left;
	}
	left_child->parent = parent;
	left_child->n = value;
	parent->left = left_child;

	return (left_child);
}
