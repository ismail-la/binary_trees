#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: - Pointer to the parent node of the node to create
 * @value: - Value to put in the node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Declaration of the node with its data type */
	binary_tree_t *New_Node;

	/* Allocate memory space for that node */
	New_Node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (New_Node == NULL)
		return (NULL);

	New_Node->parent = parent;
	New_Node->n = value;
	New_Node->left = NULL;
	New_Node->right = NULL;

	return (New_Node);
}
