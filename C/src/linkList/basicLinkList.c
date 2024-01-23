#include<stdio.h>
#include<stdlib.h>
#include "Linklist.h"

int main(int argc, char const *argv[])
{
    NODE* head=NULL,*tmp,*tmp2;
    while(1) {
        int choice, data,search;
        printf("Choose the function you want :\n");
        printf("1. Add data\n");
        printf("2. Add data after node\n");
        printf("3. Remove data\n");
        printf("4. Sort\n");
        printf("5. Print All datas\n");
        printf("6. Print data after node\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Input data:");
                scanf("%d", &data);
                insertNewDataAtLast(&head,data);
                printf("Add data successfully!\n");
                break;
            case 2:
                printf("Input new data:");
                scanf("%d", &data);
                printf("Input data where you want to put:");
                scanf("%d", &search);
                tmp = searchNode(head,search);
                if(tmp!=NULL){
                    tmp2 = createNewNode(data);
                    insertAfterNode(tmp,tmp2);
                }
                break;
            case 3:
                printf("Input want you want to remove");
                scanf("%d", &data);
                removeNode(&head,data);
                break;
            case 4:
                sort(&head);
                break;
            case 5:
                printDataAfterNode(head);
                break;
            case 6:
                printf("Input data you want to search:");
                scanf("%d", &data);
                tmp = searchNode(head,data);
                printDataAfterNode(tmp);
                break;
            case 7:
                freeList(&head);
                exit(0);
            default:
                printf("Error!\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
