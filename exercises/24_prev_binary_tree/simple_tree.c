#include "simple_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, TreeNode *tree_node) {
    
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->tree_node = tree_node;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }

    QueueNode *temp = q->front;
    TreeNode *tree_node = temp->tree_node;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return tree_node;
}

bool is_empty(Queue *q) {
    return q->front == NULL;
}

void free_queue(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

TreeNode* build_tree_by_level(int *level_order, int size) {
    // TODO: 在这里添加你的代码
    if (size == 0) {
        return NULL;
    }
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = level_order[0];
    root->left = root->right = NULL;
    Queue *q = create_queue();
    enqueue(q, root);
    int index = 1;
    while (!is_empty(q) && index < size){
        //dequeue current node
        TreeNode *current = dequeue(q);
        //add left 2*index +1 and right 2*index +2 node to queue
        if (index < size) {
            if (level_order[index] != INT_MIN) {
                TreeNode *left_node = (TreeNode*)malloc(sizeof(TreeNode));
                left_node->val = level_order[index];
                left_node->left = left_node->right = NULL;
                current->left = left_node;
                enqueue(q, left_node);
            }
            index++;
        }
        if (index < size) {
            if (level_order[index] != INT_MIN) {
                TreeNode *right_node = (TreeNode*)malloc(sizeof(TreeNode));
                right_node->val = level_order[index];
                right_node->left = right_node->right = NULL;
                current->right = right_node;
                enqueue(q, right_node);
            }
            index++;
        }
        //add left and right node to current node
        
    }
    return root;
}

void preorder_traversal(TreeNode *root) {
    // TODO: 在这里添加你的代码
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preorder_traversal(root->left);
    preorder_traversal(root->right); 
}

void preorder_traversal_iterative(TreeNode *root) {
    // TODO: 在这里添加你的代码
    if (root == NULL) {
        return;
    }
    Queue *q = create_queue();
    enqueue(q, root);
    while (!is_empty(q)) {
        TreeNode *current = dequeue(q);
        printf("%d ", current->val);
        
        if (current->left) {
            enqueue(q, current->left);
        }
        if (current->right) {
            enqueue(q, current->right);
        }
    }
    free(q);

}

void free_tree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
