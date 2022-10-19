#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
    int info;
    struct nodeitem *next;
}node;

typedef struct{
    node *top;
}stack;

stack *newStack();
node *newNode(int);
int isStackEmpty(stack*);
void push(stack*, int);
int pop(stack*);
int top(stack*);

int main(){

    stack *s = newStack();



    // printStack
    while(!isStackEmpty(s)){
        printf("[%d]", pop(s));
    }
    printf("\n");

    return 0;
}

stack *newStack(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

node *newNode(int value){
    node *n = (node*)malloc(sizeof(node));
    n->info = value;
    n->next = NULL;
    return n;
}

int isStackEmpty(stack *s){
    return s->top == NULL;
}

void push(stack *s, int value){
    node *n = newNode(value);

    n->next = s->top;
    s->top = n;
}

int pop(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty");
        exit(1);
    }
    
    node *n = s->top;
    int num = n->info;
    s->top = n->next;
    free(n);
    return num;
}

int top(stack *s){
    if(isStackEmpty(s)){
        printf("\nStack is Empty");
        exit(1);
    }
    return s->top->info;
}