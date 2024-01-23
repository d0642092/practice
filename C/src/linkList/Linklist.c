#include <stdlib.h>
#include <stdio.h>
#include "Linklist.h"

NODE* createNewNode(int data){
    NODE*tmp = (NODE*)malloc(sizeof(NODE));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

NODE* searchNode(NODE*start,int want){
    NODE*tmp = start;
    while(tmp!=NULL){
        if(tmp->data==want)return tmp;
        else tmp=tmp->next;
    }
    return NULL;
}

NODE* searchNodeBeforeNode(NODE*start,NODE*want){
    NODE*tmp = start;
    while(tmp!=NULL){
        if(tmp->next==want)return tmp;
        else tmp=tmp->next;
    }
    return NULL;
}

void insertNewDataAtLast(NODE**head,int data){
    NODE*tmp=*head;
    NODE*newNode = createNewNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next=newNode;
    }
}

void insertAfterNode(NODE* n1,NODE* n2){
    n2->next=n1->next;
    n1->next=n2;
}

void freeList(NODE**head){
    NODE*tmp = *head;
    NODE*tmp2;
    while(tmp!=NULL){
        tmp2 = tmp->next;
        free(tmp);
        tmp=tmp2;
    }
    head=NULL;
}

void removeNode(NODE**head,int data){
    NODE* delNode = searchNode(*head,data);
    NODE* lastNode;
    if(delNode!=NULL){
        if(delNode==*head){
            *head = delNode->next;
        }
        else{
            lastNode = searchNodeBeforeNode(*head,delNode);
            lastNode->next=delNode->next;
        }
        free(delNode);
    }
}

void swap(NODE**head,NODE*n1,NODE*n2){
    NODE* beforeN1;
    NODE* beforeN2;
    NODE* tmp;
    if(*head==n1){
        beforeN2 = searchNodeBeforeNode(*head,n2);
        *head = n2;
        beforeN2->next=n1;
        tmp = n1->next;
        n1->next = n2->next;
        n2->next=tmp;
    }
    else if(*head==n2){
        beforeN1 = searchNodeBeforeNode(*head,n1);
        *head = n1;
        beforeN1->next=n2;
        tmp = n1->next;
        n1->next = n2->next;
        n2->next=tmp;
    }
    else{
        beforeN1 = searchNodeBeforeNode(*head,n1);
        beforeN2 = searchNodeBeforeNode(*head,n2);
        beforeN1->next=n2;
        beforeN2->next=n1;
        tmp = n1->next;
        n1->next = n2->next;
        n2->next=tmp;
    }
}

void printDataAfterNode(NODE*tmp){
    if(tmp!=NULL){
        printf("Data=%d",tmp->data);
        while(tmp->next!=NULL){
            tmp=tmp->next;
            printf(" -> %d",tmp->data);
        }
        printf("\n");
    }
    else{
        printf("No Data...");
    }
}

NODE*searchEndNode(NODE*start){
    while(start->next!=NULL){
        start = start->next;
    }
    return start;
}

void sort(NODE**head){
    NODE* i, *j;
    NODE* beforeJ,*tmp;

    //對應for(i=0; i<max_index; i++)
    for(i=*head; i->next!=NULL; i=i->next){
        //對應for(j=max_index; i<j-1; j--)
        for(j=searchEndNode(*head); i!=j; j=searchNodeBeforeNode(*head,j)){
            //找出index是j-1的節點
            beforeJ = searchNodeBeforeNode(*head,j);
            if(j->data < beforeJ->data){
                swap(head,j,beforeJ);
                tmp = beforeJ;  //fix index
                beforeJ = j;
                j = tmp;
                if(i==j){       //fix index
                    i=beforeJ;
                }
            }

        }

    }
}
