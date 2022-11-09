#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm implement the LSD radix sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int i, max;

	if (size < 2)
		return;
	max = getMax(array, size);
	for (i = 1; max / i > 0; i *= 10)
	{
		counting(array, size, i);
		print_array(array, size);
	}
}

/**
 * getMax - gets the max number in an array
 * @array: array to search
 * @size: size of the array
 * Return: the biggest number in the array
 */
int getMax(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting - counting sort of the array
 * @array: the array to sort
 * @size: size of the array
 * @exp: digit to count around
 * Return: Nothing
 */
void counting(int *array, int size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int i;
	int count[10] = {0};

	if (!output)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
