/*
João está trabalhando em uma mina, tentando retirar o máximo que consegue de
diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada
retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada
“.<...<<..>>....>....>>>.”, três diamantes são formados.
Exemplos:
“<..><.<..>>” Resp: 3
“<<<..<......<<<<....>” Resp: 1
Escreva um programa que receba uma string e imprima o número de diamantes
encontrados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef struct{
    char data[N];
    int top;
}stack;

stack *newStack();
void push(stack*, char);
int pop(stack*);
int top(stack*);
int isStackEmpty(stack*);
int isStackFull(stack*);

int minerar(char[]);

int main(){
    char string[N] = {"..><..><<<..>>.<<..>.<..>"};
    
    int diamantes = minerar(string);

    if(diamantes == 0){
        printf("Não tiveram diamantes minerados");
    }
    else printf("%d diamantes minerados", diamantes);

    return 0;
}

int minerar(char string[]){
    stack *s = newStack();
    int i, diamante = 0;
    for(i = 0; i < strlen(string); i++){
        if(string[i] == '<'){
            push(s, '<');
        }
        else if(string[i] == '>' && s->top != 0){
            pop(s);
            diamante++;
        }
    }
    return diamante;
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

int pop(stack *s){
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
