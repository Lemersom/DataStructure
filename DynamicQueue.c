#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
    int info;
    struct nodeitem *next;
}node;

typedef struct{
    node *head;
    node *tail;
}queue;


queue *newQueue();
node *newNode(int);
int isQueueEmpty(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
void showQueue(queue*);


int main(){

    queue *q = newQueue();



    showQueue(q);

    return 0;
}


queue *newQueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

node *newNode(int value){
    node *n = (node*)malloc(sizeof(node));
    n->info = value;
    n->next = NULL;
    return n;
}

int isQueueEmpty(queue *q){
    if(q->head == NULL){
        q->tail = NULL;
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q, int value){
    node *n = newNode(value);
    if(isQueueEmpty(q)){
        q->head = n;
        q->tail = n;
        return;
    }
    q->tail->next = n;
    q->tail = n;
}

int dequeue(queue *q){
    if(isQueueEmpty(q)){
        printf("\nQueue is Empty");
        exit(1);
    }
    node *n = q->head;
    q->head = q->head->next;
    int num = n->info;
    free(n);
    return num;
}

void showQueue(queue *q){
    if(isQueueEmpty(q)){
        printf("\nQueue is Empty");
        exit(1);
    }
    node *n = q->head;
    while(n != NULL){
        printf("[%d]", n->info);
        n = n->next;
    }
    printf("\n");
}