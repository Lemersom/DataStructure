#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

//Direcao da Raiz para as Folhas usa-se recursao
int isLeaf(node*);
node *root(node*);//retorna a raiz de uma arvore
int level(node*);//nivel em relacao a raiz
int depth(node*);//profundidade a partir de um noh
int isStrict(node*);//nohs com filhos direitos e esquerdos, ou sao folha
int isComplete(node*);//nohs com filhos direitos e esquerdos e folhas no treeDepth
int treeDepth(node*);//profundidade a partir da raiz
void showTree(node*);

int lenght(node*);//quantidade de nohs
int highestValue(node*);//maior valor da arvore
int sumTree(node*);//soma os valores da arvore

int max(int, int);

node *insert(node*, int);
node *search(node*, int);


int main(){

    return 0;
}


//sem recursao
node *insert(node *tree, int value){
    if(tree == NULL) return makeTree(value);
    node *aux;
    while(tree != NULL){
        aux = tree;
        if(value < tree->info) tree = tree->left;
        else tree = tree->right;
    }
    if(value < aux->info) addLeft(aux, value);
    else addRight(aux, value);
}

//sem recursao
node *search(node *tree, int key){
    while(tree != NULL){
        if(tree->info == key) break;
        else if(key < tree->info) tree = tree->left;
        else tree = tree->right;
    } 
    return tree;
}


int max(int a, int b){
    return a > b ? a : b; //se a > b retorna a, senao retorna b
}

int isLeaf(node *n){
    return n->left == NULL && n->right == NULL;
}

node *root(node *n){
    while(n->father != NULL){
        n = n->father;
    }
    return n;
}
/*Versao Recursiva
node *root(node *n){
    if(n->father == NULL) return n;
    return root(n->father);
}
*/

int level(node *n){
    int i = 0;
    while(n->father != NULL){
        i++;
        n = n->father;
    }
    return i;
}
/*Versao Recursiva
int level(node *n){
    if(n->father == NULL) return 0;
    else return level(n->father) + 1;
}
*/

int depth(node *n){
    if(n == NULL || isLeaf(n)) return 0;
    return max(depth(n->left), depth(n->right)) + 1;
}

int isStrict(node *tree){
    if(tree == NULL) return 0;
    else if(isLeaf(tree)) return 1;
    return isStrict(tree->left) && isStrict(tree->right);
}

int isComplete(node *tree){
    if(tree == NULL) return 0;
    else if(isLeaf(tree)) return level(tree) == treeDepth(tree);
    return isComplete(tree->left) && isComplete(tree->right);
}

int treeDepth(node *tree){
    return depth(root(tree));
}

void showTree(node *tree){
    if(tree == NULL) return;
    printf("No: %2d\n", tree->info);
    printf("  -> Filhos: [%2d, %2d]\n", tree->left->info, tree->right->info);
    printf("  -> Nivel: %d\n", level(tree));
    printf("  -> Profundidade: %d\n\n", depth(tree));
    showTree(tree->left);
    showTree(tree->right);
}

int lenght(node *tree){
    if(tree == NULL) return 0;
    return lenght(tree->left) + lenght(tree->right) + 1;
}

int highestValue(node *tree){
    if(tree == NULL) return 0;
    int h = max(highestValue(tree->left), highestValue(tree->right));
    return max(tree->info, h);
}

int sumTree(node *tree){
    if(tree == NULL) return 0;
    return tree->info + sumTree(tree->left) + sumTree(tree->right);
}



//--------------------------------------------------------------------//
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
