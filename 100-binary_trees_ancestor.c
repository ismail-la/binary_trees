#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node to find the ancestor.
 * @second: Pointer to the second node to find the ancestor.
 *
 * Return: pointer to the ancestor node, (NULL if there is no ancestor node).
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t First_Depth, Second_Depth;

	if (!first || !second)
		return (NULL);

	First_Depth = binary_tree_depth(first);
	Second_Depth = binary_tree_depth(second);

	while (First_Depth > Second_Depth)
	{
		first = first->parent;
		First_Depth--;
	}

	while (Second_Depth > First_Depth)
	{
		second = second->parent;
		Second_Depth--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to calculate the depth.
 *
 * Return: depth of the node, (0 if tree is NULL).
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t Depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		Depth++;
		tree = tree->parent;
	}
	return (Depth);
}
