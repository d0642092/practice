#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int number,char **arr)
{
    // number: number of inputs
    // arr: input value, arr[0]: .exe. arr[1]: value...
    FILE*fptr;
    FILE*fout;
    fptr = fopen(arr[1],"r");   /*讀入資料*/
    fout = fopen(arr[2],"w");   /*寫入資料*/

    long int one=0,two=0,three=0,four=0,five=0,six=0,over=0/*超過6*/;
    int i,j,templen=0;
    char readstring[100];
    if(fptr==NULL){
        printf("Does not find file\n");
        return 0;
    }
    else{
        while(1){
            fscanf(fptr,"%s",readstring);/*讀去到的字串送到readstring儲存*/
            templen=strlen(readstring);     /*用來判斷是否readstring都不是英文字的變數*/
            if(feof(fptr))break;
            else{
                for(i=0;i<strlen(readstring);i++){
                    if(isalpha(readstring[i])!=0){
                        continue;
                    }
                    else{
                        for(j=i;j<strlen(readstring);j++){
                            readstring[j]=readstring[j+1];/*將後面前移一格*/
                        }
                        templen--;/*字數下降*/
                        i--;/*因前移一格所以要從前一格開始判斷*/
                    }
                }
                if(templen!=0){
                    switch(strlen(readstring)){
                            case 1:
                                one++;
                                break;
                            case 2:
                                two++;
                                break;
                            case 3:
                                three++;
                                break;
                            case 4:
                                four++;
                                break;
                            case 5:
                                five++;
                                break;
                            case 6:
                                six++;
                                break;
                            default:
                                over++;
                                break;
                    }
                    fprintf(fout,"%s ",readstring);/*寫出到out.txt*/
                }
                else{
                    continue;
                }
            }
        }
    }
    printf("Length of 1: %ld\n",one);
    printf("Length of 2: %ld\n",two);
    printf("Length of 3: %ld\n",three);
    printf("Length of 4: %ld\n",four);
    printf("Length of 5: %ld\n",five);
    printf("Length of 6: %ld\n",six);
    printf("Length greater than 6 : %ld\n",over);
    fclose(fout);
    fclose(fptr);
    system("pause");
    return 0;
}
