#include <stdio.h>
#include <stdlib.h>

int GCD (int a, int b);
int main()
{
    int m,n;
    while(1){
        printf("Input two numbers: ");
        scanf("%d%d",&m,&n);
        printf("GCD result: %d\n",GCD(m,n));
    }
}
int GCD (int a,int b)
{
    int r;
    r = a % b;
    if(r==0){
        return b;/*因為r 已經給b*/
    }
    else{
        a = b;
        b = r;
        return GCD(a,b);
    }
}
