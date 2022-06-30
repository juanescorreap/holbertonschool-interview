#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2
/**
 * slide_line - function that slides and merges an array of integers.
 * @line: points to an array of integers containing
 * @size: elements, that must be slided & merged to the
 * @direction: represented by direction
 * Return: 1 upon success, or 0 upon failure.
 *
 * Prototype
 */
int slide_line(int *line, size_t size, int direction);
#endif /* SLIDE_LINE_H */
