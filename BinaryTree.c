/* Binary Tree && Binary Search Tree*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
}node;


node *makeTree(int value);
int isLeft(node *n);
int isRight(node *n);
int isLeaf(node *n);
void addLeft(node *nf, int value);
void setNodeLeft(node *nf, node *nl);
void addRight(node *nf, int value);
void setNodeRight(node *nf, node *nr);
void freeTree(node *n);

void preOrdem(node *n); //current, left, right
void emOrdem(node *n);  //left, current, right
void posOrdem(node *n); //left, right, current

int max(int a, int b);

node *root(node *n);
int level(node *n);
int depth(node *n);
int treeDepth(node *n);
int isStrict(node *n);
int isComplete(node *n);
int nodeQuantity(node *n);
int highestValue(node *n);
int nodeSum(node *n);

node *insert(node *n, int value);      // Binary
node *search(node *n, int key);        // search
node *deleteRoot(node *tree);          // tree
node *delete(node *tree, int value);   // functions


int main(){
    //node *n = makeTree();


    return 0;
}


node *makeTree(int value){
    node *n = (node*)malloc(sizeof(node));
    n->father = NULL;
    n->info = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int isLeft(node *n){
    if(n->father == NULL) return 0;
    return n == n->father->left;
}

int isRight(node *n){
    if(n->father == NULL) return 0;
    return n == n->father->right;
}

int isLeaf(node *n){
    return n->left == NULL && n->right == NULL;
}

void addLeft(node *nf, int value){
    node *nl = makeTree(value);
    nf->left = nl;
    nl->father = nf;
}

void setNodeLeft(node *nf, node *nl){
    nf->left = nl;
    nl->father = nf;
}

void addRight(node *nf, int value){
    node *nr = makeTree(value);
    nf->right = nr;
    nr->father = nf;
}

void setNodeRight(node *nf, node *nr){
    nf->right = nr;
    nr->father = nf;
}

void freeTree(node *n){
    if(n != NULL){
        node *nFather = n->father;
        if(isLeft(n)) nFather->left = NULL;
        else if(isRight(n)) nFather->right = NULL;

        freeTree(n->left);
        freeTree(n->right);
        free(n);
    }
}


void preOrdem(node *n){ //current, left, right
    if(n != NULL){
        printf("[%d]", n->info);
        preOrdem(n->left);
        preOrdem(n->right);
    }
}

void emOrdem(node *n){ //left, current, right
    if(n != NULL){
        emOrdem(n->left);
        printf("[%d]", n->info);
        emOrdem(n->right);
    }
}

void posOrdem(node *n){ //left, right, current
    if(n != NULL){
        posOrdem(n->left);
        posOrdem(n->right);
        printf("[%d]", n->info);
    }
}


int max(int a, int b){
    return a > b ? a : b;
}


node *root(node *n){
    while(n->father != NULL){
        n = n->father;
    } 
    return n;
}
/* Recursive Version
node *root(node *n) {
    if (n->father == NULL) return n;
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
/* Recursive Version
int level(node *n){
    if(n->father == NULL) return 0;
    else return level(n->father) + 1;
}
*/

int depth(node *n){
    if(n == NULL || isLeaf(n)) return 0;
    return max(depth(n->left), depth(n->right)) + 1;
}

int treeDepth(node *n){
    return depth(root(n));
}

int isStrict(node *n){
    if(n == NULL) return 0;
    else if(isLeaf(n)) return 1;
    return isStrict(n->left) && isStrict(n->right);
}

int isComplete(node *n){
    if(n == NULL) return 0;
    else if(isLeaf(n)) return level(n) == treeDepth(n);
    return isComplete(n->left) && isComplete(n->right);
}

int nodeQuantity(node *n){
    if(n == NULL) return 0;
    return nodeQuantity(n->left) + nodeQuantity(n->right) + 1;
}

int highestValue(node *n){
    int h;
    if(n == NULL) return 0;
    h = max(highestValue(n->left), highestValue(n->right));
    return max(n->info, h);
}

int nodeSum(node *n){
    if(n == NULL) return 0;
    return n->info + nodeSum(n->left) + nodeSum(n->right);
}


node *insert(node *n, int value){
    if(n == NULL) return makeTree(value);
    
    if(value < n->info) setNodeLeft(n, insert(n->left, value));
    else setNodeRight(n, insert(n->right, value));
    return n;
}

node *search(node *n, int key){
    if(n == NULL || n->info == key) return n;
    if(key < n->info) return search(n->left, key);
    else return search(n->right, key);
}

node *deleteRoot(node *tree){
    node *n, *f;

    if(tree->left == NULL) n = tree->right;
    else{
        n = tree->left;
        while(n->right != NULL){
            n = n->right;
        }

        if(n->father != tree){
            f = n->father;
            setNodeRight(f, n->left);
            setNodeLeft(n, tree->left);
        }
        setNodeRight(n, tree->right);
    }

    if(n != NULL) n->father = NULL;
    free(tree);
    return n;
}

node *delete(node *tree, int value){
    node *n = search(tree, value);
    node *f = n->father;
    if(f == NULL) return deleteRoot(n);

    if(isLeft(n)) setNodeLeft(f, deleteRoot(n));
    else setNodeRight(f, deleteRoot(n));

    return tree;
}