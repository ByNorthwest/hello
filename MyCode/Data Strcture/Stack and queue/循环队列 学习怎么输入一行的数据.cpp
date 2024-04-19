#include<stdio.h>
#include<stdlib.h>
 
typedef struct{//定义带有队头队尾的结构体
    int *Data;
    int length;
    int rear;
    int K;
} Queue;
 
Queue* creat(int k){  //不确定k的值所以动态申请队列
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q->K = k + 1;//多申请一个，因为循环队列要一直保留至少一个空的空间来判断是否满队列
    Q->Data = (int*)malloc(sizeof(int)*Q->K);
    Q->length = Q->rear = 0;
    return Q;
}
 
void plus(Queue *Q, int item)//在队尾加一个
{
    if((Q->rear+1)%Q->K==(Q->rear-Q->length)%Q->K){
        return;//如果队尾加一个之后成了队头 满
    }
    else{
        Q->rear = (Q->rear+1)%Q->K;//我选择了先移动队尾在输入元素，也可以选择先输入元素再移动队尾
        Q->Data[Q->rear]=item;
		Q->length++;
    }
 
}
 
int del(Queue *Q)
{//在队头删一个
    if(Q->length==0){
        printf("kong\n");
        return NULL;
    }
    else{
        Q->length--;//队列
        return Q->Data[Q->rear-Q->length];
    }
}
 
int found(Queue *Q)
{
	if(Q->length==0){
        printf("kong\n");
        return NULL;
    }
	else{
		return Q->Data[Q->rear-Q->length+1];
	}
}
int main()
{
	int k,i=0,len,m;
	int A[1000];
	scanf("%d",&k);
	Queue *Q=creat(k);
	while(1){
		scanf("%d",&A[i]);
		i++;
		char c=getchar();
		if(c=='\n')
			break;//输入一串数字 遇到回车停止输入
	}
	len=i;
	i=0;
	while(i<len&&i<k&&Q->length<k){
		plus(Q,A[i]);
		i++;
	}//当长度合适时将字符入队
	//printf("%d",Q->Data[1]);
	char L[100];
	scanf("%s",L);
	scanf("%d",&m);//输入要出队的元素
	while(found(Q)!=m&&Q->length!=0)
		del(Q);
	if(Q->length!=0)
		del(Q);//将包括该元素在内的之前元素出队
	int d=found(Q);//记录下队头元素
	while(Q->length!=0){
		printf("%d ",del(Q));//输出对内剩余元素
	}
	printf("\n");
	printf("%d",d);//输出队头元素
	return 0;
}