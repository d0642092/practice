#include <stdlib.h>
#include <stdio.h>

int choose_min(int *cal, int i, int add, int minus, int row){
    if(add >= row){
        add = 0;
    }else if(minus<0){
        minus = row-1;
    }
    int min=cal[minus], min_d=minus;
    if(cal[add] < cal[i]){
        if(cal[add] < min){
            min = cal[add];
            min_d = add;
        } else if(cal[add] == min && add < min_d){
            min = cal[add];
            min_d = add;
        }
    }else{
        if(cal[i]<min){
            min = cal[i];
            min_d = i;
        } else if(cal[i] == min && i < min_d){
            min = cal[i];
            min_d = i;
        }
    }
    return min_d;
}

void show_min_path(int *calW, int *index_w, int row, int col){
    // find min W
    int i=0,min=calW[0],min_d=0;
    for(i=1;i<row;i++){
        if(calW[i]<min){
            min_d = i;
            min = calW[i];
        }
    }
    int actual_index = (col-1) + min_d*col;
    int path[col],j=col-1;
    // show path
    path[j] = actual_index/col+1;
    while(index_w[actual_index] != -1){
        actual_index = index_w[actual_index];
        j--;
        path[j] = actual_index/col+1;
    }
    for(i=0;i<col;i++){
        if(i!=col-1){
            printf("%d ", path[i]);
        }else{
            printf("%d\n", path[i]);
        }
    }
    printf("%d\n",min);
    return;

}

void find_min_path(int row, int col, int *w, int *index_w){
    int i=0,j=0,k=0, calW[row], tmpA[row];
    for(j=0;j<row;j++){
        calW[j] = w[j*col];
    }
    for(i=1;i<col;i++){
        for(j=0;j<row;j++){
            tmpA[j] = w[i+j*col];
        }
        for(j=0;j<row;j++){ 
            k=choose_min(calW, j, j+1, j-1, row);
            index_w[i+j*col] = (i-1)+k*col;
            tmpA[j] = tmpA[j]+calW[k];
        }
        for(j=0;j<row;j++){ 
            calW[j] = tmpA[j];
        }
    }
    show_min_path(calW,index_w,row,col);
    return;
}

void main(){
    FILE *myFile;
    myFile = fopen("../data/min_path.txt", "r");
    if (myFile == NULL){
        printf("Error Reading File\n");
    }
    else{
        while(!feof(myFile)){
            int row=0, col=0, i=0;
            fscanf(myFile, "%d %d", &row, &col);
            int w[row*col], index_w[row*col];
            for(i=0;i<row*col;i++){
                fscanf(myFile, "%d", &w[i] );
                index_w[i] = -1;
            }
            find_min_path(row, col, w,index_w);
        }
    }
    fclose(myFile);
    system("pause");
    return;
}