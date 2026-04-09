#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;
void init_queue(Queue *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}
void enqueue(Queue *q, People p) {
    if (q->count == MAX_PEOPLE){
        return;
    }
    q->data[q->tail]   = p;
    q->tail = (q->tail + 1) % MAX_PEOPLE;
    q->count++;
}
People dequeue(Queue *q) {
    People temp = q->data[q->head]; // 先保存要淘汰的人
    if (q->count == 0) {
        People empty = {0};
        return empty;
    }
    q->head = (q->head + 1) % MAX_PEOPLE;
    q->count--;
    return temp;
}
int isEmpty(Queue *q) {
    return q->count == 0;
}


int main() {
    Queue q;
    init_queue(&q);

    int total_people=50;
    int report_interval=5;
    int eliminate_count = 0; 
    for (int i=1; i<=total_people; i++) {
        People p = {i};
        enqueue(&q,p);
    }
    while(q.count>1 ){
        for (int i = 0; i < report_interval - 1; i++) {
            if (!isEmpty(&q)) {
                People p = q.data[q.head];
                dequeue(&q);
                enqueue(&q, p);
            }
        }
        if (!isEmpty(&q)) {
            People out = dequeue(&q); // 移除当前间隔的最后一个
            eliminate_count++;
            printf("淘汰: %d\n", out.id); 
        }
    }
    
      printf("\n总共淘汰人数：%d\n", eliminate_count);
    printf("最后剩下的人是: %d\n", q.data[q.head].id);

    return 0;
}