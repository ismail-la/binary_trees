#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count the nodes.
 *
 * Return: number of nodes counted, (0 if tree is NULL).
 *
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		count++;

	count += binary_tree_nodes(tree->right);
	count += binary_tree_nodes(tree->left);


	return (count);
}
