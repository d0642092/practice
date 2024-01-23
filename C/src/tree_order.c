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
    char valueLeft,valueRight;      //�s���k�`�I��
    NODE *ptr= head;
    printf("Top node is ");
    scanf("%c",&valueLeft);
    ptr->vol = valueLeft;
    ptr->left = NULL;
    ptr->right = NULL;
    while(valueLeft != '!'){
        printf("%d floor with left node\n",i+2);      //�@�h�@�h���
        scanf(" %c",&valueLeft);/*�|�Y��W�@��enter*/
        if(valueLeft == '!'){
            break;
        }
        printf("%d floor with right node\n",i+2);
        scanf(" %c",&valueRight);/*�|�Y��W�@��enter*/

        i++;

        ptr->left = node(valueLeft);      //�и`�I�Ŷ�
        ptr->right = node(valueRight);
        ptr = ptr->left;            //������
    }
    return;
}
NODE *node(char value)  //�и`�I
{
    NODE *ptr = (NODE*) malloc(1*sizeof(NODE));
    ptr->vol = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void inorder(NODE*head)//������̥��bprint�Ỽ�j���k���ƨB�J
{
    if(head!=NULL){
        inorder(head->left);
        printf("%c  ",head->vol);
        inorder(head->right);
    }
    else return;
}
void postorder(NODE*head) //���ˬd���k�`�I���S���F��S�L�b�L�ۤv
{
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        printf("%c  ",head->vol);
    }
    else return;
}
void preorder(NODE*head)    //���L�ۤv�b�L���k�`�I
{
    if(head!=NULL){
        printf("%c  ",head->vol);
        preorder(head->left);
        preorder(head->right);
    }
    else return;
}
