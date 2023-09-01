#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 *
 * @node: pointer to the node to find the sibling.
 *
 * Return: Pointer to the sibling node
 *         NULL if node or parent are NULL
 *         NULL if the node has no siblings.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
