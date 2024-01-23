#include <stdio.h>
#include <stdlib.h>
typedef struct graph{
    struct graph *next;
    int to;
    int edgeNode;
}GRAPH;
typedef struct {
    int from;
    int to;
    int edge;
}EDGE;
GRAPH Arr[7];
EDGE edge[18];
EDGE Trans[7];
void creat(GRAPH *);
GRAPH *node(int,int);
void Kruskal(int );
void Prim(int,int,int);
int isCycle(EDGE,EDGE[],int);
int lessThan(int[],int);
int finish(int[],int);
void print(EDGE [],int);

int main()
{
    creat(Arr);
    edge[0].from = 0;  edge[1].from = 2; edge[2].from = 1; edge[3].from = 1;/*不好節圖所以沒縮排*/
    edge[0].to = 5;    edge[1].to = 3;   edge[2].to = 6;   edge[3].to = 2;
    edge[0].edge = 10; edge[1].edge = 12;edge[2].edge = 14;edge[3].edge = 16;

    edge[4].from = 3; edge[5].from = 3; edge[6].from = 4;edge[7].from = 4;edge[8].from = 0;
    edge[4].to = 6;   edge[5].to = 4;   edge[6].to = 6;edge[7].to = 5;edge[8].to = 1;
    edge[4].edge = 18;edge[5].edge = 22;edge[6].edge = 24;edge[7].edge = 25;edge[8].edge = 28;

    Kruskal(7);
    printf("\nPrim:\n");
    Prim(0,6,0);
    return 0;
}
void creat(GRAPH Arr[])
{

    int i,nextRoad,edg;
    for(i=0;i<7;i++){
        Arr[i].next = NULL;
        Arr[i].to = i;
        Arr[i].edgeNode = -1;
    }
    i=0;
    GRAPH *ptr= (Arr+0);
    printf("0 with ");
    while(i<7){
        scanf("%d%d",&nextRoad,&edg);   //塞值
        if(nextRoad == -1 || edg == -1){
            i++;
            ptr = (Arr+i);
            if(i<7){
                printf("%d with ",i);
            }
            continue;
        }
        ptr->next = node(nextRoad,edg); //創node
        ptr = ptr->next;
    }
}
GRAPH *node(int nextRoad,int edg)
{
    GRAPH *ptr = (GRAPH*) malloc(1*sizeof(GRAPH));
    ptr->to = nextRoad;
    ptr->edgeNode = edg;
    ptr->next =NULL;
    return ptr;
}
void Kruskal(int n)
{
    EDGE T[n];
    int nowSave=0,i=0;

    while(nowSave<n-1){
        if(isCycle(edge[i],T,nowSave) == 0){//找循環
            T[nowSave].from = edge[i].from; //沒有循環塞值
            T[nowSave].to = edge[i].to;
            T[nowSave].edge = edge[i].edge;
            nowSave++;
        }
        i++;
    }
    print(T,nowSave);   //印出
}
void Prim(int pre,int start,int nowSave)
{

    GRAPH *w;
    EDGE already;   //暫存要判斷circle
    int compare[4];
    int i=0,temp,flag=1;
    for(i=0;i<4;i++){
        compare[i]=1000;
    }
    i=0;
    printf("%5d",Arr[start].to);
    while(nowSave<6){   //最多6
        for(w = Arr+start;w;w=w->next){
            if(w->edgeNode == -1){  //edge=-1 or 為前一個跳過
                continue;
            }
            if(w->to == pre){
                continue;
            }
            compare[i] = w->edgeNode;   //塞進陣列準備比較
            i++;
        }
        while(flag==1){
            flag =0;
            temp = lessThan(compare,i);//找最小
            for(w = Arr+start;w;w=w->next){
                if(w->edgeNode == temp){
                    already.from = start;
                    already.to = w->to;
                    already.edge = w->edgeNode;
                    if(isCycle(already,Trans,nowSave) == 0){    //找循環
                        Trans[nowSave].from = start;
                        Trans[nowSave].to = w->to;
                        Trans[nowSave].edge = w->edgeNode;
                        nowSave++;
                        Prim(start,w->to,nowSave);
                    }
                    else{   //有循環temp重找
                        for(i=0;i<4;i++){
                            if(compare[i]==temp){
                                compare[i] = 1000;
                            }
                        }
                        flag = 1;
                    }
                }
            }
        }

    }
}
int lessThan(int arr[],int total)
{
    int min=arr[0],i;
    for(i=1;i<total;i++){
        if(min==-1){
            min = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int finish(int visit[],int nowSave)
{
    int i;
    for(i=0;i<nowSave;i++){
        if(visit[i] == 1){
            return 0;
        }
    }
    return 1;
}


int isCycle(EDGE temp,EDGE T[],int nowSave)
{
    if(nowSave == 0){
        return 0;
    }
    else{
        int begin = temp.from;  //設開頭結尾
        int end = temp.to;
        int i,j=0;
        int visit[nowSave];

        while(finish(visit,nowSave)==0 || j<=nowSave){  //finish(visit,nowSave)==1為結束
            for(i=0;i<nowSave;i++){
                visit[i] = 0;
                if(T[i].from == end || T[i].to == end){ //找到開頭結尾為循環
                    if(T[i].from == begin || T[i].to == begin){
                        return 1;
                    }
                }
                if(T[i].from == end){   //是否為結尾
                    end = T[i].to;
                    j++;
                    continue;
                }
                else if(T[i].to == end){//是否為結尾
                    end = T[i].from;
                    j++;
                    continue;
                }
                else{
                    if(T[i].from == begin){//是否為開頭
                        begin = T[i].from;
                        j++;
                        continue;
                    }
                    else if(T[i].to == begin){//是否為開頭
                        begin = T[i].from;
                        j++;
                        continue;
                    }
                    else{
                        visit[i]= 0;
                        continue;
                    }
                }
            }
            j++;}
        return 0;
    }
}

void print(EDGE T[],int total)
{
    int i,start=6,num=0;
    int visit[total];
    for(i=0;i<total;i++){
        visit[i] = 1;
    }
    printf("Kruskal algorithm:\n");
    while(finish(visit,total)== 0){//確認是否都有走過
        for(i=0;i<total;i++){
            if(T[i].from==start && visit[i]==1){
                printf("%5d",T[i].from);
                start = T[i].to;    //從6開始找到後替換到結束
                visit[i] = -1;
                num++;
                if(num == total){
                    printf("%5d",T[i].to);
                }
            }



            else if(T[i].to==start && visit[i]==1){
                printf("%5d",T[i].to);
                start = T[i].from;  //從6開始找到後替換到結束
                visit[i] = -1;
                num++;
                if(num == total){       //num 為印出數量 == total總數量則表示為結尾 印出相應數字
                    printf("%5d",T[i].from);
                }
            }
            else{
                continue;
            }
        }
    }
}
