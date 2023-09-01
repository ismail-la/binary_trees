#include "binary_trees.h"

/**
 * binary_tree_levelorder - function that goes through a binary tree
 * using level-order traverse.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t MaxçLevel, Level;

	if (!tree || !func)
		return;
	MaxçLevel = binary_tree_height(tree) + 1;
	for (Level = 1; Level <= MaxçLevel; Level++)
		btlo_helper(tree, func, Level);
}

/**
 * btlo_helper - function that goes through a binary tree
 * using post-order traverse.
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */

void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Right_Height = 0;
	size_t Left_Height = 0;

	if (!tree)
		return (0);

	Right_Height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	Left_Height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	return (Left_Height > Right_Height ? Left_Height : Right_Height);
}
