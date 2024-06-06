#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: Pointer to the sibling node, or NULL if no sibling exists.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return ((node->parent->left == node) ? node->parent->right 
			: node->parent->left);
}
