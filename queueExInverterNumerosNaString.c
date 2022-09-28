/*
5) Escreva um programa que receba uma sequencia alfanumérica (letras e números). O
programa deve processar a sequencia para que as letras sejam exibidas na ordem em que
foram apresentadas e que os números sejam apresentados em ordem invertida.
Exemplo:
A 1 E 5 T 7 W 8 G → A 8 E 7 T 5 W 1 G
3 9 C A 4 6 Q → 6 4 C A 9 3 Q
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct{
    int data[N];
    int head;
    int tail;
}queue;

typedef struct{
    int data[N];
    int top;
}stack;


stack *newStack();
void push(stack*, int);
int pop(stack*);
int top(stack*);
int isStackEmpty(stack*);
int isStackFull(stack*);

queue *newQueue();
void enqueue(queue*, char);
char dequeue(queue*);
int isQueueEmpty(queue*);
int isQueueFull(queue*);
void showQueue(queue*);


queue *sequencia(char[]);

int main(){

    queue *q = sequencia("A1E5T7W8G");

    showQueue(q);

    return 0;
}


queue *sequencia(char str[]){
    queue *q = newQueue();
    stack *s = newStack();
    int c;

    for(c = 0; c < strlen(str); c++){
        if(str[c] >= 48 && str[c] <= 57){
            push(s, str[c]);
        }
    }

    for(c = 0; c < strlen(str); c++){
        if(str[c] >= 48 && str[c] <= 57){
            enqueue(q, pop(s));
        }else{
            enqueue(q, str[c]);
        }
    }
    free(s);

    return q;
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

void push(stack *s, int n){
    if(isStackFull(s)){
        printf("\nStack is Full - Stack Overflow\n");
        exit(1);
    }
    s->data[s->top] = n;
    s->top++;
}

int pop(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty - Stack Underflow\n");
        exit(1);
    }
    s->top--;
    return s->data[s->top];
}

int top(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty -- Stack Underflow\n");
        exit(1);
    }
    return s->data[s->top-1];
}

int isStackEmpty(stack *s){
    return s->top == 0;
}

int isStackFull(stack *s){
    return s->top == N;
}