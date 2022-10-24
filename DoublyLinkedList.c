#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
	int info;
	struct nodeitem *prev;
	struct nodeitem *next;
}node;

typedef struct{
	node *first;
	node *last;	
}dlist;


node *newNode(int);
dlist *newDlist();
int isDlistEmpty(dlist*);
void addFirst(dlist*, int);
void addLast(dlist*, int);
void addOn(dlist*, int, int);
int dlistSize(dlist*);
void showDlist(dlist*);
node *searchNode(dlist*, int);
void deleteValue(dlist*, int);
void deleteOn(dlist*, int); //using position
void deleteFirst(dlist*);
void deleteLast(dlist*);


int main(){
	
	dlist *l = newDlist();



    showDlist(l);
	
	return 0;
}


node *newNode(int value){
	node *n = (node*)malloc(sizeof(node));
	n->info = value;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

dlist *newDlist(){
	dlist *l = (dlist*)malloc(sizeof(dlist));
	l->first = NULL;
	l->last = NULL;
	return l;
}

int isDlistEmpty(dlist *l){
	return l->first == NULL;
}

void addFirst(dlist *l, int value){
	node *n = newNode(value);
	if(isDlistEmpty(l)){
		l->first = n;
		l->last = n;
		return;
	}
	
	n->next = l->first;
	l->first->prev = n;
	l->first = n;
}

void addLast(dlist *l, int value){
	node *n = newNode(value);
	if(isDlistEmpty(l)){
		l->first = n;
		l->last = n;
		return;
	}
	
	n->prev	= l->last;
	l->last->next = n;
	l->last = n;
}

void addOn(dlist *l, int value, int pos){
	if(pos == 0){
		addFirst(l, value); return;
	}
	else if(pos == dlistSize(l)){
		addLast(l, value); return;
	}

	node *n = l->first;
	int i = 0;
	while(n != NULL){
		if(pos == i){
			node *n1 = newNode(value);
			n->prev->next = n1;
			n1->prev = n->prev;
			n1->next = n;
			n->prev = n1;
			return; 
		}
		n = n->next;
		i++;
	}
	
	printf("\nPosition Not Found");
	exit(1);
}

int dlistSize(dlist *l){
	if(isDlistEmpty(l)) return 0;
	
	node *n = l->first;

	int i = 0;
	while(n != NULL){
		i++;
		n = n->next;
	}
	
	return i;
}

void showDlist(dlist *l){
	node *n = l->first;
	printf("List Size: %d\n", dlistSize(l));
	while(n != NULL){
		printf("[%d] ", n->info);
		n = n->next;
	}
    printf("\n");
}

node *searchNode(dlist *l, int value){
	node *n = l->first;
	while(n != NULL){
		if(n->info == value) break;
		n = n->next;
	}
	return n;
}

void deleteValue(dlist *l, int value){
	node *n = searchNode(l, value);
	
	if(n == NULL){
		printf("\nValue not Found");
		exit(1);
	}

	if(n == l->first){
		deleteFirst(l);
		return;
	}
	if(n == l->last){
		deleteLast(l);
		return;
	}
	
	n->prev->next = n->next;
	n->next->prev = n->prev;
	
	free(n);

}

void deleteFirst(dlist *l){
	if(isDlistEmpty(l)){
		printf("\nList is Empty");
		exit(1);
	}

	node *n = l->first;
	l->first = n->next;
	l->first->prev = NULL;
	free(n);
}

void deleteLast(dlist *l){
	if(isDlistEmpty(l)){
		printf("\nList is Empty");
		exit(1);
	}

	node *n = l->last;
	l->last = l->last->prev;
	l->last->next = NULL;
	free(n);
}

void deleteOn(dlist *l, int pos){
	if(isDlistEmpty(l)){
		printf("\nList is Empty");
		exit(1);
	}

	if(pos < 0 || pos > dlistSize(l) - 1){
		printf("\nPosition Error");
		exit(1);
	}
	if(pos == 0){
		deleteFirst(l);
		return;
	}
	if(pos == dlistSize(l) - 1){
		deleteLast(l);
		return;
	}

	node *n = l->first;
	int i = 0;

	while(n != NULL){
		if(i == pos) break;
		i++;
		n = n->next;
	}

	if(n == NULL){
		printf("\nPosition not Found");
		exit(1);
	}

	n->prev->next = n->next;
	n->next->prev = n->prev;

	free(n);
}
