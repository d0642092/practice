#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *left;
    struct node *right;
    int data; // 0 false ; 1 true
    char vol;
}NODE;
void creatList(NODE*,int);
void postorder(NODE*);
int main()
{
    char value;
    scanf("%c",&value);     //��top�`�I
    NODE *head =(NODE*) malloc(1*sizeof(NODE));;
    head->left = NULL;
    head->right =NULL;
    head->vol = value;
    creatList(head,0);
    postorder(head);
    if(head->data == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
    return 0;
}
void creatList(NODE *head,int floor)
{
    char valueL,valueR; //�s���k�`�I
    printf("%d floor left node ",floor+1);//�@�h�@�h���
    scanf(" %c",&valueL);
    printf("%d floor right node ",floor+1);
    scanf(" %c",&valueR);
    if(valueL != '!' || valueR != '!'){     // ! ���P�_�O�_��NULL
        head->left = (NODE*)malloc(1*sizeof(NODE));
        head->right = (NODE*)malloc(1*sizeof(NODE));
        head->left->vol = valueL;
        head->right->vol = valueR;

        if(valueL == '!'){      //  ! �N���Υk�`�I�]��NULL
            head->left = NULL;
        }
        if(valueR == '!'){
            head->right = NULL;
        }
        floor++;
        if(head->left != NULL){     // �Y���Υk�`�I��NULL �h���L���쥪�Υk�`�I�B�J
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
void postorder(NODE*head){//�q�U���W�� �N�B�⧹���Ȧs��U�`�I��data{
    if(head!=NULL){
        postorder(head->left);
        postorder(head->right);
        switch(head->vol){
            case '~':
                head->data = !head->right->data;    //  �]�� ~ ���U�@�ӭȩ�b�k�`�I
                break;
            case '^':
                head->data = head->left->data && head->right->data; //�N���k�`�I��data���B��
                break;
            case 'V':
                head->data = head->left->data || head->right->data; //�N���k�`�I��data���B��
                break;
            case 'T':
                head->data = 1; // �]1��TRUE
                break;
            case 'F':
                head->data = 0; //�] 0��FALSE
                break;
        }
    } else return;
}
