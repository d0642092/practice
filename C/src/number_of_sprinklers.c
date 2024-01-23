#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct{
    float left_x;
    float right_x;
}CIRCLE;
void sort_circle(CIRCLE *circles,int first, int last){
    int i, j, pivot;
    CIRCLE tmp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(circles[i].left_x <= circles[pivot].left_x && i<last) i++;
            while(circles[j].left_x > circles[pivot].left_x) j--;
            if(i<j){
                tmp.left_x = circles[i].left_x;
                tmp.right_x = circles[i].right_x;
                circles[i].left_x = circles[j].left_x;
                circles[i].right_x = circles[j].right_x;
                circles[j].left_x = tmp.left_x;
                circles[j].right_x = tmp.right_x;
            }
        }
        tmp.left_x = circles[pivot].left_x;
        tmp.right_x = circles[pivot].right_x;
        circles[pivot].left_x = circles[j].left_x;
        circles[pivot].right_x = circles[j].right_x;
        circles[j].left_x = tmp.left_x;
        circles[j].right_x = tmp.right_x;
        sort_circle(circles, first, j-1);
        sort_circle(circles, j+1, last);
    }
    return;
}

void main(){
    FILE *myFile;
    myFile = fopen("../data/number_of_sprinklers.txt", "r");
    if (myFile == NULL){
        printf("Error Reading File\n");
    }
    else{
        while(!feof(myFile)){
            int n=0, l=0, w=0,i=0,j=0, ans=0, flag=0;
            fscanf(myFile, "%d %d %d", &n, &l, &w);
            CIRCLE circles[n];
            for(i=0;i<n;i++){
                int p=0, r=0;
                float len=0.0;
                fscanf(myFile, "%d %d", &p, &r);
                float tmp = w/2;
                if(r < tmp || flag){
                    circles[i].left_x = l + 1000.0;
                    circles[i].right_x = l + 1000.0;
                    continue;
                }
                len = sqrt(r*r - 0.25*w*w);
                circles[i].left_x = p - len;
                circles[i].right_x = p + len;
                if(p - len <= 0 && p+len >=l){
                    ans = 1;
                    flag = 1;
                }
            }
            
            if(ans){
                printf("1\n");
            }else{
                ans = 1;
                sort_circle(circles,0, n-1);
                for(i=0;i<n;i++){
                    if(circles[i].right_x >= l){
                        break;
                    }
                    int next_num = -1; // init next circles
                    for(j=i+1; j<n;j++){
                        if(circles[i].right_x >= circles[j].left_x){ // cover end point last time
                            if(next_num == -1){ // find next circle
                                next_num = j;
                            } else if(circles[j].right_x >= circles[next_num].right_x){
                                next_num = j; // find more far circle
                            }
                        }
                    }
                    i = next_num-1;
                    ans++;
                    if(next_num == -1){ //fail
                        ans = 0;
                        break;
                    }
                    if(circles[next_num].right_x >= l) break; //find finish

                }
                if(ans!=0 && circles[0].left_x <= 0){
                    // confirm left margin
                    printf("%d\n", ans);
                }else{
                    printf("-1\n");
                }
            }
        }
    }
    fclose(myFile);
    system("pause");
    return;
}