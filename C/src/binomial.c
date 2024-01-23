#include <stdio.h>
#include <stdlib.h>

int binomial (int x);
int main()
{
    int i,j,k;
    while(1) {
        scanf("%d",&k);
        for(i=0;i<=k;i++){
            for(j=0;j<=i;j++){
                printf("%d ",binomial(i)/binomial(j)/binomial(i-j));/*m取n*/
            }
            printf("\n");
        }
    }
    system("pause");
}
int binomial(int x)
{
    if(x==0){
        return 1;
    }
    else {
        return x*binomial(x-1);/*遞迴*/
    }
}
