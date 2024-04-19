#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct {
    int ele[MAXSIZE];
    int rear;
    int front;
    int length;
}Queue;
int len;
void initial(Queue *que){
    que->length = 0;
    que->rear = 0;
    que->front = 0;
}

void EnterQueue(Queue *que,int a){
  
        que->length ++;
        que->ele[que->rear] = a;
        que->rear = (que->rear+1)%MAXSIZE;

    
}

int  gettop(Queue * que){
    return que->ele[que->front];
}
void DeletQueue(Queue *que){
    if(que->length == 0){
        return;
    }else{
        que->length --;
        que->front = (que->front + 1)%MAXSIZE;
    }
}
int  getnumber(char *a,int m){
        int v=0;
    for(int i=0;i<m;i++){
        int b = a[i] - 48;
        v +=b * (i+1);
    }
    return v;
}
void SeqQueue(){
    Queue qu;
    initial(&qu);
    int i = 0,A[MAXSIZE];
    while(1){
        scanf("%d",&A[i]);
        i++;
        char c = getchar();
        if(c=='\n')
            break;
    }
    
    int k= i;
    i = 0;
    while(i<k){
        EnterQueue(&qu,A[i]);
        i++;
    }
    int d;
    scanf("%d",&d);
    if ( i == len){
        printf("yes");
    }else{
        printf("no");
    }
    while(d != gettop(&qu)){
        DeletQueue(&qu);
    }
    DeletQueue(&qu);
    printf("\n");
    int g = gettop(&qu);
    while(qu.length !=1){
        printf("%d ",gettop(&qu));
        DeletQueue(&qu);
    }
    printf("%d",gettop(&qu));
        DeletQueue(&qu);
    printf("\n%d",g);
}

int main(){
    scanf("%d",&len);
    SeqQueue();
    return 0;
}
