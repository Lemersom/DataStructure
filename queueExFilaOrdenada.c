/*
4) Escreva um programa que verifique se os elementos de uma fila estão ordenados de
forma crescente, utilizando apenas as funções de manipulação de fila:
enqueue/dequeue/isQueueEmpty.
*/

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
void filaCrescente(queue*);


int main(){
    queue *q = newQueue();

    enqueue(q, 4);
    enqueue(q, 1);
    dequeue(q);
    enqueue(q, 3);
    enqueue(q, 4);


    showQueue(q);

    filaCrescente(q);

    return 0;
}


void filaCrescente(queue *q){
    if(q->tail > N){ // Circular Queue
        int n, menor = q->data[q->head % N], maior = q->data[q->tail % N -1],
            i = q->head + 1, aux = q->data[i % N]; // temporario

        while(!isQueueEmpty(q)){
            n = dequeue(q);
            if(q->head != 1 && i != q->tail){
                if(n < menor || n > maior || n > aux){
                    printf("Fila nao esta em Ordem Crescente\n");
                    return;
                }
            }
            i++;
            aux = q->data[i % N];
        }

        if(n != maior){
            printf("Fila nao esta em Ordem Crescente"); 
            return;
        }
    }
    else{ // Not a Circular Queue
        int n, menor = q->data[q->head], maior = q->data[q->tail - 1],
            i = q->head + 1, aux = q->data[i]; // temporario

        while(!isQueueEmpty(q)){
            n = dequeue(q);
            if(q->head != 1 && i != q->tail){
                if(n < menor || n > maior || n > aux){
                    printf("Fila nao esta em Ordem Crescente\n");
                    return;
                }
            }
            i++;
            aux = q->data[i];
        }

        if(n != maior){
            printf("Fila nao esta em Ordem Crescente"); 
            return;
        }
    }
    

    printf("Fila esta em Ordem Crescente\n");
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
        exit(1);
    }

    q->data[q->tail % N] = n;
    q->tail++;
}

int dequeue(queue *q){
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
        printf("[%d] ", q->data[i % N]);
    printf("\n");
}