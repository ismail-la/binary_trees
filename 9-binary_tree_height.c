#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of tree to measure the height.
 *
 * Return: height of the tree or 0 if tree is NULL.
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Right_Height = 0;
	size_t Left_Height = 0;

	if (!tree)
		return (0);

	Left_Height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	Right_Height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (Left_Height > Right_Height ? Left_Height : Right_Height);
}
