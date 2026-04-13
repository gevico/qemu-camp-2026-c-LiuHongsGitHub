#include "doubly_circular_queue.h"

#include <stdlib.h>

// 头尾哨兵
static struct node tailsentinel;
static struct node headsentinel = {0, NULL, &tailsentinel};
static struct node tailsentinel = {0, &headsentinel, NULL};

static link head = &headsentinel;
static link tail = &tailsentinel;

link make_node(int data) {
    link p = (link) malloc(sizeof(struct node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void free_node(link p) {
    free(p);
}

link search(int key) {
    for (link p = head->next; p != tail; p = p->next) {
        if (p->data == key) {
            return p;
        }
    }
    return NULL;
}

void insert(link p) {
    link first;
    if (p == NULL) return;
    first = head->next;
    head->next = p;
    p->prev = head;
    p->next = first;
    first->prev = p;
}




void delete(link p) {
    if (p == NULL) return;
    if (p == head || p == tail) return; // 不允许删除哨兵节点
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->prev = NULL;
    p->next = NULL;
}

void traverse(void (*visit)(link)) {
    if (visit == NULL) {
        return;
    }

    for (link p = head->next; p != tail; p = p->next) {
        visit(p);
    }
}

void destroy(void) {
    link first = head->next;
    while (first != tail) {
        link next = first->next;
        delete(first);
        free_node(first);
        first = next;
    }
    head->next = tail;
    tail->prev = head;
}
