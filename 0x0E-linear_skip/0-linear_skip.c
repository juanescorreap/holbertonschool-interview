#include "search.h"
/**
 * linear_skip - Function that searches for
 * a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 * Return: A pointer to the node where the value is
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *_list;

	if (!list)
		return (NULL);
	_list = list;
	while (_list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   _list->express->index, _list->express->n);
		if (_list->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   _list->index, _list->express->index);
			break;
		}
		_list = _list->express;
	}
	if (!_list->express)
	{
		list = _list;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			   _list->index, list->index);
	}
	list = _list;
	while (list != _list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   list->index, list->n);
		if (list->n == value)
			break;
		list = list->next;
	}
	if (list != _list->express)
		return (list);
	return (NULL);
}
