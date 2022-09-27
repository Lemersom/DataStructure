/*
3) Utilizando a estrutura de pilhas, resolva o problema de decidir se uma dada sequência
de parênteses e colchetes está bem-formada (ou seja, parênteses e colchetes são
fechados na respectiva ordem que foram abertos). Por exemplo, a sequência ( ( ) [ ( ) ] )
está bem formada, enquanto que a sequência ( [ ) ] está malformada.
Dica: Ao processar um item de abertura ‘(‘ ou ‘[‘ adicione o mesmo na pilha, ao encontrar
um item de fechamento ‘)’, ‘]’ remova o topo da pilha e confirme se o item removido é
correspondente ao item de abertura. Ao final do programa a pilha deve estar vazia e
lembre-se que em nenhum momento é possível remover um item se a pilha está vazia.
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

int bemFormado(char[]);

int main(){
    char string[N] = {"()( [] ) [( () )]"};
    
    int resp = bemFormado(string);

    if(resp == 0){
        printf("Sequencia esta mal formada");
    }
    else printf("Sequencia esta bem formada");

    return 0;
}

int bemFormado(char string[]){
    stack *s = newStack();
    int i;

    for(i = 0; i < strlen(string); i++){
        if(string[i] == '(' || string[i] == '[') push(s, string[i]);
        else if(string[i] == ')' && !isStackEmpty(s)){
            int p = pop(s);
            if(p != '(') return 0;
        }
        else if(string[i] == ']' && !isStackEmpty(s)){
            int p = pop(s);
            if(p != '[') return 0;
        }
        else if((string[i] == ']' || string[i] == ')') && s->top == 0) return 0;
    }
    if(!isStackEmpty(s)) return 0;


    return 1; // bem formada
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
