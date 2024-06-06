#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of the leftmost leaf node.
 * @tree: Pointer to the root node of the tree to measure the depth.
 *
 * Return: Depth of the leftmost leaf node.
 */

int tree_depth(const binary_tree_t *tree)
{
    int depth = 0;
    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return (depth);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: Pointer to the root node of the tree to check.
 * @depth: Depth of the leftmost leaf node.
 * @level: Current level in the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */

int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
	is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int depth = tree_depth(tree);
	return (is_perfect_recursive(tree, depth, 0));
}
