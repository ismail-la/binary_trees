#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Description: If parent already has a right-child, the new node must take
 *			    its place, and the old right-child must be set as
 *				the right-child of the new node.
 *
 * Return: Pointer to the created node,
 *         or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *New_Node;

	if (!parent)
		return (NULL);

	New_Node = malloc(sizeof(binary_tree_t));
	if (!New_Node)
		return (NULL);

	New_Node->n = value;
	New_Node->parent = parent;
	New_Node->left = NULL;
	New_Node->right = parent->right;
	parent->right = New_Node;

	if (New_Node->right)
		New_Node->right->parent = New_Node;

	return (New_Node);
}
