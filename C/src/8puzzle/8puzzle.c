#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>
#include"function.h"

int main(){
    time_t startTime=time(NULL),endTime; //total run time
    int r = 0; //random 0 完全隨機
    int success=0,not_finish=0,fail=0; //count
    printf("please wait...\n");
    srand(time(NULL));
    for(int k=0;k<1000;k++){
        // init local variable
        time_t s=time(NULL),e; // each run time
        candicate *fringe = NULL,*ptr=NULL,*tailptr=NULL,*headptr=NULL;
        node *current_node = NULL;
        int position=0;
        int limit=28; //depth limit
        // init globel variable
        targetnode = NULL;
        total_node=0;
        cutoff = 0;
        // init array
        int *init_array = random(r, &position);
        current_node = create_node(init_array,position,-1,0,NULL);// create node
        fringe = create_candicate(current_node, NULL);// put into candicate
        headptr = fringe;  // record head of candicate to free memory at finish
        tailptr = headptr;

        while(targetnode==NULL && fringe!=NULL){
            current_node = fringe->node_data;
            ptr = fringe; // tmp current candicate addr
            fringe = expend(current_node, fringe->next_node, limit); // get a new candicate (partial) we focus now
            ptr->next_node = NULL; // set current candicate addr next is NULL
            tailptr->next_node = ptr; // put after the hole candicate
            tailptr = tailptr->next_node; 
        }

        if(targetnode!=NULL){
            printf("find\n");
            success++;
            successful(targetnode);
        }
        else if(cutoff){
            not_finish++;
            printf("not find but cutoff\n");
        }
        else{
            fail++;
            printf("not find but failure\n");
        }

        printf("total node:%d\n",total_node);
        printf("iter: %d\n",k);
        free_memory(headptr);
        e = time(NULL);
        printf("cost time: %d\n\n",e-s);
        system("pause");
        
    }
    endTime = time(NULL);
    printf("cost time: %d\n",endTime-startTime);
    printf("success:%d , notfinish: %d, fail: %d\n",success,not_finish,fail);
    system("pause");
    return 0;
}