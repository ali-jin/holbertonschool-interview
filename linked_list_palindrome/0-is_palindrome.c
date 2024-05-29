#include "lists.h"

/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * A palindrome is a sequence that reads the same forwards and backwards.
 *
 * @head: A pointer to a pointer to the first node of the linked list.
 *
 * Return: 1 if the list is a palindrome, 0 if it's not.
 */

int is_palindrome(listint_t **head)
{
    listint_t *fast = *head, *slow = *head;
    listint_t *prev = NULL, *temp = NULL, *second_half;

    if (*head == NULL || (*head)->next == NULL)
        return 1;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    while (slow != NULL) {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    second_half = prev;

    while (second_half != NULL) {
        if ((*head)->n != second_half->n)
            return 0;
        *head = (*head)->next;
        second_half = second_half->next;
    }

    return 1;
}