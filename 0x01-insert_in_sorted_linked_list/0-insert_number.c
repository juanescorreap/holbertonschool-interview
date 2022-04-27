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
    listint_t *tmp = *head;

    newnode = malloc(sizeof(listint_t));
    if (newnode == NULL)
    {
        return (NULL);
    }
    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = NULL;
        return (newnode);
    }
    newnode->n = number;
    if (tmp->next == NULL)
    {
        newnode->next = NULL;
        tmp->next = newnode;
        return (newnode);
    }
    if (number <= tmp->n)
    {
        newnode->next = tmp;
        *head = newnode;
        return (newnode);
    }
    while (tmp->next && number >= (tmp->next->n))
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
    return (newnode);
}



