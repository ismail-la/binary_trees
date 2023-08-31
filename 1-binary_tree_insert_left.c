#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: it's a pointer to the node to insert the left-child in
 * @value:  it's the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must take its
 *		 place and the old left-child must be set as the left-child of
 *		 the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *New_Node;

	if (!parent)
		return (NULL);

	New_Node = malloc(sizeof(binary_tree_t));
	if (!New_Node)
		return (NULL);

	New_Node->n = value;
	New_Node->parent = parent;
	New_Node->right = NULL;
	New_Node->left = parent->left;
	parent->left = New_Node;
	if (New_Node->left)
		New_Node->left->parent = New_Node;

	return (New_Node);
}
