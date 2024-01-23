#include <stdio.h>
#include <stdlib.h>

long long int fac(int a, int b);/*整體算式*/
long long int factorial(int x);/*階層*/
int main()
{
    while(1){
        int m, n;
        long long int k;
        printf("Input two positive numbers, M more than N:\n");
        // printf("輸入兩正數M,N，且M需大於等於N:\n");
        scanf("%d%d",&m,&n);
        if(m<n){
            continue;
        }
        else{
            printf("C(%d, %d) = %lld\n",m,n,fac(m,n));
        }
    }
}
long long int fac(int a, int b)
{
    return factorial(a)/factorial(b)/factorial(a-b);
}

long long int factorial(int x)
{
    if(x==0){
        return 1;
    }
    else{
        return x*factorial(x-1);/*遞迴*/
    }
}
