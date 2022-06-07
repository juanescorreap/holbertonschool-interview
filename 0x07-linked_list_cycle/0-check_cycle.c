#include "lists.h"
/**
 * check_cycle - Function that iterates through a single
 * linked list and checks for a cycle
 * @list: First node of the single linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *current_node = list;
    listint_t *tmp = list;

    if (!list)
    {
        return (0);
    }
    while (tmp && tmp->next)
    {
        current_node = current_node->next;
        tmp = tmp->next->next;
        if (current_node == tmp)
        {
            return (1);
        }
    }
    return (0);
}
