#include "../inc/header.h"

 void mx_pop_back_node(AdjListNode **head) {
    if (head == NULL || *head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    AdjListNode *current = *head;

    while (current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
}
