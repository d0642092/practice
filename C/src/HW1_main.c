#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct{
    int n;
    int k;
    float *p;
}CASE;
float test(float *p, float *tmp_p , int i, int n, int k);
int main(){
    CASE testCase[10];
    int tmp_n=0,i=0,j=0, num_testCase=0;
    while(num_testCase<=10){
        scanf("%d", &tmp_n);
        if(tmp_n==0 || num_testCase==10){
            break;
        }
        testCase[num_testCase].n = tmp_n;
        scanf("%d", &testCase[num_testCase].k);
        if(testCase[num_testCase].k>=2 && testCase[num_testCase].k<=testCase[num_testCase].n && testCase[num_testCase].n<=200){
            testCase[num_testCase].p = (float*)calloc(testCase[num_testCase].n, sizeof(float*));
            for(i=0;i<testCase[num_testCase].n;i++){
                scanf("%f", &testCase[num_testCase].p[i]);
            }
            num_testCase++;
        }
    }

    for(i=0;i<num_testCase;i++){
        float tmp_s,s;
        float *tmp_p = calloc(testCase[i].n, sizeof(float*));
        tmp_s = test(testCase[i].p, tmp_p, 0, testCase[i].n, testCase[i].k);
        free(tmp_p);
        free(testCase[i].p);
        s =(int)((tmp_s * 100000) + 0.5) / 100000.0;
        printf("%.5f\n", s);
    }
    system("pause");
    return 0;
}
// test(0,4,3)
// q0*test(1,4,2) + p0*q1*test(2,4,2) + p0*p1*q2*test(3,4,2)
// test(0,4,2)
// q0*test(1,4,2) + p0*q1*test(2,4,2)
// test(1,4,2)
// q1*test(2,4,2) + p1*q2*test(3,4,2)
// test(2,4,2)
// q2*test(3,4,2) + p2*q4*test(4,4,2)
// test(3,4,2)
// p3*q3
// test(4,4,2)
// 1
float test(float *p, float *tmp_p ,int i, int n, int k){
    float s = 0.0,proP = 1.0;
    if(tmp_p[i]!=0){
        return tmp_p[i];
    }else{
        for(int j=i;j<k+i;j++){
            proP = 1.0;
            for (int m=i;m<j;m++){
                proP *= p[m];
            }   
            if(j+1<n){
                s += proP*(1-p[j])*test(p,tmp_p,j+1,n,k);
            }else{
                s += proP*(1-p[j]);
            }
        }
        if(tmp_p[i]==0){
            tmp_p[i] = s;
            return tmp_p[i];
        }
    }
}