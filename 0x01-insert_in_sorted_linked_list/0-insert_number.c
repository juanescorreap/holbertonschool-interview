#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_node - Function that inserts a number into a sorted singly linked list.
 * Return: The address of the new node, or NULL if it failed.
 * @head: Pointer to the pointer that points to the head of the linked list
 * @number: Data of the newly added node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newnode;
    listint_t *tmp;
    unsigned int j = 0;
    tmp = *head;

    while (tmp->next && number > (tmp->next->n))
    {
        tmp = tmp->next;
        j++;
    }
    j--;
    newnode = malloc(sizeof(listint_t));
    if (newnode == NULL)
    {
        return (NULL);
    }
    newnode->n = number;
    if (j == 0)
    {
        newnode->next = (*head);
        *head = newnode;
        return (newnode);
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    return (newnode);

}