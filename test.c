#include <stdio.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_preorder_next(const binary_tree_t *node, const binary_tree_t *subtree_root)
{
	binary_tree_t *tmp;

	if (node == NULL || subtree_root == NULL)
		return NULL;

	if (node->left != NULL)
		return node->left;

	if (node->right != NULL)
		return node->right;

	while (node->parent != NULL)
	{
		if (node == node->parent->left && node->parent->right != NULL)
		{
			//return node->parent->right;

			tmp = node->parent->right;
			//	printf("to return = %d | subtree: %d\n", tmp->n, subtree_root->n);
			while (tmp)
			{
				//	printf("%d |", tmp->n);
				if (tmp == subtree_root)
					return node->parent->right;
				tmp = tmp->parent;
			}
			return NULL;

		}
		node = node->parent;
	}

	return NULL;
}
int main(void)
{
	binary_tree_t *root, *node;

	root = binary_tree_node(NULL, 1);
	root->left = binary_tree_node(root, 2);
	root->right = binary_tree_node(root, 3);
	root->left->left = binary_tree_node(root->left, 4);
	root->left->right = binary_tree_node(root->left, 5);
	root->right->left = binary_tree_node(root->right, 6);
	root->right->right = binary_tree_node(root->right, 7);
	root->left->left->left = binary_tree_node(root->left->left, 8);
	root->left->left->right = binary_tree_node(root->left->left, 9);
	root->right->right->left = binary_tree_node(root->right->right, 10);
	root->right->right->right = binary_tree_node(root->right->right, 11);
	root->left->right->left = binary_tree_node(root->left->right, 12);
	root->left->right->right = binary_tree_node(root->left->right, 13);
	root->right->left->left = binary_tree_node(root->right->left, 14);
	root->right->left->right = binary_tree_node(root->right->left, 15);
	root->left->left->left->left = binary_tree_node(root->left->left->left, 16);
	node = root->left;
	node = root->left->left;
	binary_tree_print(root);

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = binary_tree_preorder_next(node, root->left->left);
	}

	return 0;
}
