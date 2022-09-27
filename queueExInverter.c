/*
3) Escreva um programa que inverta uma fila (utilize uma pilha). O usuário pode realizar
as seguintes operações:
a) Inserir elementos na fila
b) Inverter a fila
c) Exibir a fila
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct{
    char data[N];
    int head;
    int tail;
}queue;

typedef struct{
    char data[N];
    int top;
}stack;

queue *newQueue();
void enqueue(queue*, char);
char dequeue(queue*);
int isQueueEmpty(queue*);
int isQueueFull(queue*);
void showQueue(queue*);
void inverteFila(queue*);

stack *newStack();
void push(stack*, char);
char pop(stack*);
int top(stack*);
int isStackEmpty(stack*);
int isStackFull(stack*);


int main(){
    queue *q = newQueue();

    enqueue(q, 'a');
    enqueue(q, 'b');
    dequeue(q);
    enqueue(q, 'c');
    enqueue(q, 'd');
    enqueue(q, 'e');
    dequeue(q);
    enqueue(q, 'f');

    showQueue(q);

    inverteFila(q);

    showQueue(q);

    return 0;
}


void inverteFila(queue *q){
    stack *s = newStack();
    int i = 0;
    
    for(i = q->head; i < q->tail; i++){
        push(s, q->data[i % N]);
    }

    q->head = 0; q->tail = 0;

    while(!isStackEmpty(s)){
        enqueue(q, pop(s));
    }
}

queue *newQueue(){
    queue *q = (queue*) malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    return q;
}

void enqueue(queue *q, char n){
    if(isQueueFull(q)){
        printf("Queue is Full - Queue Overflow\n");
        exit(1);
    }

    q->data[q->tail % N] = n;
    q->tail++;
}

char dequeue(queue *q){
    if(isQueueEmpty(q)){
        printf("Queue is Empty - Queue Underflow\n");
        exit(1);
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
        printf("[%c] ", q->data[i % N]);
    printf("\n");
}





stack *newStack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = 0;
    return s;
}

void push(stack *s, char n){
    if(isStackFull(s)){
        printf("\nStack is Full - Stack Overflow\n");
        return;
    }
    s->data[s->top] = n;
    s->top++;
}

char pop(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty - Stack Underflow\n");
        return -1;
    }
    s->top--;
    return s->data[s->top];
}

int top(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty -- Stack Underflow\n");
    }
    return s->data[s->top-1];
}

int isStackEmpty(stack *s){
    return s->top == 0;
}

int isStackFull(stack *s){
    return s->top == N;
}
