#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int x;      //to save group number
}Add;
void shiftFolding(int arr[],int total)
{
    int i,k,sum,temp;
    if(total%3 == 0)        /* Determine how many groups can cut */
        temp = total/3;     //each group have 3
    else
        temp = total/3+1;
    Add num[temp];
    for(i=0,k=0;i<total,k<temp;i+=3,k++){
        if(i+2 < total)     //save each group
            num[k].x = arr[i]*100 + arr[i+1]*10 + arr[i+2]*1;
        else{
            int m = total - i;  /*find How many number not save*/
            switch(m){
                case 1:
                    num[k].x = arr[i]*1;
                    break;
                case 2:
                    num[k].x = arr[i]*10 + arr[i+1]*1;
                    break;
                default:
                    break;
            }
        }
    }
    for(k=0;k<temp;k++){
        sum += num[k].x;
        printf("x%d: %d\t",k+1,num[k].x);
    }
    sum = sum % 1000;   //divide 1000 to find address
    printf("add: %d\n",sum);
}

void foldingBoundaries(int arr[],int total)
{
    int i,k,sum,temp;
    if(total%3 == 0)    /* Determine how many groups can cut */
        temp = total/3; //each group have 3
    else
        temp = total/3+1;
    Add num[temp];
    for(i=0,k=0;i<total,k<temp;i+=3,k++){
        if(i+2 < total){
            if((k+1) % 2 == 0){ /*check Is it evem now*/
                num[k].x = arr[i]*1 + arr[i+1]*10 + arr[i+2]*100;
            }
            else{
                num[k].x = arr[i]*100 + arr[i+1]*10 + arr[i+2]*1;
            }
        }
        else{
            int m = total - i;
            switch(m){          /*find How many number not save*/
                case 1:
                    num[k].x = arr[i]*1;
                    break;
                case 2:
                    if((k+1) % 2 == 0) /*check Is it evem now*/
                        num[k].x = arr[i+1]*10 + arr[i]*1;
                    else
                        num[k].x = arr[i]*10 + arr[i+1]*1;
                    break;
                default:
                    break;
            }
        }
    }

    sum=0;
    for(k=0;k<temp;k++){
        sum += num[k].x;
        printf("x%d: %d\t",k+1,num[k].x);
    }
    sum = sum % 1000; //divide 1000 to find address
    printf("add: %d\n",sum);
}
int main(){
    int total,i;
    scanf("%d",&total);
    while(total<10)             //moreThan 10
        scanf("%d",&total);
    int arr[total];             /*save number*/
    int temp;
    srand(time(NULL));
    for(i=0;i<total;i++){
        temp = rand()%10;
        if(i==0){
            while(temp == 0)   /*First Number does not Zero*/
                temp = rand()%10;
            arr[i] = temp;
            continue;
        }
        arr[i] = temp;
    }
    for(i=0;i<total;i++)
        printf("%d",arr[i]);
    printf("\nshiftFolding\n");
    shiftFolding(arr,total);
    printf("\nfoldingBoundaries\n");
    foldingBoundaries(arr,total);
    return 0;
}
