#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect or Null
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t Height_bt = 0, Perfect_size = 0;

	if (tree == NULL)
		return (0);

	Height_bt = binary_tree_height(tree);
	Perfect_size = (1 << (Height_bt + 1)) - 1;

	if (Perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}


/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: size of the tree
 *         0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t Right_Node, Left_Node;

		Left_Node = binary_tree_size(tree->left);
		Right_Node = binary_tree_size(tree->right);

		return (1 + Left_Node + Right_Node);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree
 *         0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{

		int Left_Height = 0, Right_Height = 0;

		if (tree->right)
			Right_Height = 1 + binary_tree_height(tree->right);
		if (tree->left)
			Left_Height = 1 + binary_tree_height(tree->left);
		if (Left_Height > Right_Height)
			return (Left_Height);
		else
			return (Right_Height);
	}
	else
		return (0);
}
