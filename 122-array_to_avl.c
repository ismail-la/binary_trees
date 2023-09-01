#include "binary_trees.h"

/**
 * array_to_avl - Function that builds an AVL tree from an array.
 *
 * @array: array to create from.
 * @size: size of the array.
 *
 * Return: a pointer to the root node of the created AVL tree
 *	  NULL on failure.
 *
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *Tree = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		avl_insert(&Tree, array[i]);

	return (Tree);
}
