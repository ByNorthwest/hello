#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct {
    int data[MAXSIZE];
    int rear;
    int front;
    int tag;
}SeqQueue;
int max,k;

void initial(SeqQueue *que){
    que->rear = que->front = 0;
    que->tag = 0;
}
void enQueue(SeqQueue * que,int a){
    if (que->tag ==1){
        que->front = (que->front + 1)%k;
    }//此处不能有else 因为front消除最前一个时也必须在最后增添一个元素确保k
    //理解课本上损失一个元素的意义是什么
        que->data[que->rear] = a;
        que->rear =(que->rear + 1)% k;

    if (que->rear == que->front && que->tag ==0 ){
        que->tag =1;
    }
}
void deQueue(SeqQueue *que,int *p){
    *p = que->data[que->front];
    que->front =(que->front +1) % k;
    que->tag = 0;
}
void Fibonaci(){
    SeqQueue que;
    initial(&que);
        for(int i=0;i<k;i++){
        enQueue(&que,0);
    }
    
    enQueue(&que,1);
    enQueue(&que,1);
    /* int a,b,c;
    a = 1;
    b = 1;
    c = 2;
    while(c<=max){
        enQueue(&que,c);
        a = b;
        b = c;
        c = a +b;
    } */
    int c = 2;
    while(c<=max){
        enQueue(&que,c);
        int sum = 0;
        int  que1 = que.rear;
        int  que2 = que.front;
        do{
            sum +=que.data[que1];
            que1 = (que1+1)%k;
        }while(que1 != que2);
        c = sum;
    }
    int h;
    for(int i=0;i<k-1;i++){
        deQueue(&que,&h);
        printf("%d ",h);
    }
    deQueue(&que,&h);
    printf("%d",h);
}

int main(){
    scanf("%d%d",&max,&k);
    Fibonaci();
    return 0;
}