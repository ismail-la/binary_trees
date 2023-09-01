#include "binary_trees.h"
/**
 * bst_insert - Function that inserts a value in a Binary Search Tree.
 *
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, NULL on failure.
 *
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *Second_Val = NULL;
	bst_t *New = NULL;
	bst_t *T = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	T = *tree;
	while (T)
	{
		Second_Val = T;
		if (value < T->n)
			T = T->left;
		else if (value > T->n)
			T = T->right;
		else if (value == T->n)
			return (NULL);
	}

	New = binary_tree_node(NULL, value);

	if (Second_Val == NULL)
		Second_Val = New;

	else if (value < Second_Val->n)
	{
		Second_Val->left = New;
		New->parent = Second_Val;
	}
	else
	{
		Second_Val->right = New;
		New->parent = Second_Val;
	}
	return (New);
}
