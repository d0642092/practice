#ifndef _LINKLIST_
#define _LINKLIST_ _LINKLIST.H_

typedef struct node{
    int data;
    struct node * next;
}NODE;

NODE* createNewNode(int);

NODE* searchNode(NODE*,int);

NODE* searchNodeBeforeNode(NODE*,NODE*);

void insertNewDataAtLast(NODE**,int);

void insertAfterNode(NODE*,NODE*);

void freeList(NODE**);

void removeNode(NODE**,int);

void printDataAfterNode(NODE*);

void swap(NODE**,NODE*,NODE*);

NODE*searchEndNode(NODE*);

void sort(NODE**head);

#endif // _LINKLIST_
