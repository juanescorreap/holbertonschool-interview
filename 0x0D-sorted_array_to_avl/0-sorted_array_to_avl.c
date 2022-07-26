#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_search - recursive function that builds an AVL tree from an array
 * @array:pointer to the first element of the array to be converted
 * @start: first element of the array to be converted
 * @end: last element of the array to be converted
 * @parent: root node of the tree to be build from the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 **/
avl_t *binary_search(int *array, int start, int end, avl_t *parent)
{
	int middle_element;
	avl_t *node;

	if (start > end)
	{
		return (NULL);
	}
	middle_element = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
	{
		return (NULL);
	}
	node->n = array[middle_element];
	node->parent = parent;
	node->left = binary_search(array, start, middle_element - 1, node);
	node->right = binary_search(array, middle_element + 1, end, node);
	return (node);
}
/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array:pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: Pointer to the parent of the binary tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
	{
		return (NULL);
	}
	return (binary_search(array, 0, size - 1, NULL));
}
