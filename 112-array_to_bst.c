#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a Binary Search Tree from an array.
 *
 * @array: pointer to the first element of the array to be converted.
 * @size: the number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, NULL on failure.
 *
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *Tree = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		bst_insert(&Tree, array[i]);

	return (Tree);
}
