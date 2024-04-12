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
    if (que->length == len){
        return ;
    }else{
        que->length ++;
        que->ele[que->rear] = a;
        que->rear = (que->rear+1)%MAXSIZE;

    }
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
void SeqQueue(){
    Queue qu;
    initial(&qu);
    int a,i=0;
    /*#include<stdio.h>
int main(){
	int a;
	while(scanf("%d",&a)){
		printf("%d",a);
	}
	return 0;
} *///其中使用while(scanf)这个技巧可以读取一整行的数//这个读没有结束了
    while(scanf("%d",&a)){
        EnterQueue(&qu,a);
        i++;
        if(i==len-1){
            printf("yes");
            break;
        }
    } 
    scanf("%d",&a);
    while(qu.ele[qu.front] !=a){
        DeletQueue(&qu);
    }
    if(i ==len){
        printf("yes");
    }else{
        printf("no");
    }
    DeletQueue(&qu);
    int g = gettop(&qu);
    while(qu.length){
        printf("%d ",gettop(&qu));
        DeletQueue(&qu);
    }
    printf("\n%d",g);
}
int main(){
    scanf("%d",&len);
    SeqQueue();
    return 0;
}