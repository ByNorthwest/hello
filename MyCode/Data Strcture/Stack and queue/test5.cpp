#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 110
typedef struct {
    int data[MAXSIZE];
    int rear;
    int front;
}SeqQueue;
int n,k;
void initial (SeqQueue * que){
    que->rear = que->front = 0;
}
void enQueue(SeqQueue * que,int a){
    que->data[que->rear] = a;
    que->rear = (que->rear+1)%n;
}
void deQueue(SeqQueue * que,int *i){
    *i = que->data[que->front];
    que->front = (que->front +1)%n;
}
void MoveRight ( ){
    SeqQueue que;
    initial(&que);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        enQueue(&que,a);
    }
    k= k%n;//考虑k比n大时的情况
    for(int i=0;i<k;i++){
        int temp;
        deQueue(&que,&temp);
        enQueue(&que,temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        deQueue(&que,&temp);
        printf("%d ",temp);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    MoveRight();
    return 0;
}