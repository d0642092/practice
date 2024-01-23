#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[10];
    int i,j;
    int temp;//暫存

    for (i=0;i<10;i++){
        scanf("%d",&num[i]);
    }
    for(j=9;j>0;j--){//比較次數
        for(i=0;i<j;i++){
            if(num[i]<num[i+1]){//交換
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%d ",num[i]);
    }
    system("pause");
    return 0;
}
