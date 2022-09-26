#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct{
    int data[N];
    int head;
    int tail;
}queue;

queue *newQueue();
void enqueue(queue*, int);
int dequeue(queue*);
int isQueueEmpty(queue*);
int isQueueFull(queue*);
void showQueue(queue*);

int main(){
    queue *q = newQueue();



    showQueue(q);

    return 0;
}

queue *newQueue(){
    queue *q = (queue*) malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    return q;
}

void enqueue(queue *q, int n){
    if(isQueueFull(q)){
        printf("Queue is Full - Queue Overflow\n");
        return;
    }

    q->data[q->tail % N] = n;
    q->tail++;
}

int dequeue(queue *q){
    if(isQueueEmpty(q)){
        printf("Queue is Empty - Queue Underflow\n");
        return -1;
    }

    q->head++;
    return q->data[(q->head - 1) % N];
}

int isQueueEmpty(queue *q){
    return q->head == q->tail;
}

int isQueueFull(queue *q){
    return q->tail - q->head == N;
}

void showQueue(queue *q){
    int i;
    for(i = q->head; i < q->tail; i++)
        printf("[%d] ", q->data[i % N]);
}