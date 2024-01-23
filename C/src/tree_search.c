#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}NODE;

void creatList(NODE*,int);
int search(int,NODE*);

int main()
{
    int value1,value2;      //創2數的top 節點
    printf("Input Tree 1 top and Tree 2 top \n");
    scanf("%d %d",&value1,&value2);
    printf("Tree 1: \n");
    NODE *head1 =(NODE*) malloc(1*sizeof(NODE));;
    head1->left = NULL;
    head1->right =NULL;
    head1->data = value1;
    creatList(head1,0);//建樹

// tree 2
    printf("\nTree 2: \n");
    NODE *head2 =(NODE*) malloc(1*sizeof(NODE));;
    head2->left = NULL;
    head2->right =NULL;
    head2->data = value2;
    creatList(head2,0);//建樹

    if(search(2,head1)){    //search(2,head1)==1 為TRUE
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    if(search(66,head2)){   //search(66,head2)==1 為TRUE
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}
void creatList(NODE *head,int floor)
{
    int valueL,valueR;//存左右節點
    printf("%d floor left node ",floor+1);//一層一層塞值
    scanf(" %d",&valueL);
    printf("%d floor right node ",floor+1);
    scanf(" %d",&valueR);
    if(valueL != -1 || valueR != -1){   // -1 為判斷是否塞NULL
        head->left = (NODE*)malloc(1*sizeof(NODE));
        head->right = (NODE*)malloc(1*sizeof(NODE));
        head->left->data = valueL;
        head->right->data = valueR;

        if(valueL == -1){   //  -1 將左或右節點設為NULL
            head->left = NULL;
        }
        if(valueR == -1){
            head->right = NULL;
        }
        floor++;
        if(head->left != NULL){      // 若左或右節點為NULL 則跳過移到左或右節點步驟
            creatList(head->left,floor);
        }
        if(head->right != NULL){
            creatList(head->right,floor);
        }
    }
    else{
        head->left = NULL;
        head->right=NULL;
    }
}
int search(int num,NODE* head)
{
    // 因為為 2元搜尋樹 則左小右大
    while(head){
        if(num > head->data){
            head = head->right;
        }
        else if(num < head->data){
            head = head->left;
        }
        else{
            return 1;
        }
    }
    return 0;
}
