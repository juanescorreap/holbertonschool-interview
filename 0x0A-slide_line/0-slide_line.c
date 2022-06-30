#include "slide_line.h"
/**
 * reverse - reverse the array
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing.
 **/
void reverse(int *line, size_t size)
{
	size_t a, b;

	a = 0;
	b = size - 1;
	while (a < b)
	{
		int temp = line[a];

		line[a] = line[b];
		line[b] = temp;
		a++;
		b--;
	}
}

/**
 * slide_zero - moves zeros
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing.
 **/
void slide_zero(int *line, size_t size)
{
	size_t i;
	size_t zero = 0;

	i = 0;
	while (i < size)
	{
		if (line[i] == 0)
			zero++;
		else if (zero)
			line[i - zero] = line[i];
		i++;
	}
	while (zero > 0)
	{
		line[i - 1] = 0;
		zero--;
		i--;
	}
}

/**
 * slide_non_zero - moves non zeros
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing.
 **/
void slide_non_zero(int *line, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
		i += 2;
	}
}
/**
 * slide_line - function that slides and merges an array of integers.
 * @line: points to an array of integers containing
 * @size: elements, that must be slided & merged to the
 * @direction: represented by direction
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction == SLIDE_LEFT)
	{
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		reverse(line, size);
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		reverse(line, size);
		return (1);
	}
	return (0);
}
