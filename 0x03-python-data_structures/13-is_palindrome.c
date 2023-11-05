#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/* Structure for a node in the linked list */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head) {
    listint_t *slow = *head, *fast = *head;
    listint_t *prev_slow = *head;
    listint_t *second_half, *mid_node = NULL;
    int is_palindrome = 1;

    if (*head != NULL && (*head)->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        /* List has odd number of elements */
        if (fast != NULL) {
            mid_node = slow;
            slow = slow->next;
        }

        second_half = slow;
        prev_slow->next = NULL;
        reverse_list(&second_half);
        is_palindrome = compare_lists(*head, second_half);
        
        /* Reconstruct the original list */
        reverse_list(&second_half);
        if (mid_node != NULL) {
            prev_slow->next = mid_node;
            mid_node->next = second_half;
        } else {
            prev_slow->next = second_half;
        }
    }
    return is_palindrome;
}

/* Function to reverse the linked list */
void reverse_list(listint_t **head) {
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/* Function to compare two linked lists */
int compare_lists(listint_t *head1, listint_t *head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->n != head2->n) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

/* Example usage */
int main() {
    listint_t *head = NULL;
    int result;

    /* Your code to create the linked list */

    result = is_palindrome(&head);
    if (result == 1) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}

