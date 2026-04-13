#include "circular_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_circular_list(int n) {
    // 参数校验
    if (n <= 0) return NULL;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->id = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // 形成环
    if (tail != NULL) {
        tail->next = head;
    }

    return head;
}

void free_list(Node* head) {
    if (head == NULL) return;
    
    Node* current = head;
    do {
        Node* next = current->next;
        free(current);
        current = next;
    } while (current != head);
}
