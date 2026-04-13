#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// 全局头指针
static link head = NULL;

// 创建新节点
link make_node(unsigned char item) {
    link node = (link)malloc(sizeof(struct node));
    node->item = item; 
    node->next = NULL;
    return node;
}

// 释放节点
void free_node(link p) { free(p); }

// 查找节点
link search(unsigned char key) {
    while(head != NULL ){
        if(head->item == key){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// 在链表头部插入节点
void insert(link p) {
    push(p);
}

// 删除指定节点
void delete(link p) {
    if(p == NULL || head == NULL){
        return;
    }
    if (head == p){
        head = head->next;
        free_node(p);
        return;
    }
    link prev = head;
    while(prev->next != NULL && prev->next != p){
        prev = prev->next;
    }
    if (prev->next == p){
        prev->next = p->next;
        free_node(p);
        return;
    }
}

// 遍历链表
void traverse(void (*visit)(link)) {
    if (visit == NULL) {
        return;
    }

    for (link p = head; p != NULL; p = p->next) {
        visit(p);
    }
}

// 销毁整个链表
void destroy(void) {
    free_list(head);
    head = NULL;
}

// 在链表头部推入节点
void push(link p) { 
    if (p == NULL) {
        return;
    }
    p->next = head;
    head = p;
 }

// 从链表头部弹出节点
link pop(void) {
    if (head == NULL) {
        return NULL;
    }
    link p = head;
    head = head->next;
    p->next = NULL;
    return p;
}

// 释放链表内存
void free_list(link list_head) {
    while (list_head != NULL) {
        link p = list_head;
        list_head = list_head->next;
        free_node(p);
    }
}
