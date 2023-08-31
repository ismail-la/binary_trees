#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a bal tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return: the height, (If tree is NULL, return 0)
 */

size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t Right_Height = 0, Left_Height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		Left_Height = 1 + binary_tree_height_balance(tree->left);

	if (tree->right)
		Right_Height = 1 + binary_tree_height_balance(tree->right);

	if (Left_Height > Right_Height)
		return (Left_Height);

	return (Right_Height);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree.
 *
 * @tree: tree to go through.
 *
 * Return: balanced factor, (If tree is NULL, return 0).
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t Right_Height = 0, Left_Height = 0;

	if (!tree)
		return (0);

	if (tree->right)
		Right_Height = 1 + binary_tree_height_balance(tree->right);

	if (tree->left)
		Left_Height = 1 + binary_tree_height_balance(tree->left);

	return (Left_Height - Right_Height);
}
