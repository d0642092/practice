#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *left;
    struct node *right;
    char vol;
}NODE;
void creatList(NODE*);
NODE *node(char);
void inorder(NODE*);
void postorder(NODE*);
void preorder(NODE*);
int main()
{
    NODE *head =(NODE*) malloc(1*sizeof(NODE));;
    creatList(head);
    printf("Inorder: ");
    inorder(head);
    printf("\nPostorder: ");
    postorder(head);
    printf("\nPreorder: ");
    preorder(head);
    return 0;
}
void creatList(NODE *head)
{
    int i=0;
    char valueLeft,valueRight;      //存左右節點值
    NODE *ptr= head;
    printf("Top node is ");
    scanf("%c",&valueLeft);
    ptr->vol = valueLeft;
    ptr->left = NULL;
    ptr->right = NULL;
    while(valueLeft != '!'){
        printf("%d floor with left node\n",i+2);      //一層一層塞值
        scanf(" %c",&valueLeft);/*會吃到上一個enter*/
        if(valueLeft == '!'){
            break;
        }
        printf("%d floor with right node\n",i+2);
        scanf(" %c",&valueRight);/*會吃到上一個enter*/

        i++;

        ptr->left = node(valueLeft);      //創節點空間
        ptr->right = node(valueRight);
        ptr = ptr->left;            //往左移
    }
    return;
}
NODE *node(char value)  //創節點
{
    NODE *ptr = (NODE*) malloc(1*sizeof(NODE));
    ptr->vol = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void inorder(NODE*head)//先移到最左在print後遞迴往右重複步驟
{
    if(head!=NULL){
        inorder(head->left);
        printf("%c  ",head->vol);
        inorder(head->right);
    }
    else return;
}
void postorder(NODE*head) //先檢查左右節點有沒有東西沒印在印自己
{
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        printf("%c  ",head->vol);
    }
    else return;
}
void preorder(NODE*head)    //先印自己在印左右節點
{
    if(head!=NULL){
        printf("%c  ",head->vol);
        preorder(head->left);
        preorder(head->right);
    }
    else return;
}
