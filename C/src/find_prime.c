#include <stdio.h>
#include <stdlib.h>
#include <math.h>//上網找的

int main()
{
    int num[100000];//陣列大小
    int i = 1;//要儲存的陣列
    int j;//以儲存的陣列
    int n = 2;
    int flag = 0;
    num[0]=2;//已知第一個質數

    while(i<100000){
        flag = 0;//flag 要重置
        n++;
        for(j=0;j<(int)sqrt(n);j++){//sqrt()是小數形式 要轉為 int
            if((n%num[j])==0){
                flag = 1;//表示有碰到可以整除n的質數
                break;
            }
            else{
                continue;
            }
            /*如果已經有質數可以整除n就離開
                若沒有就繼續找
                    找到迴圈結束或有數可以整除
                */
        }
        if(flag==1){
            continue;
        }
        /*表示有碰到可以整除n的質數
            繼續迴圈且n+1
        */
        else{
            num[i]=n;
        }
        /*表示沒有找到可以整除n的質數
            將n存到 num[i] 裡
        */
        i++;
    }
    printf("%d\n",num[99999]);//因為陣列是從0開始
    system("pause");
    return 0;
}

