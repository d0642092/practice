#include <stdlib.h>
#include <stdio.h>
void takeAllOn(int n);
void takeAllDown(int n);
int step = 0;
int main(){
    int n=0,action=1;
    do{
        printf("input num('>0'): ");
        scanf("%d", &n);
    }while(n<=0);
    do{
        printf("Action 1 for all down, 2 for all on: ");
        scanf("%d",&action);
    }while(action !=1 && action!=2);
    printf("\n");
    if(action==1){
        takeAllDown(n);
    }else{
        takeAllOn(n);
    }
    system("pause");
    return 0;
}
void takeAllOn(int n){
    if(n>0){
        if(n!=2){
            takeAllOn(n-1);
            takeAllDown(n-2);
            printf("step %d, take ring up  : %d\n",++step,n);
            takeAllOn(n-2);
        }else{
            printf("step %d, take ring up  : 1,2\n",++step);
        }
    }
    return;
}

void takeAllDown(int n){
    if(n>0){
        if(n!=2){
            takeAllDown(n-2);
            printf("step %d, take ring down: %d\n",++step,n);
            takeAllOn(n-2);
            takeAllDown(n-1);
        }else{
            printf("step %d, take ring down: 1,2\n",++step);
        }
    }
    return;
}