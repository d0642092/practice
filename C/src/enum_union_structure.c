#include <stdio.h>
#include <stdlib.h>

typedef enum{
    Int=1,String=2
}condition;         /*兩種型態 1=Int 2=String*/
typedef union{
    int number;
    char word[10];
}contain;           /*每筆資料所含內容*/
typedef struct{
    contain data;
    condition type;
}document;          /*每個文件內容*/
int main()
{
    int times=0;/*次數*/
    condition choose;
    document file[10];      /*10個文件*/
    while(times<10){
        printf("Please enter which type you want to input(1.Int 2.String): ");
        scanf("%d",&choose);
        switch(choose){
            case Int:
                printf("Please enter data: ");
                scanf("%d",&file[times].data.number);
                file[times].type = Int;     /*第 times 文件型態為 Int*/
                times++;
                break;
            case String:
                printf("Please enter data: ");
                scanf("%s",file[times].data.word);
                file[times].type = String; /*第 times 文件型態為 String*/
                times++;
                break;
            default:
                break;
        }
    }
    for(times=0;times<10;times++){
        if(file[times].type == Int){
            printf("%d. %d\n",times+1,file[times].data.number);
        }
        else{
            printf("%d. %s\n",times+1,file[times].data.word);
        }
    }
}
