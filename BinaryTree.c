#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
    int info;
    struct nodeitem *father;
    struct nodeitem *left;
    struct nodeitem *right;
}node;


node *brother(node*);
int isLeft(node*);
int isRight(node*);

node *makeTree(int);
void addLeft(node*, int);
void setNodeLeft(node*, node*);
void addRight(node*, int);
void setNodeRight(node*, node*);
void freeTree(node*);

void preOrdem(node*); //Noh atual, filho esquerdo, filho direito
void emOrdem(node*); //Filho esquerdo, noh atual, filho direito
void posOrdem(node*); //Filho esquerdo, filho direito, noh atual

int main(){

    return 0;
}


node *brother(node *n){
    if(n->father == NULL) return NULL;
    if(isLeft(n)) return n->father->right;
    if(isRight(n)) return n->father->left;
}

int isLeft(node *n){
    if(n->father == NULL) return 0;
    return n->father->left == n;
}

int isRight(node *n){
    if(n->father == NULL) return 0;
    return n->father->right == n;
}


node *makeTree(int value){
    node *n = (node*)malloc(sizeof(node));
    n->father = n->left = n->right = NULL;
    n->info = value;

    return n;
}

void addLeft(node *tree, int value){
    node *n1 = makeTree(value);
    n1->father = tree;
    tree->left = n1;
}

void setNodeLeft(node *tree, node *n){
    tree->left = n;
    n->father = tree;
}

void addRight(node *tree, int value){
    node *n = makeTree(value);
    n->father = tree;
    tree->right = n;
}

void setNodeRight(node *tree, node *n){
    tree->right = n;
    n->father = tree;
}

void freeTree(node *n){
    if(n != NULL){
        node *father = n->father;
        freeTree(n->left);
        freeTree(n->right);

        if(isLeft(n)) father->left = NULL;
        if(isRight(n)) father->right = NULL;

        free(n);
    }
}


//Noh atual, filho esquerdo, filho direito
void preOrdem(node *n){
    if(n != NULL){
        printf("[%d]", n->info);
        preOrdem(n->left);
        preOrdem(n->right);
    } 
}

//Filho esquerdo, noh atual, filho direito
void emOrdem(node *n){
    if(n != NULL){
        emOrdem(n->left);
        printf("[%d]", n->info);
        emOrdem(n->right);
    }
}

//Filho esquerdo, filho direito, noh atual
void posOrdem(node *n){
    if(n != NULL){
        posOrdem(n->left);
        posOrdem(n->right);
        printf("[%d]", n->info);
    }
}