#include <math.h>

typedef struct 
{
    int *data;
    int node_position;
    int node_action;
    int node_depth;
    struct node* node_parent;
}node; //node information

typedef struct
{
    struct node *node_data;
    struct candicate *next_node;
}candicate; // candicate all node


node *targetnode =NULL; //target node
int total_node=0, cutoff = 0; // falg
int target_array[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5}; // target array
int check_dir[9] = {-1, -1, 3, 2, -1, 3, 2, -1, -1}; // which direction can not move ,-1->not need consider
int move_action[4] = {-3, 3, -1, 1}; // up = -3, down = 3, left = -1, right = 1

int *random(int r,int *position); // init array r=0 random choose, r=1 random walk
int *getRand(int min, int max, int num); // generate random array
int wherespace(int *arr); //find the space which is 0
int move(int *array, int action,int position); // move function
int score_arr(int *arr); // compare expend node score to sort them

void check_direction(int *action_array, int *array, int now_position, int pre_action); // check direction of currentnode
void copy_array_A2B(int *A, int *B); // copy array A to B
void print_array(int *array); // print array
void print_node(node* tmp_node);// print node information
void successful(node *target); // successful function
void free_memory(candicate *ptr); // free memory

node *create_node(int *array, int position, int action,int depth, node *parent);
candicate *create_candicate(node *tmp_node, candicate *next);
candicate *expend(node *tmp_node, candicate *next, int limit);

node *create_node(int *array, int position, int action, int depth, node *parent){
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->data = array;
    new_node->node_position = position;
    new_node->node_action = action;
    new_node->node_depth = depth;
    new_node->node_parent = parent;
    return new_node;
}

candicate *create_candicate(node *tmp_node, candicate *next){
    candicate *new_candicate = (candicate*) calloc(1, sizeof(candicate));
    new_candicate->node_data = tmp_node;
    new_candicate->next_node = next;
    return new_candicate;
}

candicate *expend(node *tmp_node, candicate *next, int limit){
    // check node direction DFS
    candicate *head=NULL, *tail=NULL;
    node *ntmp=NULL;
    int tmp_addr[4]={0},score[4]={0},action_array[4]={0};
    int i=0,j=0,index=0,new_position=0,temp=0,depth=tmp_node->node_depth+1;
    if( depth == limit){
        cutoff=1;
        return next;
    }
    check_direction(action_array,tmp_node->data, tmp_node->node_position, tmp_node->node_action);
    for(i=0;i<4;i++){
        // move and create node
        if(action_array[i]!=0){
            int *new_array = (int*) calloc(9, sizeof(int));
            copy_array_A2B(tmp_node->data, new_array);
            new_position=move(new_array,action_array[i],tmp_node->node_position);
            score[index]=score_arr(new_array);
            node *new_node = create_node(new_array,new_position,i, depth ,tmp_node);
            tmp_addr[index] = new_node;
            index++;
        }
    }
    
    if(index!=0){
        // ranking node
        for (i = 0; i < index; i++) {
            for (j = 0; j < i; j++) {
                if (score[j] < score[i]) {
                    temp = score[j];
                    score[j] = score[i];
                    score[i] = temp;
                    temp = tmp_addr[j];
                    tmp_addr[j] = tmp_addr[i];
                    tmp_addr[i] = temp;
                }
            }
        }
        // put into candicate and compare target
        for(i=0;i<index;i++){
            total_node++;
            if(head == NULL){
                head = create_candicate(tmp_addr[i], NULL);
                tail = head;
            }else{
                tail->next_node = create_candicate(tmp_addr[i], NULL);;
                tail = tail->next_node;
            }
            ntmp = tmp_addr[i];
            if(memcmp(target_array,ntmp->data,sizeof(target_array))==0){
                targetnode = tail->node_data;
                tail->next_node = next;
                return head;
            }
        }
    }
    if(head==NULL){
        // if no expend
        head = next;
    }
    else{

        tail->next_node = next;
    }

    return head;
}

void check_direction(int *action_array, int *array, int now_position, int pre_action){
    int rejection=-1,direction=0;

    switch (pre_action)
    {
        case 0://up
            rejection = 1; // reject down
            break;
        case 1://down
            rejection = 0; // reject up
            break;
        case 2://left
            rejection = 3;//reject right
            break;
        case 3://right
            rejection = 2;//reject left
            break;
        default:
            break;
    }
    for(direction=0;direction<4;direction++){
        if(direction==rejection||check_dir[now_position] == direction || now_position+move_action[direction]<0 || now_position+move_action[direction]>8){
            continue;
        }
        *(action_array+direction) = move_action[direction];
    }
}

int move(int *array, int action,int position){
    int tmp=0;
    tmp=*(array+position);
    *(array+position) = *(array+position+action);
    *(array+position+action) = tmp;
    position = position + action;
    return position;
}

int *random(int r,int *position){
    int *init_array = (int*)calloc(sizeof(int),9);
    int i=0, direction=0,prevoius_action = -1,rejectAction=-1;
    if(r){
        // init game create array
        *position = 4;
        copy_array_A2B(target_array, init_array);
        for(i=0;i<1000;i++){
            direction = rand() % 4;
            switch (prevoius_action)
            {
                case 0://up
                    rejectAction = 1; // reject down
                    break;
                case 1://down
                    rejectAction = 0; // reject up
                    break;
                case 2://left
                    rejectAction = 3;//reject right
                    break;
                case 3://right
                    rejectAction = 2;//reject left
                    break;
                default:
                    break;
            }
            if(direction==rejectAction||check_dir[*position] == direction || *position+move_action[direction]<0 || *position+move_action[direction]>8){
                i--; 
                continue;
            }else{
                *position = move(init_array,move_action[direction],*position);
            }
        }
        
    }
    else{
        int *array=getRand(0,8,9);
        copy_array_A2B(array, init_array);
        *position = wherespace(init_array);
    }
    return init_array;
}

int wherespace(int *arr){
    int i=0;
    for(i=0;i<9;i++){
        if(*(arr+i)==0){
            return i;
        }
    }
    return NULL;
}

int *getRand(int min, int max, int num){
    int tol = max - min +1, a[9], i, j,ctr;  
    static int b[9];  
    for(i=0;i<tol;i++){  
        *(a+i) = min+i;
    }
    for(i=0;i<num;i++){
        ctr = rand()%(tol-i);
        b[i] = a[ctr];  
        for(j=ctr;j<(tol-1-i);j++){ 
            a[j] = a[j+1];  
        }
    }
    return b;
}

void successful(node *target){
    candicate *head=NULL,*tail=NULL,*p=NULL;
    tail=create_candicate(target,NULL);
    target = target->node_parent;
    head=create_candicate(target,NULL);
    head->next_node = tail;
    target = target->node_parent;

    while (target != NULL)
    {
        tail=create_candicate(target,NULL);
        tail->next_node = head;
        head = tail;
        target = target->node_parent;
    }
    while (head!=NULL)
    {
        target = head->node_data;
        print_array(target->data);
        printf("\n");
        p = head;
        head = head->next_node;
        free(p);
    }
    return;
}

void free_memory(candicate *ptr){
    node *ntmp = NULL;
    candicate *ctmp=NULL;
    while(ptr!=NULL){
        ntmp = ptr->node_data;
        free(ntmp->data);
        free(ntmp);
        ctmp=ptr;
        ptr=ptr->next_node;
        free(ctmp);
    }
}

void print_array(int *array){
    int i = 0;
    for (i = 0; i < 9; i++){
        if(i%3==0){
            printf("\n");
        }
        printf("%d ",*(array+i));
    }
    printf("\n");
    return;
}

void print_node(node* tmp_node){
    printf("After moving Array: \n");
    print_array(tmp_node->data);
    printf("now space position: %d\n",tmp_node->node_position);
    printf("action(0:up,1:down,2:left,3:right): %d\n",tmp_node->node_action);
    printf("this node parent addr: %p\n",tmp_node->node_parent);
    printf("******************************************\n"); 
    return;    
}

void copy_array_A2B(int *A, int *B){
    int i = 0;
    for (i = 0; i < 9; i++){
        *(B+i) = *(A+i);
    }
    return;
}

int score_arr(int *arr){
    int i=0,score=0;
    for(i=0;i<9;i++){
        if(*(arr+i)==target_array[i]){
            score++;
        }
    }
    return score;
}