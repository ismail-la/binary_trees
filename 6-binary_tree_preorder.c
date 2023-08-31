#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 *
 * @tree: Pointer to the tree to traverse.
 * @func: pointer to a function to call for each node.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
/* Call the function on the current node */
	func(tree->n);

/* Traverse the subtree */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
