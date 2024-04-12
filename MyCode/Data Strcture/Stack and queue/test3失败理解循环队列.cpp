#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    Node *next;
}QueueNode;

typedef struct {
    QueueNode *rear;
    int length;
}QueueList;

void initial(QueueList * que){
    que->length = 0;
    que->rear = (QueueNode *)malloc (sizeof(QueueNode));
    que->rear->next= que->rear;
}

void EnterQueue(QueueList * que, int data)//还是传入一级指针
{
    QueueNode * temp= (QueueNode*)malloc (sizeof(QueueNode));
    temp->data = data;
    /*if(que->rear->next == que ->rear){
        q
        
    }不需要进行分类讨论，当队列中不含元素时入队列操作相同*/
    temp->next = que->rear->next;
    que->rear->next = temp;
    que->rear = temp;//三步走
    que->length ++:
}

void DeletQueue(QueueList * que){
    QueueNode * temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp = que->rear->next->next;
    que->rear->next->next = temp ->next;
    free(temp);
}

void 
int main(){
    int len;
    scanf("%d",&len);
    
}