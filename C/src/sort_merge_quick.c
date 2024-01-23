#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(char words[],int num)
{
    int i,j,k=0;
    char temp;
    for(i=0;i<num-1;i++){ /*from right to left*/
        for(j=0;j<num-i-1;j++){/*from left to already know*/
            if(words[j]>words[j+1]){
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}
void Qsort(char words[],int left,int right)
{
    int i,j,k;
    char temp,privot;
    if(left < right){
        i = left;
        j = right+1;
        privot = words[left];//find the left
        do{
            do{
                i++;
            }while(words[i]<privot);//is moreThan right i++
            do {
                j--;
            }while(words[j]>privot);//is lessThan left j--
            if(i<j){                /*As left > right swap*/
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }while(i < j);
        temp = words[left];         /*swap the first and final*/
        words[left] = words[j];
        words[j] = temp;
        Qsort(words,left,j-1);
        Qsort(words,j+1,right);
    }
}

void Msort(char words[],int n)
{
    int lengh = 1;
    char extra[n+1];
    extra[n]='\0';
    while(lengh < n){
        merge_pass(words,extra,n,lengh);
        lengh*=2;
        merge_pass(extra,words,n,lengh);
        lengh*=2;
    }
}
void merge_pass(char words[],char extra[],int n,int lengh)
{
    int i,j;
    for(i=0; i<=n-2*lengh ; i += 2*lengh)
        merge(words,extra,i,i+lengh-1,i+2*lengh-1);/*two String compare and make them become one*/
    if(i+lengh<n)  /*if have alone group*/
        merge(words,extra,i,i+lengh-1,n-1);
    else
        for(j=i;j<n;j++)
            extra[j] = words[j];
}
void merge(char words[],char extra[],int i,int m,int n)
{
    int j,k,t;
    j = m+1;
    k=i;
    while(i<=m && j<=n){
        if(words[i] <= words[j]) //left lessThan right save left
            extra[k++] = words[i++];
        else                     //right lessThan left save right
            extra[k++] = words[j++];
    }
    if(i>m)
        for(t=j;t<=n;t++)        //save another word
            extra[k+t-j] = words[t];
    else
        for(t=i;t<=m;t++)
            extra[k+t-i] = words[t];
}
void Reset(char orginal[],char words[],int num)
{   /*RESET WORDS*/
    int i;
    for(i=0;i<num;i++){
        words[i] = orginal[i];
    }
}
int main()
{
    char alpha[27];
    alpha[0] = 'a';
    int i,k=0,num,choose,num2;
    int time1,time2;
    for(i=1;i<26;i++){/*A~Z*/
        alpha[i] = alpha[i-1]+1;
    }
    alpha[26] = '\0';
    scanf("%d",&num);
    num2=num;
    srand(time(NULL));
    char *words = (char*)calloc(sizeof(char),num+1);
    char *tempWords = (char*)calloc(sizeof(char),num+1);
    i=0;
    while(num2>0){
        choose = rand()%26;
        *(words+i) = alpha[choose];
        *(tempWords+i) = alpha[choose];
        i++;
        num2--;
    }
    *(words+i) = '\0';/*the end*/
    *(tempWords+i) = '\0';
    printf("original: %s\n",words);
    time1 = time(NULL);//begin time
    time2 = time(NULL);
    while(time2 - time1 < 1 ){
        Reset(tempWords,words,num);
        sort(words,num);
        k++;
        time2 = time(NULL);//end time
    }
    printf("BuBBleSort: %s\n",words);
    printf("BuBBleSort 1 seconds: %3d times\n\n",k);

    Reset(tempWords,words,num);
    k=0;
    printf("original: %s\n",words);
    time1 = time(NULL);
    time2 = time(NULL);
    while(time2 - time1 < 1 ){
        Reset(tempWords,words,num);
        Qsort(words,0,num-1);
        k++;
        time2 = time(NULL);
    }
    printf("QuickSort: %s\n",words);
    printf("QuickSort 1 seconds: %3d times\n",k);

    Reset(tempWords,words,num);
    k=0;
    printf("\noriginal: %s\n",words);
    time1 = time(NULL);
    time2 = time(NULL);
    while(time2 - time1 < 1 ){
        Reset(tempWords,words,num);
        Msort(words,num);
        k++;
        time2 = time(NULL);
    }
    printf("MergeSort: %s\n",words);
    printf("MergeSort 1 seconds: %3d times\n",k);
}
