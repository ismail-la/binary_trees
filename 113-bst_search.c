#include "binary_trees.h"

/**
 * bst_search - Function that searches for a value in a Binary Search Tree.
 *
 * @tree: Pointer to the root node of the BST to search.
 * @value: Value to search in the tree.
 *
 * Return: Pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL or no match is found
 *
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *Node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (Node)
	{
		if (value == Node->n)
			return (Node);

		if (value < Node->n)
			Node = Node->left;

		else if (value > Node->n)
			Node = Node->right;
	}


	return (NULL);
}
