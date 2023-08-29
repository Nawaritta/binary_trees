#include "binary_trees.h"
#include "10-binary_tree_depth.c"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *up, *down, *DOWN;

	if (first == NULL || second == NULL)
		return (NULL);

	up = first;
	down = second;

	if (binary_tree_depth(second) < binary_tree_depth(first))
	{
		up = second;
		down = first;
	}
	DOWN = down;

	while (up)
	{
		down = DOWN;
		while(down->parent)
		{
			if (up == down->parent)
				return (down->parent);
			down = down->parent;
		}
		up = up->parent;
	}
	return (NULL);
}