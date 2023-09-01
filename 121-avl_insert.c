#include "binary_trees.h"

/**
 * r_insert_node - node value instertion in a AVL.
 *
 * @tree: type **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new: type**pointer left or right insertion.
 * @Val_n: insertion value of the AVL.
 *
 * Return: Pointer to the new root after insertion otherwise NULL
 */

avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int Val_n)
{
	int Val_b;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, Val_n));
	if ((*tree)->n > Val_n)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, Val_n);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < Val_n)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, Val_n);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	Val_b = binary_tree_balance(*tree);
	if (Val_b > 1 && (*tree)->left->n > Val_n)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (Val_b > 1 && (*tree)->left->n < Val_n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (Val_b < -1 && (*tree)->right->n < Val_n)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (Val_b < -1 && (*tree)->right->n > Val_n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert -  Function that inserts a value in an AVL Tree.
 *
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 *
 * Return: inserted node, or NULL if fails.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
		*tree = binary_tree_node(NULL, value);
		return (*tree);

	r_insert_node(tree, *tree, &new, value);

	return (new);
}
