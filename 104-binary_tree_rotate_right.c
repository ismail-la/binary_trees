#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that rotates right the binary tree.
 *
 * @tree: Pointer to the root node of the three.
 * Return: Pointer to the new root node after rotation.
 *
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *New_Root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	New_Root = tree->left;
	tree->left = New_Root->right;

	if (New_Root->right != NULL)
		New_Root->right->parent = tree;

	New_Root->right = tree;
	New_Root->parent = tree->parent;
	tree->parent = New_Root;

	return (New_Root);
}
