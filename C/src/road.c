#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum{
    N,NE,E,SE,S,SW,W,NW
}dir;
typedef struct{
    int value;
    int passing;
    dir diration;
}road;
typedef struct{
    int passrow;
    int passcol;
}transport;

int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    road arr[m+2][n+2];
    transport mark[m*n];
    int top = -1;
    int flag=0;
    int times =0;
    srand(time(NULL));
    while(flag!=1){
        system("CLS");
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(i==1 && j==1){
                    arr[i][j].value=0;
                    arr[i][j].passing=0;
                    arr[i][j].diration = N;
                }
                else if(i==m&&j==n){
                    arr[i][j].value=0;
                    arr[i][j].passing=0;
                    arr[i][j].diration = N;
                }
                else{
                    arr[i][j].value = rand()%2;
                    arr[i][j].passing=0;
                    arr[i][j].diration= N;
                }
            }
        }
        for(i=0;i<m+2;i++){
            for(j=0;j<n+2;j++){
                if(i==0 && j==0){
                    arr[i][j].value = 1;
                }
                else if(i==0 && j!=0){
                    arr[i][j].value = 1;
                }
                else if(j==0 && i!=0){
                    arr[i][j].value = 1;
                }
                else if(i==m+1){
                    arr[i][j].value = 1;
                }
                else if(j==n+1){
                    arr[i][j].value = 1;
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                printf("%2d",arr[i][j].value);
            }
            printf("\n");
        }
        int row=1,col=1;
        flag = 0;
        while(1){
            if(row==m && col==n){
                printf("true\n");
                flag=1;
                break;
            }
            switch(arr[row][col].diration){
                case 0:
                    if(arr[row-1][col].value == 1 || arr[row-1][col].passing == 1 || arr[row-1][col].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row -= 1;
                    }
                    break;
                case 1:
                    if(arr[row-1][col+1].value == 1 || arr[row-1][col+1].passing == 1 || arr[row-1][col+1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row -= 1;
                        col += 1;
                    }
                    break;
                case 2:
                    if(arr[row][col+1].value == 1 || arr[row][col+1].passing == 1 || arr[row][col+1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        col += 1;
                    }
                    break;
                case 3:
                    if(arr[row+1][col+1].value == 1 || arr[row+1][col+1].passing == 1 || arr[row+1][col+1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row += 1;
                        col += 1;
                    }
                    break;
                case 4:
                    if(arr[row+1][col].value == 1 || arr[row+1][col].passing == 1 || arr[row+1][col].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row += 1;
                    }
                    break;
                case 5:
                    if(arr[row+1][col-1].value == 1 || arr[row+1][col-1].passing == 1 || arr[row+1][col-1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row += 1;
                        col -= 1;
                    }
                    break;
                case 6:
                    if(arr[row][col-1].value == 1 || arr[row][col-1].passing == 1 || arr[row
                       ][col-1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        col -= 1;
                    }
                    break;
                case 7:
                    if(arr[row-1][col-1].value == 1 || arr[row-1][col-1].passing == 1 || arr[row-1][col-1].passing == -1){
                        arr[row][col].diration += 1;
                    }
                    else{
                        top+=1;
                        arr[row][col].passing = 1;
                        mark[top].passrow = row;
                        mark[top].passcol = col;
                        row -= 1;
                        col -= 1;
                        //printf("arr[%d][%d].diration = %d\n",row ,col,arr[row][col].diration);
                        //system("pause");
                    }
                    break;
                default:
                    if(row == 1 && col == 1){
                        printf("worng\n");
                        flag=-1;
                        //printf("arr[%d][%d].diration = %d\n",row ,col,arr[row][col].diration);
                        //system("pause");
                    }
                    else{

                        arr[row][col].passing = -1;
                        row = mark[top].passrow;
                        col = mark[top].passcol;
                        top -= 1;
                        //printf("arr[%d][%d].diration = %d\n",row ,col,arr[row][col].diration);
                       // system("pause");
                    }
                    break;
            }
            if(flag==-1){
                times+=1;
                break;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j].passing==1){
                arr[i][j].value = 2;
            }
            printf("%2d",arr[i][j].value);
        }
        printf("\n");
    }
    printf("times = %d\n",times);
    return 0;
}
