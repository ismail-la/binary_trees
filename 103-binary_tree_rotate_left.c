#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that rotates left the binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *New_Root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	New_Root = tree->right;
	tree->right = New_Root->left;

	if (New_Root->left != NULL)
		New_Root->left->parent = tree;

	New_Root->left = tree;
	New_Root->parent = tree->parent;
	tree->parent = New_Root;

	return (New_Root);
}
