#include <stdio.h>
#include <stdlib.h>
typedef struct graph{
    int value;
    struct graph *next;
}GRAPH;

GRAPH Arr[8];   //存Graph
int mark[8];    //被visit過為-1 未visit為1

void creat(GRAPH *);
GRAPH *node(int);
void dfs(int v);
void bfs(int v);
int repeat(int [],int);

int main()
{
    int i;
    creat(Arr);
    printf("dfs:\n");
    dfs(0);
    printf("\n");
    for(i=0;i<8;i++){   //重置
        mark[i]= 1;
    }
    printf("bfs:\n");
    bfs(0);
    return 0;
}
void creat(GRAPH Arr[])
{

    int i,num;
    for(i=0;i<8;i++){   //初始化Array mark
        mark[i] = 1;
        Arr[i].next = NULL;
        Arr[i].value = i;
    }
    i=0;
    GRAPH *ptr= (Arr+0);    // 用ptr指到Arr[0]
    while(i<8){
        printf("%d with ",i);
        scanf("%d",&num);
        if(num == -1){  //  -1 為判斷是否停止 並將 ptr 只到 下一個位置
                            //EX: ptr = arr+0 -> ptr = arr+1;
            i++;
            ptr = (Arr+i);
            continue;
        }
        ptr->next = node(num);  //創節點
        ptr = ptr->next;        //往後移
    }
}

GRAPH *node(int num)//創節點
{
    GRAPH *ptr = (GRAPH*) malloc(1*sizeof(GRAPH));
    ptr->value = num;
    ptr->next =NULL;
    return ptr;
}

void dfs(int v)
{
    GRAPH *w;
    mark[v] = -1;
    printf("%2c v%d",' ',v);
    for(w = (Arr+v) ; w ; w=w->next){   //w 指到 arr[0~7] 並往其next 移動
        if(mark[w->value] == 1){    //未被visit則遞迴讓 v = w->value
            dfs(w->value);
        }
    }
}
void bfs(int v)//重v0開始
{
    int front =0,rear=0,i;  //紀錄開頭即尾巴
    int arr[8];
    GRAPH *w;
    mark[v] = -1;
    printf("%2c v%d",' ',v);
    arr[front] = v;     //將0塞到queue
    rear++;
    while(front!=rear){//當開頭 == 尾巴則代表queue是空的
        v = arr[front]; //將arr[0]給v
        for(i=0;i<8;i++){   //將arr往前移一格
            arr[i] = arr[i+1];
        }
        rear--;
        for(w = (Arr+v)->next ; w ; w=w->next){ //w 指到 arr[0~7] 的next並往後移動
            if(mark[w->value] == 1){

                if(repeat(arr,w->value) == 0){  //如果再arr裡沒有相同的再塞進queue在印
                    printf("%2c v%d",' ',w->value);
                    arr[rear] = w->value;
                    rear++;

                }
                mark[v] = -1;
            }
        }
    }
}
int repeat(int arr[],int num)
{
    int i;
    for(i=0;i<8;i++){
        if(arr[i] == num){
            return 1;
        }
    }
    return 0;
}
