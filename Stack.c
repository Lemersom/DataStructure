#include <stdio.h>
#include <stdlib.h>

#define N 10

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

int main(){

    stack *s = newStack();


    return 0;
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
    return s->data[s->top--];
}

int isStackEmpty(stack *s){
    return s->top == 0;
}

int isStackFull(stack *s){
    return s->top == N;
}
