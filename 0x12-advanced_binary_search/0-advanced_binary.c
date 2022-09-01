#include "search_algos.h"
/**
 * print - Function that prints an array
 * @array: Pointer to the first element of the array to print
 * @left: First element of the array
 * @right: Last element of the array
 * Return: Void
 **/
void print(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}
/**
 * use_recursion - Function that searches for a value in an array of integers
 * @array: Pointer to the first element of the array to search in
 * @left: Index of first element of the array
 * @right: Index of last element of the array
 * @value: Value to search for
 * Return: Index where value is located, otherwise return -1
 **/
int use_recursion(int *array, int left, int right, int value)
{
	int middle;

	print(array, left, right);
	middle = (right - left) / 2 + left;
	if (left == right)
		return (-1);
	if (array[middle] == value && array[middle - 1] != value)
		return (middle);
	if (array[middle] >= value)
		return (use_recursion(array, left, middle, value));
	if (array[middle] <= value)
		return (use_recursion(array, middle + 1, right, value));
	return (-1);
}
/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, otherwise return -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (use_recursion(array, 0, size - 1, value));
}
