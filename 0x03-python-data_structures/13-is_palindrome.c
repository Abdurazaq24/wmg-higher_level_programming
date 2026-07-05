#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second, *first;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return 1;

    slow = *head;
    fast = *head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)  /* odd number of nodes */
        slow = slow->next;

    second = reverse_list(slow);
    first = *head;

    while (second)
    {
        if (first->n != second->n)
            return 0;
        first = first->next;
        second = second->next;
    }

    return 1;
}
