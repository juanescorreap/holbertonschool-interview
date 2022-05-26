#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * linked_list_length - function that measures the length of a linked list
 * @head: pointer to head of list
 * Return: the length of the linked list
 */
int linked_list_length(listint_t **head)
{
    int i = 0;
    listint_t *temp = *head;
    for (i = 0; temp != NULL; i++)
    {
        temp = temp->next;
    }
    return (i);
}
/**
 * reverse_list - function that reverses a linked list
 * @head: pointer to head of list
 * Return: pointer to head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *previous_node = NULL;
    listint_t *next_node = NULL;
    listint_t *temp = *head;

    while (temp != NULL)
    {
        next_node = temp->next;
        temp->next = previous_node;
        previous_node = temp;
        temp = next_node;
    }
    *head = previous_node;
    return (*head);
}
/**
 * is_palindrome - function in C that checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
    int list_length = linked_list_length(head);
    int palindrome_check = 1;
    int i = 0;
    listint_t *second_half_head;
    listint_t *temp = *head;
    listint_t *temp_second_half;

    second_half_head = *head;
    for (i = 0; i < (list_length / 2); i++)
    {
        second_half_head = second_half_head->next;
    }
    if ((list_length % 2) != 0)
    {
        second_half_head = second_half_head->next;
    }
    second_half_head = reverse_list(&second_half_head);
    temp_second_half = second_half_head;
    temp = *head;
    while (temp_second_half != NULL)
    {
        if (temp_second_half->n != temp->n)
        {
            palindrome_check = 0;
        }
        temp_second_half = temp_second_half->next;
        temp = temp->next;
    }
    return (palindrome_check);
}
