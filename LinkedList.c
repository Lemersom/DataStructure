#include <stdio.h>
#include <stdlib.h>


typedef struct nodeitem{
	int info;
	struct nodeitem *next;
}node;

typedef struct{
	node *first;
}list;



list *newList();
node *newNode(int);
int isListEmpty(list*);
void showList1(list*);
void showList2(node*);
void showList3(node *n);
int listSize(list*);
int search(list*, int);
node *addFirstValue(list*, int);
node *addLastValue(list*, int);
node *addValueOn(list*, int, int);
void removeFirstValue(list*);
void removeLastValue(list*);
void removeValueOn(list*, int);



int main(){

	list *l = newList();
	
	
	
	showList1(l);

	return 0;
}



list *newList(){
	list *l = (list*)malloc(sizeof(list));
	l->first = NULL;
	return l;
}

node *newNode(int value){
	node *n = (node*)malloc(sizeof(node));
	n->info = value;
	n->next = NULL;
	return n;
}

int isListEmpty(list *l){
	return l->first == NULL;
}

void showList1(list *l){
	node *n = l->first;
	
	while(n != NULL){
		printf("[%d] ", n->info);
		n = n->next;
	}
	printf("\n");
}

void showList2(node *n){
	while(n != NULL){
		printf("[%d] ", n->info);
		n = n->next;
	}
	printf("\n");
}

void showList3(node *n){
	if(n == NULL) return;
	printf("[%d] ", n->info);
	showList3(n->next);
}

int listSize(list *l){
	int c = 0;
	node *n = l->first;
	while(n != NULL){
		c++;
		n = n->next;
	}
	return c;
}

int search(list *l, int value){
	node *n = l->first;
	while(n != NULL){
		if(n->info == value){
			return 1;
		}
		n = n->next;
	}
	return 0;
}

node *addFirstValue(list *l, int value){
	//criar noh
	node *n = newNode(value);
	
	//atualizar o proximo noh
	n->next = l->first;
	
	//atualizar a lista
	l->first = n;
	
	return n;
}

node *addLastValue(list *l, int value){
	node *n1 = l->first;
	while(n1->next != NULL){
		n1 = n1->next;
	}

	node *n2 = newNode(value);
	n1->next = n2;

	return n2;
}

node *addValueOn(list *l, int value, int index){
	node *n1 = l->first;
	int c = 0;
	while(n1 != NULL){
		if(c == index-1){
			node *n2 = newNode(value);
			n2->next = n1->next;
			n1->next = n2;
			return n2;
		}
		n1 = n1->next;
		c++;
	}
	printf("\nERRO ao adicionar - Posicao nao encontrada");
	exit(1);
}

void removeFirstValue(list *l){
	l->first = l->first->next;
}

void removeLastValue(list *l){
	node *n1 = l->first;
	node *n2; //anterior
	while(n1 != NULL){
		if(n1->next == NULL){
			n2->next = NULL;
			free(n1);
			break;
		}
		n2 = n1;
		n1 = n1->next;
	}
}

void removeValueOn(list *l, int index){
	node *n1 = l->first;
	node *n2;
	int c = 0;
	while(n1 != NULL){
		if(c == index){
			n2->next = n1->next;
			free(n1);
			return;
		}
		c++;
		n2 = n1;
		n1 = n1->next;
	}

	printf("ERRO ao remover - Posicao nao encontrada");
	exit(1);
}